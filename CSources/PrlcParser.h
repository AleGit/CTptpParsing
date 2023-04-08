//  PrlcParser.h
//  Copyright © 2016 Alexander Maringele. All rights reserved.

#ifndef PrlcParser_h
#define PrlcParser_h

#include "PrlcData.h"

#pragma mark - PrlcLexer.l

extern int prlc_lineno;
extern int prlc_leng;

extern char * prlc_text;
extern FILE * prlc_in;

void prlc_output(void);

int prlc_lex(void);
void prlc_restart(FILE * file);

#pragma mark - PrlcParser.y

int prlc_parse(void);
int prlc_error (const char * const s);

#pragma mark - parse functions and data structures

int prlcParseString(const char * const,
  prlc_store ** ,
  prlc_tree_node **,
  PRLC_TREE_NODE_TYPE,
  const char * const
);

// int prlcParseForm(const char * const,
//   prlc_store ** ,
//   prlc_tree_node ** );

int prlcParsePath(const char * const,
  prlc_store ** ,
  prlc_tree_node ** );

extern prlc_store * prlcParsingStore;
extern prlc_tree_node * prlcParsingRoot;

#endif /* PrlcParser_h */
