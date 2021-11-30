#include "position.h"

position_t position_add(position_t a, position_t b)
{
  position_t sum = {
    .x = a.x + b.x,
    .y = a.y + b.y
  };
  return sum;
}




int position_equals(position_t a, position_t b)
{
  return a.x == b.x && a.y == b.y;
}
