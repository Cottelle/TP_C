#include "solveur.h"
#include <stdio.h>
#include <stdlib.h>

void sortir(Piece *depart, int **chemin, int *longueur)
{
    //     printf("distanceinitial=%i\n", depart->distance);
    // printf("distance=%i\n", (*(depart->portes) + 2)->distance);
    int *cheminsortie = malloc(50 * 8);
    Piece piece = *depart;
    int dist = piece.distance;
    *longueur = 0;
    Piece *porte = *(piece.portes);
    while (dist != 0)
    {
        for (int i = 0; i < 4; i++)
        {
            // printf("i=%i\n",i);
            printf("%p\n", (piece.portes) + 1);
            if ((porte + i * sizeof(int)) != NULL)
            {
                if ((*(porte + i * sizeof(int))).distance < dist)
                {
                    printf("test0\n");
                    piece = *(porte + i);
                    printf("test1\n");
                    dist = piece.distance;
                    printf("test2\n");
                    porte = *(piece.portes);
                    printf("test3\n");
                    *(cheminsortie + *longueur) = i;
                    (*longueur)++;
                    break;
                }
            }
            else
            {
                printf("NULL\n");
            }
        }
    }
    (*longueur)++;
    *chemin = cheminsortie;
    //printf("sortie\n");
}
// }