/*
Guilherme Melo - 2021217138
João Gaspar - 2021221276
*/
%{
  int flag = 0;
  int line = 1, column = 1;
  int start_line = 1, start_col = 1;
  char buffer[1024];
  int buffer_index = 0;
%}
CHAR          char
INT           int
SHORT         short
DOUBLE        double
IF            if
ELSE          else
WHILE         while
RETURN        return
VOID          void
NOT           "!"
BITWISEAND    "&"
BITWISEOR     "|"
BITWISEXOR    "^"
AND           "&&"
OR            "||"
EQ            "=="
NE            "!="
GE            ">="
LE            "<="
GT            ">"
LT            "<"
LBRACE        "{"
RBRACE        "}"
LPAR          "("
RPAR          ")"
ASSIGN        "="
MUL           "*"
COMMA         ","
DIV           "/"
MINUS         "-"
MOD           "%"
PLUS          "+"
SEMI          ";"
DIGIT         [0-9]
VAR           [a-zA-Z_]
RESERVED      [\[\]]|"++"|"--"|auto|break|case|const|continue|default|do|enum|extern|float|for|goto|inline|long|register|restrict|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|_Bool|_Complex|_Imaginary
NEWLINE       \r\n|\n|\r
ESCAPESEQUENCES  \\(n|t|\\|\'|\"|[0-7]{1,3}) 
DECIMAL      ({DIGIT}+"."{DIGIT}*|"."{DIGIT}+|{DIGIT}+)
%x COMMENT_ML
%x COMMENT_SL
%%
"//"                                        { BEGIN(COMMENT_SL); start_col = column; start_line=line; column += yyleng; }
<COMMENT_SL>.                               { column += yyleng;}
<COMMENT_SL><<EOF>>                         { BEGIN(INITIAL);}
<COMMENT_SL>{NEWLINE}                       { line++; column = 1; BEGIN(INITIAL);}
"/*"                                        { BEGIN(COMMENT_ML); start_col = column; start_line=line; column += yyleng; }
<COMMENT_ML>.                               { column += yyleng;}
<COMMENT_ML><<EOF>>                         { printf("Line %d, column %d: unterminated comment\n", start_line, start_col); BEGIN(INITIAL);} 
<COMMENT_ML>{NEWLINE}                       { line++; column = 1;} 
<COMMENT_ML>"*/"                            { column += yyleng; BEGIN(INITIAL);}
{NEWLINE}                                   { line++; column = 1; }
" "|"\t"                                    { column += yyleng; }
{CHAR}                                      { if(flag)printf("CHAR\n"); column += yyleng; }
{INT}                                       { if(flag)printf("INT\n"); column += yyleng; }
{SHORT}                                     { if(flag)printf("SHORT\n"); column += yyleng; }
{DOUBLE}                                    { if(flag)printf("DOUBLE\n"); column += yyleng; }
{IF}                                        { if(flag)printf("IF\n"); column += yyleng; }
{ELSE}                                      { if(flag)printf("ELSE\n"); column += yyleng; }
{WHILE}                                     { if(flag)printf("WHILE\n"); column += yyleng; }
{RETURN}                                    { if(flag)printf("RETURN\n"); column += yyleng; }
{VOID}                                      { if(flag)printf("VOID\n"); column += yyleng; }
{NOT}                                       { if(flag)printf("NOT\n"); column += yyleng; }
{BITWISEAND}                                { if(flag)printf("BITWISEAND\n"); column += yyleng; }
{BITWISEOR}                                 { if(flag)printf("BITWISEOR\n"); column += yyleng; }
{BITWISEXOR}                                { if(flag)printf("BITWISEXOR\n"); column += yyleng; }
{AND}                                       { if(flag)printf("AND\n"); column += yyleng; }
{OR}                                        { if(flag)printf("OR\n"); column += yyleng; }
{EQ}                                        { if(flag)printf("EQ\n"); column += yyleng; }
{NE}                                        { if(flag)printf("NE\n"); column += yyleng; }
{GE}                                        { if(flag)printf("GE\n"); column += yyleng; }
{LE}                                        { if(flag)printf("LE\n"); column += yyleng; }
{GT}                                        { if(flag)printf("GT\n"); column += yyleng; }
{LT}                                        { if(flag)printf("LT\n"); column += yyleng; }
{LBRACE}                                    { if(flag)printf("LBRACE\n"); column += yyleng; }
{RBRACE}                                    { if(flag)printf("RBRACE\n"); column += yyleng; }
{LPAR}                                      { if(flag)printf("LPAR\n"); column += yyleng; }
{RPAR}                                      { if(flag)printf("RPAR\n"); column += yyleng; }
{ASSIGN}                                    { if(flag)printf("ASSIGN\n"); column += yyleng; }
{MUL}                                       { if(flag)printf("MUL\n"); column += yyleng; }
{COMMA}                                     { if(flag)printf("COMMA\n"); column += yyleng; }
{DIV}                                       { if(flag)printf("DIV\n"); column += yyleng; }
{MINUS}                                     { if(flag)printf("MINUS\n"); column += yyleng; }
{MOD}                                       { if(flag)printf("MOD\n"); column += yyleng; }
{PLUS}                                      { if(flag)printf("PLUS\n"); column += yyleng; }
{SEMI}                                      { if(flag)printf("SEMI\n"); column += yyleng; }                     
{RESERVED}                                  { if(flag)printf("RESERVED(%s)\n", yytext); column += yyleng; }
{VAR}+({VAR}|{DIGIT})*                      { if(flag)printf("IDENTIFIER(%s)\n", yytext); column += yyleng; }
{DIGIT}{DIGIT}*                             { if(flag)printf("NATURAL(%s)\n", yytext); column += yyleng; }
{DECIMAL}([Ee][+-]?{DIGIT}+)?              { if(flag)printf("DECIMAL(%s)\n", yytext); column += yyleng; }
\'([^\'\n\r\\]|{ESCAPESEQUENCES})\'            { if(flag)printf("CHRLIT(%s)\n", yytext); column += yyleng; }
\'([^\'\n\r\\]|{ESCAPESEQUENCES})*             { printf("Line %d, column %d: unterminated char constant\n", line, column); column += yyleng; }
\'([^\'\n\r\\]|{ESCAPESEQUENCES}|[^\'\n\r]*)   { printf("Line %d, column %d: unterminated char constant\n", line, column); column += yyleng; }
\'([^\'\n\r\\]|{ESCAPESEQUENCES}|\\[^\n\r'])*\'  { printf("Line %d, column %d: invalid char constant (%s)\n", line, column, yytext); column += yyleng; }
.                                           { printf("Line %d, column %d: unrecognized character (%s)\n", line, column, yytext); column += yyleng; }
%%
extern int yylex();
int main(int argc, char **argv) {
  if(argc > 1){
    if(!strcmp(argv[1], "-l")){
      flag = 1;
    }
  }
  yylex();    /* run the lexical analysis automaton */  
  return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
  return 1;
}



