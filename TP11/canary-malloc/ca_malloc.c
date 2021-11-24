#include "ca_malloc.h"
#include <stdlib.h>
#include <stdio.h>

void *ca_malloc(int n)
{
    char *retour = malloc(n + 16);
    if (retour == NULL)
    {
        return NULL;
        for (int i = 0; i < n + 16; i++)
        {
            retour[i] = 'a';
        }
    }
    for (int i = 0; i < 8; i++)
    {
        retour[n + 16 - i - 1] = 'c';
    }
    // (long *)retour;
    ((long *)retour)[0] =(long)n;
    (void *)retour;
    return (retour + 8);
}

void ca_free(void *pointeur)
{
    (void *)pointeur;
    pointeur = pointeur - 8;
    long *recupnb;
    long n = ((long *)pointeur)[0];
    // printf("%i", n);
    char *test = pointeur;
    for (int i = 0; i < 8; i++)
    {
        // printf("%c",test[n+16 - i - 1]);
        if (test[n + 16 - i - 1] != 'c')
        {
            fprintf(stderr, "Erreur vous avez fait n'importe quoi avec le pointeur que je vous ai passé, Signé Malloc");
            free(pointeur);
            return;
        }
    }
    free(pointeur);
    return;
}

// int main(void)
// {
//     int *tab =ca_malloc(16);
//     ca_free(tab);
// }
