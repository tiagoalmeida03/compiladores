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
     LBRACE = 258,
     RBRACE = 259,
     LPAR = 260,
     RPAR = 261,
     SEMI = 262,
     CHAR = 263,
     INT = 264,
     DOUBLE = 265,
     VOID = 266,
     SHORT = 267,
     ASSIGN = 268,
     COMMA = 269,
     PLUS = 270,
     MINUS = 271,
     MUL = 272,
     DIV = 273,
     MOD = 274,
     EQ = 275,
     NE = 276,
     GT = 277,
     GE = 278,
     LT = 279,
     LE = 280,
     AND = 281,
     OR = 282,
     BITWISEAND = 283,
     BITWISEOR = 284,
     BITWISEXOR = 285,
     NOT = 286,
     IF = 287,
     ELSE = 288,
     WHILE = 289,
     RETURN = 290,
     RESERVED = 291,
     IDENTIFIER = 292,
     CHRLIT = 293,
     DECIMAL = 294,
     NATURAL = 295,
     LOW = 296
   };
#endif
/* Tokens.  */
#define LBRACE 258
#define RBRACE 259
#define LPAR 260
#define RPAR 261
#define SEMI 262
#define CHAR 263
#define INT 264
#define DOUBLE 265
#define VOID 266
#define SHORT 267
#define ASSIGN 268
#define COMMA 269
#define PLUS 270
#define MINUS 271
#define MUL 272
#define DIV 273
#define MOD 274
#define EQ 275
#define NE 276
#define GT 277
#define GE 278
#define LT 279
#define LE 280
#define AND 281
#define OR 282
#define BITWISEAND 283
#define BITWISEOR 284
#define BITWISEXOR 285
#define NOT 286
#define IF 287
#define ELSE 288
#define WHILE 289
#define RETURN 290
#define RESERVED 291
#define IDENTIFIER 292
#define CHRLIT 293
#define DECIMAL 294
#define NATURAL 295
#define LOW 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "uccompiler.y"
{ 
    char *lexeme;
    struct node *node;
}
/* Line 1529 of yacc.c.  */
#line 136 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

