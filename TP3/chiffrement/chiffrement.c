#include <stdio.h>
#include <stdlib.h>
char **apprantissage(char **exemple){
    int i;
    for(i=0;exemple[0][i]!='\0';i++){

    }
    char **tab= malloc(2*i);
    for(int j=0;j<i;i++){
        tab[0][j]=exemple[0][j];
        tab[1][j]=exemple[1][j];        
    }
    return tab;
}

int main(void){
        char arr[200];
        fgets(arr, 200, stdin);
        char arre[200];
        fgets(arre, 200, stdin);
        char *exemple[]={arr,arre};
        char **test=apprantissage(exemple);

        //for(int j=0;arr[j]!='\0';j++){
           // if 
        free(test);
            
            
    printf(" ");
    printf("\n");
    return 0;
}