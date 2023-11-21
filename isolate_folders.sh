meta="meta2"

for file in "./c/$meta"/*c; do
    file_name=$(basename "${file%.*}")
    echo "Testing ${file%.*}"
    echo "filename $file_name"
    mkdir -p "./c/$meta/$file_name"
    mv "${file%.*}".* "./c/$meta/$file_name/"
done
