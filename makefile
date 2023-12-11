uccompiler: lex.yy.c y.tab.c ast.c semantics.c
    cc -o uccomp lex.yy.c y.tab.c ast.c semantics.c -Wall -Wno-unused-function

lex.yy.c: uccompiler.l
    lex uccompiler.l

y.tab.c: uccompiler.y
    yacc -d -v -t -g --report=all uccompiler.y

uccompiler.zip: uccompiler.l uccompiler.y ast.c ast.h semantics.c semantics.h
    zip uccompiler.zip $^

clean:
    rm -f lex.yy.c y.tab.c uccomp uccompiler.zip