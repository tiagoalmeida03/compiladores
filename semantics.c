#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ast.h"
#include "semantics.h"

int semantic_errors = 0;
struct symbol_list *symbol_table;
struct symbol_list *global_table;
struct scoped_table_list *local_table_list;

void check_function(struct node *scoped_table_list) {
    struct node *id = getchild(scoped_table_list, 0);
    struct symbol_list *symbol = search_symbol(global_table, id->token);

    if (symbol == NULL) {
        insert_symbol(global_table, id->token, no_type, scoped_table_list);

        // Additional checks for parameters
        struct node *params = getchild(scoped_table_list, 1);
        // Iterate through parameter list and perform necessary checks

        // Additional checks for expressions
        struct node *body = getchild(scoped_table_list, 2);
        check_expression(body, global_table);
    } else {
        printf("Identifier %s already declared\n", id->token);
        semantic_errors++;
    }
}

enum type get_variable_type(struct node *declaration) {
    struct node *typeNode = getchild(declaration, 0);
    // Determine the type based on the typeNode and return it
}

struct scoped_table_list *insert_symbol_list(struct node *scoped_table_list, struct symbol_list *symbol_table){
    struct scoped_table_list *new_list = malloc(sizeof(struct function));
    new_list->function = scoped_table_list;
    new_list->symbol_table = symbol_table;
    struct scoped_table_list *current = local_table_list;
    while(current != NULL) {
        if(current->next == NULL) {
            current->next = new_list;    /* insert new symbol at the tail of the list */
            break;
        }
        current = current->next;
    }
    return new_list;
}

void check_declaration(struct node *declaration) {
    struct node *id = getchild(declaration, 1);
    struct symbol_list *symbol = search_symbol(global_table, id->token);

    if (symbol == NULL) {
        enum type varType = get_variable_type(declaration);
        insert_symbol(global_table, id->token, varType, declaration);
    } else {
        printf("Identifier %s already declared\n", id->token);
        semantic_errors++;
    }
}

void check_function_call(struct node *call) {
    struct node *id = getchild(call, 0);
    struct symbol_list *functionSymbol = search_symbol(global_table, id->token);

    if (functionSymbol == NULL) {
        printf("Unknown symbol %s\n", id->token);
        semantic_errors++;
        return;
    }

    functionSymbol->defined = 1;

    // Additional checks for argument types and number of arguments
    struct node *args = getchild(call, 1);
    // Iterate through arguments and compare types with the function's parameter types
}

void check_return_statement(struct node *returnStmt) {
    if (returnStmt->children->node->category != Return) {
        printf("Return statement must have an expression\n");
        semantic_errors++;
        return;
    }

    struct node *expr = getchild(returnStmt, 0);
    check_expression(expr, global_table);
    enum type returnType = expr->type;

    // Compare returnType with the expected return type of the current function
    struct node *currentFunction = find_enclosing_function(returnStmt);
    enum type expectedReturnType = get_function_return_type(currentFunction);

    if (returnType != expectedReturnType) {
        printf("Return type mismatch. Expected: %s, Got: %s\n", type_name(expectedReturnType), type_name(returnType));
        semantic_errors++;
    }
}

enum type comparator(enum type type1, enum type type2, int operationCategory) {
    // Assuming type1 and type2 are valid types (e.g., int_type, double_type)

    if (type1 == type2) {
        // Types are the same
        return type1;
    } else if (operationCategory == 0) {
        // Binary operations (e.g., +, -, *, /)
        // Perform type coercion if possible
        if ((type1 == integer_type && type2 == double_type) || (type1 == double_type && type2 == integer_type)) {
            // Coerce to the wider type (double)
            return double_type;
        } else {
            // Incompatible types
            return undef_type;
        }
    } else if (operationCategory == 1) {
        // Logical operations (e.g., &&, ||, !)
        // Both operands must be of type int
        if (type1 == integer_type && type2 == integer_type) {
            return integer_type;
        } else {
            return undef_type;
        }
    } else if (operationCategory == 2) {
        // Comparison operations (e.g., ==, !=, <, >, <=, >=)
        // Result is always of type int
        return integer_type;
    } else if (operationCategory == 3) {
        // Assignment operation (e.g., =)
        // The result type is the type of the left-hand side
        return type1;
    }

    // Default case (should not be reached)
    return undef_type;
}

void handleBinaryOperation(struct node *expression, struct symbol_list *symbol_table, enum category opCategory) {
    check_expression(getchild(expression, 0), symbol_table);
    check_expression(getchild(expression, 1), symbol_table);

    expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 0);

    if (expression->type == undef_type) {
        printf("Error: Invalid operation\n");
    }
}

void handleUnaryOperation(struct node *expression, struct symbol_list *symbol_table, enum category opCategory, enum type expectedType) {
    check_expression(getchild(expression, 0), symbol_table);

    expression->type = comparator(getchild(expression, 0)->type, expectedType, 0);

    if (expression->type == undef_type) {
        printf("Error: Invalid operation\n");
    }
}

void check_expression(struct node *expression, struct symbol_list *symbol_table) {
    struct symbol_list *symbol = NULL;
    struct node_list *current = expression->children->next;

    switch (expression->category) {
        case Natural:
            expression->type = integer_type;
            break;
        case Chrlit:
            expression->type = integer_type;
            break;
        case Decimal:
            expression->type = double_type;
            break;
        case Null:
            expression->type = undef_type;
            break;
        case Add:
            check_expression(getchild(expression, 0), symbol_table);
            check_expression(getchild(expression, 1), symbol_table);
            expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 0);
            break;
        case Sub:
            check_expression(getchild(expression, 0), symbol_table);
            check_expression(getchild(expression, 1), symbol_table);
            expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 0);
            break;
        case Mul:
            check_expression(getchild(expression, 0), symbol_table);
            check_expression(getchild(expression, 1), symbol_table);
            expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 0);
            break;
        case Div:
            check_expression(getchild(expression, 0), symbol_table);
            check_expression(getchild(expression, 1), symbol_table);
            expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 0);
            break;
        case Mod:
            check_expression(getchild(expression, 0), symbol_table);
            check_expression(getchild(expression, 1), symbol_table);
            if(comparator(getchild(expression, 0)->type, integer_type, 1) == undef_type || comparator(getchild(expression, 1)->type, integer_type, 1) == undef_type){
                printf("Error: Invalid operation\n");
            }
            expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 0);
            break;
        case And:
            check_expression(getchild(expression, 0), symbol_table);
            check_expression(getchild(expression, 1), symbol_table);
            if(comparator(getchild(expression, 0)->type, integer_type, 1) == undef_type || comparator(getchild(expression, 1)->type, integer_type, 1) == undef_type){
                printf("Error: Invalid operation\n");
            }
            expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 0);
            break;
        case Or:
            check_expression(getchild(expression, 0), symbol_table);
            check_expression(getchild(expression, 1), symbol_table);
            if(comparator(getchild(expression, 0)->type, integer_type, 1) == undef_type || comparator(getchild(expression, 1)->type, integer_type, 1) == undef_type){
                printf("Error: Invalid operation\n");
            }
            expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 0);
            break;
        case BitWiseAnd:
            check_expression(getchild(expression, 0), symbol_table);
            check_expression(getchild(expression, 1), symbol_table);
            if(comparator(getchild(expression, 0)->type, integer_type, 1) == undef_type || comparator(getchild(expression, 1)->type, integer_type, 1) == undef_type){
                printf("Error: Invalid operation\n");
            }
            expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 0);
            break;
        case BitWiseOr:
            check_expression(getchild(expression, 0), symbol_table);
            check_expression(getchild(expression, 1), symbol_table);
            if(comparator(getchild(expression, 0)->type, integer_type, 1) == undef_type || comparator(getchild(expression, 1)->type, integer_type, 1) == undef_type){
                printf("Error: Invalid operation\n");
            }
            expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 0);
            break;
        case BitWiseXor:
            check_expression(getchild(expression, 0), symbol_table);
            check_expression(getchild(expression, 1), symbol_table);
            if(comparator(getchild(expression, 0)->type, integer_type, 1) == undef_type || comparator(getchild(expression, 1)->type, integer_type, 1) == undef_type){
                printf("Error: Invalid operation\n");
            }
            expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 0);
            break;
        case Eq:
            check_expression(getchild(expression, 0), symbol_table);
            check_expression(getchild(expression, 1), symbol_table);
            if(comparator(getchild(expression, 0)->type, integer_type, 1) == undef_type || comparator(getchild(expression, 1)->type, integer_type, 1) == undef_type){
                printf("Error: Invalid operation\n");
            }
            expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 0);
            break;
        case Ne:
            check_expression(getchild(expression, 0), symbol_table);
            check_expression(getchild(expression, 1), symbol_table);
            if(comparator(getchild(expression, 0)->type, integer_type, 1) == undef_type || comparator(getchild(expression, 1)->type, integer_type, 1) == undef_type){
                printf("Error: Invalid operation\n");
            }
            expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 0);
            break;
        case Lt:
            check_expression(getchild(expression, 0), symbol_table);
            check_expression(getchild(expression, 1), symbol_table);
            if(comparator(getchild(expression, 0)->type, integer_type, 1) == undef_type || comparator(getchild(expression, 1)->type, integer_type, 1) == undef_type){
                printf("Error: Invalid operation\n");
            }
            expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 0);
            break;
        case Gt:
            check_expression(getchild(expression, 0), symbol_table);
            check_expression(getchild(expression, 1), symbol_table);
            if(comparator(getchild(expression, 0)->type, integer_type, 1) == undef_type || comparator(getchild(expression, 1)->type, integer_type, 1) == undef_type){
                printf("Error: Invalid operation\n");
            }
            expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 1);
            break;
        case Le:
            check_expression(getchild(expression, 0), symbol_table);
            check_expression(getchild(expression, 1), symbol_table);
            if(comparator(getchild(expression, 0)->type, integer_type, 1) == undef_type || comparator(getchild(expression, 1)->type, integer_type, 1) == undef_type){
                printf("Error: Invalid operation\n");
            }
            expression->type = comparator(getchild(expression, 0)->type, getchild(expression, 1)->type, 1);
            break;
        case Ge:
            handleBinaryOperation(expression, symbol_table, expression->category);
            break;
        case Not:
            handleUnaryOperation(expression, symbol_table, expression->category, integer_type);
            break;
        case Plus:
        case Minus:
            handleBinaryOperation(expression, symbol_table, expression->category);
            break;
        case If:
            check_expression(getchild(expression, 0), symbol_table);
            if (comparator(getchild(expression, 0)->type, integer_type, 1) == undef_type) {
                printf("Error: Invalid operation\n");
            }
            check_expression(getchild(expression, 1), symbol_table);
            check_expression(getchild(expression, 2), symbol_table);
            break;
        case While:
            check_expression(getchild(expression, 0), symbol_table);
            if (comparator(getchild(expression, 0)->type, integer_type, 1) == undef_type) {
                printf("Error: Invalid operation\n");
            }
            check_expression(getchild(expression, 1), symbol_table);
            break;
        case Comma:
            handleBinaryOperation(expression, symbol_table, expression->category);
            break;
        case Store:
            handleBinaryOperation(expression, symbol_table, expression->category);
            break;
        case Identifier:
            // Handle identifier
            symbol = search_symbol(symbol_table, expression->token);
            if (symbol) {
                expression->type = symbol->type;
                return;
            }
            symbol = search_symbol(global_table, expression->token);
            if (symbol) {
                expression->type = symbol->type;
                return;
            }
            printf("Error: Undeclared variable %s\n", expression->token);
            expression->type = undef_type;
            break;
        case StatList:
            while (current != NULL) {
                check_expression(current->node, symbol_table);
                current = current->next;
            }
            break;
        case Return:
            symbol = search_symbol(symbol_table, "return");
            check_expression(getchild(expression, 0), symbol_table);
            if (comparator(getchild(expression, 0)->type, symbol->type, 1) == undef_type) {
                printf("Error: Invalid return type\n");
            }
            break;
        default:
            printf("Checking expression\n");
            break;
    }
}


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

void addPutcharGetchar(struct symbol_list *symbol_table){
    struct node *putchar = newNode(FuncDefinition, "putchar");
    addChild(putchar, newNode(Int, NULL));
    addChild(putchar, newNode(Identifier, "putchar"));
    addChild(putchar, newNode(ParamList, NULL));
    addChild(getchild(putchar, 2), newNode(ParamDeclaration, NULL));
    addChild(getchild(getchild(putchar, 2), 0), newNode(Int, NULL));
    insert_symbol(symbol_table, "putchar", integer_type, putchar);
    struct node *getchar = newNode(FuncDefinition, "getchar");
    addChild(getchar, newNode(Int, NULL));
    addChild(getchar, newNode(Identifier, "getchar"));
    addChild(getchar, newNode(ParamList, NULL));
    addChild(getchild(getchar, 2), newNode(ParamDeclaration, NULL));
    addChild(getchild(getchild(getchar, 2), 0), newNode(Void, NULL));
    insert_symbol(symbol_table, "getchar", integer_type, getchar);
}

void checkGlobalDeclaration(struct node *declaration){
    //! change this
    struct node *type = getchild(declaration, 0);
    struct node *identifier = getchild(declaration, 1);
    struct node *expression = getchild(declaration, 2);
    if (type->category == Void){
        printf("Error: Invalid type\n");
        return;
    }
    struct symbol_list *symbol = search_symbol(global_table, identifier->token);
    if (symbol != NULL && symbol->node->category == Declaration && symbol->type != category_type(type->category)){
        printf("Error: Redeclaration of variable %s\n", identifier->token);
        return;
    }
    insert_symbol(global_table, identifier->token, category_type(type->category), declaration);
    if(expression)
        check_expression(expression, global_table);
}

int checkProgram(struct node *program){
    global_table = malloc(sizeof(struct symbol_list));
    global_table->identifier = NULL;

    local_table_list = malloc(sizeof(struct function));
    local_table_list->function = NULL;
    local_table_list->symbol_table = NULL;
    local_table_list->next = NULL;

    struct node_list *current = program->children->next;
    addPutcharGetchar(global_table);
    while (current != NULL){
        if (current->node->category == Declaration){
            checkGlobalDeclaration(current->node);
        }else if (current->node->category == FuncDeclaration){
            //! MISSING REDECLARATION, VOID CHECK AND PARAM CHECK
            struct node *type = getchild(current->node, 0);
            struct node *identifier = getchild(current->node, 1);
            struct node *param_list = getchild(current->node, 2);
            struct symbol_list *symbol = search_symbol(global_table, identifier->token);
            struct symbol_list *local_table = malloc(sizeof(struct symbol_list));
            local_table->identifier = NULL;
            local_table->next = NULL;
            if (symbol != NULL && symbol->node->category == FuncDeclaration){
                printf("Error: Redeclaration of function %s\n", identifier->token);
                current = current->next;
                continue;
            }
            insert_symbol_list(current->node, local_table);
            insert_symbol(global_table, identifier->token, category_type(type->category), current->node);
        }else if (current->node->category == FuncDefinition){
            //! MISSING REDECLARATION, VOID CHECK AND PARAM CHECK
            struct node *type = getchild(current->node, 0);
            struct node *identifier = getchild(current->node, 1);
            struct node *param_list = getchild(current->node, 2);
            struct node *body = getchild(current->node, 3);
            struct symbol_list *symbol = search_symbol(global_table, identifier->token);
            struct symbol_list *local_table = malloc(sizeof(struct symbol_list));
            local_table->identifier = NULL;
            local_table->next = NULL;
            if (symbol != NULL && symbol->node->category == FuncDefinition){
                printf("Error: Redeclaration of function %s\n", identifier->token);
                current = current->next;
                continue;
            }
            insert_symbol(local_table, "return", category_type(type->category), current->node);
            checkParams(param_list, local_table);
            insert_symbol_list(current->node, local_table);
            insert_symbol(global_table, identifier->token, category_type(type->category), current->node);
            struct node_list *current_body = body->children->next;
            while(current_body != NULL){
                if (current_body->node->category == Declaration)
                    checkLocalDeclaration(current_body->node, local_table);
                else 
                    check_expression(current_body->node, local_table);
                current_body = current_body->next;
            }
        }
        current = current->next;
    }
    return 1;
}

void checkParams(struct node *params, struct symbol_list *symbol_table){
    struct node_list *current = params->children->next;
    while (current != NULL){
        struct node *type = getchild(current->node, 0);
        struct node *identifier = getchild(current->node, 1);
        if(identifier){
            insert_symbol(symbol_table, identifier->token, category_type(type->category), current->node);
        }
        current = current->next;
    }
}

void checkLocalDeclaration(struct node *declaration, struct symbol_list *symbol_table){
    struct node *type = getchild(declaration, 0);
    struct node *identifier = getchild(declaration, 1);
    struct node *expression = getchild(declaration, 2);
    if (type->category == Void){
        printf("Error: Invalid type\n");
        return;
    }
    struct symbol_list *symbol = search_symbol(symbol_table, identifier->token);
    if (symbol != NULL && symbol->node->category == Declaration && symbol->type != category_type(type->category)){
        printf("Error: Redeclaration of variable %s\n", identifier->token);
        return;
    }
    insert_symbol(symbol_table, identifier->token, category_type(type->category), declaration);
    if(expression)
        check_expression(expression, global_table);
}


void showSymbolTable() {
    // Global symbol table
    printf("===== Global Symbol Table =====\n");
    struct symbol_list *current = global_table->next;
    while (current != NULL) {
        printf("%s\t%s", current->identifier, type_name(current->type));
        if (current->node->category == ParamDeclaration)
            printf("\tparam");
        else if (current->node->category == FuncDefinition || current->node->category == FuncDeclaration) {
            struct node_list *param_list = getchild(current->node, 2)->children->next;
            printf("(");
            while (param_list != NULL) {
                printf("%s", type_name(category_type(getchild(param_list->node, 0)->category)));
                param_list = param_list->next;
                if (param_list != NULL)
                    printf(",");
            }
            printf(")");
        }

        printf("\n");
        current = current->next;
    }
    printf("\n");

    // Local symbol tables
    struct scoped_table_list *current_local = local_table_list->next;
    while (current_local != NULL) {
        if (current_local->function->category == FuncDefinition) {
            printf("===== Function %s Symbol Table =====\n", getchild(current_local->function, 1)->token);
            current = current_local->symbol_table->next;
            while (current != NULL) {
                printf("%s\t%s", current->identifier, type_name(current->type));
                if (current->node->category == ParamDeclaration)
                    printf("\tparam");
                printf("\n");
                current = current->next;
            }
            printf("\n");
        }
        current_local = current_local->next;
    }
}
