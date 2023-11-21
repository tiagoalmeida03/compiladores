#ifndef _AST_H
#define _AST_H

#define categories { "Program", "FuncDeclaration", "FuncDefinition", "ParamList", "FuncBody", "ParamDeclaration", "Declaration", "StatList", "If", "While", "Return", "Or", "And", "Eq", "Ne", "Lt", "Gt", "Le", "Ge", "Add", "Sub", "Mul", "Div", "Mod", "Not", "Minus", "Plus", "Store", "Comma", "Call", "BitWiseAnd", "BitWiseOr", "BitWiseXor", "Char", "ChrLit", "Identifier", "Int", "Short", "Natural", "Double", "Decimal", "Void", "Null", "Undefined"};

enum category { Program, FunctionDeclaration, FunctionDefinition, ParamList, FuncBody,
                ParamDeclaration, Declaration, StatList, If, While, Return, Or,
                And, Eq, Ne, Lt, Gt, Le, Ge, Add, Sub, Mul, Div, Mod, Not, Minus,
                Plus, Store, Comma, Call, BitWiseAnd, BitWiseOr, BitWiseXor,
                Char, ChrLit, Identifier, Int, Short, Natural, Double, Decimal,
                Void, Null, Undefined
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

struct node *newNode(enum category category, char *token);
void addChild(struct node *parent, struct node *child);
void addFirstChild(struct node *parent, struct node *child);
void show(struct node *n, int level);
#endif
