#include <stdio.h>
void printstr(char *str );

void removeLetter(char *str,char c){
    int i,supr;
    for(i=0,supr=0;str[i]!='\0';i++){
        if(str[i]==c){
                str[i]='\1';
                supr++;
        }
        }
    printstr(str);
    int deca=0;
    for(int j=0; str[j]!='\0';j++){
        if (str[j]=='\1'){
            deca++;
        }
        else{
            str[j-deca]=str[j];
        }
    }
    str[i-supr]='\0';
    }


void printstr(char *str){
    for(int i=0;str[i]!='\0';i++){
        printf("%c \n",str[i]);
    }
}

