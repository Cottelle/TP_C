

#ifndef POSITION_H
#define POSITION_H

#include "types.h"

/**
* Ajoute deux positions
*/
position_t position_add(position_t a, position_t b);

/**
* test l'égalité entre deux positions
*/
int position_equals(position_t a, position_t b);

#endif
