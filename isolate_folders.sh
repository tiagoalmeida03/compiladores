meta="meta2"

find "./c/$meta" -maxdepth 1 -type f -name "*c" | while read -r file; do
    file_name=$(basename "${file%.*}")
    echo "Testing ${file%.*}"
    echo "filename $file_name"

    destination="./c/$meta/$file_name"

    mkdir -p "$destination"

    mv "$file" "$destination/"
done
