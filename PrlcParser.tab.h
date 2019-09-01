/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NOT_A_TOKEN = 258,
     COMMENT = 259,
     DOLLAR_FOF = 260,
     DOLLAR_FOT = 261,
     DOLLAR_CNF = 262,
     FOF = 263,
     FOT = 264,
     CNF = 265,
     INCLUDE = 266,
     DESCRIPTION = 267,
     IQUOTE = 268,
     INFIX_INEQUALITY = 269,
     INFIX_EQUALITY = 270,
     IFF = 271,
     IMPLY = 272,
     YLPMI = 273,
     NIFF = 274,
     NOR = 275,
     NAND = 276,
     GENTZEN_ARROW = 277,
     SINGLE_QUOTED = 278,
     DISTINCT_OBJECT = 279,
     DOLLAR_WORD = 280,
     DOLLAR_DOLLAR_WORD = 281,
     LOWER_WORD = 282,
     UPPER_WORD = 283,
     INTEGER = 284,
     RATIONAL = 285,
     REAL = 286
   };
#endif
/* Tokens.  */
#define NOT_A_TOKEN 258
#define COMMENT 259
#define DOLLAR_FOF 260
#define DOLLAR_FOT 261
#define DOLLAR_CNF 262
#define FOF 263
#define FOT 264
#define CNF 265
#define INCLUDE 266
#define DESCRIPTION 267
#define IQUOTE 268
#define INFIX_INEQUALITY 269
#define INFIX_EQUALITY 270
#define IFF 271
#define IMPLY 272
#define YLPMI 273
#define NIFF 274
#define NOR 275
#define NAND 276
#define GENTZEN_ARROW 277
#define SINGLE_QUOTED 278
#define DISTINCT_OBJECT 279
#define DOLLAR_WORD 280
#define DOLLAR_DOLLAR_WORD 281
#define LOWER_WORD 282
#define UPPER_WORD 283
#define INTEGER 284
#define RATIONAL 285
#define REAL 286




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "CSources/PrlcParser.y"
{
    const char* cstring;        // basic to
    prlc_tree_node* node;
}
/* Line 1529 of yacc.c.  */
#line 116 "PrlcParser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE prlc_lval;

