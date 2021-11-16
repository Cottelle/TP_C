#include "arbrebinaire.h"
#include <stdio.h>
#include <string.h>
int compar(void *s1,void *s2)
{
    char *a=s1;
    char *b=s2;
    return (strcmp(a,b));
}

int main(void)
{
    arbrebinaire *arbre=arbrevide();
    ajoutearbre("ABCD",arbre,compar);
    ajoutearbre("CDCD",arbre,compar);
    ajoutearbre("SQCD",arbre,compar);
    ajoutearbre("UOCD",arbre,compar);
    printf("%i\n",presencearbre("UOCD",arbre,compar));
    
}