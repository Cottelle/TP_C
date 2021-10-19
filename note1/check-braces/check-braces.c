#include <stdio.h>
#include <stdlib.h>

int main(void){
    char str[1000];
    fgets(str,1000,stdin);
    int ouv=0;
    int fer=0;
    int count=0;
    int b=0;
    for(int j=0;str[j]!='\0';j++){
            if (str[j]=='{'){
                ouv++;
            }
            if (str[j]=='}'){
                fer++;
            }
            if (ouv-fer<0){
                b=1;
                break;
            }
            count++;

        }

    if (b==0){
        return 0;
    }

    return 0;
}