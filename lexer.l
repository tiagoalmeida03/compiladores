                    /* Authors: */
/* TIAGO NUNO MATOS CABO LOPES DE ALMEIDA - 2021221615 */
    /* JOÃO FILIPE GASPAR DOS SANTOS - 2021217215*/

digit   [0-9]

%{
#include <ctype.h>
#include <stdbool.h>
#include "structures.h"
#include "semantics.h"
#include "gen_code.h"
#include "functions.h"
#include "symbol_table.h"
#include "y.tab.h"

%%
char                    {if(l) printf("CHAR\n"); column += yyleng; if( !l && !e1 ) if( !l && !e1 ) return CHAR;}
if                      {if(l) printf("IF\n"); column += yyleng; if( !l && !e1 ) return IF;}
else                    {if(l) printf("ELSE\n"); column += yyleng; if( !l && !e1 ) return ELSE;}
while                   {if(l) printf("WHILE\n"); column += yyleng; if( !l && !e1 ) return WHILE;}
int                     {if(l) printf("INT\n"); column += yyleng; if( !l && !e1 ) return INT;}
short                   {if(l) printf("SHORT\n"); column += yyleng; if( !l && !e1 ) return SHORT;}
double                  {if(l) printf("DOUBLE\n"); column += yyleng; if( !l && !e1 ) return DOUBLE;}
return                  {if(l) printf("RETURN\n"); column += yyleng; if( !l && !e1 ) return RETURN;}
void                    {if(l) printf("VOID\n"); column += yyleng; if( !l && !e1 ) return VOID;}
\&                       {if(l) printf("BITWISEAND\n"); column += yyleng; if( !l && !e1 ) return BITWISEAND;}
\|                      {if(l) printf("BITWISEOR\n"); column += yyleng; if( !l && !e1 ) return BITWISEOR;}
\^                      {if(l) printf("BITWISEXOR\n"); column += yyleng; if( !l && !e1 ) return BITWISEXOR;}
\&\&                      {if(l) printf("AND\n"); column += yyleng; if( !l && !e1 ) return AND;}
\=                       {if(l) printf("ASSIGN\n"); column += yyleng; if( !l && !e1 ) return ASSIGN;}
\*                      {if(l) printf("MUL\n"); column += yyleng; if( !l && !e1 ) return MUL;}
\,                       {if(l) printf("COMMA\n"); column += yyleng; if( !l && !e1 ) return COMMA;}
\/                      {if(l) printf("DIV\n"); column += yyleng; if( !l && !e1 ) return DIV;}
\=\=                      {if(l) printf("EQ\n"); column += yyleng; if( !l && !e1 ) return EQ;}
\>\=                      {if(l) printf("GE\n"); column += yyleng; if( !l && !e1 ) return GE;}
\>                       {if(l) printf("GT\n"); column += yyleng; if( !l && !e1 ) return GT;}
\{                      {if(l) printf("LBRACE\n"); column += yyleng; if( !l && !e1 ) return LBRACE;}
\<=                     {if(l) printf("LE\n"); column += yyleng; if( !l && !e1 ) return LE;}
\(                      {if(l) printf("LPAR\n"); column += yyleng; if( !l && !e1 ) return LPAR;}
\<                      {if(l) printf("LT\n"); column += yyleng; if( !l && !e1 ) return LT;}
\-                      {if(l) printf("MINUS\n"); column += yyleng; if( !l && !e1 ) return MINUS;}
\%                       {if(l) printf("MOD\n"); column += yyleng; if( !l && !e1 ) return MOD;}
\!\=                      {if(l) printf("NE\n"); column += yyleng; if( !l && !e1 ) return NE;}
\!                       {if(l) printf("NOT\n"); column += yyleng; if( !l && !e1 ) return NOT;}
\|\|                    {if(l) printf("OR\n"); column += yyleng; if( !l && !e1 ) return OR;}
\+                      {if(l) printf("PLUS\n"); column += yyleng; if( !l && !e1 ) return PLUS;}
\}                      {if(l) printf("RBRACE\n"); column += yyleng; if( !l && !e1 ) return RBRACE;}
\)                      {if(l) printf("RPAR\n"); column += yyleng; if( !l && !e1 ) return RPAR;}
\;                      {if(l) printf("SEMI\n"); column += yyleng; if( !l && !e1 ) return SEMI;}

    /*RESERVED WORDS*/
auto|break|case|const|continue|inline|define|default|do|long|NULL|register|restrict|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|enum|extern|float|for|goto|_Packed|_Bool|_Complex|_Imaginary|"++"|"--"|\[|\] {if(l) printf("RESERVED(%s)\n", yytext); column += yyleng; if( !l && !e1 ) return RESERVED;}



char * toUPPER(char * text){
    for(int i = 0; text[i]; i++){
	text[i] = toupper(text[i]);	
    }	
    return text;
}

int line_num = 0;
int column_num = 0;

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

%}

%%
{digit}+                { count(yytext); printf("NATURAL(%s)\n", yytext); }
{digit}*"."{digit}+     { count(yytext); printf("DECIMAL(%s)\n", yytext); }

{reserved}+		{ count(yytext); char* upper = toUPPER(yytext); printf("%s\n", upper); }

[ \n\t]			{ count(yytext); ;}

[-()=,*/+]		{ count(yytext); printf("%s\n", yytext); }

[a-zA-Z]+[a-zA-Z0-9]*	{ count(yytext); printf("IDENTIFIER(%s)\n", yytext); }


.                       { count(yytext); report_error(yytext[0], line_num, column_num); }

%%
extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}
