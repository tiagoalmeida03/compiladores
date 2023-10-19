digit   [0-9]
reserved integer|double|if|then|else

%{
#include <ctype.h>

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

char                    { count(yytext); printf("CHAR(%s)\n", yytext); }
if                      { count(yytext); printf("IF(%s)\n", yytext); }
else                    { count(yytext); printf("ELSE(%s)\n", yytext); }
while                   { count(yytext); printf("WHILE(%s)\n", yytext); }
int                     { count(yytext); printf("INT(%s)\n", yytext); }
short                   { count(yytext); printf("SHORT(%s)\n", yytext); }
double                  { count(yytext); printf("DOUBLE(%s)\n", yytext); }
return                  { count(yytext); printf("RETURN(%s)\n", yytext); }
void                    { count(yytext); printf("VOID(%s)\n", yytext); }
\&                      { count(yytext); printf("BITWISEAND(%s)\n", yytext); }
\|                      { count(yytext); printf("BITWISEOR(%s)\n", yytext); }
\^                      { count(yytext); printf("BITWISEXOR(%s)\n", yytext); }
\&\&                    { count(yytext); printf("AND(%s)\n", yytext); }
\=                      { count(yytext); printf("ASSIGN(%s)\n", yytext); }
\*                      { count(yytext); printf("MUL(%s)\n", yytext); }
\,                      { count(yytext); printf("COMMA(%s)\n", yytext); }
\/                      { count(yytext); printf("DIV(%s)\n", yytext); }
\=\=                    { count(yytext); printf("EQ(%s)\n", yytext); }
\>\=                    { count(yytext); printf("GE(%s)\n", yytext); }
\>                      { count(yytext); printf("GT(%s)\n", yytext); }
\{                      { count(yytext); printf("LBRACE(%s)\n", yytext); }
\<=                     { count(yytext); printf("LE(%s)\n", yytext); }
\(                      { count(yytext); printf("LPAR(%s)\n", yytext); }
\<                      { count(yytext); printf("LT(%s)\n", yytext); }
\-                      { count(yytext); printf("MINUS(%s)\n", yytext); }
\%                      { count(yytext); printf("MOD(%s)\n", yytext); }
\!\=                    { count(yytext); printf("NE(%s)\n", yytext); }
\!                      { count(yytext); printf("NOT(%s)\n", yytext); }
\|\|                    { count(yytext); printf("OR(%s)\n", yytext); }
\+                      { count(yytext); printf("PLUS(%s)\n", yytext); }
\}                      { count(yytext); printf("RBRACE(%s)\n", yytext); }
\)                      { count(yytext); printf("RPAR(%s)\n", yytext); }
\;                      { count(yytext); printf("SEMI(%s)\n", yytext); }

%%
extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}