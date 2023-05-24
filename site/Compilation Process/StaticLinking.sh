#!/bin/sh

gcc Script02.c
ar rcs libmylib.a Script02.o
gcc -static Script01.c -L. -lmylib
./a.out