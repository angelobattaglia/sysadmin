#include <stdio.h>
#include "Script02.h"

int g = 100;
int h;
static int s;

int main(int argc, char *argv[]){
    int a = 1;
    int b;
    static int c = 3;
    b = 2;
    c = mysum(a, b);
    printf("sum = %d\n", c);
}