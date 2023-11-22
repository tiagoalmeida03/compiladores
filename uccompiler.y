/*AUTORES*/
/*TIAGO NUNO M. C. L. DE ALMEIDA - 2021221615*/
/*JOÃO FILIPE GASPAR DOS SANTOS - 2021217215*/

%{
#include "ast.h"
#include <stdlib.h> 

int yylex(void);
void yyerror(char *);

struct node *program;
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
%type<node> FunctionsDeclaration
%type<node> TypeSpec
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
%type<node> ExprCall

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
        FunctionsAndDeclarations                                             { $$ = program = newnode(Program, NULL); 
                                                                               addchild($$, $1); }
        ;

FunctionsAndDeclarations:
        FunctionsDefinition FunctionsAndDeclarations                         { $$ = $1; addBrother($$, $2); }
        | FunctionsDeclaration FunctionsAndDeclarations                      { $$ = $1; addBrother($$, $2); }
        | Declaration FunctionsAndDeclarations                               { $$ = $1; addBrother($$, $2); }
        | FunctionsDefinition                                                { $$ = $1; }
        | FunctionsDeclaration                                               { $$ = $1; }
        | Declaration                                                        { $$ = $1; }
        ;

TypeSpec:
        CHAR                                                                 { $$ = newnode(Char, $1); }
        | INT                                                                { $$ = newnode(Int, $1); }
        | DOUBLE                                                             { $$ = newnode(Double, $1); }
        | VOID                                                               { $$ = newnode(Void, $1); }
        | SHORT                                                              { $$ = newnode(Short, $1); }
        ;

FunctionsDefinition: 
        TypeSpec FunctionsDeclarator FunctionsBody                           { $$ = newnode(FunctionsDefinition, NULL); 
                                                                               addchild($$, $1); 
                                                                               addchild($$, $2); 
                                                                               addchild($$, $3); }
        ;

FunctionsBody:
        LBRACE DeclarationsAndStatements RBRACE                              { $$ = newnode(FunctionsBody, NULL); 
                                                                               addchild($$, $2); }
        | LBRACE  RBRACE                                                     { $$ = newnode(FunctionsBody, NULL); }
        ;

DeclarationsAndStatements:
        DeclarationsAndStatements Declaration                                { $$ = $1; addBrother($$, $2); }
        | DeclarationsAndStatements Statement                                { $$ = $1; addBrother($$, $2); }
        | Declaration                                                        { $$ = $1; }
        | Statement                                                          { $$ = $1; }
        ;

FunctionsDeclaration:
        TypeSpec FunctionsDeclarator SEMI                                    { $$ = newnode(FunctionsDeclaration, NULL); 
                                                                               addchild($$, $1); 
                                                                               addchild($$, $2); }
        ;

FunctionsDeclarator:
        IDENTIFIER LPAR ParamList RPAR                                       { $$ = newnode(FunctionsDeclarator, NULL); 
                                                                               addchild($$, newnode(Identifier, $1)); 
                                                                               addchild($$, $3); }
        ;

ParamList:
        ParamList COMMA ParamDeclaration                                     { $$ = $1; addBrother($$, $3); }
        | ParamDeclaration                                                   { $$ = $1; }
        ;

ParamDeclaration:
        TypeSpec IDENTIFIER                                                  { $$ = newnode(ParamDeclaration, NULL); 
                                                                               addchild($$, $1); 
                                                                               addchild($$, newnode(Identifier, $2)); }
        | TypeSpec                                                           { $$ = newnode(ParamDeclaration, NULL); 
                                                                               addchild($$, $1); }
        ;

Declaration:
        TypeSpec DeclaratorList SEMI                                         { $$ = newnode(Declaration, NULL); 
                                                                               addchild($$, $1); 
                                                                               addchild($$, $2); }
        | error SEMI                                                         { $$ = newnode(Null, NULL); }
        ;

DeclaratorList: /*Dúvida cm se mete raiz no 1o mas chama origem recursivamente*/
        DeclaratorList COMMA Declarator                                      { $$ = $1; addBrother($$, $3); }
        | Declarator                                                         { $$ = $1; }
        ;

Declarator:
        IDENTIFIER                                                           { $$ = newnode(Identifier, $1); }
        | IDENTIFIER ASSIGN ExprList                                         { $$ = newnode(Identifier, $1); 
                                                                               addBrother($$, $3); }
        ;

StatementList:
        StatementList StatementError                                        { $$ = $1; addBrother($$, $2); }
        | StatementError                                                    { $$ = $1; }
        ;

StatementError: Statement                                                   { $$ = $1; }              
        | error SEMI                                                        { $$ = newnode(Null, NULL); }
        ;

Statement:
        ExprList SEMI                                                       { $$ = $1; }
        | LBRACE StatementList RBRACE                                       { newnode(StatList, NULL);
                                                                               addchild($$, $2); }
        | IF LPAR ExprList RPAR StatementError %prec LOW                    { $$ = newnode(If, NULL); 
                                                                               addchild($$, $3); 
                                                                               addchild($$, $5); }
        | IF LPAR ExprList RPAR StatementError ELSE StatementError          { $$ = newnode(If, NULL); 
                                                                               addchild($$, $3); 
                                                                               addchild($$, $5); 
                                                                               addchild($$, $7); }
        | WHILE LPAR ExprList RPAR StatementError                           { $$ = newnode(While, NULL); 
                                                                               addchild($$, $3); 
                                                                               addchild($$, $5); }
        | RETURN ExprList SEMI                                              { $$ = newnode(Return, NULL); 
                                                                               addchild($$, $2); }
        | RETURN SEMI                                                       { $$ = newnode(Return, NULL); }
        | SEMI                                                              { newnode(NullN, NULL); }
        | LBRACE error RBRACE                                               { $$ = newnode(Null, NULL); }
        | LBRACE RBRACE                                                     { $$ = newnode(Null, NULL); }
        ;

ExprList:
        ExprList COMMA Expr                                        { $$ = $1; addBrother($$, $3); }
        | Expr                                                     { $$ = $1; }
        ;


ExprCall:
        ExprCall COMMA Expr                                        { $$ = $1; addBrother($$, $3); }
        | Expr                                                     { $$ = $1; }
        ;

Expr:
        Expr OR Expr                                               { $$ = newnode(Or, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr AND Expr                                            { $$ = newnode(And, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr BITWISEOR Expr                                      { $$ = newnode(Bitwiseor, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr BITWISEXOR Expr                                     { $$ = newnode(Bitwisexor, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr BITWISEAND Expr                                     { $$ = newnode(Bitwiseand, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr EQ Expr                                             { $$ = newnode(Eq, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr NE Expr                                             { $$ = newnode(Ne, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr GT Expr                                             { $$ = newnode(Gt, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr GE Expr                                             { $$ = newnode(Ge, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr LT Expr                                             { $$ = newnode(Lt, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr LE Expr                                             { $$ = newnode(Le, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr ASSIGN Expr                                         { $$ = newnode(Store, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr MUL Expr                                            { $$ = newnode(Mul, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr MOD Expr                                            { $$ = newnode(Mod, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr DIV Expr                                            { $$ = newnode(Div, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr PLUS Expr                                           { $$ = newnode(Plus, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | Expr MINUS Expr                                          { $$ = newnode(Minus, NULL);
                                                                     addchild($$, $1); 
                                                                     addchild($$, $3); }
        | IDENTIFIER LPAR RPAR                                     { $$ = newnode(Identifier, $1); }
        | MINUS Expr %prec NOT                                     { $$ = newnode(Minus, NULL);
                                                                     addchild($$, $2); }
        | PLUS Expr %prec NOT                                      { $$ = newnode(Plus, NULL);
                                                                     addchild($$, $2); }
        | NOT Expr                                                 { $$ = newnode(Not, NULL);
                                                                     addchild($$, $2); }
        | IDENTIFIER LPAR ExprCall RPAR                            { $$ = newnode(Call, $1); 
                                                                     addchild($$, newnode(Identifier, $1));
                                                                     addchild($$, $3); }
        | LPAR ExprList RPAR                                       { $$ = $2; }
        | IDENTIFIER                                               { $$ = newnode(Identifier, $1); }
        | CHRLIT                                                   { $$ = newnode(Chrlit, $1); }
        | DECIMAL                                                  { $$ = newnode(Decimal, $1); }
        | NATURAL                                                  { $$ = newnode(Natural, $1); }
        | IDENTIFIER LPAR error RPAR                               { $$ = newnode(Identifier, $1); }
        | LPAR error RPAR                                          { $$ = newnode(Null, NULL); }
        ;
%%