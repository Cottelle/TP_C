#ifndef ARBRE
#define ARBRE

#include <stdio.h>

typedef struct arbrebinaire
{
    void *node;
    struct arbrebinaire *gauche;
    struct arbrebinaire *doite;
} arbrebinaire;
// structure d'arbre de type void par la suite compar est une comparaison entre void * qui renvoie negatif si le premier est plus grand, positif si le second est plus garnd, 0 si ils ont egaux

int presencearbre(void *value, arbrebinaire *arbre, int (*compar)(void *, void *));
// revoit -1 si value n'est pas dans l'abre et 1 si elle est presente.

arbrebinaire *ajoutearbre(void *value, arbrebinaire *arbre, int (*compar)(void *, void *));
// ajoute value a l'abre et renvoie un nouveau arbre

arbrebinaire *arbrevide(void);
// renvoie un arbre vide aka renvoie le pointeur NULL

void freearbre(arbrebinaire *arbre);
// librere l'espace de l'arbre loue dynamiquement

#endif 