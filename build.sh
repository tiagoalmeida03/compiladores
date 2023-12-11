#!/bin/sh

# Remove existing temporary files
rm -f lex.yy.c y.tab.c uccomp

# Compile the Yacc and Lex files
yacc -d -v -t -g --report=all uccompiler.y
lex uccompiler.l

# Check if compilation steps were successful
if [ $? -eq 0 ]; then
    # Compile the C files
    cc -o uccomp lex.yy.c y.tab.c ast.c semantics.c -Wall -Wno-unused-function

    # Check if the executable was created successfully
    if [ -e uccomp ]; then
        echo "Build successful. Compiler executable: uccomp"
    else
        echo "Build failed. Unable to create the compiler executable."
        exit 1
    fi

    # Create a ZIP file with relevant source files
    zip uccompiler.zip uccompiler.l uccompiler.y ast.c ast.h semantics.c semantics.h

    echo "ZIP file uccompiler.zip created with source files."

else
    echo "Yacc or Lex compilation failed. Unable to proceed with C compilation."
    exit 1
fi

# Remove intermediate files
rm -f lex.yy.c y.tab.c


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