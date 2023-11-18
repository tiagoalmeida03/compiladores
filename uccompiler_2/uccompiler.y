%{
// Frederico Ferreira 2021217116
// Andre Louro 2021232388

#include "ast.h"
#include <stdlib.h>

int yylex(void);
void yyerror(char *);

struct node *program;
struct node *type_spec;
struct node_list *aux;
%}

%union{ 
    char *lexeme;
    struct node *node;
}

%token LBRACE 
%token RBRACE
%token LPAR
%token RPAR
%token SEMI
%token CHAR
%token INT
%token DOUBLE
%token VOID
%token SHORT
%token ASSIGN
%token COMMA
%token PLUS
%token MINUS
%token MUL
%token DIV
%token MOD
%token EQ
%token NE 
%token GT
%token GE
%token LT
%token LE
%token AND
%token OR
%token BITWISEAND
%token BITWISEOR
%token BITWISEXOR
%token NOT
%token IF
%token ELSE
%token WHILE
%token RETURN
%token RESERVED

%token<lexeme> IDENTIFIER
%token<lexeme> CHRLIT
%token<lexeme> DECIMAL
%token<lexeme> NATURAL

%type<node> Program
%type<node> FuncAndDeclarations
%type<node> FuncDefinition
%type<node> FuncBody 
%type<node> Type
%type<node> FuncDeclaration
%type<node> ParamDeclaration
%type<node> Declarator
%type<node> DeclaratorList
%type<node> Declaration
%type<node> FuncDeclarator
%type<node> ParamList
%type<node> DeclarationsAndStats 
%type<node> StatList
%type<node> Stat
%type<node> StatError
%type<node> Expr
%type<node> ExprList
%type<node> ExprCall

%nonassoc LOW
%nonassoc ELSE

%left COMMA
%right ASSIGN
%left OR
%left AND
%left BITWISEOR
%left BITWISEXOR
%left BITWISEAND
%left EQ NE 
%left GT GE LT LE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%%
Program: 
        FuncAndDeclarations                                        { ; }
        ;

FuncAndDeclarations:
        FuncAndDeclarations FuncDefinition                         { ; }
        | FuncAndDeclarations FuncDeclaration                      { ; }
        | FuncAndDeclarations Declaration                          { ; }
        | FuncDefinition                                           { ; }
        | FuncDeclaration                                          { ; }
        | Declaration                                              { ; }
        ;

Type:
        CHAR                                                       { ; }
        | INT                                                      { ; }
        | DOUBLE                                                   { ; }
        | VOID                                                     { ; }
        | SHORT                                                    { ; }
        ;

FuncDefinition: 
        Type FuncDeclarator FuncBody                               { ; }
        ;

FuncBody:
        LBRACE DeclarationsAndStats RBRACE                         { ; }
        | LBRACE  RBRACE                                           { ; }
        ;

DeclarationsAndStats:
        DeclarationsAndStats Declaration                           { ; }
        | DeclarationsAndStats Stat                                { ; }
        | Declaration                                              { ; }
        | Stat                                                     { ; }
        ;

FuncDeclaration:
        Type FuncDeclarator SEMI                                   { ; }
        ;

FuncDeclarator:
        IDENTIFIER LPAR ParamList RPAR                             { ; }
        ;

ParamList:
        ParamList COMMA ParamDeclaration                           { ; }
        | ParamDeclaration                                         { ; }
        ;

ParamDeclaration:
        Type IDENTIFIER                                            { ; }
        | Type                                                     { ; }
        ;

Declaration:
        Type DeclaratorList SEMI                                   { ; }
        | error SEMI                                               { ; }
        ;

DeclaratorList:
        DeclaratorList COMMA Declarator                            { ; }
        | Declarator                                               { ; }
        ;

Declarator:
        IDENTIFIER                                                 { ; }
        | IDENTIFIER ASSIGN ExprList                               { ; }
        ;

StatList:
        StatList StatError                                         { ; }
        | StatError                                                { ; }
        ;

StatError: Stat                                                    { ; }              
        | error SEMI                                               { ; }
        ;

Stat:
        ExprList SEMI                                              { ; }
        | LBRACE StatList RBRACE                                   { ; }
        | IF LPAR ExprList RPAR Stat %prec LOW                     { ; }
        | IF LPAR ExprList RPAR Stat ELSE Stat                     { ; }
        | WHILE LPAR ExprList RPAR Stat                            { ; }
        | RETURN ExprList SEMI                                     { ; }
        | RETURN SEMI                                              { ; }
        | SEMI                                                     { ; }
        | LBRACE error RBRACE                                      { ; }
        ;

ExprList:
        ExprList COMMA Expr                                        { ; }
        | Expr                                                     { ; }
        ;

ExprCall:
        ExprCall COMMA Expr                                        { ; }
        | Expr                                                     { ; }
        ;

Expr:
        Expr OR Expr                                               { ; }
        | Expr AND Expr                                            { ; }
        | Expr BITWISEOR Expr                                      { ; }
        | Expr BITWISEXOR Expr                                     { ; }
        | Expr BITWISEAND Expr                                     { ; }
        | Expr EQ Expr                                             { ; }
        | Expr NE Expr                                             { ; }
        | Expr GT Expr                                             { ; }
        | Expr GE Expr                                             { ; }
        | Expr LT Expr                                             { ; }
        | Expr LE Expr                                             { ; }
        | Expr ASSIGN Expr                                         { ; }
        | Expr PLUS Expr                                           { ; }
        | Expr MINUS Expr                                          { ; }
        | Expr MUL Expr                                            { ; }
        | Expr DIV Expr                                            { ; }
        | Expr MOD Expr                                            { ; }
        | MINUS Expr %prec NOT                                     { ; }
        | PLUS Expr %prec NOT                                      { ; }
        | NOT Expr                                                 { ; }
        | IDENTIFIER LPAR ExprCall RPAR                            { ; }
        | LPAR ExprList RPAR                                       { ; }
        | IDENTIFIER                                               { ; }
        | CHRLIT                                                   { ; }
        | DECIMAL                                                  { ; }
        | NATURAL                                                  { ; }
        | IDENTIFIER LPAR error RPAR                               { ; }
        | LPAR error RPAR                                          { ; }
        ;
%%
  