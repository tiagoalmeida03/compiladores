#ifndef _AST_H
#define _AST_H

enum category { Program, FuncDefinition, FuncBody, FuncDeclaration, Call, 
                ParamList, ParamDeclaration, Declaration, Identifier, Store, 
                If, While, Return, Add, Sub, Mul, Div, Mod, Or, And, BitWiseOr, 
                BitWiseAnd, BitWiseXor, Plus, Minus, Not, Eq, Ne, Le, Ge, Lt, 
                Gt, Char, Decimal, Int, Void, Short, Double, Natural, Chrlit, 
                Null, StatList, Comma, NullN, FuncDeclrator };



struct node {
    enum category category;
    char *token;
    struct node_list *children;
};

struct node_list {
    struct node *node;
    struct node_list *next;
};

struct node *newNode(enum category category, char *token);
void addChild(struct node *parent, struct node *child);
void addChildren(struct node *parent, struct node *children);
void show(struct node *n, int level);
int yylex_destroy();

#endif