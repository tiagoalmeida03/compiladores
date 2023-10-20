/*AUTORES*/
/*TIAGO NUNO M. C. L. DE ALMEIDA - 2021221615*/
/*JOÃO FILIPE GASPAR DOS SANTOS - 2021217215*/


digit   [0-9]
SEC \\(n|t|\\|\'|\"|[0-7]{1,3})
CHARACCEPT [^\'\n\r\\]|{SEC}

%{
#include <ctype.h>

int line_num = 1, column_num = 1, un_line = 0, un_column = 0;


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

void und_comment(char character, int line, int column) {
    printf("Line %d, column %d: unterminated comment\n", line, column);
}

void unt_char(int line, int column) {
    printf("Line %d, column %d: unterminated char constant\n", line, column);
}

%}
%x COMMENT
%%

"char"                    { printf("CHAR\n"); count(yytext); }
"if"                      { printf("IF\n"); count(yytext); }
"else"                    { printf("ELSE\n"); count(yytext); }
"while"                   { printf("WHILE\n"); count(yytext); }
"int"                     { printf("INT\n"); count(yytext); }
"short"                   { printf("SHORT\n"); count(yytext); }
"double"                  { printf("DOUBLE\n"); count(yytext); }
"return"                  { printf("RETURN\n"); count(yytext); }
"void"                    { printf("VOID\n"); count(yytext); }
"&"                       { printf("BITWISEAND\n"); count(yytext); }
"|"                       { printf("BITWISEOR\n"); count(yytext); }
"^"                       { printf("BITWISEXOR\n"); count(yytext); }
"&&"                      { printf("AND\n"); count(yytext); }
"="                       { printf("ASSIGN\n"); count(yytext); }
"*"                       { printf("MUL\n"); count(yytext); }
","                       { printf("COMMA\n"); count(yytext); }
"/"                       { printf("DIV\n"); count(yytext); }
"=="                      { printf("EQ\n"); count(yytext); }
">="                      { printf("GE\n"); count(yytext); }
">"                       { printf("GT\n"); count(yytext); }
"{"                       { printf("LBRACE\n"); count(yytext); }
"<="                      { printf("LE\n"); count(yytext); }
"("                       { printf("LPAR\n"); count(yytext); }
"<"                       { printf("LT\n"); count(yytext); }
"-"                       { printf("MINUS\n"); count(yytext); }
"%"                       { printf("MOD\n"); count(yytext); }
"!="                      { printf("NE\n"); count(yytext); }
"!"                       { printf("NOT\n"); count(yytext); }
"||"                      { printf("OR\n"); count(yytext);}
"+"                       { printf("PLUS\n"); count(yytext); }
"}"                       { printf("RBRACE\n"); count(yytext); }
")"                       { printf("RPAR\n"); count(yytext); }
";"                       { printf("SEMI\n"); count(yytext); }

    /*RESERVED WORDS*/
auto|break|case|const|continue|inline|define|default|do|long|NULL|register|restrict|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|enum|extern|float|for|goto|_Packed|_Bool|_Complex|_Imaginary|"++"|"--"|\[|\] { count(yytext); printf("RESERVED(%s)\n", yytext); }

    /* NATURAL, IDENTIFIER, DECIMAL AND CHRLIT*/
{digit}+                                                        { printf("NATURAL(%s)\n", yytext); count(yytext); }
([a-z]|[A-Z]|"_")([a-z]|[A-Z]|[0-9]|"_")*		                { printf("IDENTIFIER(%s)\n", yytext); count(yytext); }
{digit}+\.{digit}*([Ee][+-]?{digit}+)? {
    printf("DECIMAL(%s)\n", yytext);
    count(yytext);
}
{digit}*\.{digit}+([Ee][+-]?{digit}+)? {
    printf("DECIMAL(%s)\n", yytext);
    count(yytext);
}
{digit}+[Ee][+-]?{digit}+ {
    printf("DECIMAL(%s)\n", yytext);
    count(yytext);
}                    
\'({CHARACCEPT})\'	                                            { printf("CHRLIT(%s)\n", yytext); count(yytext); }

    /* INVALID CHAR CONSTANTS */
'([^'\n\\]|(\\')|(\\[^'\n]))*'                                  { printf("Line %d, column %d: invalid char constant (%s)\n", line_num, column_num, yytext); count(yytext); }

    /* UNTERMINATED CHAR CONSTANTS */
'([^'\n\\]|(\\')|(\\[^'\n]))*(\n|(\\\n))                        { unt_char(line_num, column_num); count(yytext); }

    /* COMMENTS */
"//".*                      {count(yytext);}
"/*"                        {BEGIN COMMENT; un_line = line_num; un_column = column_num; column_num += yyleng;}
<COMMENT>"*/"               {BEGIN 0; count(yytext);}
<COMMENT>.                  {count(yytext);}
<COMMENT>\n                 {line_num++ ; column_num = 1;}
<COMMENT><<EOF>>            {und_comment(yytext[0], un_line, un_column); BEGIN 0;}

    /* ILLEGAL CHARACTERS */
[\t|\r| ]	                            { column_num += yyleng; }
\n	                                    { line_num += 1; column_num = 1; }
.                                       { report_error(yytext[0], line_num, column_num); count(yytext); }


%%
extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}