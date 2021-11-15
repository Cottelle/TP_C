#include "solveur.h"
#include <stdio.h>
#include <stdlib.h>

void sortir(Piece *depart, int **chemin, int *longueur)
{
    *chemin=malloc(sizeof(int));
    if (chemin==NULL)
    {
        free(chemin);
        return;
    }
    *longueur=0;
    while(depart->distance!=0){
        int num;
        for (int i=0;i<4;i++)
        {
            if (depart->portes[i]!=NULL){
                if (depart->portes[i]->distance<depart->distance)
                {
                    depart=depart->portes[i];
                    num=i;
                    break;
                }
            }
        }
    (*chemin)[*longueur]=num;
    *longueur=*longueur+1;
    int *surp=realloc(*chemin,(*longueur+1)*sizeof(int));
    if (surp==NULL)
    {
        free(surp);
        return;
    }
    *chemin=surp;
    }
}
