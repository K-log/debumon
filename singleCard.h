#ifndef SINGLECARD_H
#define SINGLECARD_H
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class SingleCard{
    public:
        SingleCard(int start_x, int start_y, string &start_name, int start_cost, string &start_location, SDL_Renderer *rend);
        ~SingleCard();
        int getCost();
        string& getName();
        int getX();
        int getY();
        void changeX(int new_x);
        void changeY(int new_y);
        void display(SDL_Renderer *rend);
    private:
        int cost, x, y;
        string name, location;
        SDL_Texture *cardTexture;
        SDL_Surface *cardImage;
        SDL_Rect *cardRect;
};
#endif
