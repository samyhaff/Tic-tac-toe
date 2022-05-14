#include <SDL2/SDL.h>
#include "game.h"

void render(SDL_Renderer *renderer, game_t *game) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
