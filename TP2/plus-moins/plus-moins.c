#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    int essai=0;
    int chiffre;
    do
    {
        essai++;
        scanf("%i",&chiffre);
        if (chiffre>n){
            printf("c'est moins\n");
        }
        if (chiffre <n){
            printf("c'est plus\n");
        }
    } while (chiffre!=n);
    printf("Nombre d'essais nécessaires : \n");
    printf("%i\n",essai);
    

    return 0;
}