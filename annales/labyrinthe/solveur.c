#include "solveur.h"
#include <stdio.h>
#include <stdlib.h>

void sortir(Piece *depart, int **chemin, int *longueur){
    int *cheminsortie=malloc(50*8);
    Piece piece= *depart;
    int dist = piece.distance;
    printf("dist=%i\n",dist);
    *longueur=0;
    Piece *porte = *(piece.portes);
    while (dist != 0){
        for(int i=0;i<4;i++){
            printf("%i\n",i);
            printf("dist %i=%i\n",i,porte[i].distance);    //n'arrive pas a obtenir porte[06>distance] pour main 4 mais y arrive pour min 8 ?
            if (porte[i].distance < dist ){
                piece=porte[i];
                dist = piece.distance;
                porte = *(piece.portes);
                //printf("test\n");
                cheminsortie[*longueur]=i;
                (*longueur)++;
                break;
            }
        }
    }
    (*longueur)++;
    *chemin=cheminsortie;
    //printf("sortie\n");

}