#include "singleCard.h"

SingleCard::SingleCard(int start_x, int start_y, string &start_name, int start_cost, string &start_location, SDL_Renderer *rend){
    cost = start_cost;
    name = start_name;
    location = start_location;
    x = start_x;
    y = start_y;
    cardImage = IMG_Load(location.c_str());
    if (!cardImage){
        printf("IMG_Load: %s\n", IMG_GetError());
    }
    cardRect->x = x;
    cardRect->y = y; 
    cardRect->w = 100;
    cardRect->h = 200;
    cardTexture = SDL_CreateTextureFromSurface(rend, cardImage);
}
SingleCard::~SingleCard(){
    
}
int SingleCard::getCost(){
    return cost;
}
string& SingleCard::getName(){
    return name;
}
int SingleCard::getX(){
    return x;
}
int SingleCard::getY(){
    return y;
}
void SingleCard::changeX(int new_x){
    x += new_x;
}
void SingleCard::changeY(int new_y){
    y += new_y;
}
void SingleCard::display(SDL_Renderer *rend){
    SDL_RenderCopy(rend, cardTexture, NULL, cardRect);
}
