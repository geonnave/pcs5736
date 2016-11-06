#!/bin/bash

[ -z "$1" ] && echo "must provide 'filename.c' or 'clear'" && exit 1
program=`echo "$1" | sed "s/.c$//g"`

echo compiling $program..
gcc -o $program -fopenmp ${program}.c
[ $? != 0 ] && echo compilation failed && exit 1

echo running $program..
./$program


exit 0
