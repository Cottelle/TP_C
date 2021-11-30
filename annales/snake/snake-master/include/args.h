
#ifndef ARGS_H
#define ARGS_H


#include "types.h"

/**
* Parse les arguments de ligne de commande
* et definie les attributs de game en fonction.
*/
void parse_args(int argc,  char ** argv, game_state_t *game);


/**
* Affiche l'aide
*/
void print_usage(void);


#endif
