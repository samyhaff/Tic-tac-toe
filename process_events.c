#include <SDL2/SDL.h>
#include "game.h"
#include "logic.h"

void process_events(SDL_Event *e, game_t *game) {
    while (SDL_PollEvent(e) != 0) {
        switch (e->type) {
            case SDL_QUIT:
                game->state = QUIT;
                break;

            case SDL_WINDOWEVENT:
                switch (e->window.event) {
                    case SDL_WINDOWEVENT_CLOSE:
                        game->state = QUIT;
                        break;
                    default: break;
                }

            case SDL_KEYDOWN:
                switch (e->key.keysym.sym) {
                    case SDLK_ESCAPE:
                        game->state = QUIT;
                        break;
                    default: break;
                }

            case SDL_MOUSEBUTTONDOWN: {
                player_move(game, e->button.x, e->button.y);
                break;
            }

            default:
                break;
        }
    }
}
