#!/bin/bash

filename=$(basename -- "$1")
extension="${filename##*.}"
filename="${filename%.*}"

mkdir -p bin
cd bin
g++ -o $filename ../$1
./$filename
cd ..