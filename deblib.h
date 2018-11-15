#include <SDL2/SDL.h>
#include <emscripten.h>
#include <cstdlib>

struct context {
    SDL_Renderer* renderer;
    SDL_Window* window;
    int iteration;
};
