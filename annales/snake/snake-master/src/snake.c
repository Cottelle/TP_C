
#include <stdio.h>

#include "args.h"
#include "types.h"
#include "ui.h"
#include "game_io.h"
#include "game.h"

int main(int argc, char **argv) {



  game_state_t game = {};

  parse_args(argc, argv, &game);

  game_loop(&game);

  save_game(game.last_save_filename, &game);

  clean_game(&game);

  return 0;
}
