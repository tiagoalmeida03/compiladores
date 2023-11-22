#!/bin/sh
rm -f uccomp lex.yy.c y.tab.c y.tab.h
yacc -d -v -t -g --report=all uccompiler.y
lex uccompiler.l
cc -o uccomp lex.yy.c y.tab.c ast.c -Wall -Wno-unused-function
zip uccompiler.zip uccompiler.l uccompiler.y ast.c ast.h

FILE=$1
if [ -z "$FILE" ]; then
    exit 0
elif [ "$FILE" = "ALL" ]; then
    # Initialize test number
    test_number=1
    passed = 0

    # Loop over all .uc files in the meta2 directory
    for file in ./meta2/*.uc; do
        # Get the base name of the file (without the .uc extension)
        base_name=$(basename "$file" .uc)

        # Run the compiler and diff the output
        ./uccomp -t < "$file" > output.txt
        if diff -y output.txt "./meta2/$base_name.out" >/dev/null; then
            # If the files are equal, print the test number in green
            printf "\033[32mTest %d: PASS\033[0m (%s)\n" "$test_number" "$base_name.uc"
            ((passed++))
        else
            # If the files are different, print the test number in red
            printf "\033[31mTest %d: FAIL\033[0m (%s)\n" "$test_number" "$base_name.uc"
        fi

        # Increment the test number
        ((test_number++))
    done
    printf "\033[32m%d/%d tests passed\033[0m\n" "$passed" "$((test_number - 1))"
else
    ./uccomp -t < ./meta2/$FILE.uc > output.txt
    diff -y --color=always output.txt ./meta2/$FILE.out
fi