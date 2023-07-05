#!/bin/bash

# Competitive Programming instant exe. Only for C++

in="./src/Code"
out="./out/Code"
file_cpp="$in/sol.cpp"
file_out="$out/sol.exe"
input="./src/Code/input.txt"
output="./src/Code/output.txt"

truncate --size 0 "$output"
mkdir -p "$out"

g++ "$file_cpp" -o "$file_out"

"$file_out" < "$input" > "$output"