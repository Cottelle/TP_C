#include "generateur.h"
#include "solveur.h"


#include <stdio.h>
#include <stdlib.h>

#define ABS(a) ((a) >= 0 ? (a) : (-(a)))

Piece * generer_donjon(int taille) {
    srand(2);

    Piece * map = calloc(taille * taille + 1, sizeof(Piece));
    map++;
    int sortieI = rand()%taille;
    int sortieJ = rand()%taille;

    if(taille > 1000) {
        sortieI = sortieJ = 0;
    }

    for(int i = 0; i < taille; i++) {
        for(int j = 0; j < taille; j++) {
            map[i+taille*j].portes[0] = i == 0        ? NULL : &(map[i-1+taille*j]);
            map[i+taille*j].portes[2] = i == taille-1 ? NULL : &(map[i+1+taille*j]);
            map[i+taille*j].portes[1] = j == taille-1        ? NULL : &(map[i+taille*(j+1)]);
            map[i+taille*j].portes[3] = j == 0 ? NULL : &(map[i+taille*(j-1)]);
            map[i+taille*j].distance = ABS(i - sortieI) + ABS(j - sortieJ);
        }
    }

    int departI = rand()%taille;
    int departJ = rand()%taille;
    if(taille > 1000) {
        departI = departJ = taille-1;
    }

    *(map-1) = map[departI+taille*departJ];

    return map-1;
}

void print_donjon(Piece * depart, int taille) {
    Piece *map = depart+1;
    for(int i = 0; i < taille; i++) {
        for(int j = 0; j < taille; j++) {

            if(map[i+taille*j].portes[0] == depart->portes[0] &&
                    map[i+taille*j].portes[1] == depart->portes[1] &&
                    map[i+taille*j].portes[2] == depart->portes[2] &&
                    map[i+taille*j].portes[3] == depart->portes[3]) {
                printf("[\e[0;31m  🚹 \e[0m ]");
            }else if(map[i+taille*j].distance == 0) {
                printf("[\e[0;31m  E  \e[0m]");
            } else {
                printf("[ %*i  ]", 2, map[i+taille*j].distance);
            }

        }
        printf("\n");
    }

}