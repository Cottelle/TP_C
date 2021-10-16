#include <stdio.h>

int getScore(int nbQ, int sumQ){
    if (nbQ>1){
        return nbQ;}
    else{
        return sumQ;
    }
    
    }
int newScore(int score , int point){
    int s= score + point;
    if (s>50){
        return 25;
    }
    else{
        return s;
    }
}

int isWin(int score){
    if (score==50){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void) {
  int score = 0;
  int nbLancer = 0;
  while(!isWin(score)) {

    nbLancer++;
    printf("🎳\nNombre de quilles tombées? ");
    int nbQuilles;
    scanf("%i", &nbQuilles);
    printf("Somme des points des quilles tombées? ");
    int sumQuilles;
    scanf("%i", &sumQuilles);

    int points = getScore(nbQuilles, sumQuilles);

    score = newScore(score, points);

    printf("Vous avez renversé %d quilles dont la somme des"
           " points fait %d, vous marquez donc %d points\n"
           "Votre score est maintenant de %d\n",
           nbQuilles, sumQuilles, points, score);
  }
  printf("Gagné 🏆 🎉 (en %d lancers)\n", nbLancer);
}