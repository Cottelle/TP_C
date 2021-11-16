#include <stdio.h>
#include "arbrebinaire.h"
#include <stdlib.h>

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

void ajoutearbre (void *value,arbrebinaire *arbre,int (*compar)(void *,void *))
    {
    if (arbre == NULL)
    {
        (arbre)=malloc(sizeof(arbrebinaire));
        if (arbre==NULL)
        {
            free(arbre);
            exit (1);
        }
        arbre->node=value;
        arbre->gauche=NULL;
        arbre->doite=NULL;
        return;
    }
    if (compar(value, arbre->node) < 0)
    {
        return ajoutearbre(value, arbre->gauche, compar);
    }
    else if (compar(value, arbre->node) >= 0)
    {
        return ajoutearbre(value, arbre->doite, compar);
    }
}
arbrebinaire *arbrevide(void)
{
    return NULL;
}

void freearbre(arbrebinaire *arbre)
{
    if (arbre!=NULL)
    {
        freearbre(arbre->doite);
        freearbre(arbre->gauche);
    }
    free(arbre);
}