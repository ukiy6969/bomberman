#include "boningen.h"

#define FIELD_HEIGHT  10
#define FIELD_WIDTH   30

#define _FIELD_HEIGHT 10
#define _FIELD_WIDTH  31

#define DEF_M_POS_X   2
#define DEF_A_POS_Y   28
#define DE_GRD        8

typedef struct {
  boningen b;
  char field[_FIELD_HEIGHT][_FIELD_WIDTH];
} game;

void create_game(game* game);
void create_field(char f[_FIELD_HEIGHT][_FIELD_WIDTH]);
void show_boningen(game *game);

