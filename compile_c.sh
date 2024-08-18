#!/bin/bash

CXXFLAGS="-Iinclude -std=c++14"

if [ $# -ne 1 ]; then
    echo "how to use: $0 <file name.cpp>"
    exit 1
fi

#C++ file compile
filename=$1
output=$(echo "$filename" | cut -f 1 -d '.')
g++ -o $output $filename

# check compile success
if [ $? -eq 0 ]; then
    echo "The compilation is complete. output file : ./$output"
else
    echo "Compilation failed"
fi
