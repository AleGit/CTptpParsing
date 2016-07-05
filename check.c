
#include <stdio.h>
#include "CSources/prlc.h"

void print_memory_info(const char* name, const prlc_memory memory);
void print_store_infos(PrlcStoreRef store);

void check_string_store();

int main()
{
	printf("Hello World!\n");

	PrlcStoreRef store = prlcCreateStore(95000);

	prlcDestroyStore(&store);

	check_string_store ();
	return (0);
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
	print_memory_info("symbols", store->symbols);

	prlcDestroyStore(&store);
	printf("=== check_string_store ===\n");
}

/* helpers */

void print_memory_info(const char* name, const prlc_memory memory) {
	printf("%s: %lu.%lu.%lu\n", name, memory.size, memory.unit, memory.capacity);
}

void print_store_sizes(PrlcStoreRef store) {
	print_memory_info("symbols", store->symbols);
}
