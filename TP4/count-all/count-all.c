#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv ){
    int count[52]={};
    if(argc==1){
        return 42;
    }
    for(int i=1;i<argc;i++){
        for(int j=0;argv[i][j]!='\0';j++)
            if (argv[i][j]>=96 /*&& argv[i][j]<=96+52*/ ){
                count[argv[i][j]-97]++;
            }
    }
    for (int i=0;i<26;i++){
        printf("%c:%i\n",i+97,count[i]+count[i+('A'-'a')]);
    }

}