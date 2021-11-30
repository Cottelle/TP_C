#include <stdio.h>
#include "tps_unit_test.h"

#include "types.h"
#include "position.h"
#include "game_io.h"
#include "game.h"

int __remaining_alloc;

void test1(void)
{

    position_t a ={.x=1, .y=1}, b={.x=2, .y=2};
    position_t c = position_add(a, b);


    tps_assert(c.x==3);
    tps_assert(c.y==3);

    position_t d = {.x = 3, .y=3};
    tps_assert(position_equals(d, c));
}

void test_game_load(void)
{
  game_state_t game;
  int ok = load_game("saves/game_1.txt", &game);
  tps_assert(ok);
  tps_assert(!game.over);
  tps_assert(game.map_size == 30);
  tps_assert(game.frame_duration == 200);
  tps_assert(game.length == 1);
  tps_assert(game.fruit.x == 5);
  tps_assert(game.fruit.y == 5);
  tps_assert(game.direction.x == 1);
  tps_assert(game.direction.y == 0);
  tps_assert(game.queue[0].x == 1);
  tps_assert(game.queue[0].y == 2);

  clean_game(&game);
}
void test_game_error_file_not_found(void)
{
  game_state_t game;
  int ok = load_game("chemin qui n'existe pas/game_error_1.txt", &game);
  tps_assert(!ok);
}
void test_game_error_1(void)
{
  game_state_t game;
  int ok = load_game("saves/game_error_1.txt", &game);
  tps_assert(!ok);
}
void test_game_error_2(void)
{
  game_state_t game;
  int ok = load_game("saves/game_error_2.txt", &game);
  tps_assert(!ok);
}
int main(void)
{
  TEST(test1);
  TEST(test_game_load);
  TEST(test_game_error_file_not_found);
  TEST(test_game_error_1);
  TEST(test_game_error_2);
}
