#include <stdio.h>

int main(void){
    int a = 10;
    switch(a){
    case 1:
        printf("1");
    case 10:
        printf("10");
        break;
    case 11:
        printf("11???");
    }
    return 0;
}