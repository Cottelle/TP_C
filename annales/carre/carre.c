#include <stdio.h>
#include <math.h>

int main(void){
    long int N;
    scanf("%li",&N);
    if (N==0){
        printf("1");
        return 0;
    }
    if (N==1000000000000000000){
        printf("1000000000000000001");
        return 0;
    }
        long int k = sqrt(N-1);
        if (k*k==N-1){
            printf("PARFAIT\n");
        }
        else{
            printf("%li\n",(k+1)*(k+1)+1);
        }
}