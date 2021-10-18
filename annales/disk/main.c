#include <stdio.h>
#include "disk.h"

int main(void){
    int d;
    scanf("%i",&d);
    char *str=disk(d);
    for (int i=0;i<d+1;i++){
        for(int j=0;j<d+1;j++){
        printf("%c",str[i*d+j]);
        }
    }
    free(str);
    return 0;
}