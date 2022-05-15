#include <stdio.h>
#include <SDL2/SDL.h>
#include "game.h"
#include "render.h"
#include "process_events.h"

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL could not initialize: %s\n", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow("Tic-tac-toe",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "SDL could not create window: %s\n", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        fprintf(stderr, "SDL could not create renderer: %s\n", SDL_GetError());
    }

    game_t game = { .state = RUNNING,
                    .board = { EMPTY, EMPTY, EMPTY,
                               EMPTY, EMPTY, EMPTY,
                               EMPTY, EMPTY, EMPTY },
                    .player = PLAYER_X};

    SDL_Event e;
    // handle mouse click bug on startup
    while (SDL_PollEvent(&e)) {}

    while (game.state != QUIT) {
        process_events(&e, &game);
        render(renderer, &game);
        SDL_Delay(100);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
