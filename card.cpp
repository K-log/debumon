#include "card.h"

Card::Card(int new_damage, int new_cost){
    damage = new_damage;
    cost = new_cost;
}
int Card::getDamage(){
    return damage;
}
int Card::getCost(){
    return cost;
}
void Card::changeX(int new_x){
    card.x = new_x;
}
void Card::changeY(int new_Y){
    card.y = new_Y;
}
int Card::getX(){
    return card.x;
}
int Card::getY(){
    return card.y;
}
void Card::changeWidth(int new_Width){
    card.w = new_Width;
}
void Card::changeHeight(int new_Height){
    card.h = new_Height;
}
int Card::getWidth(){
    return card.w;
}
int Card::getHeight(){
    return card.h;
}
void Card::rotate(double degree, SDL_Rect &sdlRect){
    SDL_RendererFlip flipType = SDL_FLIP_NONE;
    SDL_RenderCopyEx(??, ??, NULL, sdlRect, degree, NULL, flipType);
}
