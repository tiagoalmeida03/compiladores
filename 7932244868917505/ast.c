#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

char* category_names[] = categories;

   struct node *newNode(enum category category, char *token) {
    struct node *new = malloc(sizeof(struct node));
    new->category = category;
    new->token = token;
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

void addFirstChild(struct node *parent, struct node *child) {
    struct node_list *new = malloc(sizeof(struct node_list));
    new->node = child;
    new->next = parent->children->next;
    parent->children->next = new;
}

void show(struct node *n, int level){
    for(int i = 0; i < level; i++) printf("..");
    if(n -> token)
	    printf("%s(%s)\n", category_names[n->category], n->token);
    else
	    printf("%s\n", category_names[n->category]);
    struct node_list *c = n->children;
    while((c = c->next)){
        show(c->node, level + 1);
    }
}
