#!/bin/bash
echo "Compiling $1..."
rm output
g++ $(pkg-config --libs --cflags opencv) -w $1 -o output
echo "Compile DONE. Run now..."
./output
