
#include <stdio.h>
#include "CSources/PrlcParser.h"

int prlc_parse_path (const char* file_path);
int file_size(FILE *file);

void print_shelf_info(const char* name, const prlc_shelf memory);
void print_store_infos(PrlcStoreRef store);
void print_store_symbols(PrlcStoreRef store);

void check_memory();
void check_string_store();
void check_parse_file(const char *);

const char* puz001="/home/amaringele/Downloads/TPTP/Problems/PUZ/PUZ001-1.p";
const char* hwv107 = "/home/amaringele/Downloads/TPTP/Problems/HWV/HWV107-1.p";
const char* hwv134 = "/home/amaringele/Downloads/TPTP/Problems/HWV/HWV134-1.p";

int main()
{

	// check_string_store ();

	check_parse_file (hwv134);

	// check_memory ();

/*	FILE *file = fopen(hwv134,"r");

	

	int size = file_size(file);

	printf("%d, %s\n", size, hwv134);
	
	fclose(file);*/
	
	return (0);
}

void check_memory() {
	// 276455091, /home/amaringele/Downloads/TPTP/Problems/HWV/HWV134-1.p
	long size = 276455091/4;
	while (size < 27645509100) {

		printf("%ld\n",size);

		PrlcStoreRef store = prlcCreateStore(size);

		print_store_infos (store);

		prlcDestroyStore(&store);
		size *= 2;
	}
}

void check_parse_file(const char *path) {
	printf("%s\n",path);

	prlc_parse_path (path);
	
	PrlcStoreRef store = prlcParsingStore;
	prlc_tree_node* root = prlcParsingRoot;
	
	prlcParsingStore = NULL;
	prlcParsingRoot = NULL;

	int i = 0; 
	const char* name = prlcFirstSymbol (store);
	while (name != NULL && i < 23) {
		printf("»%s« ", name);
		name = prlcNextSymbol (store, name);
		i++;
	}
	
	printf("¤\n");
	
	print_store_infos (store);


	prlcDestroyStore(&store);
	
}

void check_string_store() {
	printf("*** check_string_store ***\n");
	PrlcStoreRef store = prlcCreateStore(95000);

	const char* a = "Agatha";
	const char* b = "Butler";
	const char* c = "Charles";

	const char* a0 = prlcStoreSymbol(store,"Agatha");
	const char* b1 = prlcStoreSymbol(store,b);
	const char* c1 = prlcStoreSymbol (store,c);
	
	const char* a1 = prlcStoreSymbol(store,a);
	const char* b0 = prlcStoreSymbol (store,"Butler");
	const char* c0 = prlcStoreSymbol(store, "Charles");

	const char* name = prlcFirstSymbol (store);
	while (name != NULL) {
		printf("%s ", name);
		name = prlcNextSymbol (store,name);
	}
	
	printf("\n");
	print_store_infos(store);

	prlcDestroyStore(&store);
	printf("=== check_string_store ===\n");
}

/* helpers */

void print_shelf_info(const char* name, const prlc_shelf shelf) {
	int promille = (1000 * shelf.size) / shelf.capacity + 5;
	

	
	printf("%s: %lu.%lu.%lu (%d %%)\n", name, shelf.size, shelf.unit, shelf.capacity, promille/10);
}

void print_store_infos(PrlcStoreRef store) {
	print_shelf_info("symbols", store->symbols);
	print_shelf_info("prefix nodes", store->p_nodes);
	print_shelf_info("tree nodes", store->t_nodes);
}   

// total size of file in bytes
int file_size(FILE *file) {
	int size = 0;

	if (file != NULL) {

	fseek(file, 0L, SEEK_END);
	size = ftell(file);
	rewind(file);
	}
	
	return size;
}

int prlc_parse_path (const char* path) {
	if (path == NULL) {
		fprintf(stderr,"prlc_parse_path(NULL)\n");
		return -1;
	}
	
	FILE *file = fopen(path,"r");

	int size = file_size(file);

	if (file == NULL) {
		// file not found
		fprintf(stderr,"prlc_parse_path(%s) file could not be oppened.\n", path);
		return -1; 
	}

	if (size == 0) {
		// file is empty
		fprintf(stderr,"prlc_parse_path(%s) file is empty.\n", path);
		return -1; 
	}
	
	prlc_in = file;
	prlc_restart(file);
	prlc_lineno = 1;

	prlcParsingStore = prlcCreateStore(size);
	prlcParsingRoot = prlcStoreNodeFile (prlcParsingStore,path,NULL);

	int code = prlc_parse ();

	fclose(file);

	return code;
}
