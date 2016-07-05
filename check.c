
#include <stdio.h>
#include "CSources/PrlcParser.h"

void print_memory_info(const char* name, const prlc_memory memory);
void print_store_infos(PrlcStoreRef store);

void check_memory();
void check_string_store();
void check_parse_file(const char *);

const char* puz001="/home/amaringele/Downloads/TPTP/Problems/PUZ/PUZ001-1.p";
const char* hwv = "/home/amaringele/Downloads/TPTP/Problems/HWV/HWV003-1.p";
const char* hwv134 = "/home/amaringele/Downloads/TPTP/Problems/HWV/HWV134-1.p";

int main()
{

	// check_string_store ();

	check_parse_file (puz001);

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
	while (size < 2764550910) {

		printf("%ld\n",size);

		PrlcStoreRef store = prlcCreateStore(size);

		print_store_infos (store);

		prlcDestroyStore(&store);
		size *= 2;
	}
}

void check_parse_file(const char *path) {
	printf("%s",path);
	

	prlc_parse_path (path);
	PrlcStoreRef store = prlcParsingStore;
	prlc_tree_node* root = prlcParsingRoot;
	
	prlcParsingStore = NULL;
	prlcParsingRoot = NULL;

	const char* name = prlcFirstSymbol (store);
	while (name != NULL) {
		printf("»%s« ", name);
		name = prlcNextSymbol (store,name);
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

void print_memory_info(const char* name, const prlc_memory memory) {
	printf("%s: %lu.%lu.%lu\n", name, memory.size, memory.unit, memory.capacity);
}

void print_store_infos(PrlcStoreRef store) {
	print_memory_info("symbols", store->symbols);
	print_memory_info("prefix nodes", store->p_nodes);
	print_memory_info("tree nodes", store->t_nodes);
}
