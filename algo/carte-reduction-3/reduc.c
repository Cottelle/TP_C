// #include "arbrebinaire.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct arbrebinaire
{
    void *node;
    struct arbrebinaire *gauche;
    struct arbrebinaire *doite;
} arbrebinaire;

int presencearbre(void *value, arbrebinaire *arbre, int (*compar)(void *, void *))
{
    if (arbre == NULL)
    {
        return -1;
    }
    if (compar(value, arbre->node) < 0)
    {
        return presencearbre(value, arbre->gauche, compar);
    }
    else if (compar(value, arbre->node) > 0)
    {
        return presencearbre(value, arbre->doite, compar);
    }
    else
    {
        return 1;
    }
}

arbrebinaire *ajoutearbre(void *value, arbrebinaire *arbre, int (*compar)(void *, void *))
{
    if (arbre == NULL)
    {
        arbre = malloc(sizeof(arbrebinaire));
        if (arbre == NULL)
        {
            free(arbre);
            fprintf(stderr, "ERREUR");
            exit(1);
        }
        arbre->node = value;
        arbre->gauche = NULL;
        arbre->doite = NULL;
        return arbre;
    }
    if (compar(value, arbre->node) < 0)
    {
        arbre->gauche = ajoutearbre(value, arbre->gauche, compar);
        return arbre;
    }
    else if (compar(value, arbre->node) >= 0)
    {
        arbre->doite = ajoutearbre(value, arbre->doite, compar);
        return arbre;
    }
    return NULL;
}
arbrebinaire *arbrevide(void)
{
    return NULL;
}

void freearbre(arbrebinaire *arbre)
{
    if (arbre != NULL)
    {
        freearbre(arbre->doite);
        freearbre(arbre->gauche);
    }
    free(arbre);
}

int compar(void *s1, void *s2)
{
    char *a = s1;
    char *b = s2;
    return (strcmp(a, b));
}

int main(void)
{
    //     arbrebinaire *arbre =NULL;
    //     arbre=ajoutearbre("TEST1",arbre,compar);
    //     arbre=ajoutearbre("TEST2",arbre,compar);
    //     arbre=ajoutearbre("TEST3",arbre,compar);
    //     arbre=ajoutearbre("TEST4",arbre,compar);
    //     printf("%p\n",arbre);
    //     printf("%i\n",presencearbre("TEST5",arbre,compar));
    //     return 0;
    // }
    int N;
    scanf("%i\n", &N);
    arbrebinaire *arbre = arbrevide();
    char **str = malloc(N*sizeof(char *));
    for (int i = 0; i < N; i++)
    {
        str[i]=malloc(7);
        fgets(str[i], 7, stdin);
        str[i][5]='\0';
        if (presencearbre(str[i], arbre, compar) == 1)
        {
            printf("%s\n", str[i]);
            for(int j=0;j<=i;j++)
            {
                free(str[j]);
            }
            free(str);
            freearbre(arbre);
            return 0;
        }
        arbre = ajoutearbre(str[i], arbre, compar);
    }
    for (int i=0;i<N;i++)
    {
        free(str[i]);
    }
    free(str);
    printf("-1\n");
    freearbre(arbre);
    return 0;
}