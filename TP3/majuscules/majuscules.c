#include <stdio.h>


int main(int argc, char **argv){
    for(int i=1;i<argc;i++){
        for(int j=0; argv[i][j]!='\0';j++){
            if(argv[i][j]>=97 && argv[i][j]<122){
                argv[i][j]+=-32;
            }
        }
        printf("%s \n",argv[i]);
    }
    
    return 0;
}