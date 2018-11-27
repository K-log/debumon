#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
//#include <SDL2_image/SDL_image.h>
#include <emscripten.h>

/**
 * Game 
 *
 * Defines the main game class for Debumon.
 *
 * This class handles all the main rendering of the gameboards and
 * backgrounds. It also handles game setup, takedown, timing, user input, 
 * and web browser interaction 
 *
 * Individual objects each handle there own rendering based on 
 * parameters of the game class context struct. 
 *
 *
 * */

class Game 
{
    public:
        struct context
        {
            SDL_Renderer* renderer;
            SDL_Window* window;
            int iterations;
            int canvasX;
            int canvasY;
        };

        context ctx;
        Game(SDL_Renderer *renderer, SDL_Window *window, int canvasX, int canvasY);
        ~Game(); 
        int update();
        int drawLevel(context ctx); // Draw the current level to the screen.    
        int destroyLevel(context ctx); // Destroy the current level and free the resources.
        int changeLevel(context ctx); // Change the current level without destroying it. 
}; 


#endif
