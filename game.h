#include "deblib.cpp"

#ifndef GAME_H
#define GAME_H


class Game {
    private:
        int gameSize[2] = {0, 0};

    public:
        Game();
        ~Game();
        int drawLevel(context ctx); // Draw the current level to the screen.    
        int destroyLevel(context ctx); // Destroy the current level and free the resources.
        int changeLevel(context ctx); // Change the current level without destroying it.
}; 


#endif
