#ifndef GAME_H_
#define GAME_H_

#define N 3
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

static const int cell_width = SCREEN_WIDTH / N;
static const int cell_height = SCREEN_HEIGHT / N;

enum { EMPTY, PLAYER_X, PLAYER_O };
enum { RUNNING, QUIT };

typedef struct {
    int state;
    int board[N * N];
    int player;
} game_t;

#endif
