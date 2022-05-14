#include <stdio.h>
#include <SDL2/SDL.h>

#include "game.h"

#define WIDTH 640
#define HEIGHT 480

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize: %s\n", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow("Tic-tac-toe",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WIDTH,
                              HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "SDL could not create window: %s\n", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        fprintf(stderr, "SDL could not create renderer: %s\n", SDL_GetError());
    }

    game_t game = { .state = RUNNING };

    SDL_Event e;

    while (game.state != QUIT) {
        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
                case SDL_QUIT:
                    game.state = QUIT;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
                    break;
                default:
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                    break;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
