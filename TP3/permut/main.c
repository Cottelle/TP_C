#include <stdio.h>
#include "permut.h" // <- la fonction permut doit se trouver dans ce fichier

int main(void) {

    int a = 1, b = 2, c = 3;
    //scanf("%i %i %i";&a,&b,&c);
    permut(&a,&b,&c);

    printf("%i %i %i\n", a, b, c);  // doit afficher 2 3 1

}
