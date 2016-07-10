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

extern char * _Nullable prlc_text;
extern FILE * _Nullable prlc_in;

void prlc_output(void);

int prlc_lex(void);
void prlc_restart(FILE * _Nullable file);

#pragma mark - PrlcParser.y

int prlc_parse(void);
int prlc_error (const char * _Nullable const s);

#pragma mark - parse functions and data structures

int prlcParseFile(const char *_Nonnull const,
  prlc_store * _Nullable * _Nonnull,
  prlc_tree_node * _Nullable * _Nonnull);

extern prlc_store* _Nullable prlcParsingStore;
extern prlc_tree_node* _Nullable prlcParsingRoot;

#endif /* PrlcParser_h */
