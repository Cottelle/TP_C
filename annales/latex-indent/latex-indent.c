#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

int main(int argc, char **argv)
{
    FILE *entree = NULL;
    FILE *sortie = NULL;
    if (argc == 2)
    {
        entree = fopen(argv[1], "r");
        if (entree == NULL)
        {
            return 2;
        }
        sortie = stdout;
    }
    else if (argc == 3)
    {
        entree = fopen(argv[1], "r");
        if (entree == NULL)
        {
            return 2;
        }
        sortie = fopen(argv[2], "w");
        if (sortie == NULL)
        {
            return 3;
        }
    }
    else
    {
        return 1;
    }
    char buffer[1001];
    int nbbegin;
    int nbend;
    int nbespace = 0;
    char *test;
    int beginetend;
    int startwithend;
    while (1)
    {
        test = readline(entree, buffer);
        if (test == NULL)
        {
            break;
        }
        char *new=surpblanc(buffer);
        nbbegin = countpath(buffer, "begin{");
        nbend = countpath(buffer, "end{");
        beginetend = testdebut(new, "begin{");
        startwithend=testdebut (new, "end{");
        if (beginetend <= 0 && startwithend )
        {
            nbespace = nbespace - 2 * (nbend-nbbegin);
            nbbegin=0;
        }
        if (nbespace < 0)
        {
            nbespace = 0;
        }
        char *buffersortie = decal(new, nbespace);
        fputs(buffersortie, sortie);
        free(buffersortie);
        nbespace = nbespace + 2 * nbbegin;
        if (beginetend > 0 || !startwithend )
        {
            nbespace = nbespace - 2 * nbend;
        }
        if (nbespace < 0)
        {
            nbespace = 0;
        }
        free(new);
    }
    fclose(sortie);
    return 0;
}