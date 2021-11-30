
#ifndef GAME_IO_H
#define GAME_IO_H

#include "types.h"

/**
charge l'état du jeu à partir fichier donné
dans la variable game donnée.
retourne 1 si tout se passe bien, 0 sinon
*/
int load_game(const char *path, game_state_t *game);

/**
sauvegarde l'état du jeu dans le fichier donné
retourne 1 si tout se passe bien, 0 sinon
*/
int save_game(const char *path, const game_state_t *game);

#endif
