#include "game.h"

Game::Game(SDL_Renderer *renderer, SDL_Window *window, int canvasX, int canvasY)
{
    SDL_Init(SDL_INIT_VIDEO);
    ctx.renderer = renderer;
    ctx.window = window;
    ctx.canvasX = canvasX;
    ctx.canvasY = canvasY;
    SDL_CreateWindowAndRenderer(ctx.canvasX, ctx.canvasY, 0, &ctx.window, &ctx.renderer);
}

Game::~Game()
{
    SDL_DestroyRenderer(ctx.renderer);
    SDL_DestroyWindow(ctx.window);
    SDL_Quit();
}




int Game::update()
{
    /*
    while(SDL_PollEvent(&event))
    {
        switch(event.type) { // Process the appropriate event type /
            case SDL_KEYDOWN:  // Handle a KEYDOWN event /
                printf("Oh! Key press\n");
                break;
            case SDL_MOUSEMOTION:
                printf("Mouse motion detected\n");
            default: // Report an unhandled event /
                printf("I don't know what this event is!\n");
        }
   
    }
    */

    int width = emscripten_run_script_int("window.innerWidth");
    int height = emscripten_run_script_int("window.innerHeight");
    int offW = 0.05*width; // Shrink width by 10%
    int offH = 0.05*height; // Shring height by 10%
    SDL_CreateWindowAndRenderer(width-offW, height-offH, 0, &ctx.window, &ctx.renderer);
}
