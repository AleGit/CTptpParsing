
#include <stdio.h>
#include "CSources/PrlcParser.h"

int prlc_parse_path (const char*);
int file_size(FILE*);

void print_shelf_info(const char*, const prlc_shelf);
void print_store_infos(PrlcStoreRef);
void print_store_symbols(PrlcStoreRef, PrlcTreeNodeRef);

void check_memory();
void check_string_store();
void check_parse_file(const char *);

const char* puz001="PUZ001-1.p";

int main()
{

	check_parse_file (puz001);
	
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

void print_store_symbols(PrlcStoreRef store, PrlcTreeNodeRef root) {
	size_t len = 0; 
	const char* name = prlcFirstSymbol (store);
	while (name != NULL) {
		len += strlen(name) + 3;

		if (len > 99 || name == root->symbol) {
			printf("\n");
			len = strlen(name) + 3;
		}
		
		printf("»%s« ", name);
		
		name = prlcNextSymbol (store, name);
	}
	
	printf("¤\n");
}


void check_parse_file(const char *path) {
	printf("%s\n",path);

	prlc_parse_path (path);
	
	PrlcStoreRef store = prlcParsingStore;
	prlc_tree_node* root = prlcParsingRoot;
	
	prlcParsingStore = NULL;
	prlcParsingRoot = NULL;

	
	
	print_store_infos (store);
	print_store_symbols (store, root);


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
	
	printf("%s: %lu.%lu.%lu (%d %% of %lu bytes)\n", name, shelf.size, shelf.unit, shelf.capacity, promille/10, shelf.capacity*shelf.unit);
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
