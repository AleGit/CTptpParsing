//  Created by Alexander Maringele on 14.03.16.
//  Copyright © 2016 Alexander Maringele. All rights reserved.

#import "PrlcParser.h"
#import <sys/sysctl.h>
#import <pthread.h>

prlc_store* prlcParsingStore = NULL;
prlc_tree_node* prlcParsingRoot = NULL;

int prlc_file_size(FILE *file) {
  int size = 0;
  if (file != NULL) {
    fseek(file,0L, SEEK_END);
    size = ftell(file);
    rewind(file);
  }
  return size;
}

// (unused) print store statistics
void prlc_store_stats(prlc_store *store) {

    if (store->symbols.capacity) printf("symb: %zu/%zu = %zu%% @ %p\n", store->symbols.size, store->symbols.capacity, (5 + store->symbols.size * 1000) / store->symbols.capacity / 10, store->symbols.memory);
    if (store->p_nodes.capacity) printf("prfx: %zu/%zu = %zu%% @ %p\n", store->p_nodes.size, store->p_nodes.capacity, (5 + store->p_nodes.size * 1000) / store->p_nodes.capacity / 10, store->p_nodes.memory);
    if (store->t_nodes.capacity) printf("tree: %zu/%zu = %zu%% @ %p\n", store->t_nodes.size, store->t_nodes.capacity, (5 + store->t_nodes.size * 1000) / store->t_nodes.capacity / 10, store->t_nodes.memory);

    long bytes = store->symbols.capacity * store->symbols.unit + store->p_nodes.capacity * store->p_nodes.unit + store->t_nodes.capacity * store->t_nodes.unit;
    printf("%ld bytes\n",bytes);
}

// (unsused) adjust pointer
void advance(void **p, long amount) {
  if (*p && amount) *p += amount;
}

// (unused) realloc memories and adjusts pointers
prlc_tree_node* prlc_minimize_store(prlc_store *store) {
  prlc_store_stats(store);

  long s_diff = 0, p_diff = 0, t_diff = 0;

  // there is no need to keep the prefix tree
  free(store->p_nodes.memory);
  store->p_nodes.memory = NULL;
  store->p_nodes.size = 0;
  store->p_nodes.capacity = 0;

  /* relocate symbols */


  size_t new_capacity = store->symbols.size;
  char *old_symbols = store->symbols.memory;
  char *new_symbols = realloc(old_symbols, new_capacity);

  if (new_symbols) {
    assert( !strncmp(new_symbols+3,"|",2));

      store->symbols.memory = new_symbols;
      store->symbols.capacity = new_capacity;
      s_diff = new_symbols - old_symbols;
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
  printf("+++ %ld +++ %ld +++\n",t_diff,s_diff);
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
  printf("+++ %s +++\n",((prlc_tree_node*)store->t_nodes.memory)->symbol);
}

  prlc_store_stats(store);
  return store->t_nodes.memory;
}

pthread_mutex_t parsemutex = PTHREAD_MUTEX_INITIALIZER;

int prlcParseFile(const char * const path, prlc_store** store, prlc_tree_node** root) {
  if (path == NULL) {
    fprintf(stderr,"prlc_parse_path(NULL)\n");
    return -1;
  }

  FILE *file = fopen(path,"r");

  int size = prlc_file_size(file);

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

  /* enter critical section */
  pthread_mutex_lock(&parsemutex);

  prlc_in = file;
  prlc_restart(file);
  prlc_lineno = 1;

  prlcParsingStore = prlcCreateStore(size);
  prlcParsingRoot = prlcStoreNodeFile (prlcParsingStore,path);

  int code = prlc_parse ();

  fclose(file);

  *store = prlcParsingStore;
  *root = prlcParsingRoot;

  // it seems as memory optimization is not needed
  // but intruduces small runtime overhead and
  // additional failure possibilites.
  *root = prlc_minimize_store(*store);

  prlcParsingStore = NULL;
  prlcParsingRoot = NULL;


  /* leave critical section */
  pthread_mutex_unlock(&parsemutex);

  return code;
}
