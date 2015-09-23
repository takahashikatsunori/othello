/*
    othello.h
*/
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

#define WHITE	1
#define BLACK	0

#define RESOLV_WHITE_WIN 1
#define RESOLV_BLACK_WIN 0
#define RESOLV_DRAW (-1)

typedef struct {
    int piece[8][8];
    int turn;
    int ispassed;
} BOARD;

static BOARD Initial_Board = {
    { -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1,  1,  0, -1, -1, -1,
      -1, -1, -1,  0,  1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1},
    0,
    0
};

