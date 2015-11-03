#include "boningen.h"
#include <pthread.h>
#include <unistd.h>
#define FIELD_HEIGHT  23
#define FIELD_WIDTH   35

#define _FIELD_HEIGHT 23
#define _FIELD_WIDTH  36

#define MAX_LEFT      1
#define MAX_RIGHT     32
#define MAX_UP        1
#define MAX_DOWN      21

#define DEF_M_POS_X   2
#define DEF_A_POS_X   32
#define DEF_GRD       21

#define KEY_UP        'w'
#define KEY_DOWN      's'
#define KEY_RIGHT     'd'
#define KEY_LEFT      'a'
#define BOMB          ' '

#define MOVE_DIFF      3

typedef struct {
  boningen b;
  int position;
  char field[_FIELD_HEIGHT][_FIELD_WIDTH];
  int m_b_x;
  int m_b_y;
  int a_b_x;
  int a_b_y;
  int m_bomb[2];
  int a_bomb[2];
  int m_is_bomb;
  int a_is_bomb;
} game;

typedef struct {
  int sleep;
  game *game;
} bomb_args;

void create_game(game* game);
void create_field(char f[_FIELD_HEIGHT][_FIELD_WIDTH]);
void show_boningen(game *game);
void show_m_b(game *game, int x, int y);
void show_a_b(game *game, int x, int y);
void clear_b(game *game, int x, int y);
void print_field(game *game);
int move(game* game, int turn, int dir);
void move_m_b_right(game* g);
void move_m_b_left(game* g);
void move_m_b_up(game* g);
void move_m_b_down(game* g);
void move_a_b_right(game* g);
void move_a_b_left(game* g);
void move_a_b_up(game* g);
void move_a_b_down(game* g);
int set_bomb_m(game *g);
void* bomb_thread_m(void *args);
int set_bomb_a(game *g);
void* bomb_thread_a(void *args);
