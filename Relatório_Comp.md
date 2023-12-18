Projeto de Compiladores 2023-2024

Tiago Almeida - 2021221615
João Santos - 2021217215


# Topic (i) - REWRITTEN GRAMMAR

In our revised grammar, we used the "%nonassoc" directive to eliminate ambiguities in the "if-else" production. We defined priorities and associativities using the "%left", "%right", and "%nonassoc" directives for operators, establishing the order of evaluation and associativity to the right or left.

We leveraged the "%right NOT" directive to assign the correct priority to the "+" and "-" operators when used as signs, ensuring a proper evaluation of expressions.

Added Priorities:

* %left COMMA
* %right ASSIGN

* %left OR
* %left AND

* %left BITWISEOR
* %left BITWISEXOR

* %left BITWISEAND
* %left NE EQ

* %left GT GE LT LE
* %left PLUS MINUS

* %left MUL DIV MOD
* %right NOT

* %left RPAR LPAR
* %nonassoc LOW

* %nonassoc ELSE

GRAMMAR

We restructured the original statement grammar into a simplified Backus-Naur Form (BNF) grammar to represent and enhance the understanding of syntactic rules. We included a specific node called "Statement Error" to eliminate potential ambiguities arising from error productions, ensuring proper handling of unexpected situations.

We introduced two distinct nodes - one named "ExprList" and another "ExprCall" - to address the need to incorporate the "Comma" node in the Abstract Syntax Tree (AST) only when dealing with an ExprLIST expression.


FunctionsAndDeclarations:
        FunctionsAndDeclarations FunctionsDefinition
    | FunctionsAndDeclarations FunctionsDeclaration
    | FunctionsAndDeclarations Declaration
    | FunctionsDefinition
    | FunctionsDeclaration
    | Declaration

TypeSpec:
        CHAR
    | INT
    | DOUBLE
    | VOID
    | SHORT

FunctionsDefinition:
        TypeSpec FunctionsDeclarator FunctionsBody

FunctionsBody:
        LBRACE DeclarationsAndStatements RBRACE
    | LBRACE RBRACE

DeclarationsAndStatements:
        DeclarationsAndStatements Declaration
    | DeclarationsAndStatements Statement
    | Declaration
    | Statement

FunctionsDeclaration:
        TypeSpec FunctionsDeclarator SEMI

FunctionsDeclarator:
        IDENTIFIER LPAR ParamList RPAR

ParamList:
        ParamList COMMA ParamDeclaration
    | ParamDeclaration

ParamDeclaration:
        TypeSpec IDENTIFIER
    | TypeSpec

Declaration:
        TypeSpec DeclaratorList SEMI
    | error SEMI

DeclaratorList:
        DeclaratorList COMMA Declarator
    | Declarator

Declarator:
       IDENTIFIER
    | IDENTIFIER ASSIGN ExprList

StatementList:
        StatementList StatementError
    | StatementError

 StatementError: Statement
    | error SEMI

Statement:
        ExprListSEMI
    | LBRACE StatementList RBRACE
    | IF LPAR ExprList RPAR Statement %prec LOW
    | IF LPAR ExprList RPAR Statement ELSE Statement
    | WHILE LPAR ExprList RPAR Statement
    | RETURN ExprList SEMI
    | RETURN SEMI
    | SEMI
    | LBRACE error RBRACE
    | LBRACE RBRACE

ExprList:
        ExprList COMMA Expr
    | Expr

ExprCall:
        ExprCall COMMA Expr
    | Expr

Expr:

    Expr OR Expr
    | Expr AND Expr
    | Expr BITWISEOR Expr
    | Expr BITWISEXOR Expr
    | Expr BITWISEAND Expr
    | Expr EQ Expr
    | Expr NE Expr
    | Expr GT Expr
    | Expr GE Expr
    | Expr LT Expr

    | Expr LE Expr
    | Expr ASSIGN Expr
    | Expr MUL Expr
    | Expr MOD Expr
    | Expr DIV Expr
    | Expr PLUS Expr
    | Expr MINUS Expr

    | IDENTIFIER LPAR RPAR
    | MINUS Expr %prec NOT
    | PLUS Expr %prec NOT
    | NOT Expr
    | IDENTIFIER LPAR ExprCall RPAR
    | LPAR ExprList RPAR
    | IDENTIFIER
    | CHRLIT
    | DECIMAL

    | NATURAL
    | IDENTIFIER LPAR error RPAR
    | LPAR error RPAR

# Topic (ii) - Algorithms and AST Data Structures and Symbol Table

ASTree

This C code developed describes functions related to manipulating an Abstract Syntax Tree (AST). The `newNode` function is responsible for creating a new node in the AST by dynamically allocating memory for it and initializing its fields with a specific category and token. The `addChild` function adds a child node to a parent node in the AST, while `addChildren` adds all the children of a temporary node to a parent node.

The `get_parent` function determines the parent node of a specific node in the AST by performing a recursive search in the tree. Finally, `getchild` retrieves a pointer to a specific child of a node, numbered from 0, by traversing the list of children until the desired position is reached.

These functions are designed to facilitate the construction, modification, and navigation of an AST, providing an efficient approach for handling complex data structures commonly used in the syntactic analysis of programming languages.


Symbol Table

Unfortunately, we couldn't fully implement this goal due to a segmentation fault that caused a runtime error in Mooshak. However, due to our effort and the belief that, despite not scoring any points in goal 3 in Mooshak, our work was well-structured and had the necessary functionalities, we decided to include it in the final submission.
