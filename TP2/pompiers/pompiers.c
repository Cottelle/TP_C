#include <stdio.h>

int main(void){
    int np,x1,y1,h1,l1,x2,y2,h2,l2;
    scanf("%i",&np);
    for(int i=0;i<np;i++){
        scanf("%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i",&x1,&y1,&h1,&l1,&x2,&y2,&h2,&l2);
        if ((y1+h1>y2 && x1+l1>x2) && x1<x2){
            printf("OUI\n");
        }
        else if ((y2+h2>y1 && x2+l2>x1) && x1>=x2)
        {
             printf("OUI\n");

        }
        
        
        else{
            printf("NON\n");
        }

    }
    return 0;
}