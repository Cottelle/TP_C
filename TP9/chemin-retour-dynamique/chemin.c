#include <stdio.h>
#include <stdio.h>
#include "tps_stack.h"

int main(void){
    tps_stack pile = tps_stack_create();
    int c=1;
    while (c!=0)
    {
        scanf("%i",&c);
        tps_stack_push(pile,c);
    } 
    int n = tps_stack_size(pile);
    for (int i=0;i<n;i++){
        int c = tps_stack_pop(pile);
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
tps_stack_free(pile);
return 0;
}