#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 4
#define FIRST_TOWER 4,3,2,1

int _c[3][MAX_HEIGHT]={{FIRST_TOWER}, {0}, {0}};

int getTopIndex(int zone) {
  for(int i = 0; i < MAX_HEIGHT; ++i) {
    if(_c[zone][i] == 0) {
      return i-1;
    }
  }
  return MAX_HEIGHT - 1;
}

void printZone(int z) {
  printf("[");
  for(int i = 0; i < MAX_HEIGHT && _c[z][i]; ++i){
    if(i > 0) printf(",");
    printf("%i", _c[z][i]);
  }
  printf("]");
}

void deplacer(int zone1, int zone2) {
  if(zone1 < 1 || zone1 > 3) {
    printf("Erreur: zone %i non valide\n",zone1);
    exit(1);
  }
  if(zone2 < 1 || zone2 > 3) {
    printf("Erreur: zone %i non valide\n",zone2);
    exit(1);
  }
  zone1--;
  zone2--;
  int i1 = getTopIndex(zone1);
  int i2 = getTopIndex(zone2);
  if(i1 < 0 || (i2 >= 0 && _c[zone1][i1] > _c[zone2][i2])) {
    printf("Erreur: impossible de déplacer %i (taille %i) vers %i (taille %i)\n",zone1 + 1, _c[zone1][i1], zone2 + 1, _c[zone2][i2]);
    exit(1);
  }
  _c[zone2][i2 + 1] = _c[zone1][i1];
  _c[zone1][i1] = 0;
  printZone(0);
  printZone(1);
  printZone(2);
  printf("\n");
}
