#ifndef SINGLECARD_H
#define SINGLECARD_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
using namespace std;

class SingleCard{
    public:
        SingleCard(int start_x, int start_y, string &start_type, string &start_name, int start_totalDamage, int start_damage, int start_cost, string &start_location, SDL_Renderer &rend);
        int getTotalDamage();
        int getDamage();
        void giveDamage(int new_damage);
        int getCost();
        string& getName();
        string& getType();
        int getX();
        int getY();
        void changeX(int new_x);
        void changeY(int new_y);
    private:
        int totalDamage, damage, cost, x, y;
        string &type, &name, &location;
        SDL_Texture *cardTexture;
};
#endif
