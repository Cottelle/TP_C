#include <stdio.h>
#include "minmax.h" // <- la fonction permut doit se trouver dans ce fichier

int main(void) {

    int tn[] = { 12, 23, 36, 5, 46, 9, 25 };
    int min, max;
    int lenght;
    lenght= sizeof(tn)/4;
    minmax(tn,lenght,&min,&max);



    printf("min: %i max: %i\n", min, max); // doit afficher "min: 5 max:46"

}