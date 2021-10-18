#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "test-tab.h"

#define NB_DIGITS 10
#define ARRAY_SIZE 100
#define MAX_VALUE 9999999999
#define MAX_VALUE_BOB 100000

#define TOLERANCE 0.03


void alice(unsigned long long * tab)
{
  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    long long mult = 1;
    tab[i] = 0;
    for(int d = 0; d < NB_DIGITS; d++)
    {
      tab[i] += mult*(rand()%10);
      mult *= 10;
    }
  }
}

void bob(unsigned long long * tab)
{
  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    unsigned long long v1 = rand()%MAX_VALUE_BOB;
    unsigned long long v2 = rand()%MAX_VALUE_BOB;
    tab[i] = v1*v2;
  }
}



int main(void) {

    srand(time(NULL));

    //Nombre de tests
    int K;
    scanf("%i", &K);

    //Nombre d'erreurs
    int nb_erreur = 0;

    for(int i = 0; i < K; i++) {

        unsigned long long T[ARRAY_SIZE];

        // Le tableau est initialisé par Alice ou Bob
        enum Joueur j = rand()%2 ? ALICE : BOB;
        if(j == ALICE)
        {
          alice(T);
        }
        else
        {
          bob(T);
        }

        // Est-ce que votre fonction détecte le joueur?
        if(test(T, ARRAY_SIZE) != j)
        {
          puts("Pas OK");
          nb_erreur++;
        }
    }


    if (nb_erreur > K*0.3){
      printf("Trop d'erreurs!!\n");
      return 2;
    }
    if (nb_erreur > K*TOLERANCE){
      printf("C'était pas loin!!\n");
      return 1;
    }
    puts("Victoire!!!");
    return 0;
}
