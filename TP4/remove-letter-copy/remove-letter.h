#include <stdlib.h>

char *removeLetter(char *stre,char c){

    int i;
    for(i=0;stre[i]!='\0';i++){}
    char *strs=malloc(i*1+1);
    if (strs==NULL){
        return NULL;
    }
    else{
        if (i==0){
            free(strs);
            char *strs=malloc(1);
            strs[0]='\0';
            return strs;}
        else{
    int k=0;
    int j;
    for(j=0;stre[j]!='\0';j++){
        if(stre[j]==c){
            k++;
        }
        else{
            strs[j-k]=stre[j];
        }
    }
    strs[j-k]='\0';
    return strs;
}
}
    }