#!/bin/bash

# CPP/C instant compile file

if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Please put parameters"
    echo "First parameter is dir relative to src"
    echo "Second parameter is the file that want to be compiled"
    echo "Example: ./run.sh Pointers main"
    echo "Read README.md for details"
    exit 1
fi

dir="./out/$1"
file_exe="$dir/$2"
file_c="./src/$1/$2.c"
file_cpp="./src/$1/$2.cpp"
file_cplus="./src/$1/$2.c++"

mkdir -p ./out
mkdir -p "$dir"

if ([ ! -f "$file_c" ] && [ ! -f "$file_cpp" ] && [ ! -f "$file_cplus" ]); then
    echo "$file_c or $file_cpp or $file_c\+\+ doesnt exist"
    exit 1;
fi

if [ -f "$file_c" ]; then
    gcc "$file_c" -o "$file_exe"
elif [ -f "$file_cpp" ] || [ -f "$file_cplus" ]; then
    g++ "$file_cpp" -o "$file_exe"
fi

"./$file_exe"