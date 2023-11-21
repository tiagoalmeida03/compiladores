#ifndef _AST_H
#define _AST_H

enum category { Program, FuncDefinition, FuncBody, FuncDeclaration, Call, 
                ParamList, ParamDeclaration, Declaration, Identifier, Store, 
                If, While, Return, Add, Sub, Mul, Div, Mod, Or, And, BitWiseOr, 
                BitWiseAnd, BitWiseXor, Plus, Minus, Not, Eq, Ne, Le, Ge, Lt, 
                Gt, Char, Decimal, Int, Void, Short, Double, Natural, Chrlit, 
                Null, StatList, Comma};


typedef struct node {
    enum category category;
    char *token;
    struct node *child;
    struct node *brother;
} node;

struct node *newnode(enum category category, char *token);
void addchild(node *parent, node *child);
void addBrother(node *olderBrother,  node *youngerBrother);
void show(struct node *program, int depth);
int yylex_destroy();
#endif
