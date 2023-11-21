/*AUTORES*/
/*TIAGO NUNO M. C. L. DE ALMEIDA - 2021221615*/
/*JOÃO FILIPE GASPAR DOS SANTOS - 2021217215*/

%{
#include "ast.h"
#include <stdlib.h> 

int yylex(void);
void yyerror(char *);

struct node *program;
struct node *TypeSpec_spec;
struct node_list *aux;
%}

%union{ 
    char *lexeme;
    struct node *node;
}

%token CHAR IF ELSE WHILE INT
%token SHORT DOUBLE RETURN VOID RESERVED
%token BITWISEAND BITWISEOR BITWISEXOR
%token AND ASSIGN MUL COMMA DIV
%token EQ GE GT LBRACE LE LPAR LT
%token MINUS MOD NE NOT OR PLUS
%token RBRACE RPAR SEMI

%token<lexeme> IDENTIFIER CHRLIT DECIMAL NATURAL

%type<node> Program
%type<node> FunctionsAndDeclarations
%type<node> FunctionsDefinition
%type<node> FunctionsBody 
%type<node> TypeSpec
%type<node> FunctionsDeclaration
%type<node> ParamDeclaration
%type<node> Declarator
%type<node> DeclaratorList
%type<node> Declaration
%type<node> FunctionsDeclarator
%type<node> ParamList
%type<node> DeclarationsAndStatements 
%type<node> StatementList
%type<node> Statement
%type<node> StatementError
%type<node> Expr
%type<node> ExprList

%left COMMA
%right ASSIGN
%left OR
%left AND
%left BITWISEOR
%left BITWISEXOR
%left BITWISEAND
%left NE EQ
%left GT GE LT LE
%left PLUS MINUS
%left MUL DIV MOD 
%right NOT
%left RPAR LPAR 

%nonassoc LOW
%nonassoc ELSE

%%
Program:                                                    
        FunctionsAndDeclarations                                             { ; }
        ;

FunctionsAndDeclarations:
        FunctionsDefinition FunctionsAndDeclarations                         { ; }
        | FunctionsDeclaration FunctionsAndDeclarations                      { ; }
        | Declaration FunctionsAndDeclarations                               { ; }
        | FunctionsDefinition                                                { ; }
        | FunctionsDeclaration                                               { ; }
        | Declaration                                                        { ; }
        ;

TypeSpec:
        CHAR                                                                 { ; }
        | INT                                                                { ; }
        | DOUBLE                                                             { ; }
        | VOID                                                               { ; }
        | SHORT                                                              { ; }
        ;

FunctionsDefinition: 
        TypeSpec FunctionsDeclarator FunctionsBody                           { ; }
        ;

FunctionsBody:
        LBRACE DeclarationsAndStatements RBRACE                              { ; }
        | LBRACE  RBRACE                                                     { ; }
        ;

DeclarationsAndStatements:
        DeclarationsAndStatements Declaration                                { ; }
        | DeclarationsAndStatements Statement                                { ; }
        | Declaration                                                        { ; }
        | Statement                                                          { ; }
        ;

FunctionsDeclaration:
        TypeSpec FunctionsDeclarator SEMI                                    { ; }
        ;

FunctionsDeclarator:
        IDENTIFIER LPAR ParamList RPAR                                       { ; }
        ;

ParamList:
        ParamList COMMA ParamDeclaration                                     { ; }
        | ParamDeclaration                                                   { ; }
        ;

ParamDeclaration:
        TypeSpec IDENTIFIER                                                  { ; }
        | TypeSpec                                                           { ; }
        ;

Declaration:
        TypeSpec DeclaratorList SEMI                                         { ; }
        | error SEMI                                                         { ; }
        ;

DeclaratorList:
        DeclaratorList COMMA Declarator                                      { ; }
        | Declarator                                                         { ; }
        ;

Declarator:
        IDENTIFIER                                                           { ; }
        | IDENTIFIER ASSIGN ExprList                                         { ; }
        ;

StatementList:
        StatementList StatementError                                        { ; }
        | StatementError                                                    { ; }
        ;

StatementError: Statement                                                   { ; }              
        | error SEMI                                                        { ; }
        ;

Statement:
        ExprList SEMI                                                       { ; }
        | LBRACE StatementList RBRACE                                       { ; }
        | IF LPAR ExprList RPAR StatementError           %prec LOW          { ; }
        | IF LPAR ExprList RPAR StatementError ELSE StatementError          { ; }
        | WHILE LPAR ExprList RPAR StatementError                           { ; }
        | RETURN ExprList SEMI                                              { ; }
        | RETURN SEMI                                                       { ; }
        | SEMI                                                              { ; }
        | LBRACE error RBRACE                                               { ; }
        | LBRACE RBRACE                                                     { ; }
        ;

ExprList:
        ExprList COMMA Expr                                                 { ; }
        | Expr                                                              { ; }
        ;


ExprCall:
        ExprCall COMMA Expr                                                 { ; }
        | Expr                                                              { ; }
        ;

Expr:
        Expr OR Expr                                                        { ; }
        | Expr AND Expr                                                     { ; }
        | Expr BITWISEOR Expr                                               { ; }
        | Expr BITWISEXOR Expr                                              { ; }
        | Expr BITWISEAND Expr                                              { ; }
        | Expr EQ Expr                                                      { ; }
        | Expr NE Expr                                                      { ; }
        | Expr GT Expr                                                      { ; }
        | Expr GE Expr                                                      { ; }
        | Expr LT Expr                                                      { ; }
        | Expr LE Expr                                                      { ; }
        | Expr ASSIGN Expr                                                  { ; }
        | MINUS Expr NOT                                                    { ; }
        | PLUS Expr NOT                                                     { ; }
        | Expr MUL Expr                                                     { ; }
        | Expr MOD Expr                                                     { ; }
        | Expr DIV Expr                                                     { ; }
        | Expr PLUS Expr                                                    { ; }
        | Expr MINUS Expr                                                   { ; }
        | IDENTIFIER LPAR RPAR                                              { ; }
        | MINUS Expr %prec NOT                                              { ; }
        | PLUS Expr %prec NOT                                               { ; }
        | NOT Expr                                                          { ; }
        | IDENTIFIER LPAR ExprCall RPAR                                     { ; }
        | LPAR ExprList RPAR                                                { ; }
        | IDENTIFIER                                                        { ; }
        | CHRLIT                                                            { ; }
        | DECIMAL                                                           { ; }
        | NATURAL                                                           { ; }
        | IDENTIFIER LPAR error RPAR                                        { ; }
        | LPAR error RPAR                                                   { ; }
        ;
%%
