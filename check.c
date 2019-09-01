
#include <stdio.h>
#include "CSources/PrlcParser.h"

int prlc_parse_path (const char*);
int file_size(FILE*);

void print_shelf_info(const char*, const prlc_shelf);
void print_store_infos(prlc_store*);
void print_store_symbols(prlc_store*, prlc_tree_node*);

void check_memory();
void check_string_store();
int check_parse_file(const char *);
int check_parse_string(const char * const, PRLC_TREE_NODE_TYPE);

const char* puz001="PUZ001-1.p";
int maxCount = 0;

int check_parse_string(const char * const string, PRLC_TREE_NODE_TYPE type) {

	prlc_store* store = NULL;
	prlc_tree_node* root = NULL;

	int result = prlcParseString (string, &store, &root, type);

	printf("parseString(%s, %d)\n",string,type);
	// print_store_infos (store);
	// print_store_symbols (store, root);

	prlcDestroyStore(store);

	return result;
}

void test(int expected, int actual) {
	if (expected != actual) {
		printf("🛑 \t(%d, %d)\n", expected, actual);
	}
	else {
		printf("✅ \t(%d)\n", actual);
	}
}

int main(int argc, char *argv[])
{
	if (argc > 2) {
		maxCount = atoi(argv[2]);
	}
	printf("maxCount = %ld\n", maxCount);

	if (argc > 1) {
		test(0, check_parse_file (argv[1]));
	}
	else {
		test(0, check_parse_file (puz001));

	}

	test(0, check_parse_string("X", PRLC_VARIABLE));
	test(0, check_parse_string("a", PRLC_FUNCTION));
	test(0, check_parse_string("f(X,a)", PRLC_FUNCTION));
	test(0, check_parse_string("p(f(X,a))", PRLC_PREDICATE));

	test(0, check_parse_string("a=X", PRLC_EQUATIONAL));
	test(0, check_parse_string("a=X", PRLC_CNF));
	test(0, check_parse_string("a=X|p(f(X,a))", PRLC_CNF));
	test(0, check_parse_string("a=X&p(f(X,a))", PRLC_FOF));

	test(1, check_parse_string("a=X&p(f(X,a))", PRLC_CNF));
	test(0, check_parse_string("a=X|p(f(X,a))", PRLC_FOF));

	test(0, check_parse_string("'Axioms/PUZ001.ax'", PRLC_INCLUDE));
	test(0, check_parse_string("cnf(hi,axiom,b=Y).", PRLC_FILE));





	return (0);
}

void check_memory() {
	// 276455091, /home/amaringele/Downloads/TPTP/Problems/HWV/HWV134-1.p
	long size = 276455091/4;
	while (size < 27645509100) {

		printf("%ld\n",size);

		prlc_store* store = prlcCreateStore(size);

		print_store_infos (store);

		prlcDestroyStore(store);
		size *= 2;
	}
}

void print_store_symbols(prlc_store* store, prlc_tree_node* root) {
	int count = 0;
	size_t len = 0;
	const char* name = prlcFirstSymbol (store);
	while (name != NULL && count < maxCount) {
		len += strlen(name) + 3;

		if (len > 99 || name == root->symbol) {
			printf("\n");
			len = strlen(name) + 3;
		}

		printf("»%s« ", name);

		name = prlcNextSymbol (store, name);
		count += 1;
	}

	printf("¤\n");
}




int check_parse_file(const char *path) {
	printf("%s\n",path);

	prlc_store* store = NULL;
	prlc_tree_node* root = NULL;

	int result = prlcParsePath (path, &store, &root);

	print_store_infos (store);
	print_store_symbols (store, root);

	prlcDestroyStore(store);

	return result;

}

void check_string_store() {
	printf("*** check_string_store ***\n");
	prlc_store* store = prlcCreateStore(95000);

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

	prlcDestroyStore(store);
	printf("=== check_string_store ===\n");
}

/* helpers */

void print_shelf_info(const char* name, const prlc_shelf shelf) {
	int promille = (1000 * shelf.size) / shelf.capacity + 5;

	printf("%s: %lu.%lu.%lu (%d %% of %lu bytes)\n", name, shelf.size, shelf.unit, shelf.capacity, promille/10, shelf.capacity*shelf.unit);
}

void print_store_infos(prlc_store* store) {
	if (store->symbols.capacity) print_shelf_info("symbols", store->symbols);
	if (store->p_nodes.capacity) print_shelf_info("p_nodes", store->p_nodes);
	if (store->t_nodes.capacity) print_shelf_info("t_nodes", store->t_nodes);
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
