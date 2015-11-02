#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BONINGEN_WIDTH 3
#define BONINGEN_HEIGHT 3

#define _BONINGEN_WIDTH 4
#define _BONINGEN_HEIGHT 3

typedef struct {
  char m_bo[_BONINGEN_HEIGHT][_BONINGEN_WIDTH];
  char a_bo[_BONINGEN_HEIGHT][_BONINGEN_WIDTH];
  char m_bo_attk[_BONINGEN_HEIGHT][_BONINGEN_WIDTH];
  char a_bo_attk[_BONINGEN_HEIGHT][_BONINGEN_WIDTH];
} boningen;

extern void create_boningen(boningen* b);

extern void create_mboningen(char b[_BONINGEN_HEIGHT][_BONINGEN_WIDTH]);

extern void create_aboningen(char b[_BONINGEN_HEIGHT][_BONINGEN_WIDTH]);

extern void create_mboningen_attk(char b[_BONINGEN_HEIGHT][_BONINGEN_WIDTH]);

extern void create_aboningen_attk(char b[_BONINGEN_HEIGHT][_BONINGEN_WIDTH]);

extern void print_boningen(char boningen[_BONINGEN_HEIGHT][_BONINGEN_WIDTH]);
