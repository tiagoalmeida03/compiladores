#ifndef _SEMANTICS_H
#define _SEMANTICS_H

#include "ast.h"

int check_program(struct node *program);

struct symbol_list {
	char *identifier;
	enum type type;
	struct node *node;
	struct symbol_list *next;
};

struct symbol_list *insert_symbol(struct symbol_list *symbol_table, char *identifier, enum type type, struct node *node);
struct symbol_list *search_symbol(struct symbol_list *symbol_table, char *identifier);
void show_symbol_table();
enum type check_expression(struct node *expression);
enum type get_variable_type(struct node *declaration);
void check_declaration(struct node *declaration);
struct node *find_enclosing_function(struct node *node);
enum type get_function_return_type(struct node *function);
struct node *find_enclosing_function(struct node *node);
enum type get_function_return_type(struct node *function);

#endif
