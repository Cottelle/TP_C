#include <stdio.h>

int main(void){
    int dep,dist,nb;
    scanf("%i\n%i\n%i",&dep,&dist,&nb);
    for(int i=0;i<nb;i++){
        printf("%i\n",dep);
        dep+=dist;
    }
    printf("%i\n",dep);
    return 0;
}