#include <stdio.h>
#include <stdlib.h>

int main(void){
    int c;
    scanf("%i",&c);
    int *pile=NULL;
    int j=0;
    while(c!=0){
        j++;
        int *tab = realloc(pile,j*sizeof(int));
        if (tab==NULL){
            free(tab);
            free(pile);
            return 1;
        }
        pile=tab;
        pile[j-1]=c;
        scanf("%i",&c);
    }
for (int i=j-1;i>=0;){
        int c = pile[i];
        i--;
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
free(pile);
return 0;
}