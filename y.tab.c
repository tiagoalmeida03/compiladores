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



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CHAR = 258,
     IF = 259,
     ELSE = 260,
     WHILE = 261,
     INT = 262,
     SHORT = 263,
     DOUBLE = 264,
     RETURN = 265,
     VOID = 266,
     RESERVED = 267,
     BITWISEAND = 268,
     BITWISEOR = 269,
     BITWISEXOR = 270,
     AND = 271,
     ASSIGN = 272,
     MUL = 273,
     COMMA = 274,
     DIV = 275,
     EQ = 276,
     GE = 277,
     GT = 278,
     LBRACE = 279,
     LE = 280,
     LPAR = 281,
     LT = 282,
     MINUS = 283,
     MOD = 284,
     NE = 285,
     NOT = 286,
     OR = 287,
     PLUS = 288,
     RBRACE = 289,
     RPAR = 290,
     SEMI = 291,
     IDENTIFIER = 292,
     CHRLIT = 293,
     DECIMAL = 294,
     NATURAL = 295,
     LOW = 296
   };
#endif
/* Tokens.  */
#define CHAR 258
#define IF 259
#define ELSE 260
#define WHILE 261
#define INT 262
#define SHORT 263
#define DOUBLE 264
#define RETURN 265
#define VOID 266
#define RESERVED 267
#define BITWISEAND 268
#define BITWISEOR 269
#define BITWISEXOR 270
#define AND 271
#define ASSIGN 272
#define MUL 273
#define COMMA 274
#define DIV 275
#define EQ 276
#define GE 277
#define GT 278
#define LBRACE 279
#define LE 280
#define LPAR 281
#define LT 282
#define MINUS 283
#define MOD 284
#define NE 285
#define NOT 286
#define OR 287
#define PLUS 288
#define RBRACE 289
#define RPAR 290
#define SEMI 291
#define IDENTIFIER 292
#define CHRLIT 293
#define DECIMAL 294
#define NATURAL 295
#define LOW 296




/* Copy the first part of user declarations.  */
#line 5 "uccompiler.y"

#include "ast.h"
#include <stdlib.h> 

int yylex(void);
void yyerror(char *);

struct node *program;
struct node *kind;
struct node_list *aux;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
#line 17 "uccompiler.y"
{ 
    char *lexeme;
    struct node *node;
}
/* Line 193 of yacc.c.  */
#line 195 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 208 "y.tab.c"

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
#define YYLAST   430

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    16,    18,    20,
      22,    24,    26,    28,    30,    34,    38,    41,    44,    47,
      49,    51,    55,    60,    64,    66,    69,    71,    75,    78,
      82,    84,    86,    90,    93,    95,    97,   100,   103,   107,
     113,   121,   127,   131,   134,   136,   140,   143,   147,   149,
     153,   155,   159,   163,   167,   171,   175,   179,   183,   187,
     191,   195,   199,   203,   207,   211,   215,   219,   223,   227,
     230,   233,   236,   241,   245,   247,   249,   251,   253,   258
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,    -1,    44,    46,    -1,    44,    49,
      -1,    44,    53,    -1,    46,    -1,    49,    -1,    53,    -1,
       3,    -1,     7,    -1,     9,    -1,    11,    -1,     8,    -1,
      45,    50,    47,    -1,    24,    48,    34,    -1,    24,    34,
      -1,    48,    53,    -1,    48,    58,    -1,    53,    -1,    58,
      -1,    45,    50,    36,    -1,    37,    26,    51,    35,    -1,
      51,    19,    52,    -1,    52,    -1,    45,    37,    -1,    45,
      -1,    45,    54,    36,    -1,     1,    36,    -1,    54,    19,
      55,    -1,    55,    -1,    37,    -1,    37,    17,    59,    -1,
      56,    57,    -1,    57,    -1,    58,    -1,     1,    36,    -1,
      59,    36,    -1,    24,    56,    34,    -1,     4,    26,    59,
      35,    58,    -1,     4,    26,    59,    35,    58,     5,    58,
      -1,     6,    26,    59,    35,    58,    -1,    10,    59,    36,
      -1,    10,    36,    -1,    36,    -1,    24,     1,    34,    -1,
      24,    34,    -1,    59,    19,    61,    -1,    61,    -1,    60,
      19,    61,    -1,    61,    -1,    61,    32,    61,    -1,    61,
      16,    61,    -1,    61,    14,    61,    -1,    61,    15,    61,
      -1,    61,    13,    61,    -1,    61,    21,    61,    -1,    61,
      30,    61,    -1,    61,    23,    61,    -1,    61,    22,    61,
      -1,    61,    27,    61,    -1,    61,    25,    61,    -1,    61,
      17,    61,    -1,    61,    18,    61,    -1,    61,    29,    61,
      -1,    61,    20,    61,    -1,    61,    33,    61,    -1,    61,
      28,    61,    -1,    37,    26,    35,    -1,    28,    61,    -1,
      33,    61,    -1,    31,    61,    -1,    37,    26,    60,    35,
      -1,    26,    59,    35,    -1,    37,    -1,    38,    -1,    39,
      -1,    40,    -1,    37,    26,     1,    35,    -1,    26,     1,
      35,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    76,    77,    78,    79,    81,    83,    88,
      89,    90,    91,    92,    96,   103,   104,   108,   109,   110,
     111,   115,   121,   127,   128,   132,   135,   140,   141,   145,
     146,   150,   154,   162,   163,   166,   167,   171,   172,   173,
     178,   184,   188,   190,   192,   193,   194,   198,   199,   204,
     205,   209,   212,   215,   218,   221,   224,   227,   230,   233,
     236,   239,   242,   245,   248,   251,   254,   257,   260,   262,
     264,   266,   268,   271,   272,   273,   274,   275,   276,   277
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "IF", "ELSE", "WHILE", "INT",
  "SHORT", "DOUBLE", "RETURN", "VOID", "RESERVED", "BITWISEAND",
  "BITWISEOR", "BITWISEXOR", "AND", "ASSIGN", "MUL", "COMMA", "DIV", "EQ",
  "GE", "GT", "LBRACE", "LE", "LPAR", "LT", "MINUS", "MOD", "NE", "NOT",
  "OR", "PLUS", "RBRACE", "RPAR", "SEMI", "IDENTIFIER", "CHRLIT",
  "DECIMAL", "NATURAL", "LOW", "$accept", "Program",
  "FunctionsAndDeclarations", "TypeSpec", "FunctionsDefinition",
  "FunctionsBody", "DeclarationsAndStatements", "FunctionsDeclaration",
  "FunctionsDeclarator", "ParamList", "ParamDeclaration", "Declaration",
  "DeclaratorList", "Declarator", "StatementList", "StatementError",
  "Statement", "ExprList", "ExprCall", "Expr", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    44,    44,    44,    45,
      45,    45,    45,    45,    46,    47,    47,    48,    48,    48,
      48,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    59,    59,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     2,     2,     2,     1,
       1,     3,     4,     3,     1,     2,     1,     3,     2,     3,
       1,     1,     3,     2,     1,     1,     2,     2,     3,     5,
       7,     5,     3,     2,     1,     3,     2,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     4,     3,     1,     1,     1,     1,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     9,    10,    13,    11,    12,     0,     0,     0,
       6,     7,     8,    28,     1,     3,     4,     5,    31,     0,
       0,    30,     0,     0,     0,    21,    14,     0,    27,     0,
       0,     0,     0,    74,    75,    76,    77,    32,    48,    26,
       0,    24,     0,     0,     0,     0,    16,    44,     0,     0,
      19,    20,     0,    31,    29,     0,     0,    69,    71,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
       0,    22,     0,     0,    43,     0,     0,    46,     0,    34,
      35,    15,    17,    18,    37,    79,    73,     0,    68,     0,
      50,    47,    55,    53,    54,    52,    62,    63,    65,    56,
      59,    58,    61,    60,    67,    64,    57,    51,    66,    23,
       0,     0,    42,    45,    36,     0,    38,    33,    78,     0,
      72,     0,     0,    49,    39,    41,     0,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    26,    49,    11,    19,    40,
      41,    12,    20,    21,    88,    89,    90,    52,    99,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -30
static const yytype_int16 yypact[] =
{
      49,   -27,   -30,   -30,   -30,   -30,   -30,    16,   419,    18,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,    64,   -16,
     -14,   -30,   378,   179,    65,   -30,   -30,    22,   -30,   198,
     378,   378,   378,    -7,   -30,   -30,   -30,   -30,   252,    33,
      -5,   -30,    54,    56,   363,   127,   -30,   -30,    22,   110,
     -30,   -30,   -13,     1,   -30,    48,    32,   -30,   -30,   -30,
     182,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   -30,
     179,   -30,   378,   378,   -30,   -12,   -19,   -30,   167,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,    50,   -30,    42,
     252,   252,   345,   313,   331,   294,   252,   -30,   -30,   359,
     152,   152,   152,   152,    -8,   -30,   359,   273,    -8,   -30,
      43,    44,   -30,   -30,   -30,    51,   -30,   -30,   -30,   378,
     -30,   224,   224,   252,    81,   -30,   224,   -30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,   -30,     4,    80,   -30,   -30,    84,   -30,   -30,
      14,     5,   -30,    68,   -30,     9,   -24,   -18,   -30,   -29
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int16 yytable[] =
{
      51,    57,    58,    59,    37,    27,    61,    61,    24,    13,
      67,    56,    68,    17,    80,   123,    14,   124,    22,    60,
      25,    75,    28,    94,   122,    93,    85,    39,    48,    50,
      81,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
       1,    61,     2,    48,    92,    18,     3,     4,     5,    53,
       6,   129,    61,    61,   120,   121,     1,    96,     2,    42,
      79,    43,     3,     4,     5,    44,     6,   130,   131,   132,
      82,    22,    83,    95,    39,   128,   136,   124,    15,    45,
      23,    29,    16,    30,   119,    54,    31,   127,    32,    46,
     133,    47,    33,    34,    35,    36,     0,   134,   135,     0,
       0,     1,   137,     2,    42,     0,    43,     3,     4,     5,
      44,     6,     0,     0,     0,     0,     0,     0,    86,     0,
       0,    42,     0,    43,    45,     0,    29,    44,    30,     0,
       0,    31,     0,    32,    91,     0,    47,    33,    34,    35,
      36,    45,     0,    29,     0,    30,     0,     0,    31,     0,
      32,    87,     0,    47,    33,    34,    35,    36,   125,     0,
      67,    42,    68,    43,     0,     0,     0,    44,     0,     0,
      74,    75,     2,    97,     0,    78,     3,     4,     5,     0,
       6,    45,     0,    29,     0,    30,     0,     0,    31,    55,
      32,   126,     0,    47,    33,    34,    35,    36,    29,     0,
      30,     0,     0,    31,     0,    32,     0,    98,     0,    33,
      34,    35,    36,     0,    29,     0,    30,     0,    42,    31,
      43,    32,     0,     0,    44,    33,    34,    35,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
      29,     0,    30,     0,     0,    31,     0,    32,     0,     0,
      47,    33,    34,    35,    36,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,    72,     0,    73,
      74,    75,    76,     0,    77,    78,    62,    63,    64,    65,
       0,    67,     0,    68,    69,    70,    71,     0,    72,     0,
      73,    74,    75,    76,     0,     0,    78,    62,    63,    64,
       0,     0,    67,     0,    68,    69,    70,    71,     0,    72,
       0,    73,    74,    75,    76,     0,    62,    78,    64,     0,
       0,    67,     0,    68,    69,    70,    71,     0,    72,     0,
      73,    74,    75,    76,    62,     0,    78,     0,     0,    67,
       0,    68,    69,    70,    71,     0,    72,     0,    73,    74,
      75,    76,     0,    67,    78,    68,    69,    70,    71,     0,
      72,     0,    73,    74,    75,    76,     0,    67,    78,    68,
       0,    70,    71,     0,    72,     0,    73,    74,    75,    29,
       0,    30,    78,     0,    31,     0,    32,     0,     0,    84,
      33,    34,    35,    36,    29,     0,    30,     0,     0,    31,
       0,    32,     0,     0,     0,    33,    34,    35,    36,    -2,
       1,     0,     2,     0,     0,     0,     3,     4,     5,     0,
       6
};

static const yytype_int16 yycheck[] =
{
      24,    30,    31,    32,    22,    19,    19,    19,    24,    36,
      18,    29,    20,     8,    19,    34,     0,    36,    17,    26,
      36,    29,    36,    36,    36,    49,    44,    23,    24,    24,
      35,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       1,    19,     3,    49,    49,    37,     7,     8,     9,    37,
      11,    19,    19,    19,    82,    83,     1,    35,     3,     4,
      37,     6,     7,     8,     9,    10,    11,    35,    35,    35,
      26,    17,    26,    35,    80,    35,     5,    36,     8,    24,
      26,    26,     8,    28,    80,    27,    31,    88,    33,    34,
     129,    36,    37,    38,    39,    40,    -1,   131,   132,    -1,
      -1,     1,   136,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      -1,     4,    -1,     6,    24,    -1,    26,    10,    28,    -1,
      -1,    31,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    24,    -1,    26,    -1,    28,    -1,    -1,    31,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,     1,    -1,
      18,     4,    20,     6,    -1,    -1,    -1,    10,    -1,    -1,
      28,    29,     3,     1,    -1,    33,     7,     8,     9,    -1,
      11,    24,    -1,    26,    -1,    28,    -1,    -1,    31,     1,
      33,    34,    -1,    36,    37,    38,    39,    40,    26,    -1,
      28,    -1,    -1,    31,    -1,    33,    -1,    35,    -1,    37,
      38,    39,    40,    -1,    26,    -1,    28,    -1,     4,    31,
       6,    33,    -1,    -1,    10,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      26,    -1,    28,    -1,    -1,    31,    -1,    33,    -1,    -1,
      36,    37,    38,    39,    40,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    25,    -1,    27,
      28,    29,    30,    -1,    32,    33,    13,    14,    15,    16,
      -1,    18,    -1,    20,    21,    22,    23,    -1,    25,    -1,
      27,    28,    29,    30,    -1,    -1,    33,    13,    14,    15,
      -1,    -1,    18,    -1,    20,    21,    22,    23,    -1,    25,
      -1,    27,    28,    29,    30,    -1,    13,    33,    15,    -1,
      -1,    18,    -1,    20,    21,    22,    23,    -1,    25,    -1,
      27,    28,    29,    30,    13,    -1,    33,    -1,    -1,    18,
      -1,    20,    21,    22,    23,    -1,    25,    -1,    27,    28,
      29,    30,    -1,    18,    33,    20,    21,    22,    23,    -1,
      25,    -1,    27,    28,    29,    30,    -1,    18,    33,    20,
      -1,    22,    23,    -1,    25,    -1,    27,    28,    29,    26,
      -1,    28,    33,    -1,    31,    -1,    33,    -1,    -1,    36,
      37,    38,    39,    40,    26,    -1,    28,    -1,    -1,    31,
      -1,    33,    -1,    -1,    -1,    37,    38,    39,    40,     0,
       1,    -1,     3,    -1,    -1,    -1,     7,     8,     9,    -1,
      11
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     7,     8,     9,    11,    43,    44,    45,
      46,    49,    53,    36,     0,    46,    49,    53,    37,    50,
      54,    55,    17,    26,    24,    36,    47,    19,    36,    26,
      28,    31,    33,    37,    38,    39,    40,    59,    61,    45,
      51,    52,     4,     6,    10,    24,    34,    36,    45,    48,
      53,    58,    59,    37,    55,     1,    59,    61,    61,    61,
      26,    19,    13,    14,    15,    16,    17,    18,    20,    21,
      22,    23,    25,    27,    28,    29,    30,    32,    33,    37,
      19,    35,    26,    26,    36,    59,     1,    34,    56,    57,
      58,    34,    53,    58,    36,    35,    35,     1,    35,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    52,
      59,    59,    36,    34,    36,     1,    34,    57,    35,    19,
      35,    35,    35,    61,    58,    58,     5,    58
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
#line 71 "uccompiler.y"
    { (yyval.node) = program = newNode(Program, NULL); 
                                                                               addChildren((yyval.node), (yyvsp[(1) - (1)].node)); }
    break;

  case 3:
#line 76 "uccompiler.y"
    { addChild((yyval.node), (yyvsp[(2) - (2)].node)); }
    break;

  case 4:
#line 77 "uccompiler.y"
    { addChild((yyval.node), (yyvsp[(2) - (2)].node)); }
    break;

  case 5:
#line 78 "uccompiler.y"
    { addChildren((yyval.node), (yyvsp[(2) - (2)].node)); }
    break;

  case 6:
#line 79 "uccompiler.y"
    { (yyval.node) = program = newNode(Program, NULL); 
                                                                               addChild((yyval.node), (yyvsp[(1) - (1)].node)); }
    break;

  case 7:
#line 81 "uccompiler.y"
    { (yyval.node) = program = newNode(Program, NULL); 
                                                                               addChild((yyval.node), (yyvsp[(1) - (1)].node)); }
    break;

  case 8:
#line 83 "uccompiler.y"
    { (yyval.node) = program = newNode(Program, NULL); 
                                                                               addChildren((yyval.node), (yyvsp[(1) - (1)].node)); }
    break;

  case 9:
#line 88 "uccompiler.y"
    { (yyval.node) = kind = newNode(Char, NULL); }
    break;

  case 10:
#line 89 "uccompiler.y"
    { (yyval.node) = kind = newNode(Int, NULL); }
    break;

  case 11:
#line 90 "uccompiler.y"
    { (yyval.node) = kind = newNode(Double, NULL); }
    break;

  case 12:
#line 91 "uccompiler.y"
    { (yyval.node) = kind = newNode(Void, NULL); }
    break;

  case 13:
#line 92 "uccompiler.y"
    { (yyval.node) = kind =newNode(Short, NULL); }
    break;

  case 14:
#line 96 "uccompiler.y"
    { (yyval.node) = newNode(FuncDefinition, NULL); 
                                                                               addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                               addChildren((yyval.node), (yyvsp[(2) - (3)].node)); 
                                                                               addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 15:
#line 103 "uccompiler.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 16:
#line 104 "uccompiler.y"
    { (yyval.node) = newNode(FuncBody, NULL); }
    break;

  case 17:
#line 108 "uccompiler.y"
    { addChildren((yyval.node), (yyvsp[(2) - (2)].node)); }
    break;

  case 18:
#line 109 "uccompiler.y"
    { if((yyvsp[(2) - (2)].node))addChild((yyval.node), (yyvsp[(2) - (2)].node)); }
    break;

  case 19:
#line 110 "uccompiler.y"
    { (yyval.node) = newNode(FuncBody, NULL); addChildren((yyval.node), (yyvsp[(1) - (1)].node)); }
    break;

  case 20:
#line 111 "uccompiler.y"
    { (yyval.node) = newNode(FuncBody, NULL); if((yyvsp[(1) - (1)].node))addChild((yyval.node), (yyvsp[(1) - (1)].node)); }
    break;

  case 21:
#line 115 "uccompiler.y"
    { (yyval.node) = newNode(FuncDeclaration, NULL); 
                                                                               addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                               addChildren((yyval.node), (yyvsp[(2) - (3)].node)); }
    break;

  case 22:
#line 121 "uccompiler.y"
    { (yyval.node) = newNode(NullN, NULL); 
                                                                               addChild((yyval.node), newNode(Identifier, (yyvsp[(1) - (4)].lexeme))); 
                                                                               addChild((yyval.node), (yyvsp[(3) - (4)].node)); }
    break;

  case 23:
#line 127 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (3)].node); addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 24:
#line 128 "uccompiler.y"
    { (yyval.node) = newNode(ParamList, NULL); addChild((yyval.node), (yyvsp[(1) - (1)].node)); }
    break;

  case 25:
#line 132 "uccompiler.y"
    { (yyval.node) = newNode(ParamDeclaration, NULL); 
                                                                               addChild((yyval.node), (yyvsp[(1) - (2)].node)); 
                                                                               addChild((yyval.node), newNode(Identifier, (yyvsp[(2) - (2)].lexeme))); }
    break;

  case 26:
#line 135 "uccompiler.y"
    { (yyval.node) = newNode(ParamDeclaration, NULL); 
                                                                               addChild((yyval.node), (yyvsp[(1) - (1)].node)); }
    break;

  case 27:
#line 140 "uccompiler.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); kind = (yyvsp[(1) - (3)].node); }
    break;

  case 28:
#line 141 "uccompiler.y"
    { (yyval.node) = newNode(Null, NULL); }
    break;

  case 29:
#line 145 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (3)].node); addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 30:
#line 146 "uccompiler.y"
    { (yyval.node) = newNode(NullN, NULL); addChild((yyval.node), (yyvsp[(1) - (1)].node)); }
    break;

  case 31:
#line 150 "uccompiler.y"
    { (yyval.node) = newNode(Declaration, NULL);
                                                                               addChild((yyval.node), kind);
                                                                               addChild((yyval.node), newNode(Identifier, (yyvsp[(1) - (1)].lexeme)));
                                                                               }
    break;

  case 32:
#line 154 "uccompiler.y"
    { (yyval.node) = newNode(Declaration, NULL); 
                                                                               addChild((yyval.node), kind);
                                                                               addChild((yyval.node), newNode(Identifier, (yyvsp[(1) - (3)].lexeme))); 
                                                                               addChild((yyval.node), (yyvsp[(3) - (3)].node)); 
                                                                               }
    break;

  case 33:
#line 162 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); if((yyvsp[(2) - (2)].node))addChild((yyval.node), (yyvsp[(2) - (2)].node)); }
    break;

  case 34:
#line 163 "uccompiler.y"
    { (yyval.node) = newNode(StatList, NULL); if((yyvsp[(1) - (1)].node))addChild((yyval.node), (yyvsp[(1) - (1)].node)); }
    break;

  case 35:
#line 166 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 36:
#line 167 "uccompiler.y"
    { (yyval.node) = newNode(Null, NULL); }
    break;

  case 37:
#line 171 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 38:
#line 172 "uccompiler.y"
    { if(!(yyvsp[(2) - (3)].node)->children->next){ (yyval.node) = NULL; } else if(!(yyvsp[(2) - (3)].node)->children->next->next)(yyval.node) = (yyvsp[(2) - (3)].node)->children->next->node; else (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 39:
#line 173 "uccompiler.y"
    { (yyval.node) = newNode(If, NULL); 
                                                                               addChild((yyval.node), (yyvsp[(3) - (5)].node)); 
                                                                               if((yyvsp[(5) - (5)].node))addChild((yyval.node), (yyvsp[(5) - (5)].node));
                                                                               else addChild((yyval.node), newNode(Null, NULL)); 
                                                                               addChild((yyval.node), newNode(Null, NULL));}
    break;

  case 40:
#line 178 "uccompiler.y"
    { (yyval.node) = newNode(If, NULL); 
                                                                               addChild((yyval.node), (yyvsp[(3) - (7)].node)); 
                                                                               if((yyvsp[(5) - (7)].node))addChild((yyval.node), (yyvsp[(5) - (7)].node));
                                                                               else addChild((yyval.node), newNode(Null, NULL)); 
                                                                               if((yyvsp[(7) - (7)].node))addChild((yyval.node), (yyvsp[(7) - (7)].node)); 
                                                                               else addChild((yyval.node), newNode(Null, NULL));}
    break;

  case 41:
#line 184 "uccompiler.y"
    { (yyval.node) = newNode(While, NULL); 
                                                                               addChild((yyval.node), (yyvsp[(3) - (5)].node)); 
                                                                               if((yyvsp[(5) - (5)].node))addChild((yyval.node), (yyvsp[(5) - (5)].node));
                                                                               else addChild((yyval.node), newNode(Null, NULL)); }
    break;

  case 42:
#line 188 "uccompiler.y"
    { (yyval.node) = newNode(Return, NULL); 
                                                                               addChild((yyval.node), (yyvsp[(2) - (3)].node)); }
    break;

  case 43:
#line 190 "uccompiler.y"
    { (yyval.node) = newNode(Return, NULL);
                                                                                addChild((yyval.node), newNode(Null, NULL)); }
    break;

  case 44:
#line 192 "uccompiler.y"
    { (yyval.node) = NULL; }
    break;

  case 45:
#line 193 "uccompiler.y"
    { (yyval.node) = newNode(Null, NULL); }
    break;

  case 46:
#line 194 "uccompiler.y"
    { (yyval.node) = NULL; }
    break;

  case 47:
#line 198 "uccompiler.y"
    { (yyval.node) = newNode(Comma, NULL); addChild((yyval.node), (yyvsp[(1) - (3)].node)); addChild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 48:
#line 199 "uccompiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 49:
#line 204 "uccompiler.y"
    { addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 50:
#line 205 "uccompiler.y"
    { (yyval.node) = newNode(NullN, NULL); addChild((yyval.node), (yyvsp[(1) - (1)].node)); }
    break;

  case 51:
#line 209 "uccompiler.y"
    { (yyval.node) = newNode(Or, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 52:
#line 212 "uccompiler.y"
    { (yyval.node) = newNode(And, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 53:
#line 215 "uccompiler.y"
    { (yyval.node) = newNode(BitWiseOr, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 54:
#line 218 "uccompiler.y"
    { (yyval.node) = newNode(BitWiseXor, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 55:
#line 221 "uccompiler.y"
    { (yyval.node) = newNode(BitWiseAnd, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 56:
#line 224 "uccompiler.y"
    { (yyval.node) = newNode(Eq, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 57:
#line 227 "uccompiler.y"
    { (yyval.node) = newNode(Ne, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 58:
#line 230 "uccompiler.y"
    { (yyval.node) = newNode(Gt, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 59:
#line 233 "uccompiler.y"
    { (yyval.node) = newNode(Ge, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 60:
#line 236 "uccompiler.y"
    { (yyval.node) = newNode(Lt, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 61:
#line 239 "uccompiler.y"
    { (yyval.node) = newNode(Le, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 62:
#line 242 "uccompiler.y"
    { (yyval.node) = newNode(Store, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 63:
#line 245 "uccompiler.y"
    { (yyval.node) = newNode(Mul, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 64:
#line 248 "uccompiler.y"
    { (yyval.node) = newNode(Mod, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 65:
#line 251 "uccompiler.y"
    { (yyval.node) = newNode(Div, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 66:
#line 254 "uccompiler.y"
    { (yyval.node) = newNode(Add, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 67:
#line 257 "uccompiler.y"
    { (yyval.node) = newNode(Sub, NULL);
                                                                     addChild((yyval.node), (yyvsp[(1) - (3)].node)); 
                                                                     addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 68:
#line 260 "uccompiler.y"
    { (yyval.node) = newNode(Call, NULL); 
                                                                     addChild((yyval.node), newNode(Identifier, (yyvsp[(1) - (3)].lexeme))); }
    break;

  case 69:
#line 262 "uccompiler.y"
    { (yyval.node) = newNode(Minus, NULL);
                                                                     addChild((yyval.node), (yyvsp[(2) - (2)].node)); }
    break;

  case 70:
#line 264 "uccompiler.y"
    { (yyval.node) = newNode(Plus, NULL);
                                                                     addChild((yyval.node), (yyvsp[(2) - (2)].node)); }
    break;

  case 71:
#line 266 "uccompiler.y"
    { (yyval.node) = newNode(Not, NULL);
                                                                     addChild((yyval.node), (yyvsp[(2) - (2)].node)); }
    break;

  case 72:
#line 268 "uccompiler.y"
    { (yyval.node) = newNode(Call, NULL); 
                                                                     addChild((yyval.node), newNode(Identifier, (yyvsp[(1) - (4)].lexeme)));
                                                                     addChildren((yyval.node), (yyvsp[(3) - (4)].node)); }
    break;

  case 73:
#line 271 "uccompiler.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 74:
#line 272 "uccompiler.y"
    { (yyval.node) = newNode(Identifier, (yyvsp[(1) - (1)].lexeme)); }
    break;

  case 75:
#line 273 "uccompiler.y"
    { (yyval.node) = newNode(Chrlit, (yyvsp[(1) - (1)].lexeme)); }
    break;

  case 76:
#line 274 "uccompiler.y"
    { (yyval.node) = newNode(Decimal, (yyvsp[(1) - (1)].lexeme)); }
    break;

  case 77:
#line 275 "uccompiler.y"
    { (yyval.node) = newNode(Natural, (yyvsp[(1) - (1)].lexeme)); }
    break;

  case 78:
#line 276 "uccompiler.y"
    { (yyval.node) = newNode(Identifier, (yyvsp[(1) - (4)].lexeme)); }
    break;

  case 79:
#line 277 "uccompiler.y"
    { (yyval.node) = newNode(Null, NULL); }
    break;


/* Line 1267 of yacc.c.  */
#line 2050 "y.tab.c"
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


#line 279 "uccompiler.y"

