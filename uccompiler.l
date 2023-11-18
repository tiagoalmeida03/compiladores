/*AUTORES*/
/*TIAGO NUNO M. C. L. DE ALMEIDA - 2021221615*/
/*JOÃO FILIPE GASPAR DOS SANTOS - 2021217215*/


digit   [0-9]
SEC \\(n|t|\\|\'|\"|[0-7]{1,3})
CHARACCEPT [^\'\n\r\\]|{SEC}
NL \n|\r|\r\n

%{
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

int line_num = 1, column_num = 1, un_line = 0, un_column = 0;
bool myFlag = false;

void count(char * text){
    for(int i = 0; text[i]; i++){	
	if(text[i] == '\n'){
	    line_num++;
	    column_num = 1;
	}
    	else{ column_num++; }
    }
}

void report_error(char character, int line, int column) {
    printf("Line %d, column %d: unrecognized character (%c)\n", line, column, character);
}

void unt_comment(int line, int column) {
    printf("Line %d, column %d: unterminated comment\n", line, column);
}

void unt_char(int line, int column) {
    printf("Line %d, column %d: unterminated char constant\n", line, column);
}

%}
%x COMMENT
%%

"char"                    { if(myFlag) printf("CHAR\n"); count(yytext); }
"if"                      { if(myFlag) printf("IF\n"); count(yytext); }
"else"                    { if(myFlag) printf("ELSE\n"); count(yytext); }
"while"                   { if(myFlag) printf("WHILE\n"); count(yytext); }
"int"                     { if(myFlag) printf("INT\n"); count(yytext); }
"short"                   { if(myFlag) printf("SHORT\n"); count(yytext); }
"double"                  { if(myFlag) printf("DOUBLE\n"); count(yytext); }
"return"                  { if(myFlag) printf("RETURN\n"); count(yytext); }
"void"                    { if(myFlag) printf("VOID\n"); count(yytext); }
"&"                       { if(myFlag) printf("BITWISEAND\n"); count(yytext); }
"|"                       { if(myFlag) printf("BITWISEOR\n"); count(yytext); }
"^"                       { if(myFlag) printf("BITWISEXOR\n"); count(yytext); }
"&&"                      { if(myFlag) printf("AND\n"); count(yytext); }
"="                       { if(myFlag) printf("ASSIGN\n"); count(yytext); }
"*"                       { if(myFlag) printf("MUL\n"); count(yytext); }
","                       { if(myFlag) printf("COMMA\n"); count(yytext); }
"/"                       { if(myFlag) printf("DIV\n"); count(yytext); }
"=="                      { if(myFlag) printf("EQ\n"); count(yytext); }
">="                      { if(myFlag) printf("GE\n"); count(yytext); }
">"                       { if(myFlag) printf("GT\n"); count(yytext); }
"{"                       { if(myFlag) printf("LBRACE\n"); count(yytext); }
"<="                      { if(myFlag) printf("LE\n"); count(yytext); }
"("                       { if(myFlag) printf("LPAR\n"); count(yytext); }
"<"                       { if(myFlag) printf("LT\n"); count(yytext); }
"-"                       { if(myFlag) printf("MINUS\n"); count(yytext); }
"%"                       { if(myFlag) printf("MOD\n"); count(yytext); }
"!="                      { if(myFlag) printf("NE\n"); count(yytext); }
"!"                       { if(myFlag) printf("NOT\n"); count(yytext); }
"||"                      { if(myFlag) printf("OR\n"); count(yytext);}
"+"                       { if(myFlag) printf("PLUS\n"); count(yytext); }
"}"                       { if(myFlag) printf("RBRACE\n"); count(yytext); }
")"                       { if(myFlag) printf("RPAR\n"); count(yytext); }
";"                       { if(myFlag) printf("SEMI\n"); count(yytext); }

    /*RESERVED WORDS*/
auto|break|case|const|continue|inline|define|default|do|long|NULL|register|restrict|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|enum|extern|float|for|goto|_Packed|_Bool|_Complex|_Imaginary|"++"|"--"|\[|\] { if(myFlag) printf("RESERVED(%s)\n", yytext); count(yytext); }

    /* NATURAL, IDENTIFIER, DECIMAL AND CHRLIT*/
{digit}+                                                        { if(myFlag) printf("NATURAL(%s)\n", yytext); count(yytext); }
([a-z]|[A-Z]|"_")([a-z]|[A-Z]|[0-9]|"_")*		                { if(myFlag) printf("IDENTIFIER(%s)\n", yytext); count(yytext); }
{digit}+\.{digit}*([Ee][+-]?{digit}+)? { 
    if(myFlag) printf("DECIMAL(%s)\n", yytext);
    count(yytext);
}
{digit}*\.{digit}+([Ee][+-]?{digit}+)? { 
    if(myFlag) printf("DECIMAL(%s)\n", yytext);
    count(yytext);
}
{digit}+[Ee][+-]?{digit}+ {
    if(myFlag) printf("DECIMAL(%s)\n", yytext);
    count(yytext);
}                    
\'({CHARACCEPT})\'	                                            { if(myFlag) printf("CHRLIT(%s)\n", yytext); count(yytext); }

    /* INVALID CHAR CONSTANTS */
'([^'\n\\]|(\\')|(\\[^'\n]))*'                                  { printf("Line %d, column %d: invalid char constant (%s)\n", line_num, column_num, yytext); count(yytext); }

    /* UNTERMINATED CHAR CONSTANTS */
'([^'\n\\]|(\\')|(\\[^'\n]))*(\n|(\\\n))*                       { unt_char(line_num, column_num); count(yytext); }

    /* COMMENTS */
"//".*                      {column_num += yyleng;}
"/*"                        {BEGIN (COMMENT); un_column = column_num; un_line = line_num; un_column += yyleng;}
<COMMENT>.                  {un_column += yyleng;}
<COMMENT><<EOF>>            {unt_comment(line_num, column_num); BEGIN (INITIAL);}
<COMMENT>{NL}               {un_line++ ; un_column = 1;}
<COMMENT>"*/"               {column_num = un_column; line_num = un_line; column_num += yyleng; BEGIN (INITIAL);}

    /* ILLEGAL CHARACTERS */
[\t|\r| ]	                            { column_num += yyleng; }
\n	                                    { line_num += 1; column_num = 1; }
.                                       { report_error(yytext[0], line_num, column_num); count(yytext); }


%%
extern int yylex();
int main(int argc, char **argv) {
    if(argc > 1 && argv[1][0] == '-' && argv[1][1] == 'l') myFlag = true;
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}