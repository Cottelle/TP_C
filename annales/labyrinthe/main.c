#include <stdio.h>
#include <stdlib.h>
#include "solveur.h"
#include "generateur.h"

int main(void) {

    int taille;
    scanf("%i", &taille);

    Piece *piece_de_depart = generer_donjon(taille);

    // Pour visualiser le donjon, décommenter la ligne suivante

    //print_donjon(piece_de_depart, taille);

    int *chemin;
    int longueur;

    sortir(piece_de_depart, &chemin, &longueur);

    if(chemin == NULL) return 42;

    for(int i = 0; i < longueur; i++) {
        printf("porte %i\n", chemin[i]);
    }

    free(chemin);
    free(piece_de_depart);
}
