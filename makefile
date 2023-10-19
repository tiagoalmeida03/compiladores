all: lexer

lexer: lex.yy.c
    cc lex.yy.c -o uccompiler

lex.yy.c: lexer.l
    lex lexer.l

clean:
    rm -f lex.yy.c lex