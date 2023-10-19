digit   [0-9]

%{
#include <ctype.h>

char * toUPPER(char * text){
    for(int i = 0; text[i]; i++){
	text[i] = toupper(text[i]);	
    }	
    return text;
}

int line_num = 1, column_num = 1, un_line = 0, un_column = 0;


void count(char * text){
    for(int i = 0; text[i]; i++){	
	if(text[i] == '\n'){
	    line_num++;
	    column_num = 0;
	}
    	else{ column_num++; }
    }
}

void report_error(char character, int line, int column) {
    printf("Line %d, column %d: unrecognized character (%c)\n", line, column, character);
}

void invalid_char(str character, int line, int column) {
    printf("Line %d, column %d: invalid char constant (%s)\n", line, column, character);  /*erro a imprimir a str*/
}

void und_comment(char character, int line, int column) {
    printf("Line %d, column %d: unterminated comment\n", line, column);
}

void und_char(char character, int line, int column) {
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
{digit}+                                                        { count(yytext); printf("NATURAL(%s)\n", yytext); }
([a-z]|[A-Z]|"_")([a-z]|[A-Z]|[0-9]|"_")*		                { count(yytext); printf("IDENTIFIER(%s)\n", yytext); }
({digit}"."{digit}([Ee][\+\-]?{digit})?)|{digit}[Ee][\+\-]?{digit}|{digit}"."|"."{digit}([Ee][\+\-]?{digit})?|{digit}"."([Ee][\+\-]?{digit})             { count(yytext); printf("DECIMAL(%s)\n", yytext); }
\'([^\n\'\\]|\\[0-7]{1,3}|\\n|\\t|\\\\|\\'|\\\")\'	            { count(yytext); printf("CHRLIT(%s)\n", yytext); }



    /* INVALID CHAR CONSTANTS */
'([^'\n\\]|(\\')|(\\[^'\n]))*'                                      { count(yytext); und_char(yytext[0], line_num, column_num); }

    /* UNTERMINATED CHAR CONSTANTS */
'([^'\n\\]|(\\')|(\\[^'\n]))*(\n|(\\\n))                       { count(yytext); invalid_char(yytext[:], line_num, column_num); }

    /* COMMENTS */
"//".*                      {count(yytext);}
"/*"                        {BEGIN COMMENT; un_line = line_num; un_column = column_num; column_num += yyleng;}
<COMMENT>"*/"               {BEGIN 0; count(yytext);}
<COMMENT>.                  {count(yytext);}
<COMMENT>\n                 {line_num++ ; column_num = 1;}
<COMMENT><<EOF>>            {und_comment(yytext[0], un_line, un_column); BEGIN 0;}

    /* ILLEGAL CHARACTERS */
[\t|\r| ]	                            {column_num += yyleng;}
\n	                                    {line_num += 1; column_num = 1;}
.                                       { count(yytext); report_error(yytext[0], line_num, column_num); }

%%
extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}