#include <emscripten.h>
#include <cstdlib>
#include "singleCard.h"

#define CANVAS_X 700
#define CANVAS_Y 900


struct context
{
    SDL_Renderer *renderer;
    int iteration;
    SingleCard *one;
};


/**
 * Main Loop
 * Main game loop
 */
void mainloop(void *arg)
{
    // Cast args to the right type
    context *ctx = static_cast<context*>(arg);
    
    // Get the renderer
    SDL_Renderer *renderer = ctx->renderer;

    // red background
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    // moving blue rectangle
    int X, Y;
    SDL_GetMouseState(&X, &Y);
    SDL_Rect r;
    r.x = X - 25;
    r.y = Y - 25;
    r.w = 50;
    r.h = 50;
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255 );
    SDL_RenderFillRect(renderer, &r );
    ctx->one->display(renderer); 
        
    SDL_RenderPresent(renderer);
    ctx->iteration += 1;

}

/**
 * Main
 * Setup SDL and start the game.
 */
int main()
{
    // Initialize SDL and the canvas
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(CANVAS_X, CANVAS_Y, 0, &window, &renderer);
    string oneone = "oneone";
    string owl = "assets/card.png";
    SingleCard one(10,10, oneone,25, owl, renderer);

    // Setup the context for the game
    context ctx;
    ctx.renderer = renderer;
    ctx.iteration = 0;
    ctx.one = &one;
    // Start the game
    const int simulate_infinite_loop = 1; // call the function repeatedly
    const int fps = 0; // call the function as fast as the browser wants to render (typically 60fps)
    emscripten_set_main_loop_arg(mainloop, &ctx, fps, simulate_infinite_loop); // Pass the paremeters to the emscripten loop (func, args, fps, iterations)
   
    // Cleanup  
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
