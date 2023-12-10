#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

// create a node of a given category with a given lexical symbol
char *category_char[]={ "Program", "FuncDefinition", "FuncBody", "FuncDeclaration", 
                        "Call", "ParamList", "ParamDeclaration", "Declaration", 
                        "Identifier", "Store", "If", "IfElse", "While", "Return", "Add", 
                        "Sub", "Mul", "Div", "Mod", "Or", "And", "BitWiseOr", "BitWiseAnd", 
                        "BitWiseXor", "Plus", "Minus", "Not", "Eq", "Ne", "Le", "Ge", 
                        "Lt", "Gt", "Char", "Decimal", "Int", "Void", "Short", "Double", 
                        "Natural", "ChrLit", "Null", "StatList", "Comma" };



struct node *newNode(enum category category, char *token) {
    struct node *new = malloc(sizeof(struct node));
    new->category = category;
    new->token = token;
    new->type = no_type;
    new->children = malloc(sizeof(struct node_list));
    new->children->node = NULL;
    new->children->next = NULL;
    return new;
}

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

void addChildren(struct node *parent, struct node *temporary){
  struct node_list* aux = temporary->children;
  while((aux=aux->next)){
    addChild(parent, aux->node);
  }
}

// get a pointer to a specific child, numbered 0, 1, 2, ...
struct node *getchild(struct node *parent, int position) {
    struct node_list *children = parent->children;
    while((children = children->next) != NULL)
        if(position-- == 0)
            return children->node;
    return NULL;
}

// category names #defined in ast.h
char *category_name[] = names;

void show(struct node *n, int level){
    for(int i = 0; i < level; i++) printf("..");
    if(n -> token)
	    printf("%s(%s)\n", category_char[n->category], n->token);
    else
	    printf("%s\n", category_char[n->category]);
    struct node_list *c = n->children;
    while((c = c->next)){
        show(c->node, level + 1);
    }
}