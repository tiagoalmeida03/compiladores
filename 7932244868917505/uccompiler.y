%{

#include "ast.h"
#include <stdlib.h>

int yylex(void);
void yyerror(char *);

struct node *program;
struct node *type;
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
/* Program: 
        FuncAndDeclarations                                        { $$ = program = newNode(Program, NULL); }
        ; */

FuncAndDeclarations:
        FuncAndDeclarations FuncDefinition                         { addChild($$, $2); }
        | FuncAndDeclarations FuncDeclaration                      { addChild($$, $2); }
        | FuncAndDeclarations Declaration                          { while(($2->children = $2->children->next) != NULL)
                                                                      addChild($$, $2->children->node); }
        | FuncDefinition                                           { $$ = program = newNode(Program, NULL);
                                                                    addChild($$, $1);  }
        | FuncDeclaration                                          { $$ = program = newNode(Program, NULL);
                                                                    addChild($$, $1); }
        | Declaration                                              { $1->category = Program;
                                                                    $$ = program = $1;  }
        ;

Type:
        CHAR                                                       { $$ = type = newNode(Char, NULL); }
        | INT                                                      { $$ = type = newNode(Int, NULL); }
        | DOUBLE                                                   { $$ = type = newNode(Double, NULL); }
        | VOID                                                     { $$ = type = newNode(Void, NULL); }
        | SHORT                                                    { $$ = type = newNode(Short, NULL); }
        ;

FuncDefinition: 
        Type FuncDeclarator FuncBody                               { $$ = newNode(FunctionDefinition, NULL); 
                                                                    addChild($$, $1);
                                                                    while(($2->children = $2->children->next) != NULL)
                                                                        addChild($$, $2->children->node);
                                                                    addChild($$, $3);}
        ;

FuncBody:
        LBRACE DeclarationsAndStats RBRACE                         { $$ = $2; }
        | LBRACE  RBRACE                                           { $$ = newNode(FuncBody, NULL); }
        ;

DeclarationsAndStats:
        DeclarationsAndStats Declaration                           { while(($2->children = $2->children->next) != NULL)
                                                                      addChild($$, $2->children->node); }
        | DeclarationsAndStats Stat                                { if($2)addChild($$, $2); }
        | Declaration                                              { $$ = $1; 
                                                                    $1->category = FuncBody;}
        | Stat                                                     { $$ = newNode(FuncBody, NULL); 
                                                                    if($1)addChild($$, $1); }
        ;

FuncDeclaration:
        Type FuncDeclarator SEMI                                   { $2->category = FunctionDeclaration;
                                                                    $$ = $2;
                                                                    addFirstChild($$, $1); }
        ;

FuncDeclarator:
        IDENTIFIER LPAR ParamList RPAR                             { $$ = newNode(Undefined, NULL);
                                                                    addChild($$, newNode(Identifier, $1));
                                                                    addChild($$, $3); }
        ;

ParamList:
        ParamList COMMA ParamDeclaration                           { addChild($$, $3); }
        | ParamDeclaration                                         { $$ = newNode(ParamList, NULL);
                                                                    addChild($$, $1); }
        ;

ParamDeclaration:
        Type IDENTIFIER                                            { $$ = newNode(ParamDeclaration, NULL);
                                                                    addChild($$, $1);
                                                                    addChild($$, newNode(Identifier, $2)); }
        | Type                                                     { $$ = newNode(ParamDeclaration, NULL);
                                                                    addChild($$, $1); }
        ;

Declaration:
        Type DeclaratorList SEMI                                   { $$ = $2; }
        | error SEMI                                               { $$ = newNode(Undefined, NULL); }
        ;

DeclaratorList:
        DeclaratorList COMMA Declarator                            { addChild($$, $3); }
        | Declarator                                               { $$ = newNode(Undefined, NULL);
                                                                    addChild($$, $1); }
        ;

Declarator:
        IDENTIFIER                                                 { $$ = newNode(Declaration, NULL);
                                                                    addChild($$, type); 
                                                                    addChild($$, newNode(Identifier, $1)); }
        | IDENTIFIER ASSIGN ExprList                               { $$ = newNode(Declaration, NULL);
                                                                    addChild($$, type); 
                                                                    addChild($$, newNode(Identifier, $1));
                                                                    addChild($$, $3); }
        ;

StatList:
        StatList StatError                                         { if($2) addChild($$, $2); }
        | StatError                                                { $$ = newNode(StatList, NULL);
                                                                    if($1) addChild($$, $1); }
        ;

StatError: Stat                                                    { $$ = $1; }              
        | error SEMI                                               { ; }
        ;

Stat:
        ExprList SEMI                                              { $$ = $1; }
        | LBRACE StatList RBRACE                                   { if($2->children->next && $2->children->next->next) $$ = $2;
                                                                    else if($2->children->next) $$ = $2->children->next->node; 
                                                                    else $$ = NULL;}
        | IF LPAR ExprList RPAR Stat %prec LOW                     { $$ = newNode(If, NULL);
                                                                    addChild($$, $3);
                                                                    if($5)addChild($$, $5);
                                                                    else addChild($$, newNode(Null, NULL));
                                                                    addChild($$, newNode(Null, NULL)); }
        | IF LPAR ExprList RPAR Stat ELSE Stat                     { $$ = newNode(If, NULL);
                                                                    addChild($$, $3);
                                                                    if($5)addChild($$, $5);
                                                                    else addChild($$, newNode(Null, NULL));
                                                                    if($7)addChild($$, $7);
                                                                    else addChild($$, newNode(Null, NULL)); }
        | WHILE LPAR ExprList RPAR Stat                            { $$ = newNode(While, NULL);
                                                                    addChild($$, $3);
                                                                    if($5) addChild($$, $5);
                                                                    else addChild($$, newNode(Null, NULL)); }
        | RETURN ExprList SEMI                                     { $$ = newNode(Return, NULL);
                                                                    addChild($$, $2); }
        | RETURN SEMI                                              { $$ = newNode(Return, NULL);
                                                                    addChild($$, newNode(Null, NULL)); }
        | LBRACE RBRACE                                            { $$ = NULL; }
        | SEMI                                                     { $$ = NULL; }
        | LBRACE error RBRACE                                      { ; }
        ;

ExprList:
        ExprList COMMA Expr                                        { $$ = newNode(Comma, NULL);
                                                                    addChild($$, $1);
                                                                    addChild($$, $3); }
        | Expr                                                     { $$ = $1; }
        ;

ExprCall:
        ExprCall COMMA Expr                                        { addChild($$, $3); }
        | Expr                                                     { $$ = newNode(Call, NULL); 
                                                                    addChild($$, $1);  }
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
        | Expr PLUS Expr                                           { $$ = newNode(Add, NULL); 
                                                                     addChild($$, $1);
                                                                     addChild($$, $3); }
        | Expr MINUS Expr                                          { $$ = newNode(Sub, NULL); 
                                                                     addChild($$, $1);
                                                                     addChild($$, $3); }
        | Expr MUL Expr                                            { $$ = newNode(Mul, NULL); 
                                                                     addChild($$, $1);
                                                                     addChild($$, $3); }
        | Expr DIV Expr                                            { $$ = newNode(Div, NULL); 
                                                                     addChild($$, $1);
                                                                     addChild($$, $3); }
        | Expr MOD Expr                                            { $$ = newNode(Mod, NULL); 
                                                                     addChild($$, $1);
                                                                     addChild($$, $3); }
        | MINUS Expr %prec NOT                                     { $$ = newNode(Minus, NULL); 
                                                                     addChild($$, $2); }
        | PLUS Expr %prec NOT                                      { $$ = newNode(Plus, NULL); 
                                                                     addChild($$, $2); }
        | NOT Expr                                                 { $$ = newNode(Not, NULL); 
                                                                     addChild($$, $2); }
        | IDENTIFIER LPAR ExprCall RPAR                            { $$ = $3;
                                                                    addFirstChild($$, newNode(Identifier, $1));}
        | IDENTIFIER LPAR RPAR                                     { $$ = newNode(Call, NULL); 
                                                                     addChild($$, newNode(Identifier, $1)); }
        | IDENTIFIER                                               { $$ = newNode(Identifier, $1); }
        | CHRLIT                                                   { $$ = newNode(ChrLit, $1); }
        | DECIMAL                                                  { $$ = newNode(Decimal, $1); }
        | NATURAL                                                  { $$ = newNode(Natural, $1); }
        | LPAR ExprList RPAR                                       { $$ = $2; }
        | IDENTIFIER LPAR error RPAR                               { ; }
        | LPAR error RPAR                                          { ; }
        ;
%%
  