#ifndef _SEMANTICS_H
#define _SEMANTICS_H

#include "ast.h"

int check_program(struct node *program);

// Linked function symbol structur
struct function{
	char *identifierf;
    struct symbol_list *symbol_table;
    enum type typef;
    enum type tparamf;
    struct function *next;
};

struct scoped_table_list {
	struct node *function;
	struct symbol_list *symbol_table;
	struct scoped_table_list *next;
};

// Global symbols structure
struct symbol_list {
    char *identifier;
    enum type type;
    enum type tparam;
    int defined;
    struct function *functionp; 
    struct node *node;
    struct symbol_list *next;
};

// Functions declarations
struct symbol_list *insert_symbol(struct symbol_list *symbol_table, char *identifier, enum type type, struct node *node);
struct symbol_list *search_symbol(struct symbol_list *symbol_table, char *identifier);
void check_expression(struct node *expression, struct symbol_list *symbol_table);
enum type get_variable_type(struct node *declaration);
void check_declaration(struct node *declaration);
struct node *find_enclosing_function(struct node *node);
enum type get_function_return_type(struct node *function);
struct node *find_enclosing_function(struct node *node);
enum type get_function_return_type(struct node *function);
void check_function(struct node *function);
void check_function_call(struct node *function_call);
void checkLocalDeclaration(struct node *declaration, struct symbol_list *symbol_table);
void checkParams(struct node *params, struct symbol_list *symbol_table);
void showSymbolTable();

#endif
