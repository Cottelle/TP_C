#include <stdio.h>
#include <stdlib.h>

void recuchemin(void){
    int c;
    scanf("%i",&c);
    if (c!=0){
        recuchemin();
        switch (c)
        {
        case 1: 
            printf("2");
            printf("\n");
            break;
        case 2:
            printf("1");
            printf("\n");
            break;
        case 3:
            printf("3");
            printf("\n");
            break;
        case 4:
            printf("5");
            printf("\n");
            break;
        case 5:
            printf("4");
            printf("\n");
            break;
        case 0:
            break;
        default:
            fprintf(stderr,"erreur");
            break;
        
        }    

    }
}

int main(void){
    recuchemin();
}