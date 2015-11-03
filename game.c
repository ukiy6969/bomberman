#include "game.h"

void create_game(game* game) {
  create_boningen(&game->b);
  create_field(game->field);
  create_lose(game->lose);
  create_win(game->win);
  create_draw(game->draw);
  game->m_b_x = DEF_M_POS_X;
  game->m_b_y = DEF_GRD;
  game->a_b_x = DEF_A_POS_X;
  game->a_b_y = DEF_GRD;
  game->m_bomb[0] = 0;
  game->m_bomb[1] = 0;
  game->a_bomb[0] = 0;
  game->a_bomb[1] = 0;
  game->m_is_bomb = 0;
  game->a_is_bomb = 0;
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

void create_lose(char f[_FIELD_HEIGHT][_FIELD_WIDTH]) {
  memcpy(f[0],  "-----------------------------------", _FIELD_WIDTH);
  memcpy(f[1],  "|                                 |", _FIELD_WIDTH);
  memcpy(f[2],  "|   #      ###   ####  ####       |", _FIELD_WIDTH);
  memcpy(f[3],  "|   #     #   #   #    #          |", _FIELD_WIDTH);
  memcpy(f[4],  "|   #     #   #    #   ####       |", _FIELD_WIDTH);
  memcpy(f[5],  "|   #     #   #     #  #          |", _FIELD_WIDTH);
  memcpy(f[6],  "|   ####   ###   ####  ####       |", _FIELD_WIDTH);
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
void create_win(char f[_FIELD_HEIGHT][_FIELD_WIDTH]) {
  memcpy(f[0],  "-----------------------------------", _FIELD_WIDTH);
  memcpy(f[1],  "|                                 |", _FIELD_WIDTH);
  memcpy(f[2],  "|   #  #  #  ###  ##   #          |", _FIELD_WIDTH);
  memcpy(f[3],  "|   # # # #   #   ##   #          |", _FIELD_WIDTH);
  memcpy(f[4],  "|   # # # #   #   # #  #          |", _FIELD_WIDTH);
  memcpy(f[5],  "|    #   #    #   #  # #          |", _FIELD_WIDTH);
  memcpy(f[6],  "|    #   #   ###  #   ##          |", _FIELD_WIDTH);
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
void create_draw(char f[_FIELD_HEIGHT][_FIELD_WIDTH]) {
  memcpy(f[0],  "-----------------------------------", _FIELD_WIDTH);
  memcpy(f[1],  "|                                 |", _FIELD_WIDTH);
  memcpy(f[2],  "| ####    ####      #    #  #  #  |", _FIELD_WIDTH);
  memcpy(f[3],  "| #   #   #  #     # #   # # # #  |", _FIELD_WIDTH);
  memcpy(f[4],  "| #    #  ###     #####  # # # #  |", _FIELD_WIDTH);
  memcpy(f[5],  "| #   #   #  #    #   #   #   #   |", _FIELD_WIDTH);
  memcpy(f[6],  "| ####    #   #  #     #  #   #   |", _FIELD_WIDTH);
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



int set_bomb_m(game *g) {
  int x = g->m_b_x;
  int y = g->m_b_y - 1;
  if ( (x - 1) % 3 == 1 && (y - 1) % 3 == 1 && !g->m_is_bomb) {
    g->m_bomb[0] = x;
    g->m_bomb[1] = y;
    g->m_is_bomb = 1;
    return 1;
  }
  return 0;
}

int set_bomb_a(game *g) {
  int x = g->a_b_x;
  int y = g->a_b_y - 1;
  if ( (x - 1) % 3 == 1 && (y - 1) % 3 == 1 && !g->a_is_bomb) {
    g->a_bomb[0] = x;
    g->a_bomb[1] = y;
    g->a_is_bomb = 1;
    return 1;
  }
  return 0;
}

void* bomb_thread_m(void *args) {
  bomb_args *bargs = (bomb_args *)args;
  game *g = bargs->game;
  int sleeptime = bargs->sleep;
  int i, j;
  int attackm = 0, attacka = 0;
  sleep(sleeptime);
  if (! g->m_is_bomb ){
    return NULL;
  }
  for(i = g->m_bomb[0]; i >= MAX_LEFT; i--) {
    if (g->field[g->m_bomb[1]][i] == '-' ||
        g->field[g->m_bomb[1]][i] == '|' ||
        g->field[g->m_bomb[1]][i] == '#'){
        break;
    }
    g->field[g->m_bomb[1]][i] = '*';
    g->field[g->m_bomb[1]-1][i] = '*';
    g->field[g->m_bomb[1]+1][i] = '*';
  }
  for(i = g->m_bomb[0]; i <= MAX_RIGHT+1; i++) {
    if (g->field[g->m_bomb[1]][i] == '-' ||
        g->field[g->m_bomb[1]][i] == '|' ||
        g->field[g->m_bomb[1]][i] == '#'){
      break;
    }
    g->field[g->m_bomb[1]][i] = '*';
    g->field[g->m_bomb[1]-1][i] = '*';
    g->field[g->m_bomb[1]+1][i] = '*';
  }
  for(i = g->m_bomb[1]; i >= MAX_UP; i--) {
    if (g->field[i][g->m_bomb[0]] == '-' ||
        g->field[i][g->m_bomb[0]] == '|' ||
        g->field[i][g->m_bomb[0]] == '#'){
      break;
    }
    g->field[i][g->m_bomb[0]] = '*';
    g->field[i][g->m_bomb[0]-1] = '*';
    g->field[i][g->m_bomb[0]+1] = '*';
  }
  for(i = g->m_bomb[1]; i <= MAX_DOWN; i++) {
    if (g->field[i][g->m_bomb[0]] == '-' ||
        g->field[i][g->m_bomb[0]] == '|' ||
        g->field[i][g->m_bomb[0]] == '#'){
        break;
    }
    g->field[i][g->m_bomb[0]] = '*';
    g->field[i][g->m_bomb[0]-1] = '*';
    g->field[i][g->m_bomb[0]+1] = '*';
  }
  print_field(g);
  for(i = g->m_bomb[0]; i >= MAX_LEFT; i--) {
    if (g->field[g->m_bomb[1]][i] == '-' ||
        g->field[g->m_bomb[1]][i] == '|' ||
        g->field[g->m_bomb[1]][i] == '#'){
        break;
    }
    if ( ((g->m_bomb[1]+1) == g->m_b_y && i == g->m_b_x) &&
         ((g->m_bomb[1]+1) == g->a_b_y && i == g->a_b_x)    ){
      attackm = 1;
      attacka = 1;
    } else if ( (g->m_bomb[1]+1) == g->m_b_y && i == g->m_b_x) {
      attackm = 1;
    } else if ( (g->m_bomb[1]+1) == g->a_b_y && i == g->a_b_x ) {
      attacka = 1;
    }
    g->field[g->m_bomb[1]][i] = ' ';
    g->field[g->m_bomb[1]-1][i] = ' ';
    g->field[g->m_bomb[1]+1][i] = ' ';
  }
  for(i = g->m_bomb[0]; i <= MAX_RIGHT+1; i++) {
    if (g->field[g->m_bomb[1]][i] == '-' ||
        g->field[g->m_bomb[1]][i] == '|' ||
        g->field[g->m_bomb[1]][i] == '#'){
      break;
    }
    if ( ((g->m_bomb[1]+1) == g->m_b_y && i == g->m_b_x) &&
         ((g->m_bomb[1]+1) == g->a_b_y && i == g->a_b_x)    ){
      attacka = 1;
      attackm = 1;
    } else if ( (g->m_bomb[1]+1) == g->m_b_y && i == g->m_b_x) {
      attackm = 1;
    } else if ( (g->m_bomb[1]+1) == g->a_b_y && i == g->a_b_x ) {
      attacka = 1;
    }
    g->field[g->m_bomb[1]][i] = ' ';
    g->field[g->m_bomb[1]-1][i] = ' ';
    g->field[g->m_bomb[1]+1][i] = ' ';
  }
  for(i = g->m_bomb[1]; i >= MAX_UP; i--) {
    if (g->field[i][g->m_bomb[0]] == '-' ||
        g->field[i][g->m_bomb[0]] == '|' ||
        g->field[i][g->m_bomb[0]] == '#'){
      break;
    }
    if ( ((g->m_bomb[0]) == g->m_b_x && i == g->m_b_y) &&
         ((g->m_bomb[0]) == g->a_b_x && i == g->a_b_y)    ){
      attackm = 1;
      attacka = 1;
    } else if ( (g->m_bomb[0]) == g->m_b_x && i == g->m_b_y) {
      attackm = 1;
    } else if ( (g->m_bomb[0]) == g->a_b_x && i == g->a_b_y ) {
      attacka = 1;
    }
    g->field[i][g->m_bomb[0]] = ' ';
    g->field[i][g->m_bomb[0]-1] = ' ';
    g->field[i][g->m_bomb[0]+1] = ' ';
  }
  for(i = g->m_bomb[1]; i <= MAX_DOWN; i++) {
    if (g->field[i][g->m_bomb[0]] == '-' ||
        g->field[i][g->m_bomb[0]] == '|' ||
        g->field[i][g->m_bomb[0]] == '#'){
      break;
    }
    if ( ((g->m_bomb[0]) == g->m_b_x && i == g->m_b_y) &&
         ((g->m_bomb[0]) == g->a_b_x && i == g->a_b_y)    ){
      attackm = 1;
      attacka = 1;
    } else if ( (g->m_bomb[0]) == g->m_b_x && i == g->m_b_y) {
      attackm = 1;
    } else if ( (g->m_bomb[0]) == g->a_b_x && i == g->a_b_y ) {
      attacka = 1;
    }
    g->field[i][g->m_bomb[0]] = ' ';
    g->field[i][g->m_bomb[0]-1] = ' ';
    g->field[i][g->m_bomb[0]+1] = ' ';
  }
  if ( attacka == 1 && attackm  == 1) {
    g->kekka = KEKKA_DRAW;
    print_field(g);
  } else if ( attacka && g->position == 1) {
    g->kekka = KEKKA_LOSE;
    print_field(g);
  } else if ( attacka && g->position == 0) {
    g->kekka = KEKKA_WIN;
    print_field(g);
  } else if (attackm && g->position == 1) {
    g->kekka = KEKKA_WIN;
    print_field(g);
  } else if (attackm && g->position == 0) {
    g->kekka = KEKKA_LOSE;
    print_field(g);
  }
  sleep(sleeptime);
  g->m_bomb[0] = 0;
  g->m_bomb[1] = 0;
  print_field(g);
  g->m_is_bomb = 0;
    return NULL;
}

void* bomb_thread_a(void *args) {
  bomb_args *bargs = (bomb_args *)args;
  game *g = bargs->game;
  int sleeptime = bargs->sleep;
  int i, j;
  int kekka;
  int attackm = 0, attacka = 0;
  sleep(sleeptime);
  if (! g->a_is_bomb ){
    return NULL;
  }
  for(i = g->a_bomb[0]; i >= MAX_LEFT; i--) {
    if (g->field[g->a_bomb[1]][i] == '-' ||
        g->field[g->a_bomb[1]][i] == '|' ||
        g->field[g->a_bomb[1]][i] == '#'){
        break;
    }
    g->field[g->a_bomb[1]][i] = '*';
    g->field[g->a_bomb[1]-1][i] = '*';
    g->field[g->a_bomb[1]+1][i] = '*';
  }
  for(i = g->a_bomb[0]; i <= MAX_RIGHT+1; i++) {
    if (g->field[g->a_bomb[1]][i] == '-' ||
        g->field[g->a_bomb[1]][i] == '|' ||
        g->field[g->a_bomb[1]][i] == '#'){
      break;
    }
    g->field[g->a_bomb[1]][i] = '*';
    g->field[g->a_bomb[1]-1][i] = '*';
    g->field[g->a_bomb[1]+1][i] = '*';
  }
  for(i = g->a_bomb[1]; i >= MAX_UP; i--) {
    if (g->field[i][g->a_bomb[0]] == '-' ||
        g->field[i][g->a_bomb[0]] == '|' ||
        g->field[i][g->a_bomb[0]] == '#'){
      break;
    }
    g->field[i][g->a_bomb[0]] = '*';
    g->field[i][g->a_bomb[0]-1] = '*';
    g->field[i][g->a_bomb[0]+1] = '*';
  }
  for(i = g->a_bomb[1]; i <= MAX_DOWN; i++) {
    if (g->field[i][g->a_bomb[0]] == '-' ||
        g->field[i][g->a_bomb[0]] == '|' ||
        g->field[i][g->a_bomb[0]] == '#'){
        break;
    }
    g->field[i][g->a_bomb[0]] = '*';
    g->field[i][g->a_bomb[0]-1] = '*';
    g->field[i][g->a_bomb[0]+1] = '*';
  }
  print_field(g);
  for(i = g->a_bomb[0]; i >= MAX_LEFT; i--) {
    if (g->field[g->a_bomb[1]][i] == '-' ||
        g->field[g->a_bomb[1]][i] == '|' ||
        g->field[g->a_bomb[1]][i] == '#'){
        break;
    }
    if ( ((g->a_bomb[1]+1) == g->m_b_y && i == g->m_b_x) &&
         ((g->a_bomb[1]+1) == g->a_b_y && i == g->a_b_x)    ){
      attackm = 1;
      attacka = 1;
    } else if ( (g->a_bomb[1]+1) == g->m_b_y && i == g->m_b_x) {
      attackm = 1;
    } else if ( (g->a_bomb[1]+1) == g->a_b_y && i == g->a_b_x ) {
      attacka = 1;
    }
    g->field[g->a_bomb[1]][i] = ' ';
    g->field[g->a_bomb[1]-1][i] = ' ';
    g->field[g->a_bomb[1]+1][i] = ' ';
  }
  for(i = g->a_bomb[0]; i <= MAX_RIGHT+1; i++) {
    if (g->field[g->a_bomb[1]][i] == '-' ||
        g->field[g->a_bomb[1]][i] == '|' ||
        g->field[g->a_bomb[1]][i] == '#'){
      break;
    }
    if ( ((g->a_bomb[1]+1) == g->m_b_y && i == g->m_b_x) &&
         ((g->a_bomb[1]+1) == g->a_b_y && i == g->a_b_x)    ){
      attackm = 1;
      attacka = 1;
    } else if ( (g->m_bomb[1]+1) == g->m_b_y && i == g->m_b_x) {
      attackm = 1;
    } else if ( (g->m_bomb[1]+1) == g->a_b_y && i == g->a_b_x ) {
      attacka = 1;
    }
    g->field[g->a_bomb[1]][i] = ' ';
    g->field[g->a_bomb[1]-1][i] = ' ';
    g->field[g->a_bomb[1]+1][i] = ' ';
  }
  for(i = g->a_bomb[1]; i >= MAX_UP; i--) {
    if (g->field[i][g->a_bomb[0]] == '-' ||
        g->field[i][g->a_bomb[0]] == '|' ||
        g->field[i][g->a_bomb[0]] == '#'){
      break;
    }
    if ( ((g->a_bomb[0]) == g->m_b_x && i == g->m_b_y) &&
         ((g->a_bomb[0]) == g->a_b_x && i == g->a_b_y)    ){
      attackm = 1;
      attacka = 1;
    } else if ( (g->m_bomb[0]) == g->m_b_x && i == g->m_b_y) {
      attackm = 1;
    } else if ( (g->m_bomb[0]) == g->a_b_x && i == g->a_b_y ) {
      attacka = 1;
    }
    g->field[i][g->a_bomb[0]] = ' ';
    g->field[i][g->a_bomb[0]-1] = ' ';
    g->field[i][g->a_bomb[0]+1] = ' ';
  }
  for(i = g->a_bomb[1]; i <= MAX_DOWN; i++) {
    if (g->field[i][g->a_bomb[0]] == '-' ||
        g->field[i][g->a_bomb[0]] == '|' ||
        g->field[i][g->a_bomb[0]] == '#'){
      break;
    }
    if ( ((g->a_bomb[0]) == g->m_b_x && i == g->m_b_y) &&
         ((g->a_bomb[0]) == g->a_b_x && i == g->a_b_y)    ){
      attackm = 1;
      attacka = 1;
    } else if ( (g->m_bomb[0]) == g->m_b_x && i == g->m_b_y) {
      attackm = 1;
    } else if ( (g->m_bomb[0]) == g->a_b_x && i == g->a_b_y ) {
      attacka = 1;
    }
    g->field[i][g->a_bomb[0]] = ' ';
    g->field[i][g->a_bomb[0]-1] = ' ';
    g->field[i][g->a_bomb[0]+1] = ' ';
  }
  if ( attacka == 1 && attackm == 1 ) {
    sleep(1);
    g->kekka = KEKKA_DRAW;
    print_field(g);
  } else if ( attacka && g->position == 1) {
    sleep(1);
    g->kekka = KEKKA_LOSE;
    print_field(g);
  } else if ( attacka && g->position == 0) {
    sleep(1);
    g->kekka = KEKKA_WIN;
    print_field(g);
  } else if (attackm && g->position == 1) {
    sleep(1);
    g->kekka = KEKKA_WIN;
    print_field(g);
  } else if (attackm && g->position == 0) {
    sleep(1);
    g->kekka = KEKKA_LOSE;
    print_field(g);
  }
  sleep(sleeptime);
  g->a_bomb[0] = 0;
  g->a_bomb[1] = 0;
  print_field(g);
  g->a_is_bomb = 0;
    return NULL;
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
  if ( !( game->m_bomb[0] == 0 && game->m_bomb[1] == 0) ) {
    game->field[game->m_bomb[1]][game->m_bomb[0]] = '@';
  }
  if ( !( game->a_bomb[0] == 0 && game->a_bomb[1] == 0) ) {
    game->field[game->a_bomb[1]][game->a_bomb[0]] = '@';
  }
  fprintf(stderr,  "\n");
  system("/bin/stty cooked");
  system("clear");
  if (game->kekka == KEKKA_DRAW){
    for (i = 0; i < _FIELD_HEIGHT; i++) {
      fprintf(stderr, "%s\n", game->draw[i]);
    }
  }else if (game->kekka == KEKKA_LOSE) {
    for (i = 0; i < _FIELD_HEIGHT; i++) {
      fprintf(stderr, "%s\n", game->lose[i]);
    }
  }else if (game->kekka == KEKKA_WIN) {
    for (i = 0; i < _FIELD_HEIGHT; i++) {
      fprintf(stderr, "%s\n", game->win[i]);
    }
  }else {
    for (i = 0; i < _FIELD_HEIGHT; i++) {
      fprintf(stderr, "%s\n", game->field[i]);
    }
  }
  system("/bin/stty raw");
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
  if ( ! moval_m_b(g, MOVE_DIFF, 0) ){
    return ;
  }
  clear_b(g, g->m_b_x, g->m_b_y);
  show_m_b(g, g->m_b_x + MOVE_DIFF, g->m_b_y);
}

void move_m_b_left(game*g) {
  if ( ! moval_m_b(g, -MOVE_DIFF, 0) ){
    return ;
  }
  clear_b(g, g->m_b_x, g->m_b_y);
  show_m_b(g, g->m_b_x - MOVE_DIFF, g->m_b_y);
}

void move_m_b_up(game*g) {
  if ( ! moval_m_b(g, 0, -MOVE_DIFF) ){
    return ;
  }
  clear_b(g, g->m_b_x, g->m_b_y);
  show_m_b(g, g->m_b_x, g->m_b_y - MOVE_DIFF);
}

void move_m_b_down(game*g) {
  if ( ! moval_m_b(g, 0, MOVE_DIFF) ){
    return ;
  }
  clear_b(g, g->m_b_x, g->m_b_y);
  show_m_b(g, g->m_b_x, g->m_b_y + MOVE_DIFF);
}
void move_a_b_right(game*g) {
  if ( ! moval_a_b(g, MOVE_DIFF, 0) ){
    return ;
  }
  clear_b(g, g->a_b_x, g->a_b_y);
  show_a_b(g, g->a_b_x + MOVE_DIFF, g->a_b_y);
}

void move_a_b_left(game*g) {
  if ( ! moval_a_b(g, -MOVE_DIFF, 0) ){
    return ;
  }
  clear_b(g, g->a_b_x, g->a_b_y);
  show_a_b(g, g->a_b_x - MOVE_DIFF, g->a_b_y);
}

void move_a_b_up(game*g) {
  if ( ! moval_a_b(g, 0, -MOVE_DIFF) ){
    return ;
  }
  clear_b(g, g->a_b_x, g->a_b_y);
  show_a_b(g, g->a_b_x, g->a_b_y - MOVE_DIFF);
}

void move_a_b_down(game*g) {
  if ( ! moval_a_b(g, 0, MOVE_DIFF) ){
    return ;
  }
  clear_b(g, g->a_b_x, g->a_b_y);
  show_a_b(g, g->a_b_x, g->a_b_y + MOVE_DIFF);
}

