#include <stdio.h>

int main(void){
    int n;
    scanf("%i",&n);
    int b=1;
    /*if ((n/2)*2==n){
        b=0;
    }
    else{
        b=1;
    }*/
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b==0){
                printf(".");
                b=1;
            }
            else{
                printf("#");
                b=0;
            }
        }
        printf("\n");
    if ((n/2)*2==n){
        b=(b+1)%2;
    }
    }
    return 0;
}
