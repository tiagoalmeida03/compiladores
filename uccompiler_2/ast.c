#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#define categories { "Program", "FuncDeclaration", "FuncDefinition", "ParamList", "FuncBody", "ParamDeclaration", "Declaration", "StatList", "If", "While", "Return", "Or", "And", "Eq", "Ne", "Lt", "Gt", "Le", "Ge", "Add", "Sub", "Mul", "Div", "Mod", "Not", "Minus", "Plus", "Store", "Comma", "Call", "BitWiseAnd", "BitWiseOr", "BitWiseXor", "Char", "ChrLit", "Identifier", "Int", "Short", "Natural", "Double", "Decimal", "Void", "Null"};

// create a node of a given category with a given lexical symbol
struct node *newNode(enum category category, char *token) {
    struct node *new = malloc(sizeof(struct node));
    new->category = category;
    new->token = token;
    new->children = malloc(sizeof(struct node_list));
    new->children->node = NULL;
    new->children->next = NULL;
    return new;
}

// append a node to the list of children of the parent node
void addChild(struct node *parent, struct node *child) {
    struct node_list *new = malloc(sizeof(struct node_list));
    new->node = child;
    new->next = NULL;
    struct node_list *children = parent->children;
    while(children->next != NULL){
        children = children->next;
    }
    children->next = new;
}

// // print the tree in a depth-first manner
// void show(struct node *n, int level){
//     // if(n->category == Error) return; //ignore error nodes
//     for(int i = 0; i < level; i++) printf("..");
//     if(n -> token)
// 	    printf("%s(%s)\n", categories[n->category], n->token);
//     else
// 	    printf("%s\n", categories[n->category]);
//     struct node_list *c = n->children;
//     while(c->node != NULL){
//         show(c->node, level + 1);
//         if(c->next == NULL) return;
//         c = c->next;
//     }
// }
