#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include "game.h"

#define min(a, b) (((a) < (b)) ? (a) : (b))

const int cell_width = SCREEN_WIDTH / N;
const int cell_height = SCREEN_HEIGHT / N;

SDL_Color grid_color = { .r = 255, .g = 255, .b = 255 };
SDL_Color player_x_color = { .r = 255, .g = 0, .b = 0 };
SDL_Color player_o_color = { .r = 0, .g = 0, .b = 255 };
SDL_Color board_color = { .r = 0, .g = 0, .b = 0 };

void render_grid(SDL_Renderer *renderer, game_t *game) {
    for (int i = 1; i < N; i++) {
        SDL_SetRenderDrawColor(renderer, grid_color.r, grid_color.g, grid_color.b, 255);
        SDL_RenderDrawLine(renderer, 0, i * cell_height, SCREEN_WIDTH, i * cell_height);
        SDL_RenderDrawLine(renderer, i * cell_width, 0, i * cell_width, SCREEN_HEIGHT);
    }
}

void render_player_x(SDL_Renderer *renderer, int i, int j) {
    int length = min(cell_height, cell_width) / 2 - min(cell_width, cell_height) / 6;
    int center_x = (i * cell_width + (i + 1) * cell_width) / 2;
    int center_y = (j * cell_height + (j + 1) * cell_height) / 2;
    thickLineRGBA(renderer,
                  center_x - length,
                  center_y - length,
                  center_x + length,
                  center_y + length,
                  10,
                  player_x_color.r,
                  player_x_color.g,
                  player_x_color.b,
                  255);
    thickLineRGBA(renderer,
                  center_x + length,
                  center_y - length,
                  center_x - length,
                  center_y + length,
                  10,
                  player_x_color.r,
                  player_x_color.g,
                  player_x_color.b,
                  255);
}

void render_player_o(SDL_Renderer *renderer, int i, int j) {
    int center_x = (i * cell_width + (i + 1) * cell_width) / 2;
    int center_y = (j * cell_height + (j + 1) * cell_height) / 2;
    int radius = min(cell_height, cell_width) / 2 - min(cell_width, cell_height) / 6;
    filledCircleRGBA(renderer,
                     center_x,
                     center_y,
                     radius,
                     player_o_color.r,
                     player_o_color.g,
                     player_o_color.b,
                     255);
    filledCircleRGBA(renderer,
                     center_x,
                     center_y,
                     radius - radius / 6,
                     board_color.r,
                     board_color.g,
                     board_color.b,
                     255);
}

void render_board(SDL_Renderer *renderer, game_t *game) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (game->board[N * i + j] == PLAYER_X) {
                render_player_x(renderer, i, j);
            }
            else if (game->board[N * i + j] == PLAYER_O) {
                render_player_o(renderer, i, j);
            }
        }
    }
}

void render(SDL_Renderer *renderer, game_t *game) {
    SDL_SetRenderDrawColor(renderer, board_color.r, board_color.g, board_color.b, 255);
    SDL_RenderClear(renderer);
    render_grid(renderer, game);
    render_board(renderer, game);
    SDL_RenderPresent(renderer);
}
