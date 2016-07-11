//  Created by Alexander Maringele on 14.03.16.
//  Copyright © 2016 Alexander Maringele. All rights reserved.

#import "PrlcParser.h"
#import <sys/sysctl.h>

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

    prlc_in = file;
    prlc_restart(file);
    prlc_lineno = 1;

    prlcParsingStore = prlcCreateStore(size);
    prlcParsingRoot = prlcStoreNodeFile (prlcParsingStore,path);

    int code = prlc_parse ();

    fclose(file);

    *store = prlcParsingStore;
    *root = prlcParsingRoot;

    prlcParsingStore = NULL;
    prlcParsingRoot = NULL;

    return code;



  }
