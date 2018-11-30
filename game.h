#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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
 * TODO: Add some better form of garbage collection to the update and destroy functions. Preferably add resources to be destroyed to an array and every X iterations clear the array.
 *
 *
 * */

class Game 
{
    private:
       SDL_Event event;

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
        int update(); // Update the window size and position every time it's called.
        int drawLevel(context contx); // Draw the current level to the screen.    
        int destroyLevel(context contx); // Destroy the current level and free the resources.
        int changeLevel(context contx); // Change the current level without destroying it. 
}; 


#endif
