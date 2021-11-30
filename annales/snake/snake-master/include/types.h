

#ifndef TYPES_H
#define TYPES_H
#include <stdlib.h>

/**
* represente une position sur la carte
*/
typedef struct position_t
{
  short x;
  short y;
} position_t;

/**
* Structure qui stocke l'état du jeu.
*/
typedef struct game_state_t {

  /**
  * Permet de savoir si la couleur doit être utilisée ou non
  */
  unsigned char use_color_flag;

  /**
  * taille de la carte du jeu (la carte est carré donc la taille
  * correspond à la heuteur et à la largeur)
  */
  unsigned char map_size;

  /**
  * durée en milliseconde d'une frame. Permet ainsi de définir le vitesse
  * de déplaceement du serpent.
  */
  unsigned int frame_duration;

  /**
  * tableau qui permet de stocker les positions occupées par
  * la queue du serpent.
  * Le tableau doit être allouée dynamiquement. Ca taille doit être
  * la taille maximum que peut obtenir un serpend, c'est-à-dire le nombre
  * de case sur la carte, c'est-à-dire map_size * map_size .
  * La tête du serpend se situe à l'indice 0 de ce tableau
  */
  position_t *queue;

  /**
  * Représente la direction prise par le serpent
  * Ainsi la prochaine position de la tête sera
  * queue[0] + direction
  */
  position_t direction;

  /**
  * longueur du serpent. Ainsi, cela réprésente aussi
  * le nombre d'éléments du tableau queue effectivement utilisés
  */
  size_t     length;

  /**
  * position du fruit.
  */
  position_t fruit;

  /**
  * le jeu est-il terminé ou non ?
  */
  unsigned char over;

  /**
  * Chemin vers le fichier ou sera sauvegarder
  * la partie lorsque l'on quitte.
  */
  const char *last_save_filename;

  /* Le nom du joueur */
  char *Name;
} game_state_t;


#endif
