#include "ui.h"
#include "game_io.h"
#include "position.h"

#include <tps.h>

#define WINDOW_SIZE 600

int cell_size(game_state_t *game)
{
  return WINDOW_SIZE / game->map_size;
}

void update_direction(game_state_t *game)
{
  int keyPressed = tps_getKeyPressed();
  if (keyPressed)
  {
    position_t new_direction;
    switch (keyPressed)
    {
    case SDLK_UP:
      new_direction.x = 0;
      new_direction.y = -1;
      break;
    case SDLK_DOWN:
      new_direction.x = 0;
      new_direction.y = 1;
      break;
    case SDLK_LEFT:
      new_direction.x = -1;
      new_direction.y = 0;
      break;
    case SDLK_RIGHT:
      new_direction.x = 1;
      new_direction.y = 0;
      break;
    default:
      return;
    }
    // on applique la nouvelle direction seulement
    // si ça ne nous fait pas faire un virage à 180°
    position_t new_pos = position_add(new_direction, game->queue[0]);
    if (game->length == 1 || !position_equals(new_pos, game->queue[1]))
    {
      game->direction = new_direction;
    }
  }
}

void draw_snake(game_state_t *game)
{
  for (size_t i = 0; i < game->length; i++)
  {
    int cell_s = cell_size(game);
    tps_fillRect(
        cell_s * game->queue[i].x,
        cell_s * game->queue[i].y,
        cell_s, cell_s);
  }
}

void test_game_over(game_state_t *game)
{
  if (
      game->queue[0].x >= game->map_size || game->queue[0].y >= game->map_size || game->queue[0].x < 0 || game->queue[0].y < 0)
  {
    game->over = 1;
    return;
  }

  for (size_t i = 1; i < game->length; i++)
  {
    if (position_equals(game->queue[0], game->queue[i]))
    {
      game->over = 1;
      return;
    }
  }
}
int snake_should_update(game_state_t *game)
{
  static unsigned int last_update;
  last_update += tps_getDeltaTime();
  if (last_update < game->frame_duration)
  {
    return 0;
  }
  last_update -= game->frame_duration;
  return 1;
}
void update_snake(game_state_t *game)
{
  for (size_t i = game->length; i > 0; i--)
  {
    game->queue[i] = game->queue[i - 1];
  }
  game->queue[0].x = game->queue[1].x + game->direction.x;
  game->queue[0].y = game->queue[1].y + game->direction.y;
}

void test_fruit(game_state_t *game)
{
  if (position_equals(game->fruit, game->queue[0]))
  {
    game->length++;
    game->fruit.x = rand() % game->map_size;
    game->fruit.y = rand() % game->map_size;
  }
}

void draw_fruit(game_state_t *game)
{
  tps_setColor(255, 0, 0);
  int cell_s = cell_size(game);
  tps_fillEllipse(
      game->fruit.x * cell_s + cell_s / 2,
      game->fruit.y * cell_s + cell_s / 2,
      cell_s / 2,
      cell_s / 2);
}

void game_loop(game_state_t *game)
{

  tps_createWindow(
      "Snake",
      cell_size(game) * game->map_size,
      cell_size(game) * game->map_size + 10);

  while (tps_isRunning())
  {
    tps_background(255, 255, 255);
    tps_getDeltaTime();
    tps_drawText(6, cell_size(game) * game->map_size + 5, game->Name, 100);

    tps_setColor(0, 0, 0);
    tps_drawText(20, 20, "Appuyer sur Entre pour commencer", 20);
    tps_render();
    if (tps_getKeyPressed() == SDLK_RETURN)
      break;
  }
  while (tps_isRunning())
  {
    tps_drawText(10, cell_size(game) * game->map_size -100 , game->Name, 100);
    tps_background(255, 255, 255);
    tps_setColor(0, 0, 0);

    if (game->over)
    {
      tps_drawText(20, 20, "Game Over", 20);
      tps_render();
      continue;
    }

    if (snake_should_update(game))
    {
      update_snake(game);
      test_game_over(game);
      test_fruit(game);
    }
    update_direction(game);
    draw_snake(game);
    draw_fruit(game);

    tps_render();
  }
  tps_closeWindow();
}
