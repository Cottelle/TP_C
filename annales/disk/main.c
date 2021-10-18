#include <stdio.h>
#include "disk.h"

int main(void){
    int d;
    scanf("%i",&d);
    char *str=disk(d);
    for (int i=0;i<d*(d+1);i++){
        printf("%c",str[i]);

    }
    free(str);
    return 0;
}