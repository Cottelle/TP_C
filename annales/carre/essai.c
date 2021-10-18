#include <stdio.h>
#include <math.h>

int main(void){
    long double i=1000000000000000000.0;
    long double j=i-1;
    long double k1= sqrt(i);
    long double k2=sqrt(j);
    printf("i=%Lf\nj=%Lf\nk1=%Lf\nk2=%Lf\nk*k=%Lf\n",i,j,k1,k2,k1*k1);
    return 0;
}