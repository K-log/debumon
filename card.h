#ifndef CARD_H
#define CARD_H
#include "SDL2/SDL.h"

class Card{
    public:
        Card(int new_damage, int new_cost);
        int getDamage();
        int getCost();
        void changeX(int new_x);
        void changeY(int new_y);
        int getX();
        int getY();
        void changeWidth(int new_Width);
        void changeHeight(int new_Height);
        int getWidth();
        int getHeight();
        void rotate(double degree);
    private:
        int damage, cost;
        SDL_Rect card;
};
#endif
