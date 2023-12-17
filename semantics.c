#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"

int semantic_errors = 0;
struct symbol_list *symbol_table;

void check_function(struct node *function) {
    struct node *id = getchild(function, 0);
    if (search_symbol(symbol_table, id->token) == NULL) {
        insert_symbol(symbol_table, id->token, no_type, function);
        
        // Additional checks for parameters
        struct node *params = getchild(function, 1);
        // Iterate through parameter list and perform necessary checks
        
        // Additional checks for expressions
        struct node *body = getchild(function, 2);
        check_expression(body);
    } else {
        printf("Identifier %s already declared\n", id->token);
        semantic_errors++;
    }
}

enum type get_variable_type(struct node *declaration) {
    struct node *typeNode = getchild(declaration, 0);
    // Determine the type based on the typeNode and return it
}

void check_declaration(struct node *declaration) {
    struct node *id = getchild(declaration, 1);
    if (search_symbol(symbol_table, id->token) == NULL) {
        enum type varType = get_variable_type(declaration);
        insert_symbol(symbol_table, id->token, varType, declaration);
    } else {
        printf("Identifier %s already declared\n", id->token);
        semantic_errors++;
    }
}

enum type check_expression(struct node *expression) {
    enum type resultType = no_type;
    // Perform type checking for the expression
    
    // Recursive traversal for subexpressions
    struct node_list *children = expression->children;
    while (children != NULL) {
        resultType = check_expression(children->node);
        children = children->next;
    }

    // Return the type of the expression or resultType
    return resultType;
}

void check_function_call(struct node *call) {
    struct node *id = getchild(call, 0);
    struct symbol_list *functionSymbol = search_symbol(symbol_table, id->token);
    if (functionSymbol == NULL) {
        printf("Unknown symbol %s\n", id->token);
        semantic_errors++;
        return;
    }

    // Additional checks for argument types and number of arguments
    struct node *args = getchild(call, 1);
    // Iterate through arguments and compare types with the function's parameter types
}


/*void check_return_statement(struct node *returnStmt) {
    if (returnStmt->children->node->category != Expr) {
        printf("Return statement must have an expression\n");
        semantic_errors++;
        return;
    }

    struct node *expr = getchild(returnStmt, 0);
    enum type returnType = check_expression(expr);

    // Compare returnType with the expected return type of the current function
    struct node *currentFunction = find_enclosing_function(returnStmt);
    enum type expectedReturnType = get_function_return_type(currentFunction);

    if (returnType != expectedReturnType) {
        printf("Return type mismatch. Expected: %s, Got: %s\n", type_name(expectedReturnType), type_name(returnType));
        semantic_errors++;
    }
}*/

void report_semantic_error(char *message, int line, int column) {
    printf("Line %d, column %d: %s\n", line, column, message);
    semantic_errors++;
}

struct node *find_enclosing_function(struct node *node) {
    // Traverse the AST upward to find the nearest function node
    while (node != NULL && node->category != FuncDefinition) {
        node = get_parent(node, node);
    }
    return node;
}

enum type get_function_return_type (struct node *function) {
    enum type Int, Double; // Define Int within the function
    Int = 0;
    Double = 1;
    // Assuming the function node has the expected structure
    struct node *returnTypeNode = getchild(function, 0); // Assuming the return type is the first child
    return category_type(returnTypeNode->category);
}


// semantic analysis begins here, with the AST root node
int check_program(struct node *program) {
    symbol_table = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    symbol_table->next = NULL;
    struct node_list *child = program->children;
    while((child = child->next) != NULL)
        check_function(child->node);
    return semantic_errors;
}

// insert a new symbol in the list, unless it is already there
struct symbol_list *insert_symbol(struct symbol_list *table, char *identifier, enum type type, struct node *node) {
    struct symbol_list *new = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    new->identifier = strdup(identifier);
    new->type = type;
    new->node = node;
    new->next = NULL;
    struct symbol_list *symbol = table;
    while(symbol != NULL) {
        if(symbol->next == NULL) {
            symbol->next = new;    /* insert new symbol at the tail of the list */
            break;
        } else if(strcmp(symbol->next->identifier, identifier) == 0) {
            free(new);
            return NULL;           /* return NULL if symbol is already inserted */
        }
        symbol = symbol->next;
    }
    return new;
}

// look up a symbol by its identifier
struct symbol_list *search_symbol(struct symbol_list *table, char *identifier) {
    struct symbol_list *symbol;
    for(symbol = table->next; symbol != NULL; symbol = symbol->next)
        if(strcmp(symbol->identifier, identifier) == 0)
            return symbol;
    return NULL;
}

void show_tables(){
    show_symbol_table();
    printf("\n");
    show_function_table();
}

void show_symbol_table() {
    struct symbol_list *symbol;
    printf("===== Global Symbol Table =====\n");
    for(symbol = symbol_table->next; symbol != NULL; symbol = symbol->next){
        printf("%s %s", symbol->identifier, (symbol->type));
        if (symbol->tparam != NULL)
            printf("(%s)\n", symbol->tparam);
        else
            printf("\n");
    }
    printf("\n");
}

void show_function_table(){
    struct symbol_list *symbol;
    for(symbol = symbol_table->next; symbol != NULL; symbol = symbol->next){
        //if symbol is declared
        printf("===== Function %s Symbol Table =====", symbol->identifier);
        for(symbol = symbol->function; symbol != NULL; symbol = symbol->next){
            printf("%s %s", symbol->identifier, (symbol->type));
            if (symbol->tparam != NULL)
                printf("(%s)\n", symbol->tparam);
            else
                printf("\n");
        }
    }
    printf("\n");
}
