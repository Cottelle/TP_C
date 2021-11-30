
#include <stdio.h>
#include <stdlib.h>

#include "game_io.h"

int load_position(FILE *in, position_t *p)
{
  int ok = fscanf(in, "%hd %hd", &p->x, &p->y);
  if (ok == 2)
  {
    return 1;
  }
  return 0;
}

int load_queue(FILE *in, game_state_t *game)
{
  size_t max_snake_length = game->map_size * game->map_size;
  game->queue = calloc(max_snake_length, sizeof(position_t));
  if (game->queue == NULL)
  {
    goto error;
  }

  for (size_t i = 0; i < game->length; i++)
  {
    if (!load_position(in, &game->queue[i]))
    {
      fprintf(stderr, "impossible de lire la position %zu\n", i);
      goto error;
    }
  }

  return 1;

error:
  free(game->queue);
  return 0;
}

int load_game_info(FILE *in, game_state_t *game)
{
  if (fgets(game->Name,1000,in)==NULL)
  {
    fprintf(stderr, "impossible de lire Name\n");
    return 0;
  }
  if (fscanf(in, "%hhu", &game->over) != 1)
  {
    fprintf(stderr, "impossible de lire over\n");
    return 0;
  }
  if (fscanf(in, "%hhu", &game->map_size) != 1)
  {
    fprintf(stderr, "impossible de lire la taille de la carte\n");
    return 0;
  }
  if (fscanf(in, "%hhu", &game->use_color_flag) != 1)
  {
    fprintf(stderr, "impossible de lire color flag\n");
    return 0;
  }
  if (fscanf(in, "%zu", &game->length) != 1)
  {
    fprintf(stderr, "impossible de lire la longueur du serpent\n");
    return 0;
  }
  if (fscanf(in, "%u", &game->frame_duration) != 1)
  {
    fprintf(stderr, "impossible de lire la durée d'une frame\n");
    return 0;
  }
  if (!load_position(in, &game->fruit))
  {
    fprintf(stderr, "impossible de lire la position du fruit\n");
    return 0;
  }
  if (!load_position(in, &game->direction))
  {
    fprintf(stderr, "impossible de lire la direction\n");
    return 0;
  }
  return 1;
}

int load_game(const char *path, game_state_t *game)
{

  FILE *in = fopen(path, "r");
  if (in == NULL)
  {
    fprintf(stderr, "impossible d'ouvrir le fichier\n");
    return 0;
  }

  return load_game_info(in, game) && load_queue(in, game);
}

int save_game(const char *path, const game_state_t *game)
{
  FILE *out = fopen(path, "w");
  fprintf(out, "%hhu\n", game->over);
    fprintf(out, "%hhu\n", game->map_size);
  fprintf(out,"%hhu\n",game->use_color_flag);
  fprintf(out,"%li\n",game->length);
  fprintf(out,"%i\n",game->frame_duration);
  fprintf(out,"%i %i\n",game->fruit.x,game->fruit.y);
  fprintf(out,"%i %i\n",game->direction.x,game->direction.y);
  for (size_t i=0;i<game->length;i++)
  {
    fprintf(out,"%i %i\n",(game->queue)[i].x,(game->queue)[i].y);
  }

  
  fclose(out);
  return 1;
}
