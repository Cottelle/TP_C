#include <stdio.h>

int main(void){
    double ciment;
    scanf("%le",&ciment);
    int i;
    for(i=1;i*60<ciment;i++){}
    printf("%i\n",i*45);
    return 0;
}