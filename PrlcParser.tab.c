/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse prlc_parse
#define yylex   prlc_lex
#define yyerror prlc_error
#define yylval  prlc_lval
#define yychar  prlc_char
#define yydebug prlc_debug
#define yynerrs prlc_nerrs


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




/* Copy the first part of user declarations.  */
#line 10 "CSources/PrlcParser.y"

/* *** C DECLARATIONS *************************************************************************** */

#import "CSources/PrlcMacros.h"
#import "CSources/PrlcParser.h"



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "CSources/PrlcParser.y"
{
    const char* cstring;        // basic to
    prlc_tree_node* node;
}
/* Line 193 of yacc.c.  */
#line 179 "PrlcParser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 192 "PrlcParser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   304

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNRULES -- Number of states.  */
#define YYNSTATES  208

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,     2,     2,     2,    39,     2,
      34,    36,    33,    32,    35,     2,    37,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,     2,
       2,    46,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    38,     2,    43,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    15,    17,
      19,    30,    41,    42,    46,    48,    50,    52,    54,    56,
      58,    60,    64,    66,    68,    72,    76,    80,    84,    86,
      88,    90,    94,   101,   103,   107,   110,   112,   116,   120,
     123,   127,   129,   133,   137,   139,   141,   145,   147,   150,
     152,   156,   158,   160,   162,   164,   166,   168,   170,   172,
     174,   176,   178,   180,   182,   184,   186,   188,   192,   194,
     196,   198,   200,   202,   204,   206,   211,   213,   215,   217,
     219,   221,   223,   225,   227,   232,   234,   236,   238,   243,
     245,   247,   249,   251,   255,   257,   258,   261,   263,   270,
     271,   276,   278,   282,   284,   288,   290,   292,   294,   296,
     298,   300,   302,   307,   312,   317,   322,   325,   329,   331,
     335,   337,   339,   341,   343,   345,   347,   349,   351,   353
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    -1,    49,    -1,    50,    -1,    49,    50,
      -1,    51,    -1,   103,    -1,    52,    -1,    53,    -1,     8,
      34,   112,    35,    55,    35,    56,    54,    36,    37,    -1,
      10,    34,   112,    35,    55,    35,    70,    54,    36,    37,
      -1,    -1,    35,   100,   101,    -1,    27,    -1,    57,    -1,
      67,    -1,    58,    -1,    63,    -1,    59,    -1,    60,    -1,
      63,    75,    63,    -1,    61,    -1,    62,    -1,    63,    38,
      63,    -1,    61,    38,    63,    -1,    63,    39,    63,    -1,
      62,    39,    63,    -1,    64,    -1,    66,    -1,    77,    -1,
      34,    57,    36,    -1,    74,    40,    65,    41,    42,    63,
      -1,    98,    -1,    65,    35,    98,    -1,    76,    63,    -1,
      73,    -1,    68,    22,    68,    -1,    34,    67,    36,    -1,
      40,    41,    -1,    40,    69,    41,    -1,    57,    -1,    69,
      35,    57,    -1,    34,    71,    36,    -1,    71,    -1,    72,
      -1,    71,    38,    72,    -1,    77,    -1,    43,    77,    -1,
      73,    -1,    84,    14,    84,    -1,    44,    -1,    45,    -1,
      16,    -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    43,    -1,    78,    -1,    79,    -1,    83,    -1,
      86,    -1,    80,    -1,    81,    -1,    92,    -1,    84,    82,
      84,    -1,    46,    -1,    95,    -1,    85,    -1,    98,    -1,
      86,    -1,    89,    -1,    87,    -1,    88,    34,    99,    36,
      -1,    88,    -1,   113,    -1,    90,    -1,    91,    -1,   116,
      -1,    24,    -1,    92,    -1,    93,    -1,    94,    34,    99,
      36,    -1,    94,    -1,   114,    -1,    96,    -1,    97,    34,
      99,    36,    -1,    97,    -1,   115,    -1,    28,    -1,    84,
      -1,    99,    35,    84,    -1,   106,    -1,    -1,    35,   102,
      -1,   110,    -1,    11,    34,   117,   104,    36,    37,    -1,
      -1,    35,    40,   105,    41,    -1,   112,    -1,   105,    35,
     112,    -1,   107,    -1,   107,    42,   106,    -1,   110,    -1,
     113,    -1,   108,    -1,    98,    -1,   116,    -1,    24,    -1,
     109,    -1,   113,    34,   111,    36,    -1,     5,    34,    56,
      36,    -1,     7,    34,    70,    36,    -1,     6,    34,    84,
      36,    -1,    40,    41,    -1,    40,   111,    41,    -1,   106,
      -1,   111,    35,   106,    -1,   113,    -1,    29,    -1,    27,
      -1,    23,    -1,    25,    -1,    26,    -1,    29,    -1,    30,
      -1,    31,    -1,    23,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   152,   154,   155,   157,   158,   164,   165,
     177,   181,   185,   186,   191,   209,   210,   212,   213,   215,
     216,   218,   222,   223,   225,   228,   232,   235,   239,   240,
     241,   242,   244,   248,   249,   251,   252,   267,   268,   269,
     270,   271,   272,   278,   279,   280,   281,   282,   283,   284,
     301,   310,   311,   313,   314,   315,   316,   317,   318,   320,
     333,   334,   335,   337,   338,   339,   340,   341,   342,   344,
     347,   348,   351,   352,   354,   355,   356,   357,   359,   360,
     361,   362,   363,   365,   366,   367,   368,   373,   374,   375,
     376,   381,   382,   383,   387,   410,   411,   413,   432,   433,
     434,   435,   436,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     458,   459,   461,   462,   465,   466,   467,   468,   469,   472
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NOT_A_TOKEN", "COMMENT", "DOLLAR_FOF",
  "DOLLAR_FOT", "DOLLAR_CNF", "FOF", "FOT", "CNF", "INCLUDE",
  "DESCRIPTION", "IQUOTE", "INFIX_INEQUALITY", "INFIX_EQUALITY", "IFF",
  "IMPLY", "YLPMI", "NIFF", "NOR", "NAND", "GENTZEN_ARROW",
  "SINGLE_QUOTED", "DISTINCT_OBJECT", "DOLLAR_WORD", "DOLLAR_DOLLAR_WORD",
  "LOWER_WORD", "UPPER_WORD", "INTEGER", "RATIONAL", "REAL", "'+'", "'*'",
  "'('", "','", "')'", "'.'", "'|'", "'&'", "'['", "']'", "':'", "'~'",
  "'!'", "'?'", "'='", "$accept", "TPTP_file", "TPTP_sequence",
  "TPTP_input", "annotated_formula", "fof_annotated", "cnf_annotated",
  "annotations", "formula_role", "fof_formula", "fof_logic_formula",
  "fof_binary_formula", "fof_binary_nonassoc", "fof_binary_assoc",
  "fof_or_formula", "fof_and_formula", "fof_unitary_formula",
  "fof_quantified_formula", "fof_variable_list", "fof_unary_formula",
  "fof_sequent", "fof_tuple", "fof_tuple_list", "cnf_formula",
  "disjunction", "literal", "fol_infix_unary", "fol_quantifier",
  "binary_connective", "unary_connective", "atomic_formula",
  "plain_atomic_formula", "defined_atomic_formula",
  "defined_plain_formula", "defined_infix_formula", "defined_infix_pred",
  "system_atomic_formula", "term", "function_term", "plain_term",
  "constant", "functor", "defined_term", "defined_atom",
  "defined_atomic_term", "defined_plain_term", "defined_constant",
  "defined_functor", "system_term", "system_constant", "system_functor",
  "variable", "arguments", "source", "optional_info", "useful_info",
  "include", "formula_selection", "name_list", "general_term",
  "general_data", "general_function", "formula_data", "general_list",
  "general_terms", "name", "atomic_word", "atomic_defined_word",
  "atomic_system_word", "number", "file_name", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    43,    42,    40,    44,    41,    46,   124,    38,
      91,    93,    58,   126,    33,    63,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    53,    54,    54,    55,    56,    56,    57,    57,    58,
      58,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      63,    63,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    72,    72,    72,
      73,    74,    74,    75,    75,    75,    75,    75,    75,    76,
      77,    77,    77,    78,    79,    79,    80,    81,    82,    83,
      84,    84,    85,    85,    86,    86,    87,    88,    89,    89,
      90,    90,    91,    92,    92,    93,    94,    95,    95,    96,
      97,    98,    99,    99,   100,   101,   101,   102,   103,   104,
     104,   105,   105,   106,   106,   106,   107,   107,   107,   107,
     107,   107,   108,   109,   109,   109,   110,   110,   111,   111,
     112,   112,   113,   113,   114,   115,   116,   116,   116,   117
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     1,     1,
      10,    10,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     3,     3,     3,     3,     1,     1,
       1,     3,     6,     1,     3,     2,     1,     3,     3,     2,
       3,     1,     3,     3,     1,     1,     3,     1,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     4,     1,
       1,     1,     1,     3,     1,     0,     2,     1,     6,     0,
       4,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     2,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,     3,     4,     6,     8,     9,
       7,     0,     0,     0,     1,     5,   123,   122,   121,     0,
     120,     0,   129,    99,     0,     0,     0,     0,    14,     0,
       0,     0,     0,     0,     0,     0,   101,    98,    81,   124,
     125,    91,   126,   127,   128,     0,     0,    59,    51,    52,
      12,    15,    17,    19,    20,    22,    23,    18,    28,    29,
      16,     0,    36,     0,     0,    30,    60,    61,    64,    65,
      62,     0,    70,    63,    74,    76,    73,    78,    79,    66,
      83,    85,    69,    87,    89,    71,    77,    86,    90,    80,
       0,     0,    12,    44,    45,    49,    47,     0,   100,     0,
       0,     0,    39,    41,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,     0,     0,     0,     0,     0,
      35,     0,    68,     0,     0,     0,     0,     0,    48,     0,
       0,     0,   102,    31,    38,     0,    40,     0,     0,     0,
     110,     0,   108,    95,    94,   103,   107,   111,   105,   106,
     109,     0,    25,    27,    24,    26,    21,    37,     0,    33,
      50,    72,    82,    67,    92,     0,     0,     0,    43,     0,
      46,    42,     0,     0,     0,   116,   118,     0,     0,    13,
       0,     0,    10,     0,     0,     0,    75,    84,    88,    11,
       0,     0,     0,     0,   117,    96,    97,   104,     0,    34,
       0,    93,   113,   115,   114,   119,   112,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,   106,    29,    50,
      51,    52,    53,    54,    55,    56,    57,    58,   158,    59,
      60,    61,   104,    92,    93,    94,    62,    63,   117,    64,
      65,    66,    67,    68,    69,   123,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,   165,   143,   179,   195,    10,    27,    35,   176,
     145,   146,   147,   148,   177,    19,    86,    87,    88,    89,
      23
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -103
static const yytype_int16 yypact[] =
{
      62,     0,     1,     3,    45,    62,  -103,  -103,  -103,  -103,
    -103,   -14,   -14,    29,  -103,  -103,  -103,  -103,  -103,    22,
    -103,    46,  -103,    47,    57,    57,    51,    49,  -103,    52,
      60,   -14,    61,   174,   243,   -10,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,   174,   197,  -103,  -103,  -103,
      68,  -103,  -103,  -103,  -103,    77,    85,   102,  -103,  -103,
    -103,   103,  -103,    87,   220,  -103,  -103,  -103,  -103,  -103,
    -103,    -4,  -103,    -2,  -103,    95,  -103,  -103,  -103,     2,
    -103,   100,  -103,  -103,   101,  -103,  -103,  -103,  -103,  -103,
      83,   264,    68,    98,  -103,  -103,  -103,   -14,  -103,   107,
     109,   220,  -103,  -103,    -9,   156,   110,   220,   220,  -103,
    -103,  -103,  -103,  -103,  -103,   220,   220,   220,    97,   119,
    -103,   273,  -103,   273,   273,   273,   273,    15,  -103,    92,
     112,    83,  -103,  -103,  -103,   220,  -103,   117,   118,   124,
    -103,   126,  -103,   125,  -103,   122,  -103,  -103,  -103,   131,
    -103,   134,  -103,  -103,  -103,  -103,  -103,  -103,    -8,  -103,
    -103,  -103,  -103,  -103,  -103,   -18,    26,    39,  -103,   135,
    -103,  -103,   174,   273,   243,  -103,  -103,     8,   128,  -103,
     156,   156,  -103,   119,   132,   273,  -103,  -103,  -103,  -103,
     123,   137,   139,   156,  -103,  -103,  -103,  -103,    41,  -103,
     220,  -103,  -103,  -103,  -103,  -103,  -103,  -103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,  -103,   171,  -103,  -103,  -103,    86,   152,     9,
     -38,  -103,  -103,  -103,  -103,  -103,   -61,  -103,  -103,  -103,
     143,    71,  -103,    16,   104,    64,   -30,  -103,  -103,  -103,
     -32,  -103,  -103,  -103,  -103,  -103,  -103,   -85,  -103,  -102,
    -103,  -103,  -103,  -103,  -103,   -57,  -103,  -103,  -103,  -103,
    -103,   -91,   -47,  -103,  -103,  -103,  -103,  -103,  -103,  -100,
    -103,  -103,  -103,    13,    11,    -1,   -11,  -103,  -103,   -76,
    -103
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -83
static const yytype_int16 yytable[] =
{
      20,    20,    96,   120,    95,   144,   129,    99,   103,    16,
     121,    21,   -72,    17,   142,    18,   -82,   185,   186,   161,
      20,   161,   161,   161,   161,    97,   135,   183,   159,   150,
      36,    98,   136,   184,    11,    12,   160,    13,   163,   164,
     164,   164,   122,   193,   -72,    14,   152,   153,   -82,   194,
     142,   168,    22,   131,   154,   155,   156,    24,    96,   128,
      95,   185,   187,    99,   162,   150,   162,   162,   162,   162,
       1,   161,     2,     3,   185,   188,   193,   206,   166,   167,
     197,    25,    26,   161,    28,    32,    20,    33,   191,   142,
     142,    31,   199,   205,   149,    34,   132,   171,    37,    96,
     201,    95,   142,   105,   150,   150,    16,    38,    39,    40,
      17,    41,    42,    43,    44,   107,   162,   150,   109,   110,
     111,   112,   113,   114,   108,   118,    91,   119,   162,   124,
     149,   137,   138,   139,   125,   126,   131,    46,   122,   207,
     115,   116,    96,   133,    95,   134,   151,    41,   169,    16,
     140,   172,   173,    17,    41,    42,    43,    44,   174,   202,
     178,   137,   138,   139,   180,   181,   141,   175,   141,   149,
     149,   182,   189,   203,   200,   204,    15,    30,   130,    16,
     140,   190,   149,    17,    41,    42,    43,    44,   100,   157,
     192,   196,   198,     0,   127,   170,   141,    16,    38,    39,
      40,    17,    41,    42,    43,    44,     0,     0,    45,     0,
       0,     0,     0,     0,    46,     0,     0,    47,    48,    49,
      16,    38,    39,    40,    17,    41,    42,    43,    44,     0,
       0,   101,     0,     0,     0,     0,     0,     0,   102,     0,
      47,    48,    49,    16,    38,    39,    40,    17,    41,    42,
      43,    44,     0,     0,   101,     0,     0,     0,     0,     0,
       0,     0,     0,    47,    48,    49,    16,    38,    39,    40,
      17,    41,    42,    43,    44,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    16,    38,    39,
      40,    17,    41,    42,    43,    44,    16,    38,    39,     0,
      17,    41,    42,    43,    44
};

static const yytype_int16 yycheck[] =
{
      11,    12,    34,    64,    34,   105,    91,    45,    46,    23,
      14,    12,    14,    27,   105,    29,    14,    35,    36,   121,
      31,   123,   124,   125,   126,    35,    35,    35,   119,   105,
      31,    41,    41,    41,    34,    34,   121,    34,   123,   124,
     125,   126,    46,    35,    46,     0,   107,   108,    46,    41,
     141,    36,    23,    38,   115,   116,   117,    35,    90,    91,
      90,    35,    36,   101,   121,   141,   123,   124,   125,   126,
       8,   173,    10,    11,    35,    36,    35,    36,   125,   126,
     180,    35,    35,   185,    27,    36,    97,    35,   173,   180,
     181,    40,   183,   193,   105,    35,    97,   135,    37,   131,
     185,   131,   193,    35,   180,   181,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    38,   173,   193,    16,    17,
      18,    19,    20,    21,    39,    22,    43,    40,   185,    34,
     141,     5,     6,     7,    34,    34,    38,    40,    46,   200,
      38,    39,   174,    36,   174,    36,    36,    28,    36,    23,
      24,    34,    34,    27,    28,    29,    30,    31,    34,    36,
      35,     5,     6,     7,    42,    34,    40,    41,    40,   180,
     181,    37,    37,    36,    42,    36,     5,    25,    92,    23,
      24,   172,   193,    27,    28,    29,    30,    31,    45,   118,
     174,   178,   181,    -1,    90,   131,    40,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    43,    44,    45,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    44,    45,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    23,    24,    25,    -1,
      27,    28,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    10,    11,    48,    49,    50,    51,    52,    53,
     103,    34,    34,    34,     0,    50,    23,    27,    29,   112,
     113,   112,    23,   117,    35,    35,    35,   104,    27,    55,
      55,    40,    36,    35,    35,   105,   112,    37,    24,    25,
      26,    28,    29,    30,    31,    34,    40,    43,    44,    45,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    66,
      67,    68,    73,    74,    76,    77,    78,    79,    80,    81,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,   113,   114,   115,   116,
      34,    43,    70,    71,    72,    73,    77,    35,    41,    57,
      67,    34,    41,    57,    69,    35,    54,    38,    39,    16,
      17,    18,    19,    20,    21,    38,    39,    75,    22,    40,
      63,    14,    46,    82,    34,    34,    34,    71,    77,    84,
      54,    38,   112,    36,    36,    35,    41,     5,     6,     7,
      24,    40,    98,   100,   106,   107,   108,   109,   110,   113,
     116,    36,    63,    63,    63,    63,    63,    68,    65,    98,
      84,    86,    92,    84,    84,    99,    99,    99,    36,    36,
      72,    57,    34,    34,    34,    41,   106,   111,    35,   101,
      42,    34,    37,    35,    41,    35,    36,    36,    36,    37,
      56,    84,    70,    35,    41,   102,   110,   106,   111,    98,
      42,    84,    36,    36,    36,   106,    36,    63
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 151 "CSources/PrlcParser.y"
    { (yyval.node) = NULLREF; ;}
    break;

  case 4:
#line 154 "CSources/PrlcParser.y"
    { (yyval.node) = TPTP_INPUT((yyvsp[(1) - (1)].node)); ;}
    break;

  case 5:
#line 155 "CSources/PrlcParser.y"
    { (yyval.node) = TPTP_INPUT_APPEND((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); ;}
    break;

  case 10:
#line 177 "CSources/PrlcParser.y"
    {
    (yyval.node)=CREATE_FOF((yyvsp[(3) - (10)].cstring), (yyvsp[(5) - (10)].node), (yyvsp[(7) - (10)].node), (yyvsp[(8) - (10)].node));
;}
    break;

  case 11:
#line 181 "CSources/PrlcParser.y"
    {
    (yyval.node)=CREATE_CNF((yyvsp[(3) - (10)].cstring), (yyvsp[(5) - (10)].node), (yyvsp[(7) - (10)].node), (yyvsp[(8) - (10)].node));
;}
    break;

  case 12:
#line 185 "CSources/PrlcParser.y"
    { (yyval.node) = NULLREF; ;}
    break;

  case 13:
#line 186 "CSources/PrlcParser.y"
    { (yyval.node) = NULLREF; ;}
    break;

  case 14:
#line 191 "CSources/PrlcParser.y"
    { (yyval.node) = MAKE_ROLE((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 15:
#line 209 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 16:
#line 210 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 17:
#line 212 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 18:
#line 213 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 19:
#line 215 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 20:
#line 216 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 21:
#line 218 "CSources/PrlcParser.y"
    {
    (yyval.node) = CREATE_Connective((yyvsp[(2) - (3)].cstring), CREATE_NODES2((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)));
;}
    break;

  case 22:
#line 222 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 23:
#line 223 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 24:
#line 225 "CSources/PrlcParser.y"
    {
    (yyval.node) = CREATE_Connective(_OR_ , CREATE_NODES2((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)));
;}
    break;

  case 25:
#line 228 "CSources/PrlcParser.y"
    {
    (yyval.node) = APPEND((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));
;}
    break;

  case 26:
#line 232 "CSources/PrlcParser.y"
    {
    (yyval.node) = CREATE_Connective(_AND_ , CREATE_NODES2((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)));
;}
    break;

  case 27:
#line 235 "CSources/PrlcParser.y"
    {
    (yyval.node) = APPEND((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));
;}
    break;

  case 28:
#line 239 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 29:
#line 240 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 30:
#line 241 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 31:
#line 242 "CSources/PrlcParser.y"
    { SET_PARENTHESES((yyvsp[(2) - (3)].node)); (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 32:
#line 244 "CSources/PrlcParser.y"
    {
    (yyval.node) = CREATE_Quantified((yyvsp[(1) - (6)].cstring), (yyvsp[(3) - (6)].node), (yyvsp[(6) - (6)].node));
;}
    break;

  case 33:
#line 248 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Variable((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 34:
#line 249 "CSources/PrlcParser.y"
    { (yyval.node) = NODES_APPEND((yyvsp[(1) - (3)].node),CREATE_Variable((yyvsp[(3) - (3)].cstring))); ;}
    break;

  case 35:
#line 251 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Connective(_NOT_, CREATE_NODES1((yyvsp[(2) - (2)].node))); ;}
    break;

  case 36:
#line 252 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 37:
#line 267 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Connective(_GENTZEN_ , CREATE_NODES2((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node))); ;}
    break;

  case 38:
#line 268 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); SET_PARENTHESES((yyval.node)); ;}
    break;

  case 39:
#line 269 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Connective(_COMMA_, CREATE_NODES0()); ;}
    break;

  case 40:
#line 270 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Connective(_COMMA_ , (yyvsp[(2) - (3)].node)); ;}
    break;

  case 41:
#line 271 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_NODES1((yyvsp[(1) - (1)].node)); ;}
    break;

  case 42:
#line 272 "CSources/PrlcParser.y"
    { NODES_APPEND((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); (yyval.node) = (yyvsp[(1) - (3)].node); ;}
    break;

  case 43:
#line 278 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Connective(_OR_ ,(yyvsp[(2) - (3)].node)); SET_PARENTHESES((yyval.node));;}
    break;

  case 44:
#line 279 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Connective(_OR_ ,(yyvsp[(1) - (1)].node)); ;}
    break;

  case 45:
#line 280 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_NODES1((yyvsp[(1) - (1)].node)); ;}
    break;

  case 46:
#line 281 "CSources/PrlcParser.y"
    { NODES_APPEND((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); (yyval.node)=(yyvsp[(1) - (3)].node); ;}
    break;

  case 47:
#line 282 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 48:
#line 283 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Connective(_NOT_, CREATE_NODES1((yyvsp[(2) - (2)].node))); ;}
    break;

  case 49:
#line 284 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 50:
#line 301 "CSources/PrlcParser.y"
    {(yyval.node)=CREATE_Equational(_NEQ_,CREATE_NODES2((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)));;}
    break;

  case 51:
#line 310 "CSources/PrlcParser.y"
    {(yyval.cstring)=_FORALL_;;}
    break;

  case 52:
#line 311 "CSources/PrlcParser.y"
    {(yyval.cstring)=_EXISTS_;;}
    break;

  case 53:
#line 313 "CSources/PrlcParser.y"
    { (yyval.cstring)=_IFF_; ;}
    break;

  case 54:
#line 314 "CSources/PrlcParser.y"
    { (yyval.cstring)=_IMPLY_; ;}
    break;

  case 55:
#line 315 "CSources/PrlcParser.y"
    { (yyval.cstring)=_YLPMI_; ;}
    break;

  case 56:
#line 316 "CSources/PrlcParser.y"
    { (yyval.cstring)=_NIFF_; ;}
    break;

  case 57:
#line 317 "CSources/PrlcParser.y"
    { (yyval.cstring)=_NOR_; ;}
    break;

  case 58:
#line 318 "CSources/PrlcParser.y"
    { (yyval.cstring)=_NAND_; ;}
    break;

  case 59:
#line 320 "CSources/PrlcParser.y"
    { _NOT_; ;}
    break;

  case 60:
#line 333 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 61:
#line 334 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 62:
#line 335 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 63:
#line 337 "CSources/PrlcParser.y"
    { (yyval.node) = PREDICATE((yyvsp[(1) - (1)].node)); ;}
    break;

  case 64:
#line 338 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 65:
#line 339 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 66:
#line 340 "CSources/PrlcParser.y"
    { (yyval.node) = PREDICATE((yyvsp[(1) - (1)].node)); ;}
    break;

  case 67:
#line 341 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Equational((yyvsp[(2) - (3)].cstring), CREATE_NODES2((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node))); ;}
    break;

  case 68:
#line 342 "CSources/PrlcParser.y"
    { (yyval.cstring)=_EQUAL_; ;}
    break;

  case 69:
#line 344 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 70:
#line 347 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 71:
#line 348 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Variable((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 72:
#line 351 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 73:
#line 352 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 74:
#line 354 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Constant((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 75:
#line 355 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Functional((yyvsp[(1) - (4)].cstring), (yyvsp[(3) - (4)].node)); ;}
    break;

  case 76:
#line 356 "CSources/PrlcParser.y"
    { (yyval.cstring) = (yyvsp[(1) - (1)].cstring); ;}
    break;

  case 77:
#line 357 "CSources/PrlcParser.y"
    { (yyval.cstring) = (yyvsp[(1) - (1)].cstring); ;}
    break;

  case 78:
#line 359 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 79:
#line 360 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 80:
#line 361 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Constant((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 81:
#line 362 "CSources/PrlcParser.y"
    { (yyval.node)=CREATE_DISTINCT((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 82:
#line 363 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 83:
#line 365 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Constant((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 84:
#line 366 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Functional((yyvsp[(1) - (4)].cstring), (yyvsp[(3) - (4)].node)); ;}
    break;

  case 85:
#line 367 "CSources/PrlcParser.y"
    { (yyval.cstring) = (yyvsp[(1) - (1)].cstring); ;}
    break;

  case 86:
#line 368 "CSources/PrlcParser.y"
    { (yyval.cstring) = (yyvsp[(1) - (1)].cstring); ;}
    break;

  case 87:
#line 373 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Constant((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 88:
#line 374 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_Functional((yyvsp[(1) - (4)].cstring), (yyvsp[(3) - (4)].node)); ;}
    break;

  case 89:
#line 375 "CSources/PrlcParser.y"
    { (yyval.cstring) = (yyvsp[(1) - (1)].cstring); ;}
    break;

  case 90:
#line 376 "CSources/PrlcParser.y"
    { (yyval.cstring) = (yyvsp[(1) - (1)].cstring); ;}
    break;

  case 91:
#line 381 "CSources/PrlcParser.y"
    { (yyval.cstring) = CREATE_STRING((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 92:
#line 382 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_NODES1((yyvsp[(1) - (1)].node)); ;}
    break;

  case 93:
#line 383 "CSources/PrlcParser.y"
    { NODES_APPEND((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); (yyval.node) = (yyvsp[(1) - (3)].node); ;}
    break;

  case 95:
#line 410 "CSources/PrlcParser.y"
    { (yyval.node) = NULLREF; ;}
    break;

  case 96:
#line 411 "CSources/PrlcParser.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); ;}
    break;

  case 98:
#line 432 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_INCLUDE((yyvsp[(3) - (6)].cstring), (yyvsp[(4) - (6)].node)); ;}
    break;

  case 99:
#line 433 "CSources/PrlcParser.y"
    {(yyval.node)=NULLREF;;}
    break;

  case 100:
#line 434 "CSources/PrlcParser.y"
    { (yyval.node)=(yyvsp[(3) - (4)].node); ;}
    break;

  case 101:
#line 435 "CSources/PrlcParser.y"
    { (yyval.node) = CREATE_STRINGS1((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 102:
#line 436 "CSources/PrlcParser.y"
    { STRINGS_APPEND((yyvsp[(1) - (3)].node),CREATE_STRINGS1((yyvsp[(3) - (3)].cstring))); (yyval.node) = (yyvsp[(1) - (3)].node); ;}
    break;

  case 106:
#line 442 "CSources/PrlcParser.y"
    { (yyval.node)=CREATE_Constant((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 108:
#line 444 "CSources/PrlcParser.y"
    { (yyval.node)=CREATE_Variable((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 109:
#line 445 "CSources/PrlcParser.y"
    { (yyval.node)=CREATE_Constant((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 110:
#line 446 "CSources/PrlcParser.y"
    { (yyval.node)=CREATE_DISTINCT((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 112:
#line 448 "CSources/PrlcParser.y"
    { (yyval.node)=CREATE_Functional((yyvsp[(1) - (4)].cstring), (yyvsp[(3) - (4)].node)); ;}
    break;

  case 113:
#line 449 "CSources/PrlcParser.y"
    { (yyval.node)=CREATE_DFOF((yyvsp[(3) - (4)].node)); ;}
    break;

  case 114:
#line 450 "CSources/PrlcParser.y"
    { (yyval.node)=CREATE_DCNF((yyvsp[(3) - (4)].node)); ;}
    break;

  case 115:
#line 451 "CSources/PrlcParser.y"
    { (yyval.node)=CREATE_FOT((yyvsp[(3) - (4)].node)); ;}
    break;

  case 116:
#line 452 "CSources/PrlcParser.y"
    { (yyval.node)=NULLREF; ;}
    break;

  case 117:
#line 453 "CSources/PrlcParser.y"
    {(yyval.node)=NULLREF;;}
    break;

  case 120:
#line 458 "CSources/PrlcParser.y"
    { (yyval.cstring) = (yyvsp[(1) - (1)].cstring); ;}
    break;

  case 121:
#line 459 "CSources/PrlcParser.y"
    { (yyval.cstring) = CREATE_STRING((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 122:
#line 461 "CSources/PrlcParser.y"
    { (yyval.cstring) = CREATE_STRING((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 123:
#line 462 "CSources/PrlcParser.y"
    { (yyval.cstring) = CREATE_STRING((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 124:
#line 465 "CSources/PrlcParser.y"
    { (yyval.cstring) = CREATE_STRING((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 125:
#line 466 "CSources/PrlcParser.y"
    { (yyval.cstring) = CREATE_STRING((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 126:
#line 467 "CSources/PrlcParser.y"
    { (yyval.cstring) = CREATE_STRING((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 127:
#line 468 "CSources/PrlcParser.y"
    { (yyval.cstring) = CREATE_STRING((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 128:
#line 469 "CSources/PrlcParser.y"
    { (yyval.cstring) = CREATE_STRING((yyvsp[(1) - (1)].cstring)); ;}
    break;

  case 129:
#line 472 "CSources/PrlcParser.y"
    { (yyval.cstring) = CREATE_STRING((yyvsp[(1) - (1)].cstring));;}
    break;


/* Line 1267 of yacc.c.  */
#line 2206 "PrlcParser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 482 "CSources/PrlcParser.y"


/* *** ADDITIONAL C CODE ************************************************************************ */

int yyerror (const char *s)
{
    static const char *format = "\n<%5d> s='%s' yytext='%s' yychar='%d' (tptp)\n";
    printf(format, prlc_lineno, s, prlc_text, yychar);
    //snprintf(globalStringBuffer, MAX_GLOBAL_STRING_BUFFER_SIZE, format, yylineno, s, yytext, yychar);
    return 0;
}

