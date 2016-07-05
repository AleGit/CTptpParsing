
#include <stdio.h>
#include "CSources/PrlcParser.h"

void print_memory_info(const char* name, const prlc_memory memory);
void print_store_infos(PrlcStoreRef store);

void check_string_store();
void check_parse_puz001();

int main()
{
	printf("Hello World!\n");

	check_string_store ();

	check_parse_puz001 ();
	
	return (0);
}

void check_parse_puz001() {
	

	prlc_parse_path ("/home/amaringele/Downloads/TPTP/Problems/PUZ/PUZ001-1.p");
	PrlcStoreRef store = prlcParsingStore;
	prlc_tree_node* root = prlcParsingRoot;
	
	prlcParsingStore = NULL;
	prlcParsingRoot = NULL;

	const char* name = prlcFirstSymbol (store);
	while (name != NULL) {
		printf("  %s\n ", name);
		name = prlcNextSymbol (store,name);
	}
	
	printf("\n");

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
