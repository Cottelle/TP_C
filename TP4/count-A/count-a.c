#include <stdio.h>

int main(int argc,char **argv){
    int count=0;
    if(argc<=1){
        return 42;
    } 
    else{
        for(int i=0;argv[1][i]!='\0';i++){
            if (argv[1][i]=='A'){
                count++;
            }
        }
    }
    printf("%i \n",count);

    return 0;
}