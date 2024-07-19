# Make

The mechanics of programming usually follow a fairly simple routine of editing source files, compiling the source
into an executable form, and debugging the result. The make program is intended to automate the mundane aspects of
transforming source code into an executable. The advantages of make over scripts is that you can specify the relationships
between the elements of your program to make, and it knows through these relationships and timestamps exactly what
steps need to be redone to produce the desired program each time. Using this information, make can also optimize the
build process avoiding unnecessary steps. 
[O'Reilly Managing Projects with GNU Make, Third Edition By Robert Mecklenburg November 2004](https://www.oreilly.com/openbook/make3/book/)

