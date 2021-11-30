
#include <stdio.h>
#include <stdlib.h>

#include "game.h"


void clean_game(game_state_t *game)
{
  free(game->queue);
}

void resize_game(game_state_t *game, unsigned char map_size)
{
  game->map_size=map_size;
  if(map_size < 5)
  {
    fprintf(stderr,
      "La carte est trop petite (elle doit être"
      "au minimu de taille 5\n");
      exit(5);
  }

  free(game->queue);
  size_t max_snake_length = game->map_size * game->map_size;
  game->queue = calloc(max_snake_length, sizeof(position_t));
  if(game->queue == NULL)
  {
    fprintf(stderr,
      "Impossible d'allouer assez de mémoire pour stocker"
      "la carte du jeu. Le mieux est de changer d'ordinateur "
      "à ce niveau!!\n");
      exit(42);
  }
  game->queue[0].x = game->map_size/2;
  game->queue[0].y = game->map_size/2;
}

void init_default_game(game_state_t *game)
{
  game->Name="John";
  game->frame_duration=500;
  game->use_color_flag = 0;
  game->over = 0;
  game->length=1;
  game->direction.x = 1;
  game->direction.y = 0;
  game->fruit.x = 5;
  game->fruit.y = 5;
  game->queue = NULL;
  game->fruit.x = 5;
  game->fruit.y = 5;
  game->last_save_filename = "saves/last_game.txt";
  resize_game(game, 30);
}
