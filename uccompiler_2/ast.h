#ifndef _AST_H
#define _AST_H

enum category { Program, FunctionDeclaration, FunctionDefinition, ParamList, FuncBody,
                ParamDeclaration, Declaration, StatList, If, While, Return, Or,
                And, Eq, Ne, Lt, Gt, Le, Ge, Add, Sub, Mul, Div, Mod, Not, Minus,
                Plus, Store, Comma, Call, BitWiseAnd, BitWiseOr, BitWiseXor,
                Char, ChrLit, Identifier, Int, Short, Natural, Double, Decimal,
                Void, Null, Aux, Error
                };

struct node {
    enum category category;
    char *token;
    struct node_list *children;
};

struct node_list {
    struct node *node;
    struct node_list *next;
};

struct flagsT {
    int l;
    int t;
};

struct node *newNode(enum category category, char *token);
void addChild(struct node *parent, struct node *child);
void show(struct node *n, int level);
#endif
