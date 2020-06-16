//  Copyright © 2016 Alexander Maringele. All rights reserved.

#include "PrlcData.h"

#define prlc_min(a,b) ((a < b) ? a : b)
#define prlc_max(a,b) ((a > b) ? a : b)

#pragma mark - allocate and free store

/// Alloc memory block with capacity*unit bytes.
/// The shelf can hold 'capacity' entries of size 'unit'.
void prlc_alloc_memory(prlc_shelf* shelf, size_t capacity, size_t unit) {
    shelf->memory = calloc(capacity,unit);
    shelf->capacity = capacity;
    shelf->unit = unit;
    shelf->size = 0;
}

/// Store syntactically predefined symbols
/// so that they appear in front.
void prlc_copy_predefined_symbols(prlc_store *store) {
  assert(store != NULL);

    prlcStoreSymbol(store, "");     // empty string

    prlcStoreSymbol(store, "~");    // not
    prlcStoreSymbol(store, "|");    // or
    prlcStoreSymbol(store, "&");    // and

    prlcStoreSymbol(store, "-->");  // gentzen
    prlcStoreSymbol(store, ",");    // comma

    prlcStoreSymbol(store, "<=>");  // iff
    prlcStoreSymbol(store, "=>");   // imply
    prlcStoreSymbol(store, "<=");   // ylpmi

    prlcStoreSymbol(store, "<~>");  // niff ~ xor
    prlcStoreSymbol(store, "~|");   // nor
    prlcStoreSymbol(store, "~&");   // nand

    prlcStoreSymbol(store, "!");    // forall
    prlcStoreSymbol(store, "?");    // exists

    prlcStoreSymbol(store, "=");    // equals
    prlcStoreSymbol(store, "!=");   // not equal

}

prlc_store* prlcCreateStore(size_t fileSize) {
  prlc_store* store = calloc(1,sizeof(prlc_store));
  assert(store);

  fileSize = prlc_max(fileSize, 1024*16);

	//	    hwv134   276455091
	size_t maxBytes = 12000000000; // manually derived on Linux

	size_t sCapacity = prlc_min(fileSize/3, 1 + maxBytes / sizeof(char));
	size_t pCapacity = prlc_min(fileSize, 1 + maxBytes / sizeof(prlc_prefix_node));
	size_t tCapacity = prlc_min(fileSize/3, 1 + maxBytes / sizeof(prlc_tree_node));

  prlc_alloc_memory(&(store->symbols), sCapacity, sizeof(char));
  assert(store->symbols.memory);

  prlc_alloc_memory(&(store->p_nodes), pCapacity, sizeof(prlc_prefix_node));
  assert(store->p_nodes.memory);

  prlc_alloc_memory(&(store->t_nodes), tCapacity, sizeof(prlc_tree_node));
  assert(store->t_nodes.memory);

  prlc_copy_predefined_symbols(store);

  return store;
}

void prlcDestroyStore(prlc_store* store) {

    if (!store) return;

    if (store->symbols.memory) free(store->symbols.memory);
    if (store->p_nodes.memory) free(store->p_nodes.memory);
    if (store->t_nodes.memory) free(store->t_nodes.memory);

    free(store);
}

#pragma mark -

prlc_prefix_node* prlc_prefix_node_new(prlc_store* store) {
    assert(store->p_nodes.size < store->p_nodes.capacity);

    prlc_prefix_node* base = store->p_nodes.memory;
    prlc_prefix_node* p_node = base + store->p_nodes.size;
    store->p_nodes.size += 1;

    return p_node;
}

prlc_prefix_node* prlc_prefix_path_step(prlc_store* store, prlc_prefix_node* p_node, const char* const symbol) {

    assert(symbol != NULL);

    if (strlen(symbol) == 0) return p_node;

    int cidx = symbol[0];
    if (cidx < 0) cidx += 256;

    // printf("%d %c %s\n", cidx, cidx, symbol);

    prlc_prefix_node* next_node = p_node->nexts[cidx];

    if (next_node == NULL) {
        next_node = prlc_prefix_node_new(store);
        p_node->nexts[cidx] = next_node;
    }

    return prlc_prefix_path_step(store, next_node, symbol+1);

}

prlc_prefix_node* prlc_prefix_path_build(prlc_store* store, const char* const symbol) {
    prlc_prefix_node *p_node = NULL;
    if (store->p_nodes.size == 0) {
        p_node = prlc_prefix_node_new(store);
    }
    else {
        p_node = store->p_nodes.memory;
    }

    p_node = prlc_prefix_path_step(store, p_node, symbol);

    return p_node;
}

const char* const prlc_copy_symbol(prlc_store* store, const char* const symbol) {

    size_t len = strlen(symbol);

    assert(store->symbols.size + len < store->symbols.capacity);

    char *base = store->symbols.memory;
    char *copy = strcpy(base + store->symbols.size, symbol);

    assert(strlen(copy) == len);
    assert(*(copy+len) == '\0');

    store->symbols.size += strlen(symbol) + 1;

    assert(store->symbols.size <= store->symbols.capacity);

    return copy;

}

const char* const prlcStoreSymbol(prlc_store* store, const char* const symbol) {
    prlc_prefix_node *p_node = prlc_prefix_path_build(store, symbol);

    if (p_node->symbol == NULL) {
        p_node->symbol = prlc_copy_symbol(store, symbol);
    }

    return p_node->symbol;
}

prlc_prefix_node* prlc_prefix_path_follow(prlc_store* store, const char* const symbol) {
    prlc_prefix_node *p_node = NULL;
    size_t len = strlen(symbol);
    size_t pos = 0;

    if (store->p_nodes.size > 0) {
        p_node = store->p_nodes.memory;
    }

    while (p_node != NULL && pos < len) {
        int c = *(symbol+pos);
        if (c < 0) c += 256;
        p_node = p_node->nexts[c];
        pos += 1;
    }

    return p_node;
}

const char* const prlcGetSymbol(prlc_store* store, const char* symbol) {
  if (store == NULL) return NULL;
  if (symbol == NULL) return NULL;
    prlc_prefix_node *p_node = prlc_prefix_path_follow(store, symbol);

    return p_node ? p_node->symbol : NULL;


}

const char* const prlcFirstSymbol(prlc_store *store) {
    if (store->symbols.size == 0) return NULL;
    else {
        return store->symbols.memory;
    }
}


const char* const prlcNextSymbol(prlc_store* store, const char* const symbol) {
    char *base = store->symbols.memory;

    assert (symbol - base < store->symbols.size);

    const char *next = symbol + strlen(symbol)+1;

    if ( next - base < store->symbols.size) return next;
    else return NULL;
}

#pragma mark - tree nodes

prlc_tree_node* prlc_tree_node_new(prlc_store* store) {
    assert(store != NULL);
    assert(store->t_nodes.memory != NULL);
    assert(store->t_nodes.size < store->t_nodes.capacity);

    prlc_tree_node *base = store->t_nodes.memory;
    prlc_tree_node *node = base + store->t_nodes.size;
    store->t_nodes.size += 1;

    return node;
}

prlc_tree_node* prlc_tree_node_save(prlc_store *store,
  PRLC_TREE_NODE_TYPE type,
  const char* const symbol,
  prlc_tree_node *child) {
    prlc_tree_node* t_node = prlc_tree_node_new(store);

    t_node->type = type;
    t_node->symbol = prlcStoreSymbol(store, symbol);
    t_node->sibling = NULL;
    t_node->lastSibling = NULL;
    t_node->child = child;

    return t_node;
}

prlc_tree_node* prlcStoreNodeFile(prlc_store* store, const char* const name) {
    return prlc_tree_node_save(store, PRLC_FILE, name, NULL);
}

prlc_tree_node* prlcStoreNodeAnnotated(prlc_store* store, PRLC_TREE_NODE_TYPE type, const char* const name, prlc_tree_node* role, prlc_tree_node* formula, prlc_tree_node* annotations) {

    assert(type == PRLC_CNF || type == PRLC_FOF);
    assert(role != NULL);
    assert(formula != NULL);

    prlc_tree_node* first = prlcNodeAppendNode(role,formula);
    if (annotations!=NULL) prlcNodeAppendNode(first,annotations);

    return prlc_tree_node_save(store, type, name, first);
}

prlc_tree_node* prlcStoreNodeInclude(prlc_store* store, const char* const file, prlc_tree_node* selection) {
    return prlc_tree_node_save(store, PRLC_INCLUDE, file, selection);
}

prlc_tree_node* prlcStoreNodeRole(prlc_store* store, const char* const name) {
    return prlc_tree_node_save(store, PRLC_ROLE, name, NULL);
}

prlc_tree_node* prlcStoreNodeConnective(prlc_store* store, const char* const symbol, prlc_tree_node* firstChild) {
    return prlc_tree_node_save(store, PRLC_CONNECTIVE, symbol, firstChild);
}


prlc_tree_node* prlcStoreNodeQuantified(prlc_store* store, const char* const quantifier, prlc_tree_node* variables, prlc_tree_node* formula) {
    prlc_tree_node* first_child = prlcNodeAppendNode(variables, formula);
    return prlc_tree_node_save(store, PRLC_QUANTIFIER, quantifier, first_child);
}

prlc_tree_node* prlcStoreNodeFunctional(prlc_store* store, const char* const symbol, prlc_tree_node* firstChild) {
    return prlc_tree_node_save(store, PRLC_FUNCTION, symbol, firstChild);
}
prlc_tree_node* prlcStoreNodeEquational(prlc_store* store, const char* const symbol, prlc_tree_node* firstChild) {
    return prlc_tree_node_save(store, PRLC_EQUATIONAL, symbol, firstChild);
}
prlc_tree_node* prlcStoreNodeConstant(prlc_store* store, const char* const symbol) {
    return prlc_tree_node_save(store, PRLC_FUNCTION, symbol, NULL);
}
prlc_tree_node* prlcStoreNodeVariable(prlc_store* store, const char* const symbol) {
    return prlc_tree_node_save(store, PRLC_VARIABLE, symbol, NULL);
}

prlc_tree_node* prlcStoreNodeName(prlc_store* store, const char* const name) {
    return prlc_tree_node_save(store, PRLC_NAME, name, NULL);
}

prlc_tree_node* prlcSetPredicate(prlc_tree_node *t_node) {

    if (t_node->type == PRLC_FUNCTION) t_node->type = PRLC_PREDICATE;

    assert(t_node->type == PRLC_PREDICATE);

    return t_node;
}

prlc_tree_node *prlcNodeAppendNode(prlc_tree_node *first, prlc_tree_node *last) {
    assert(first != NULL);
    assert(last != NULL);
    if (first->lastSibling != NULL) {
        // shortcut from first to last element of list
        prlcNodeAppendNode(first->lastSibling, last);
        first->lastSibling = last;
        // NOTE: lastSibling == sibling for intermediate nodes
    }
    else if (first->sibling == NULL) {
        // the first is the last element
        first->sibling = last;
        first->lastSibling = last;
    }
    else {
        // follow the path
        prlcNodeAppendNode(first->sibling, last);
    }
    return first;
}

prlc_tree_node *prlcNodeAppendChild(prlc_tree_node* parent, prlc_tree_node *last) {
    assert(parent != NULL);
    assert(last != NULL);

    if (parent->child == NULL) {
        // parent was childless so far
        parent->child = last;
    }
    else {
        prlcNodeAppendNode(parent->child, last);
    }
    return parent;
}


void prlcNodeSetChild(prlc_tree_node* parent, prlc_tree_node* child) {
    assert(false);

    assert(parent != NULL);
    assert(parent->child == NULL);
    assert(child != NULL);

    parent->child = child;
}

void* prlcLabel(const char* const label) {
    // printf("\t*** %s ***\n",label);
    return NULL;
}

prlc_tree_node* prlcFirstTreeNode(prlc_store* store) {
    assert(0 < store->t_nodes.size);
    return store->t_nodes.memory;
}

prlc_tree_node * prlcNextTreeNode(prlc_store* store, prlc_tree_node* node) {
  assert(store != NULL);
  assert(node != NULL);

  size_t index = node - prlcFirstTreeNode(store);
  return prlcTreeNodeAtIndex(store, index+1);
}

prlc_tree_node* prlcTreeNodeAtIndex(prlc_store* store, size_t index) {
    if (index < store->t_nodes.size) {
        return prlcFirstTreeNode(store) + index;
    }
    else {
        return NULL;
    }
}

// MARK: - optimize store
int prlc_file_size(FILE *file) {
  int size = 0;
  if (file != NULL) {
    fseek(file,0L, SEEK_END);
    size = ftell(file);
    rewind(file);
  }
  return size;
}

// print store statistics
void prlc_store_stats(prlc_store *store) {

    if (store->symbols.capacity) printf("symb: %zu/%zu = %zu%% @ %p\n", store->symbols.size, store->symbols.capacity, (5 + store->symbols.size * 1000) / store->symbols.capacity / 10, store->symbols.memory);
    if (store->p_nodes.capacity) printf("prfx: %zu/%zu = %zu%% @ %p\n", store->p_nodes.size, store->p_nodes.capacity, (5 + store->p_nodes.size * 1000) / store->p_nodes.capacity / 10, store->p_nodes.memory);
    if (store->t_nodes.capacity) printf("tree: %zu/%zu = %zu%% @ %p\n", store->t_nodes.size, store->t_nodes.capacity, (5 + store->t_nodes.size * 1000) / store->t_nodes.capacity / 10, store->t_nodes.memory);

    long bytes = store->symbols.capacity * store->symbols.unit + store->p_nodes.capacity * store->p_nodes.unit + store->t_nodes.capacity * store->t_nodes.unit;
    printf("%ld bytes\n",bytes);
}

// adjust pointer
void advance(void **p, long amount) {
  if (*p && amount) *p += amount;
}

// realloc memories and adjusts pointers
prlc_tree_node* prlcSetStoreReadOnly(prlc_store *store) {
  prlc_store_stats(store);

  long s_diff = 0, p_diff = 0, t_diff = 0;

  // there is no need to keep the prefix tree for a read only store
  free(store->p_nodes.memory);
  store->p_nodes.memory = NULL;
  store->p_nodes.size = 0;
  store->p_nodes.capacity = 0;

  /* relocate symbols */

  size_t new_capacity = store->symbols.size;
  char *old_symbols = store->symbols.memory;
  char *new_symbols = realloc(old_symbols, new_capacity);

  assert(new_symbols);

  if (new_symbols) {
    assert( !strncmp(new_symbols+3,"|",2));
    store->symbols.memory = new_symbols;
    store->symbols.capacity = new_capacity;
    s_diff = new_symbols - old_symbols;
  }
  else {
    fprintf(stderr, "ERROR: store->symbols resizing failed.");
  }

  /* relocate syntax tree */

  void *old_tree = store->t_nodes.memory;
  void *new_tree = realloc(old_tree, store->t_nodes.unit * store->t_nodes.size);
  if (new_tree) {
    store->t_nodes.memory = new_tree;
    store->t_nodes.capacity = store->t_nodes.size;
    t_diff = new_tree - old_tree;
  }

  if (t_diff || s_diff) {
    // printf("+++ %ld +++ %ld +++\n",t_diff,s_diff);
    int i = 0;
    prlc_tree_node *t_node = store->t_nodes.memory;
    while (i < store->t_nodes.size) {
      advance((void**)&(t_node->symbol),s_diff);
      advance((void**)&(t_node->sibling),t_diff);
      advance((void**)&(t_node->lastSibling),t_diff);
      advance((void**)&(t_node->child),t_diff);
      t_node += 1;
      i += 1;
    }
    // printf("+++ %s +++\n",((prlc_tree_node*)store->t_nodes.memory)->symbol);
  }

  prlc_store_stats(store);
  return store->t_nodes.memory;
}
