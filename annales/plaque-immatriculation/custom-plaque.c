#include <stdio.h>
#include <stdlib.h>
#include "generer-plaque.h"

int compar(char *c1,char *c2){
    int b=1;
    for(int i=0;c1[i]!='\0';i++){
        if (c1[i]!=c2[i]){
            b=0;
            break;
        }
    }
    return b;
}

int main(int argc,char **argv){
    char *plaque=malloc(13);
    Personne perso;
    perso.nom = argv[2];
    perso.prenom = argv[1];
    unsigned long i;
    for(i=0;i<1000;i++){
        generer_plaque(perso,i,plaque);
        if (compar(plaque,argv[2])){
            break;
        }

    }
    printf("n=%li\n",i);
    return 0;
}
