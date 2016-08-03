//  Created by Alexander Maringele on 14.03.16.
//  Copyright © 2016 Alexander Maringele. All rights reserved.


#import <sys/sysctl.h>
#import <pthread.h>
#import "PrlcParser.h"
#import "PrlcData.h"

prlc_store* prlcParsingStore = NULL;
prlc_tree_node* prlcParsingRoot = NULL;

pthread_mutex_t parsemutex = PTHREAD_MUTEX_INITIALIZER;

int prlcParsePath(const char * const path, prlc_store** store, prlc_tree_node** root) {
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

  *root = prlcSetStoreReadOnly(*store);

  prlcParsingStore = NULL;
  prlcParsingRoot = NULL;


  /* leave critical section */
  pthread_mutex_unlock(&parsemutex);

  return code;
}
