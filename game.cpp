#include "game.h"
#include "cards.h"

Game::Game(SDL_Renderer *renderer, SDL_Window *window, int canvasX, int canvasY, vector<Cards*> allCardPiles)
{
    SDL_Init(SDL_INIT_VIDEO);
    ctx.renderer = renderer;
    ctx.window = window;
    ctx.canvasX = canvasX;
    ctx.canvasY = canvasY;
    SDL_CreateWindowAndRenderer(ctx.canvasX, ctx.canvasY, 0, &ctx.window, &ctx.renderer);
    ctx.allCardPiles = allCardPiles;
}

Game::~Game()
{
    SDL_DestroyRenderer(ctx.renderer);
    SDL_DestroyWindow(ctx.window);
    SDL_Quit();
}




int Game::update()
{
    int width = emscripten_run_script_int("window.innerWidth");
    int height = emscripten_run_script_int("window.innerHeight");
    int offW = 0.05*width; // Shrink width by 10%
    int offH = 0.05*height; // Shring height by 10%
    SDL_CreateWindowAndRenderer(width-offW, height-offH, 0, &ctx.window, &ctx.renderer);
}


int Game::drawLevel(context ctx)
{
    return 0;
}

void Game::newCardPile(string &new_type){
    Cards newCardType(new_type);
    allCardPiles.push_back(new Cards(new_type));
}
