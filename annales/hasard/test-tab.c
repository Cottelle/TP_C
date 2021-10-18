#include <stdio.h>
#include <math.h>
#include "test-tab.h"

long int estpremier(long int a){
    long int r = sqrt(a)+1;
    if (a%2==0){
        return 0;
    }
    for (int j=3;j<=r;j=j+2){
        if ((a/j)*j==a){
            return 0;
        }
    }
    return 1;
}

int test(const unsigned long long *T,int n){
    for (int i=0;i<n;i++){
        if(estpremier(T[i])){
            return ALICE;
        }
    }
    return BOB;
} 

int main(void){
    for(long int i=0;i<1000000;i++){
        if(estpremier(i)){
            printf("%li est premier \n",i);
        }
    }
}