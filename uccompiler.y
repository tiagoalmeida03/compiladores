/*AUTORES*/
/*TIAGO NUNO M. C. L. DE ALMEIDA - 2021221615*/
/*JOÃO FILIPE GASPAR DOS SANTOS - 2021217215*/

%{
#include "ast.h"
#include <stdlib.h> 

int yylex(void);
void yyerror(char *);

struct node *program;
struct node *kind;
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
        FunctionsAndDeclarations                                             { $$ = program = newNode(Program, NULL); 
                                                                               addChildren($$, $1); }
        ;

FunctionsAndDeclarations:
        FunctionsAndDeclarations FunctionsDefinition                         { addChild($$, $2); }
        | FunctionsAndDeclarations FunctionsDeclaration                      { addChild($$, $2); }
        | FunctionsAndDeclarations Declaration                               { addChildren($$, $2); }
        | FunctionsDefinition                                                { $$ = program = newNode(Program, NULL); 
                                                                               addChild($$, $1); }
        | FunctionsDeclaration                                               { $$ = program = newNode(Program, NULL); 
                                                                               addChild($$, $1); }
        | Declaration                                                        { $$ = program = newNode(Program, NULL); 
                                                                               addChildren($$, $1); }
        ;

TypeSpec:
        CHAR                                                                 { $$ = kind = newNode(Char, NULL); }
        | INT                                                                { $$ = kind = newNode(Int, NULL); }
        | DOUBLE                                                             { $$ = kind = newNode(Double, NULL); }
        | VOID                                                               { $$ = kind = newNode(Void, NULL); }
        | SHORT                                                              { $$ = kind =newNode(Short, NULL); }
        ;

FunctionsDefinition: 
        TypeSpec FunctionsDeclarator FunctionsBody                           { $$ = newNode(FuncDefinition, NULL); 
                                                                               addChild($$, $1); 
                                                                               addChildren($$, $2); 
                                                                               addChild($$, $3); }
        ;

FunctionsBody:
        LBRACE DeclarationsAndStatements RBRACE                              { $$ = $2; }
        | LBRACE  RBRACE                                                     { $$ = newNode(FuncBody, NULL); }
        ;

DeclarationsAndStatements:
        DeclarationsAndStatements Declaration                                { addChildren($$, $2); }
        | DeclarationsAndStatements Statement                                { if($2)addChild($$, $2); }
        | Declaration                                                        { $$ = newNode(FuncBody, NULL); addChildren($$, $1); }
        | Statement                                                          { $$ = newNode(FuncBody, NULL); if($1)addChild($$, $1); }
        ;

FunctionsDeclaration:
        TypeSpec FunctionsDeclarator SEMI                                    { $$ = newNode(FuncDeclaration, NULL); 
                                                                               addChild($$, $1); 
                                                                               addChildren($$, $2); }
        ;

FunctionsDeclarator:
        IDENTIFIER LPAR ParamList RPAR                                       { $$ = newNode(NullN, NULL); 
                                                                               addChild($$, newNode(Identifier, $1)); 
                                                                               addChild($$, $3); }
        ;

ParamList:
        ParamList COMMA ParamDeclaration                                     { $$ = $1; addChild($$, $3); }
        | ParamDeclaration                                                   { $$ = newNode(ParamList, NULL); addChild($$, $1); }
        ;

ParamDeclaration:
        TypeSpec IDENTIFIER                                                  { $$ = newNode(ParamDeclaration, NULL); 
                                                                               addChild($$, $1); 
                                                                               addChild($$, newNode(Identifier, $2)); }
        | TypeSpec                                                           { $$ = newNode(ParamDeclaration, NULL); 
                                                                               addChild($$, $1); }
        ;

Declaration:
        TypeSpec DeclaratorList SEMI                                         { $$ = $2; kind = $1; }
        | error SEMI                                                         { $$ = newNode(Null, NULL); }
        ;

DeclaratorList:
        DeclaratorList COMMA Declarator                                      { $$ = $1; addChild($$, $3); }
        | Declarator                                                         { $$ = newNode(NullN, NULL); addChild($$, $1); }
        ;

Declarator:
        IDENTIFIER                                                           { $$ = newNode(Declaration, NULL);
                                                                               addChild($$, kind);
                                                                               addChild($$, newNode(Identifier, $1));
                                                                               }
        | IDENTIFIER ASSIGN ExprList                                         { $$ = newNode(Declaration, NULL); 
                                                                               addChild($$, kind);
                                                                               addChild($$, newNode(Identifier, $1)); 
                                                                               addChild($$, $3); 
                                                                               }
        ;

StatementList:
        StatementList StatementError                                        { $$ = $1; if($2)addChild($$, $2); }
        | StatementError                                                    { $$ = newNode(StatList, NULL); if($1)addChild($$, $1); }
        ;

StatementError: Statement                                                   { $$ = $1; }            
        | error SEMI                                                        { $$ = newNode(Null, NULL); }
        ;

Statement:
        ExprList SEMI                                                       { $$ = $1; }
        | LBRACE StatementList RBRACE                                       { if(!$2->children->next){ $$ = NULL; } else if(!$2->children->next->next)$$ = $2->children->next->node; else $$ = $2; }
        | IF LPAR ExprList RPAR Statement %prec LOW                         { $$ = newNode(If, NULL); 
                                                                               addChild($$, $3); 
                                                                               if($5)addChild($$, $5);
                                                                               else addChild($$, newNode(Null, NULL)); 
                                                                               addChild($$, newNode(Null, NULL));}
        | IF LPAR ExprList RPAR Statement ELSE Statement                    { $$ = newNode(If, NULL); 
                                                                               addChild($$, $3); 
                                                                               if($5)addChild($$, $5);
                                                                               else addChild($$, newNode(Null, NULL)); 
                                                                               if($7)addChild($$, $7); 
                                                                               else addChild($$, newNode(Null, NULL));}
        | WHILE LPAR ExprList RPAR Statement                                { $$ = newNode(While, NULL); 
                                                                               addChild($$, $3); 
                                                                               if($5)addChild($$, $5);
                                                                               else addChild($$, newNode(Null, NULL)); }
        | RETURN ExprList SEMI                                              { $$ = newNode(Return, NULL); 
                                                                               addChild($$, $2); }
        | RETURN SEMI                                                       { $$ = newNode(Return, NULL);
                                                                                addChild($$, newNode(Null, NULL)); }
        | SEMI                                                              { $$ = NULL; }
        | LBRACE error RBRACE                                               { $$ = newNode(Null, NULL); }
        | LBRACE RBRACE                                                     { $$ = NULL; }
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
        | Expr PLUS Expr                                           { $$ = newNode(Add, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | Expr MINUS Expr                                          { $$ = newNode(Sub, NULL);
                                                                     addChild($$, $1); 
                                                                     addChild($$, $3); }
        | IDENTIFIER LPAR RPAR                                     { $$ = newNode(Call, NULL); 
                                                                     addChild($$, newNode(Identifier, $1)); }
        | MINUS Expr %prec NOT                                     { $$ = newNode(Minus, NULL);
                                                                     addChild($$, $2); }
        | PLUS Expr %prec NOT                                      { $$ = newNode(Plus, NULL);
                                                                     addChild($$, $2); }
        | NOT Expr                                                 { $$ = newNode(Not, NULL);
                                                                     addChild($$, $2); }
        | IDENTIFIER LPAR ExprCall RPAR                            { $$ = newNode(Call, NULL); 
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