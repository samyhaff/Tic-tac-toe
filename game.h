#ifndef GAME_H_
#define GAME_H_

#define N 3
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define AI_DEPTH 9

static const int cell_width = SCREEN_WIDTH / N;
static const int cell_height = SCREEN_HEIGHT / N;

enum { EMPTY, PLAYER_X, PLAYER_O };
enum { RUNNING, QUIT, PLAYER_O_WIN, TIE, PLAYER_X_WIN };

typedef struct {
    int state;
    int board[N * N];
    int player;
} game_t;

#endif
