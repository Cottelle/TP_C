#include "ca_malloc.h"
#include <stdlib.h>
#include <stdio.h>

void *ca_malloc(int n)
{
    char *retour = malloc(n + 16+4);
    if (retour == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < 8; i++)
    {
        retour[n + 20 - i - 1] = 'c';
        retour[i+4] = 'c';

    }
    ((int *)retour)[0] =(int)n;
    (void *)retour;
    return (retour + 12);
    
}

void ca_free(void *pointeur)
{
    (void *)pointeur;
    pointeur = pointeur - 8;
    int n = ((int *)pointeur)[-1];
    // printf("%i", n);
    char *test = pointeur;
    for (int i = 0; i < 8; i++)
    {
        // printf("%c",test[n+16 - i - 1]);
        if (test[n + 16 - i - 1] != 'c'|| test[i]!='c')
        {
            fprintf(stderr, "Erreur vous avez fait n'importe quoi avec le pointeur que je vous ai passé, Signé Malloc");
            free(pointeur-4);
            return;
        }
    }
    free(pointeur-4);
    return;
}

// int main(void)
// {
//     int *tab =ca_malloc(16);
//     ca_free(tab);
// }
