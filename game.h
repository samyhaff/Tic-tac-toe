#ifndef GAME_H_
#define GAME_H_

#define N 3
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

enum { EMPTY, PLAYER_X, PLAYER_O };
enum { RUNNING, QUIT };

typedef struct {
    int state;
    int board[N * N];
} game_t;

#endif
