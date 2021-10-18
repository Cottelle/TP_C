#include <stdio.h>

int main(void){
    int n;
    scanf("%i",&n);
    if (n<2){
        printf("IMPOSSIBLE");
        return 0;
    }
    for(int i=0;i<n;i++){
        printf("_");
    }
    printf("\n");
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==n-j){
                printf("/");
            }
        else{
            printf(" ");
        }
        }
        printf("\n");
    }
    printf("/");
    for(int i=1;i<n;i++){
        printf("_");
    }
    printf("\n");

    return 0;
}