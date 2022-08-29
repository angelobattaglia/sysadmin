### References
- [Inlcude guard (wikipedia link)](https://en.wikipedia.org/wiki/Include_guard)
- [Systems Programming in UNIX Linux by K.C. Wang, Springer]()

### Let's take two files to start with
```
gcc Script01.c Script02.c
```

```
gcc Script01.c Script02.c
```

### Simple convert into a binary executable
```
gcc Script01.c Script02.c
```
or ..
```
tcc Script01.c Script02.c
```

# Statically linked library

- First step: compile Script02.c into Script02.o, important using the '-c' flag
```
gcc -c Script02.c
```

- Second step: create a Statically Linked Library with Script02.o as a member of it
```
ar rcs libmylib.a Script02.o
```

- Third step: Static compile-link Script01.c with libmylib.a as a linked library
- '-static' specifies that is being statically linked
- '-L.' specifies the library path (current directory .)
- '-l' specifies the library
- 'mylib' is specified without the prefex lib, as well as the suffix .a
```
gcc -static Script01.c -L. -lmylib
```

- Fourth step: run the result, i.e. a.out, as usual
```
./a.out
```

# Dynamic Linking

- First step: compile Script02.c into Script02.o, -fPIC compile to Position Independent Code Script02.o
```
gcc -c -fPIC Script02.c
```

- Second step: create a shared (-shared) Dinamically Linked Library (.so) with Script02.o as a member of it
```
gcc -shared -o libmylib.so Script02.o
```

- Third step: Static compile-link Script01.c with libmylib.a as a linked library
- '-L.' specifies the library path (current directory . or you can specify it)
- '-l' specifies the library as seen next
- '-lmylib' is specified without the prefex lib, as well as the suffix .a
```
gcc Script01.c -L. -lmylib
```

- Third-2 step: exporting the LD_LIBRARY = ./
- If the library is not in the curent directory set LD_LIBRARY_PATH to point to the directory containing the library
```
export LD_LIBRARY_PATH = ./
```

- Fourth step: run the result, i.e. a.out, as usual
```
./a.out
```

