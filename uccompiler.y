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
        FunctionsAndDeclarations                                             { $$ = Program = newnode(Program, NULL); }
        ;

FunctionsAndDeclarations:
        FunctionsDefinition FunctionsAndDeclarations                         { struct node *FunctionsAndDeclarations = newnode(FunctionsAndDeclarations, NULL);
                                                                               addchild(FunctionsAndDeclarations, $1);
                                                                               addchild(FunctionsAndDeclarations, $2);
                                                                               addchild($$, FunctionsAndDeclarations); }
        | FunctionsDeclaration FunctionsAndDeclarations                      { struct node *FunctionsAndDeclarations = newnode(FunctionsAndDeclarations, NULL);
                                                                               addchild(FunctionsAndDeclarations, $1);
                                                                               addchild(FunctionsAndDeclarations, $2);
                                                                               addchild($$, FunctionsAndDeclarations); }
        | Declaration FunctionsAndDeclarations                               { struct node *FunctionsAndDeclarations = newnode(FunctionsAndDeclarations, NULL);
                                                                               addchild(FunctionsAndDeclarations, $1);
                                                                               addchild(FunctionsAndDeclarations, $2);
                                                                               addchild($$, FunctionsAndDeclarations); }
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
        TypeSpec FunctionsDeclarator FunctionsBody                           { struct node *FunctionsDefinition = newnode(FunctionsDefinition, NULL);
                                                                               addchild(FunctionsDefinition, $1);
                                                                               addchild(FunctionsDefinition, $2);
                                                                               addchild(FunctionsDefinition, $3)
                                                                               addchild($$, FunctionsDefinition); }
        ;

FunctionsBody:
        LBRACE DeclarationsAndStatements RBRACE                              { $$ = $2; }
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
        IDENTIFIER                                                           { $$ = newnode(Identifier, $1); }
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
        | IF LPAR ExprList RPAR StatementError %prec LOW                    { ; }
        | IF LPAR ExprList RPAR StatementError ELSE StatementError          { ; }
        | WHILE LPAR ExprList RPAR StatementError                           { ; }
        | RETURN ExprList SEMI                                              { ; }
        | RETURN SEMI                                                       { ; }
        | SEMI                                                              { ; }
        | LBRACE error RBRACE                                               { ; }
        | LBRACE RBRACE                                                     { ; }
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
        Expr OR Expr                                               { struct node *or = newnode(Or, NULL);
                                                                     addchild(or, $1); 
                                                                     addchild(or, $3);
                                                                     addchild($$, or); }
        | Expr AND Expr                                            { struct node *and = newnode(And, NULL);
                                                                     addchild(and, $1); 
                                                                     addchild(and, $3);
                                                                     addchild($$, and); }
        | Expr BITWISEOR Expr                                      { struct node *bitwiseor = newnode(Bitwiseor, NULL);
                                                                     addchild(bitwiseor, $1); 
                                                                     addchild(bitwiseor, $3);
                                                                     addchild($$, bitwiseor); }
        | Expr BITWISEXOR Expr                                     { struct node *bitwisexor = newnode(Bitwisexor, NULL);
                                                                     addchild(bitwisexor, $1); 
                                                                     addchild(bitwisexor, $3);
                                                                     addchild($$, bitwisexor); }
        | Expr BITWISEAND Expr                                     { struct node *bitwiseand = newnode(Bitwiseand, NULL);
                                                                     addchild(bitwiseand, $1); 
                                                                     addchild(bitwiseand, $3);
                                                                     addchild($$, bitwiseand); }
        | Expr EQ Expr                                             { struct node *eq = newnode(Eq, NULL);
                                                                     addchild(eq, $1); 
                                                                     addchild(eq, $3);
                                                                     addchild($$, eq); }
        | Expr NE Expr                                             { struct node *ne = newnode(Ne, NULL);
                                                                     addchild(ne, $1); 
                                                                     addchild(ne, $3);
                                                                     addchild($$, ne); }
        | Expr GT Expr                                             { struct node *gt = newnode(Gt, NULL);
                                                                     addchild(gt, $1); 
                                                                     addchild(gt, $3);
                                                                     addchild($$, gt); }
        | Expr GE Expr                                             { struct node *ge = newnode(Ge, NULL);
                                                                     addchild(ge, $1); 
                                                                     addchild(ge, $3);
                                                                     addchild($$, ge); }
        | Expr LT Expr                                             { struct node *lt = newnode(Lt, NULL);
                                                                     addchild(lt, $1); 
                                                                     addchild(lt, $3);
                                                                     addchild($$, lt); }
        | Expr LE Expr                                             { struct node *le = newnode(Le, NULL);
                                                                     addchild(le, $1); 
                                                                     addchild(le, $3);
                                                                     addchild($$, le); }
        | Expr ASSIGN Expr                                         { struct node *assign = newnode(Assign, NULL);
                                                                     addchild(assign, $1); 
                                                                     addchild(assign, $3);
                                                                     addchild($$, assign); }
        | MINUS Expr NOT                                           { ; }
        | PLUS Expr NOT                                            { ; }
        | Expr MUL Expr                                            { struct node *mul = newnode(Mul, NULL);
                                                                     addchild(mul, $1); 
                                                                     addchild(mul, $3);
                                                                     addchild($$, mul); }
        | Expr MOD Expr                                            { struct node *mod = newnode(Mod, NULL);
                                                                     addchild(mod, $1); 
                                                                     addchild(mod, $3);
                                                                     addchild($$, mod); }
        | Expr DIV Expr                                            { struct node *div = newnode(Div, NULL);
                                                                     addchild(div, $1); 
                                                                     addchild(div, $3);
                                                                     addchild($$, div); }
        | Expr PLUS Expr                                           { struct node *add = newnode(Add, NULL);
                                                                     addchild(add, $1); 
                                                                     addchild(add, $3);
                                                                     addchild($$, add); }
        | Expr MINUS Expr                                          { struct node *sub = newnode(Sub, NULL);
                                                                     addchild(sub, $1); 
                                                                     addchild(sub, $3);
                                                                     addchild($$, sub); }
        | IDENTIFIER LPAR RPAR                                     { ; }
        | MINUS Expr %prec NOT                                     { struct node *minus = newnode(Minus, NULL);
                                                                     addchild(minus, $1); 
                                                                     addchild($$, minus); }
        | PLUS Expr %prec NOT                                      { struct node *plus = newnode(Plus, NULL);
                                                                     addchild(plus, $1); 
                                                                     addchild(plus, $3);
                                                                     addchild($$, plus); }
        | NOT Expr                                                 { struct node *not = newnode(Not, NULL);
                                                                     addchild(not, $1); 
                                                                     addchild(not, $3);
                                                                     addchild($$, not); }
        | IDENTIFIER LPAR ExprCall RPAR                            { ; }
        | LPAR ExprList RPAR                                       { ; }
        | IDENTIFIER                                               { $$ = newnode(Identifier, $1); }
        | CHRLIT                                                   { $$ = newnode(Chrlit, $1); }
        | DECIMAL                                                  { $$ = newnode(Decimal, $1); }
        | NATURAL                                                  { $$ = newnode(Natural, $1); }
        | IDENTIFIER LPAR error RPAR                               { ; }
        | LPAR error RPAR                                          { ; }
        ;
%%

