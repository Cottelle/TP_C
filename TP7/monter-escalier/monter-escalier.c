#include <stdio.h>
#include <stdlib.h>

    int countesc(int n){
        if(n==1 || n==2){
            return n;
        }
        return (countesc(n-1)+countesc(n-2));
    }

int main(int argc, char **argv ){
    if(argc != 2){
        return 1;
    }
    int n = atoi(argv[1]);
    if (n<=0){
        return 1;
    }
    printf("%i\n",countesc(n));
    return 0;
}