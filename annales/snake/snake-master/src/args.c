#include "args.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "game_io.h"
#include "game.h"

void parse_args(int argc,  char ** argv, game_state_t *game)
{
  init_default_game(game);
  char * load_from = NULL;
  opterr = 0;
  int c;

  while ((c = getopt (argc, argv, "f:s:cl:ho:n")) != -1)
    {
    switch (c)
      {
      case 'o':
        game->last_save_filename = optarg;
        break;
      case 'h':
        print_usage();
        exit(0);
        break;
      case 'f':
        game->frame_duration = (unsigned int)atoll(optarg);
        break;
      case 'l':
        load_from = optarg;
        break;
      case 's':
        game->map_size = (size_t)atoll (optarg);
        if(!game->map_size)
        {
          fputs("option -s should be a size\n",stderr);
          exit(1);
        }
        resize_game(game, game->map_size);
        break;
      case 'c':
        game->use_color_flag = 1;
        break;
      
      case 'n':
        game->Name= optarg;
        break;
      case '?':
        if (optopt == 's' || optopt == 'f')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
        {
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        }
        else
        {
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        }
        print_usage();
        exit(1);
      default:
        fprintf (stderr,
                 "Unknown option character `%c'.\n",
                 c);
        print_usage();
        exit(1);
      }
    if(load_from)
    {
      clean_game(game);
      if(!load_game(load_from, game))
      {
        fprintf(stderr, "Erreur lors du chargement à partir du "
          "fichier de sauvegarde <%s>\n", load_from);
        exit(5);
      }
      printf(
        "Chargement du jeu à partir de la sauvegarde <%s>\n"
        "Les autres options seront ignorée\n",
        load_from);
    }
}
}


void print_usage(void)
{
  puts(
  "Usage:\n"
  "-l FICHIER    permet de charger la partie\n"
  "              contenue dans FICHIER\n"
  "-s TAILLE     taille de la carte\n"
  "-f DUREE      durée d'une frame en milliseconde\n"
  "-c            utiliser la couleur (non implémentée)\n"
  "-h            afficher l'aide");
}
