#include "boningen.h"

void create_boningen(boningen* b) {
  create_mboningen(b->m_bo);
  create_aboningen(b->a_bo);
  create_mboningen_attk(b->m_bo_attk);
  create_aboningen_attk(b->a_bo_attk);
}

void create_mboningen(char b[_BONINGEN_HEIGHT][_BONINGEN_WIDTH]) {
  int i;
  memcpy(b[0], " O ",_BONINGEN_WIDTH);
  memcpy(b[1], "/I\\",_BONINGEN_WIDTH);
  memcpy(b[2], "/\\ ", _BONINGEN_WIDTH);
}

void create_aboningen(char b[_BONINGEN_HEIGHT][_BONINGEN_WIDTH]) {
  int i;
  memcpy(b[0], " O ", _BONINGEN_WIDTH);
  memcpy(b[1], "/I\\", _BONINGEN_WIDTH);
  memcpy(b[2], " /\\", _BONINGEN_WIDTH);
}

void create_mboningen_attk(char b[_BONINGEN_HEIGHT][_BONINGEN_WIDTH]) {
  int i;
  memcpy(b[0], " O ", _BONINGEN_WIDTH);
  memcpy(b[1], "/|-", _BONINGEN_WIDTH);
  memcpy(b[2], "/\\ ", _BONINGEN_WIDTH);
}

void create_aboningen_attk(char b[_BONINGEN_HEIGHT][_BONINGEN_WIDTH]) {
  int i;
  memcpy(b[0], " O ", _BONINGEN_WIDTH);
  memcpy(b[1], "-|\\", _BONINGEN_WIDTH);
  memcpy(b[2], " /\\", _BONINGEN_WIDTH);
}

void print_boningen(char b[_BONINGEN_HEIGHT][_BONINGEN_WIDTH]) {
  int i, j;
  for(i=0; i<BONINGEN_HEIGHT;i++) {
    printf("%s", b[i]);
    printf("|\n");
  }
  printf("\n");
}
void print_b(boningen *b) {
  print_boningen(b->m_bo);
  print_boningen(b->a_bo);
  print_boningen(b->m_bo_attk);
  print_boningen(b->a_bo_attk);
}

