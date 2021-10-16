#include <stdio.h>

int main(void){
    char str[1000];
    fgets(str, 1000, stdin);
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        if (str[i]=='A'){
            count++;
        }
    }
    printf("%i",count);
    return 0;
}