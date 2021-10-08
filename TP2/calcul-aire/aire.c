#include <stdio.h>

int main(void){
    int b =0;
    int largeur,longeur;
    while(b==0){
        printf("Donnez une longueur:");
        scanf("%i",&longeur);
        printf("Donnez une largeur:");
        scanf("%i",&largeur);
        if (largeur>=0 && longeur>=0){
            b=1;
        }
        else{
            printf("Donnez des valeurs positives svp \n");
        }
    }
    int resultat;
    resultat= longeur*largeur;
    printf("Aire = %i \n",resultat);

    return 0;
}