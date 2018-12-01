#include <SDL2/SDL.h>
#include <cstdlib>
#include "deblib.h"
#include "game.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

struct baseColors
{
    int red;
    int green;
    int blue;
    int alpha;
};

/**
 * Main Loop
 * Main game loop
 */
void mainloop(void *arg)
{
    // Cast args to the right type
    Game *game = static_cast<Game*>(arg);
    

    // example: draw a moving rectangle
    baseColors bgc;

    bgc.red = 96;
    bgc.green = 96;
    bgc.blue = 96;
    bgc.alpha = 255;

    // red background
    SDL_SetRenderDrawColor(game->ctx.renderer, bgc.red, bgc.blue, bgc.green, bgc.alpha);
    SDL_RenderClear(game->ctx.renderer);
    
    // moving blue rectangle
    int X, Y;
    int *oldX, *oldY;
    if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        SDL_GetMouseState(&X, &Y);
        SDL_Rect r;
        r.x = X - 25;
        r.y = Y - 25;
        r.w = 50;
        r.h = 50;
        oldX = &X;
        oldY = &Y;
    }

    SDL_Rect r;
    r.x = 25;
    r.y = 25;
    r.w = 50;
    r.h = 50;
    SDL_SetRenderDrawColor(game->ctx.renderer, 0, 0, 255, 255 );
    SDL_RenderFillRect(game->ctx.renderer, &r );

    
    SDL_RenderPresent(game->ctx.renderer);


    game->update();
}

/**
 * Main
 * Setup SDL and start the game.
 */
int main()
{
    // Setup the Game class
    SDL_Window *window;
    SDL_Renderer *renderer;
    int width = 900;
    int height = 700;
    vector<Cards*> allCardPiles;
    Game game(renderer, window, width, height, allCardPiles);
    string basic = "Basic";
    game.newCardPile(basic);   
    // Start the game
    const int simulate_infinite_loop = 1; // call the function repeatedly
    const int fps = 0; // call the function as fast as the browser wants to render (typically 60fps)
    emscripten_set_main_loop_arg(mainloop, &game, fps, simulate_infinite_loop); // Pass the paremeters to the emscripten loop (func, args, fps, iterations)
  

    return EXIT_SUCCESS;
}
