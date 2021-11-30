#ifndef GAME_H
#define GAME_H

#include "types.h"


/**
* libère la mémoire des attributs de 'game'
* qui ont été dynamiquement alloué lors de
* son initialisation
*/
void clean_game(game_state_t *game);

/**
* redimensionne le plateau de jeu.
* Attention, la taille ne peut pas être inférieur à 5.
*/
void resize_game(game_state_t *game, unsigned char map_size);

/**
* Initialise les attribut de 'game' avec des valeurs par défaut
* En particulier, alloue de la mémoire pour les attributs qui
* doivent être dynamiquement alloué.
*/
void init_default_game(game_state_t *game);


#endif
