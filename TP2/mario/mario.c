#include <stdio.h>

int main(void){
    int hauteur;
    scanf("%i",&hauteur);
     if (hauteur<=0){
         printf("IMPOSSIBLE");
     }
    else{
    int largeur = hauteur +1;
    int bloc=2;
    for (int i=0;i<hauteur;i++){
        for(int j=0;j<largeur-bloc;j++){
            printf(" ");
        }
        for(int j=largeur-bloc; j<largeur;j++){
            printf("#");
        }
    printf("\n");
    bloc+=1;
    }
    }
    return 0;
}