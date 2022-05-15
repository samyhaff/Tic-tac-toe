#include <SDL2/SDL.h>
#include "game.h"

const int cell_width = SCREEN_WIDTH / N;
const int cell_height = SCREEN_HEIGHT / N;

SDL_Color grid_color = { .r = 255, .g = 255, .b = 255 };;

void render_grid(SDL_Renderer *renderer, game_t *game) {
    for (int i = 1; i < N; i++) {
        SDL_SetRenderDrawColor(renderer, grid_color.r, grid_color.g, grid_color.b, 255);
        SDL_RenderDrawLine(renderer, 0, i * cell_height, SCREEN_WIDTH, i * cell_height);
        SDL_RenderDrawLine(renderer, i * cell_width, 0, i * cell_width, SCREEN_HEIGHT);
    }
}

void render(SDL_Renderer *renderer, game_t *game) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    render_grid(renderer, game);
    SDL_RenderPresent(renderer);
}
