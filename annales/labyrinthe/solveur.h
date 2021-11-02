
#ifndef SOLVEUR_H
#define SOLVEUR_H

// Structure qui représente une pièce du donjon
// avec ces 4 portes et un nombre indiquant la
// distance (en nombre de porte) jusqu'à la sortie

// NE DOIT PAS ETRE MODIFIE

typedef struct Piece {
    struct Piece *portes[4];
    int distance;
} Piece;

void sortir(Piece *depart, int **chemin, int *longueur);

#endif