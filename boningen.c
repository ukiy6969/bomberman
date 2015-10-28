#include "boningen.h"

void create_boningen(boningen* b) {
  create_mboningen(b->m_bo);
  create_aboningen(b->a_bo);
  create_mboningen_attk(b->m_bo_attk);
  create_aboningen_attk(b->a_bo_attk);
}

void create_mboningen(char b[_BONINGEN_HEIGHT][_BONINGEN_WIDTH]) {
  int i;
  memcpy(b[0], "  O  ",BONINGEN_WIDTH);
  memcpy(b[1], " /|\\ ",BONINGEN_WIDTH);
  memcpy(b[2], " /\\  ", BONINGEN_WIDTH);
  for(i = 0; i < BONINGEN_HEIGHT; i++) {
    b[i][_BONINGEN_WIDTH - 1] = '\0';
  }
}

void create_aboningen(char b[_BONINGEN_HEIGHT][_BONINGEN_WIDTH]) {
  int i;
  memcpy(b[0], "  O  ", BONINGEN_WIDTH);
  memcpy(b[1], " /|\\ ", BONINGEN_WIDTH);
  memcpy(b[2], "  /\\ ", BONINGEN_WIDTH);
  for(i = 0; i < BONINGEN_HEIGHT; i++) {
    b[i][_BONINGEN_WIDTH - 1] = '\0';
  }
}

void create_mboningen_attk(char b[_BONINGEN_HEIGHT][_BONINGEN_WIDTH]) {
  int i;
  memcpy(b[0], "  O  ", BONINGEN_WIDTH);
  memcpy(b[1], " /|--", BONINGEN_WIDTH);
  memcpy(b[2], " /\\  ", BONINGEN_WIDTH);
  for(i = 0; i < BONINGEN_HEIGHT; i++) {
    b[i][_BONINGEN_WIDTH - 1] = '\0';
  }
}

void create_aboningen_attk(char b[_BONINGEN_HEIGHT][_BONINGEN_WIDTH]) {
  int i;
  memcpy(b[0], "  O  ", BONINGEN_WIDTH);
  memcpy(b[1], "--|\\", BONINGEN_WIDTH);
  memcpy(b[2], "  /\\ ", BONINGEN_WIDTH);
  for(i = 0; i < BONINGEN_HEIGHT; i++) {
    b[i][_BONINGEN_WIDTH - 1] = '\0';
  }
}

void print_boningen(char b[_BONINGEN_HEIGHT][_BONINGEN_WIDTH]) {
  int i;
  for(i=0; i<BONINGEN_HEIGHT;i++) {
    printf("%s\n", b[i]);
  }
}
void print_b(boningen *b) {
  print_boningen(b->m_bo);
  print_boningen(b->a_bo);
  print_boningen(b->m_bo_attk);
  print_boningen(b->a_bo_attk);
}

