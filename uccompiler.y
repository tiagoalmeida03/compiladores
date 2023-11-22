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
                                                                               addChildren($$, $1); }
        ;

FunctionsAndDeclarations:
        FunctionsAndDeclarations FunctionsDefinition                         { addChild($$, $2); }
        | FunctionsAndDeclarations FunctionsDeclaration                      { addChild($$, $2); }
        | FunctionsAndDeclarations Declaration                               { addChild($$, $2); }
        | FunctionsDefinition                                                { $$ = newNode(NullN, NULL); 
                                                                               addchild($$, $1); }
        | FunctionsDeclaration                                               { $$ = newNode(NullN, NULL); 
                                                                               addchild($$, $1); }
        | Declaration                                                        { $$ = newNode(NullN, NULL);
                                                                               addchild($$, $1); }
        ;

TypeSpec:
        CHAR                                                                 { $$ = newNode(Char, NULL); }
        | INT                                                                { $$ = newNode(Int, NULL); }
        | DOUBLE                                                             { $$ = newNode(Double, NULL); }
        | VOID                                                               { $$ = newNode(Void, NULL); }
        | SHORT                                                              { $$ = newNode(Short, NULL); }
        ;

FunctionsDefinition: 
        TypeSpec FunctionsDeclarator FunctionsBody                           { $$ = newNode(FuncDefinition, NULL); 
                                                                               addChild($$, $1); 
                                                                               addChild($$, $2); 
                                                                               addChild($$, $3); }
        ;

FunctionsBody:
        LBRACE DeclarationsAndStatements RBRACE                              { $$ = newNode(FuncBody, NULL); 
                                                                               addChild($$, $2); }
        | LBRACE  RBRACE                                                     { $$ = newNode(FuncBody, NULL); }
        ;

DeclarationsAndStatements:
        DeclarationsAndStatements Declaration                                { $$ = $1; addBrother($$, $2); }
        | DeclarationsAndStatements Statement                                { $$ = $1; addBrother($$, $2); }
        | Declaration                                                        { $$ = $1; }
        | Statement                                                          { $$ = $1; }
        ;

FunctionsDeclaration:
        TypeSpec FunctionsDeclarator SEMI                                    { $$ = newNode(FuncDeclaration, NULL); 
                                                                               addChild($$, $1); 
                                                                               addChild($$, $2); }
        ;

FunctionsDeclarator:
        IDENTIFIER LPAR ParamList RPAR                                       { $$ = newNode(FuncDeclrator, NULL); 
                                                                               addChild($$, newNode(Identifier, $1)); 
                                                                               addChild($$, $3); }
        ;

ParamList:
        ParamList COMMA ParamDeclaration                                     { $$ = $1; addBrother($$, $3); }
        | ParamDeclaration                                                   { $$ = $1; }
        ;

ParamDeclaration:
        TypeSpec IDENTIFIER                                                  { $$ = newNode(ParamDeclaration, NULL); 
                                                                               addChild($$, $1); 
                                                                               addChild($$, newNode(Identifier, $2)); }
        | TypeSpec                                                           { $$ = newNode(ParamDeclaration, NULL); 
                                                                               addChild($$, $1); }
        ;

Declaration:
        TypeSpec DeclaratorList SEMI                                         { $$ = newNode(Declaration, NULL); 
                                                                               addChild($$, $1); 
                                                                               addChildren($$, $2); }
        | error SEMI                                                         { $$ = newNode(Null, NULL); }
        ;

DeclaratorList:
        DeclaratorList COMMA Declarator                                      { $$ = $1; addChild($$, $3); }
        | Declarator                                                         { $$ = newNode(NullN, NULL); addChild($$, $1); }
        ;

Declarator:
        IDENTIFIER                                                           { $$ = newNode(Identifier, $1); }
        | IDENTIFIER ASSIGN ExprList                                         { $$ = newNode(Identifier, $1); 
                                                                               addChild($$, $3); }
        ;

StatementList:
        StatementList StatementError                                        { $$ = $1; addChild($$, $2); }
        | StatementError                                                    { $$ = newNode(StatList, NULL); addChild($$, $1); }
        ;

StatementError: Statement                                                   { $$ = $1; }              
        | error SEMI                                                        { $$ = newNode(Null, NULL); }
        ;

Statement:
        ExprList SEMI                                                       { $$ = $1; }
        | LBRACE StatementList RBRACE                                       { $$ = $2; }
        | IF LPAR ExprList RPAR Statement %prec LOW                         { $$ = newNode(If, NULL); 
                                                                               addChild($$, $3); 
                                                                               addChild($$, $5); 
                                                                               addChild($$, newNode(Null, NULL)); }
        | IF LPAR ExprList RPAR Statement ELSE Statement                    { $$ = newNode(If, NULL); 
                                                                               addChild($$, $3); 
                                                                               addChild($$, $5); 
                                                                               addChild($$, $7); }
        | WHILE LPAR ExprList RPAR Statement                                { $$ = newNode(While, NULL); 
                                                                               addChild($$, $3); 
                                                                               addChild($$, $5); }
        | RETURN ExprList SEMI                                              { $$ = newNode(Return, NULL); 
                                                                               addChild($$, $2); }
        | RETURN SEMI                                                       { $$ = newNode(Return, NULL); }
        | SEMI                                                              { newNode(NullN, NULL); }
        | LBRACE error RBRACE                                               { $$ = newNode(Null, NULL); }
        | LBRACE RBRACE                                                     { $$ = newNode(Null, NULL); }
        ;

ExprList:
        ExprList COMMA Expr                                        { $$ = newNode(Comma, NULL); addChild($$, $1); addChild($$, $3);}
        | Expr                                                     { $$ = $1; }
        ;


ExprCall:
        ExprCall COMMA Expr                                        { addChild($$, $3); }
        | Expr                                                     { $$ = newNode(NullN, NULL); addChild($$, $1); }
        ;

Expr:
        Expr OR Expr                                               { $$ = newNode(Or, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr AND Expr                                            { $$ = newNode(And, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr BITWISEOR Expr                                      { $$ = newNode(BitWiseOr, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr BITWISEXOR Expr                                     { $$ = newNode(BitWiseXor, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr BITWISEAND Expr                                     { $$ = newNode(BitWiseAnd, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr EQ Expr                                             { $$ = newNode(Eq, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr NE Expr                                             { $$ = newNode(Ne, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr GT Expr                                             { $$ = newNode(Gt, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr GE Expr                                             { $$ = newNode(Ge, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr LT Expr                                             { $$ = newNode(Lt, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr LE Expr                                             { $$ = newNode(Le, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr ASSIGN Expr                                         { $$ = newNode(Store, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr MUL Expr                                            { $$ = newNode(Mul, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr MOD Expr                                            { $$ = newNode(Mod, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr DIV Expr                                            { $$ = newNode(Div, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr PLUS Expr                                           { $$ = newNode(Plus, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr MINUS Expr                                          { $$ = newNode(Minus, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | IDENTIFIER LPAR RPAR                                     { $$ = newNode(Call, $1); 
                                                                     addChild($$, newNode(Identifier, $1)); }
        | MINUS Expr %prec NOT                                     { $$ = newNode(Minus, NULL);
                                                                     addChild($$, $2); }
        | PLUS Expr %prec NOT                                      { $$ = newNode(Plus, NULL);
                                                                     addChild($$, $2); }
        | NOT Expr                                                 { $$ = newNode(Not, NULL);
                                                                     addChild($$, $2); }
        | IDENTIFIER LPAR ExprCall RPAR                            { $$ = newNode(Call, $1); 
                                                                     addChild($$, newNode(Identifier, $1));
                                                                     addChildren($$, $3); }
        | LPAR ExprList RPAR                                       { $$ = $2; }
        | IDENTIFIER                                               { $$ = newNode(Identifier, $1); }
        | CHRLIT                                                   { $$ = newNode(Chrlit, $1); }
        | DECIMAL                                                  { $$ = newNode(Decimal, $1); }
        | NATURAL                                                  { $$ = newNode(Natural, $1); }
        | IDENTIFIER LPAR error RPAR                               { $$ = newNode(Identifier, $1); }
        | LPAR error RPAR                                          { $$ = newNode(Null, NULL); }
        ;
%%