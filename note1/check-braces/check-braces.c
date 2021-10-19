#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int ouv=0;
    int fer=0;
    int count=0;
    int b=0;
    for(int i=0;i<argc && b==0;i++){
        for(int j=0;argv[j][i]!='\0';j++){
            if (argv[j][i]=='{'){
                ouv++;
            }
            if (argv[j][i]=='}'){
                fer++;
            }
            if (ouv-fer<0){
                b=1;
                break;
            }
            count++;

        }

    }
    if (b==0){
        return 0;
    }

    return 0;
}