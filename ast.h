#ifndef _AST_H
#define _AST_H

enum category { Program, FuncDefinition, FuncBody, FuncDeclaration, Call, \
                ParamList, ParamDeclaration, Declaration, Identifier, Store, \
                If, IfElse, While, Return, Add, Sub, Mul, Div, Mod, Or, And, BitWiseOr, \
                BitWiseAnd, BitWiseXor, Plus, Minus, Not, Eq, Ne, Le, Ge, Lt, \
                Gt, Char, Decimal, Int, Void, Short, Double, Natural, Chrlit, \
                Null, StatList, Comma, Undef, NullN };

enum type { \
    integer_type, \
    double_type, \
    char_type, \
    undef_type, \
    void_type, \
    no_type, \
};

#define names { "Program", "FuncDefinition", "FuncBody", "FuncDeclaration", "Call", \
                "ParamList", "ParamDeclaration", "Declaration", "Identifier", "Store", \
                "If", "IfElse", "While", "Return", "Add", "Sub", "Mul", "Div", "Mod", \
                "Or", "And", "BitWiseOr", "BitWiseAnd", "BitWiseXor", "Plus", "Minus", \
                "Not", "Eq", "Ne", "Le", "Ge", "Lt", "Gt", "Char", "Decimal", "Int", \
                "Void", "Short", "Double", "Natural", "Chrlit", "Null", "StatList", "Comma", "NullN" };

#define category_type(category) \
    (category == Int ? integer_type : \
     (category == Double ? double_type : \
      (category == Char ? char_type : \
       (category == Undef ? undef_type : \
         category == Void ? void_type : \
          no_type))))

struct node *get_parent(struct node *root, struct node *child);
struct node *getchild(struct node *parent, int position);
enum type get_function_return_type(struct node *function);
int yylex_destroy();

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
enum type type_name(char *type);
int yylex_destroy();

#endif