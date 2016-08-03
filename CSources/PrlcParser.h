//  PrlcParser.h
//  Copyright © 2016 Alexander Maringele. All rights reserved.

#ifndef PrlcParser_h
#define PrlcParser_h

#include "PrlcData.h"

#pragma mark - PrlcLexer.l

extern int prlc_lineno;

#if(linux)
extern int prlc_leng;
#else
extern unsigned long prlc_leng;
#endif

extern char * prlc_text;
extern FILE * prlc_in;

void prlc_output(void);

int prlc_lex(void);
void prlc_restart(FILE * file);

#pragma mark - PrlcParser.y

int prlc_parse(void);
int prlc_error (const char * const s);

#pragma mark - parse functions and data structures

int prlcParsePath(const char *  const,
  prlc_store ** ,
  prlc_tree_node ** );

extern prlc_store * prlcParsingStore;
extern prlc_tree_node * prlcParsingRoot;

#endif /* PrlcParser_h */
