#include <stdio.h>
#include <stdlib.h>

    int countesc(int n){                //pas optimal il faudrait faire une liste des countesc deja calculer
        int tab[n];
        tab[0]=1;
        tab[1]=2;
        int i =1;
        while (i<n){
        i++;
        tab[i]=tab[i-1]+tab[i-2];
        }
        return tab[n-1];
    }

int main(int argc, char **argv ){
    if(argc != 2){
        return 1;
    }
    int n = atoi(argv[1]);
    if (n<=0){
        return 1;
    }
    printf("%i\n",countesc(n));
    return 0;
}