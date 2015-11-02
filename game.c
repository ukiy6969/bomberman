#include "game.h"

void create_game(game* game) {
  create_boningen(&game->b);
  create_field(game->field);
  game->m_b_x = DEF_M_POS_X;
  game->m_b_y = DEF_GRD;
  game->a_b_x = DEF_A_POS_X;
  game->a_b_y = DEF_GRD;
}

void create_field(char f[_FIELD_HEIGHT][_FIELD_WIDTH]) {
  memcpy(f[0],  "-----------------------------------", _FIELD_WIDTH);
  memcpy(f[1],  "|                                 |", _FIELD_WIDTH);
  memcpy(f[2],  "|                                 |", _FIELD_WIDTH);
  memcpy(f[3],  "|                                 |", _FIELD_WIDTH);
  memcpy(f[4],  "|   ###   ###   ###   ###   ###   |", _FIELD_WIDTH);
  memcpy(f[5],  "|   ###   ###   ###   ###   ###   |", _FIELD_WIDTH);
  memcpy(f[6],  "|   ###   ###   ###   ###   ###   |", _FIELD_WIDTH);
  memcpy(f[7],  "|                                 |", _FIELD_WIDTH);
  memcpy(f[8],  "|                                 |", _FIELD_WIDTH);
  memcpy(f[9],  "|                                 |", _FIELD_WIDTH);
  memcpy(f[10], "|   ###   ###   ###   ###   ###   |", _FIELD_WIDTH);
  memcpy(f[11], "|   ###   ###   ###   ###   ###   |", _FIELD_WIDTH);
  memcpy(f[12], "|   ###   ###   ###   ###   ###   |", _FIELD_WIDTH);
  memcpy(f[13], "|                                 |", _FIELD_WIDTH);
  memcpy(f[14], "|                                 |", _FIELD_WIDTH);
  memcpy(f[15], "|                                 |", _FIELD_WIDTH);
  memcpy(f[16], "|   ###   ###   ###   ###   ###   |", _FIELD_WIDTH);
  memcpy(f[17], "|   ###   ###   ###   ###   ###   |", _FIELD_WIDTH);
  memcpy(f[18], "|   ###   ###   ###   ###   ###   |", _FIELD_WIDTH);
  memcpy(f[19], "|                                 |", _FIELD_WIDTH);
  memcpy(f[20], "|                                 |", _FIELD_WIDTH);
  memcpy(f[21], "|                                 |", _FIELD_WIDTH);
  memcpy(f[22], "-----------------------------------", _FIELD_WIDTH);
}

void show_boningen(game *game) {
  int m_x = DEF_M_POS_X,
      m_y = DEF_GRD,
      a_x = DEF_A_POS_X,
      a_y = DEF_GRD,
      b_w = BONINGEN_WIDTH / 2;

  show_m_b(game, m_x, m_y);
  show_a_b(game, a_x, a_y);
  //clear_b(game, a_x, a_y);

}

void show_m_b(game *game, int x, int y) {
  int i, j;
  int w = BONINGEN_WIDTH / 2;
  int h = BONINGEN_HEIGHT - 1;
  int bx = 0, by = 0;
  game->m_b_x = x;
  game->m_b_y = y;
  for (j = y - h; j <= y; j++) {
    for(i = x - w; i <= x + w; i++) {
      game->field[j][i] = game->b.m_bo[by][bx];
      bx++;
    }
    bx=0;
    by++;
  }
}

void show_a_b(game *game, int x, int y) {
  int i, j;
  int w = BONINGEN_WIDTH / 2;
  int h = BONINGEN_HEIGHT - 1;
  int bx = 0, by = 0;
  game->a_b_x = x;
  game->a_b_y = y;
  for (j = y - h; j <= y; j++) {
    for(i = x - w; i <= x + w; i++) {
      game->field[j][i] = game->b.a_bo[by][bx];
      bx++;
    }
    bx=0;
    by++;
  }
}

int moval_m_b(game *g, int dx, int dy) {
  int i, j;
  int w = BONINGEN_WIDTH / 2;
  int h = BONINGEN_HEIGHT - 1;
  int x = g->m_b_x + dx;
  int y = g->m_b_y + dy;
  for (j = y - h; j <= y; j++) {
    for(i = x - w; i <= x + w; i++) {
      if (g->field[j][i] == '|'
         || g->field[j][i] == '-'
         || g->field[j][i] == '#'){
        return 0;
      }
    }
  }
  return 1;
}

int moval_a_b(game *g, int dx, int dy) {
  int i, j;
  int w = BONINGEN_WIDTH / 2;
  int h = BONINGEN_HEIGHT - 1;
  int x = g->a_b_x + dx;
  int y = g->a_b_y + dy;
  for (j = y - h; j <= y; j++) {
    for(i = x - w; i <= x + w; i++) {
      if (g->field[j][i] == '|'
         || g->field[j][i] == '-'
         || g->field[j][i] == '#'){
        return 0;
      }
    }
  }
  return 1;
}

void clear_b(game *game, int x, int y) {
  int i, j;
  int w = BONINGEN_WIDTH / 2;
  int h = BONINGEN_HEIGHT - 1;
  int bx = 0, by = 0;
  for (j = y - h; j <= y; j++) {
    for(i = x - w; i <= x + w; i++) {
      game->field[j][i] = ' ';
      bx++;
    }
    bx=0;
    by++;
  }
}

void print_field(game *game) {
  int i, j;
  //system("clear");
  fprintf(stderr,  "\n");
  for (i = 0; i < _FIELD_HEIGHT; i++) {
    fprintf(stderr, "%s\n", game->field[i]);
  }
}

int move(game* g, int position, int c) {
  if (position == 0) {
    if (c == '.'){
      return 1;
    }
    if (c == KEY_RIGHT ) {
      move_m_b_right(g);
    }
    if (c == KEY_LEFT ) {
      move_m_b_left(g);
    }
    if (c == KEY_UP ) {
      move_m_b_up(g);
    }
    if (c == KEY_DOWN ) {
      move_m_b_down(g);
    }
    if (c == 32) {
    }
  } else {
    if (c == '.') {
      return 1;
    }
    if (c == KEY_RIGHT ) {
      move_a_b_right(g);
    }
    if (c == KEY_LEFT ) {
      move_a_b_left(g);
    }
    if (c == KEY_UP ) {
      move_a_b_up(g);
    }
    if (c == KEY_DOWN ) {
      move_a_b_down(g);
    }
    if (c == 32) {
    }
  }
  return 0;
}



void move_m_b_right(game*g) {
  if ( ! moval_m_b(g, 1, 0) ){
    return ;
  }
  clear_b(g, g->m_b_x, g->m_b_y);
  show_m_b(g, g->m_b_x + 1, g->m_b_y);
}

void move_m_b_left(game*g) {
  if ( ! moval_m_b(g, -1, 0) ){
    return ;
  }
  clear_b(g, g->m_b_x, g->m_b_y);
  show_m_b(g, g->m_b_x - 1, g->m_b_y);
}

void move_m_b_up(game*g) {
  if ( ! moval_m_b(g, 0, -1) ){
    return ;
  }
  clear_b(g, g->m_b_x, g->m_b_y);
  show_m_b(g, g->m_b_x, g->m_b_y - 1);
}

void move_m_b_down(game*g) {
  if ( ! moval_m_b(g, 0, 1) ){
    return ;
  }
  clear_b(g, g->m_b_x, g->m_b_y);
  show_m_b(g, g->m_b_x, g->m_b_y + 1);
}
void move_a_b_right(game*g) {
  if ( ! moval_a_b(g, 1, 0) ){
    return ;
  }
  clear_b(g, g->a_b_x, g->a_b_y);
  show_a_b(g, g->a_b_x + 1, g->a_b_y);
}

void move_a_b_left(game*g) {
  if ( ! moval_a_b(g, -1, 0) ){
    return ;
  }
  clear_b(g, g->a_b_x, g->a_b_y);
  show_a_b(g, g->a_b_x - 1, g->a_b_y);
}

void move_a_b_up(game*g) {
  if ( ! moval_a_b(g, 0, -1) ){
    return ;
  }
  clear_b(g, g->a_b_x, g->a_b_y);
  show_a_b(g, g->a_b_x, g->a_b_y - 1);
}

void move_a_b_down(game*g) {
  if ( ! moval_a_b(g, 0, 1) ){
    return ;
  }
  clear_b(g, g->a_b_x, g->a_b_y);
  show_a_b(g, g->a_b_x, g->a_b_y + 1);
}

