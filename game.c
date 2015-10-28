#include "game.h"

void create_game(game* game) {
  create_boningen(&game->b);
  create_field(game->field);
}

void create_field(char f[_FIELD_HEIGHT][_FIELD_WIDTH]) {
  memcpy(f[0], "                              ", BONINGEN_WIDTH);
  memcpy(f[1], "                              ", BONINGEN_WIDTH);
  memcpy(f[2], "                              ", BONINGEN_WIDTH);
  memcpy(f[3], "                              ", BONINGEN_WIDTH);
  memcpy(f[4], "                              ", BONINGEN_WIDTH);
  memcpy(f[5], "                              ", BONINGEN_WIDTH);
  memcpy(f[6], "                              ", BONINGEN_WIDTH);
  memcpy(f[7], "                              ", BONINGEN_WIDTH);
  memcpy(f[8], "                              ", BONINGEN_WIDTH);
  memcpy(f[9], "------------------------------", BONINGEN_WIDTH);
}

void show_boningen(game *game) {
  int m_x = DEF_M_POS_X;
}

