#include <stdio.h>
#include "game.h"

int update_board(game_t *game, int x, int y) {
    int cell_idx = N * (y / cell_height) + (x / cell_width);
    if ((cell_idx < 0) | (cell_idx > N*N)) return 0;
    if (game->board[cell_idx] != EMPTY) return 0;
    game->board[cell_idx] = game->player;
    return 1;
}

void switch_player(game_t *game) {
    game->player = game->player == PLAYER_X ? PLAYER_O : PLAYER_X;
}

int check_player_win(game_t *game, int player) {
    int count_diag_1 = 0;
    int count_diag_2 = 0;
    for (int i = 0; i < N; i++) {
        int count_x = 0;
        int count_y = 0;
        for (int j = 0; j < N; j++) {
            if (game->board[i * N + j] == player) count_x++;
            if (game->board[j * N + i] == player) count_y++;
        }
        if ((count_x == N) | (count_y == N)) return 1;
        if (game->board[i * N + i] == player) count_diag_1++;
        if (game->board[i * N + N - 1 - i] == player) count_diag_2++;
    }
    if ((count_diag_1 == N) | (count_diag_2 == N)) return 1;
    return 0;
}

void reset_game(game_t *game) {
    for (int i = 0; i < N * N; i++) game->board[i] = EMPTY;
    game->state = RUNNING;
    game->player = PLAYER_X;
}

int count_moves(game_t *game) {
    int count = 0;
    for (int i = 0; i < N * N; i++) {
        if (game->board[i] != EMPTY) count++;
    }
    return count;
}

int check_tie(game_t *game) {
    return count_moves(game) == N * N;
}

void update_state(game_t *game) {
    if (check_tie(game)) game->state = TIE;
    if (check_player_win(game, PLAYER_X)) game->state = PLAYER_X_WIN;
    if (check_player_win(game, PLAYER_O)) game->state =PLAYER_O_WIN;
}

void cell_click(game_t *game, int x, int y) {
    if (game->state == RUNNING) {
        if (update_board(game, x, y)) {
            switch_player(game);
            update_state(game);
        }
    } else {
        reset_game(game);
    }
}
