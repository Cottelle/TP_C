#include <stdio.h>

void permut(int *a,int *b,int *c){
    int d= *a;
    *a=*b;
    *b=*c;
    *c=d;
}
