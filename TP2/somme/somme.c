#include <stdio.h>

int main(void){
    unsigned long long int n;
    /*printf("Donnez un entier : "); */
    scanf("%lld",&n);
    
    unsigned long long int res;
    res= n*(n+1)/2;
    printf("%lld \n",res);
    return 0;
}