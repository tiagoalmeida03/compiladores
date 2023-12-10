#ifndef _AST_H
#define _AST_H

enum category { Program, FuncDefinition, FuncBody, FuncDeclaration, Call, 
                ParamList, ParamDeclaration, Declaration, Identifier, Store, 
                If, IfElse, While, Return, Add, Sub, Mul, Div, Mod, Or, And, BitWiseOr, 
                BitWiseAnd, BitWiseXor, Plus, Minus, Not, Eq, Ne, Le, Ge, Lt, 
                Gt, Char, Decimal, Int, Void, Short, Double, Natural, Chrlit, 
                Null, StatList, Comma, NullN };
#define names { "Program", "FuncDefinition", "FuncBody", "FuncDeclaration", "Call", "ParamList", "ParamDeclaration", "Declaration", "Identifier", "Store", "If", "IfElse", "While", "Return", "Add", "Sub", "Mul", "Div", "Mod", "Or", "And", "BitWiseOr", "BitWiseAnd", "BitWiseXor", "Plus", "Minus", "Not", "Eq", "Ne", "Le", "Ge", "Lt", "Gt", "Char", "Decimal", "Int", "Void", "Short", "Double", "Natural", "Chrlit", "Null", "StatList", "Comma", "NullN" };

enum type {integer_type, double_type, no_type};
#define type_name(type) (type == integer_type ? "integer" : (type == double_type ? "double" : "none"))
#define category_type(category) (category == Integer ? integer_type : (category == Double ? double_type : no_type))

struct node {
    enum category category;
    char *token;
    enum type type;
    struct node_list *children;
};

struct node_list {
    struct node *node;
    struct node_list *next;
};

struct node *newNode(enum category category, char *token);
void addChild(struct node *parent, struct node *child);
void addChildren(struct node *parent, struct node *children);
struct node *getchild(struct node *parent, int position);
void show(struct node *n, int level);
int yylex_destroy();

#endif