/*AUTORES*/
/*TIAGO NUNO M. C. L. DE ALMEIDA - 2021221615*/
/*JOÃO FILIPE GASPAR DOS SANTOS - 2021217215*/


digit   [0-9]
SEC \\(n|t|\\|\'|\"|[0-7]{1,3})
CHARACCEPT [^\'\n\r\\]|{SEC}
NL \n|\r|\r\n

%{
#include "y.tab.h"
#include "ast.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define YY_USER_ACTION { syn_line = line; syn_column = column; column += yyleng; }
#define PASS_TOKEN() yylval.lexeme = strdup(yytext);

extern int yyparse();

int un_line = 1, un_column = 1, line = 1, column = 1, syn_line = 1, syn_column = 1, errors = 0;
int myFlag = 0;

void report_error(char character, int line, int column) {
    printf("Line %d, column %d: unrecognized character (%c)\n", line, column, character);
}

void unt_comment(int line, int column) {
    printf("Line %d, column %d: unterminated comment\n", line, column);
}

void unt_char(int line, int column) {
    printf("Line %d, column %d: unterminated char constant\n", line, column);
}

void inv_char(int line, int column, char character) {
    printf("Line %d, column %d: invalid char constant (%c)\n", line, column, character);
}

extern struct node *program;

%}
%x COMMENT
%%

"char"                    { if(myFlag) printf("CHAR\n"); if(myFlag != 1) return CHAR; }
"if"                      { if(myFlag) printf("IF\n"); if(myFlag != 1) return IF; }
"else"                    { if(myFlag) printf("ELSE\n"); if(myFlag != 1) return ELSE; }
"while"                   { if(myFlag) printf("WHILE\n"); if(myFlag != 1) return WHILE; }
"int"                     { if(myFlag) printf("INT\n"); if(myFlag != 1) return INT; }
"short"                   { if(myFlag) printf("SHORT\n"); if(myFlag != 1) return SHORT; }
"double"                  { if(myFlag) printf("DOUBLE\n"); if(myFlag != 1) return DOUBLE; }
"return"                  { if(myFlag) printf("RETURN\n"); if(myFlag != 1) return RETURN; }
"void"                    { if(myFlag) printf("VOID\n"); if(myFlag != 1) return VOID; }
"&"                       { if(myFlag) printf("BITWISEAND\n"); if(myFlag != 1) return BITWISEAND; }
"|"                       { if(myFlag) printf("BITWISEOR\n"); if(myFlag != 1) return BITWISEOR; }
"^"                       { if(myFlag) printf("BITWISEXOR\n"); if(myFlag != 1) return BITWISEXOR; }
"&&"                      { if(myFlag) printf("AND\n"); if(myFlag != 1) return AND; }
"="                       { if(myFlag) printf("ASSIGN\n"); if(myFlag != 1) return ASSIGN; }
"*"                       { if(myFlag) printf("MUL\n"); if(myFlag != 1) return MUL; }
","                       { if(myFlag) printf("COMMA\n"); if(myFlag != 1) return COMMA; }
"/"                       { if(myFlag) printf("DIV\n"); if(myFlag != 1) return DIV; }
"=="                      { if(myFlag) printf("EQ\n"); if(myFlag != 1) return EQ; }
">="                      { if(myFlag) printf("GE\n"); if(myFlag != 1) return GE; }
">"                       { if(myFlag) printf("GT\n"); if(myFlag != 1) return GT; }
"{"                       { if(myFlag) printf("LBRACE\n"); if(myFlag != 1) return LBRACE; }
"<="                      { if(myFlag) printf("LE\n"); if(myFlag != 1) return LE; }
"("                       { if(myFlag) printf("LPAR\n"); if(myFlag != 1) return LPAR; }
"<"                       { if(myFlag) printf("LT\n"); if(myFlag != 1) return LT; }
"-"                       { if(myFlag) printf("MINUS\n"); if(myFlag != 1) return MINUS; }
"%"                       { if(myFlag) printf("MOD\n"); if(myFlag != 1) return MOD; }
"!="                      { if(myFlag) printf("NE\n"); if(myFlag != 1) return NE; }
"!"                       { if(myFlag) printf("NOT\n"); if(myFlag != 1) return NOT; }
"||"                      { if(myFlag) printf("OR\n"); if(myFlag != 1) return OR; }
"+"                       { if(myFlag) printf("PLUS\n"); if(myFlag != 1) return PLUS; }
"}"                       { if(myFlag) printf("RBRACE\n"); if(myFlag != 1) return RBRACE; }
")"                       { if(myFlag) printf("RPAR\n"); if(myFlag != 1) return RPAR; }
";"                       { if(myFlag) printf("SEMI\n"); if(myFlag != 1) return SEMI; }

    /* RESERVED WORDS */
auto|break|case|const|continue|inline|define|default|do|long|register|restrict|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|enum|extern|float|for|goto|_Packed|_Bool|_Complex|_Imaginary|"++"|"--"|\[|\] { if(myFlag) printf("RESERVED(%s)\n", yytext); PASS_TOKEN(); if(myFlag != 1) return RESERVED; }

    /* NATURAL, IDENTIFIER, DECIMAL AND CHRLIT*/
{digit}+                                                        { if(myFlag) printf("NATURAL(%s)\n", yytext); PASS_TOKEN(); if(myFlag != 1) return NATURAL; }
([a-z]|[A-Z]|"_")([a-z]|[A-Z]|[0-9]|"_")*                      { if(myFlag) printf("IDENTIFIER(%s)\n", yytext); PASS_TOKEN(); if(myFlag != 1) return IDENTIFIER; }
{digit}+\.{digit}*([Ee][+-]?{digit}+)? { 
    if(myFlag) printf("DECIMAL(%s)\n", yytext);
    PASS_TOKEN(); 
    if(myFlag != 1) return DECIMAL;
}
{digit}*\.{digit}+([Ee][+-]?{digit}+)? { 
    if(myFlag) printf("DECIMAL(%s)\n", yytext);
    PASS_TOKEN(); 
    if(myFlag != 1) return DECIMAL;
}
{digit}+[Ee][+-]?{digit}+ {
    if(myFlag) printf("DECIMAL(%s)\n", yytext);
    PASS_TOKEN(); 
    if(myFlag != 1) return DECIMAL;
}                    
\'({CHARACCEPT})\'                                            { if(myFlag) printf("CHRLIT(%s)\n", yytext); PASS_TOKEN(); if(myFlag != 1) return CHRLIT; }

    /* INVALID CHAR CONSTANTS */
'([^'\n\\]|(\\')|(\\[^'\n]))*'                                { inv_char(line, column-yyleng, yytext[0]); }

    /* UNTERMINATED CHAR CONSTANTS */
'([^'\n\\]|(\\')|(\\[^'\n]))*(\n|(\\\n))*                     { unt_char(line, column-yyleng); line+=1; column=1; syn_column=column; syn_line=line; }

    /* COMMENTS */
"//".*                      {;}
"/*"                        {BEGIN (COMMENT); un_column = column-yyleng; un_line = line; }
<COMMENT>.                  {;}
<COMMENT><<EOF>>            {unt_comment(un_line, un_column); BEGIN (INITIAL);}
<COMMENT>{NL}               {line++; column = 1; syn_column=column; syn_line=line; }
<COMMENT>"*/"               {BEGIN (INITIAL);}

    /* ILLEGAL CHARACTERS */
[\t|\r| ]	                            { syn_column = column; syn_line = line; }
\n	                                    { line += 1; column = 1; syn_line=line; syn_column=column; }
.                                       { report_error(yytext[0], line, column-yyleng); }

%%
extern int yylex();
int main(int argc, char **argv) {
    if(argc > 1){
        if(!strcmp(argv[1], "-l")){
            yylex();
            myFlag = 1;
        }else{
            yyparse(); 
            if(!strcmp(argv[1], "-t")){
                myFlag = 2;
            }
        }
    }else{
        yyparse();
    }
    return 0;
}

int yywrap() {
    return 1;
}

void yyerror(char *error) {
    errors++;
    printf("Line %d, column %d: %s: %s\n", syn_line, syn_column, error,  yytext);
}