#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

// create a node of a given category with a given lexical symbol
char *category_char[]={ "Program", "FuncDefinition", "FuncBody", "FuncDeclaration", "Call", "ParamList", "ParamDeclaration", "Declaration", "Identifier", "Store", "If", "While", "Return", "Add", "Sub", "Mul", "Div", "Mod", "Or", "And", "BitWiseOr", "BitWiseAnd", "BitWiseXor", "Plus", "Minus", "Not", "Eq", "Ne", "Le", "Ge", "Lt", "Gt", "Char", "Decimal", "Int", "Void", "Short", "Double", "Natural", "ChrLit", "Null", "StatList", "Comma"};

struct node *newnode(enum category category, char *token) {
    struct node *new = malloc(sizeof(struct node));
    if (new==NULL)
        return NULL;
    new->category = category;
    new->token = token;
    new->brother=NULL;
    new->child=NULL;
    return new;
}

// append a node to the list of children of the parent node
void addchild(struct node *parent, struct node *child) {
    if(parent->child==NULL){
        parent->child=child;
    }
    else{
        addBrother(parent->child, child);
    }

}

void addBrother(struct node *olderBrother, struct node *youngerBrother) {
    struct node *aux=olderBrother;
    while(aux->brother!=NULL){
        aux=aux->brother;
    }
    aux->brother=youngerBrother;
}


void show(struct node *n, int depth) {
    for (int i = 0; i < depth; i++) 
        printf("..");
            
    if(n->token != NULL)
        printf("%s(%s)",category_char[n->category],n->token);
    else 
        printf("%s",category_char[n->category]);
    printf("\n");
    
    if(n && n->child != NULL)
        show(n->child,depth+1);
    

    if (n && n->brother != NULL)
        show(n->brother,depth);
    
   
    if (n->token != NULL)
        free(n->token);
    if (n != NULL)
        free(n); 
}




