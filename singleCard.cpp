#include "singleCard.h"

/*
 * Needed for a card:
 * totalDamage = The total damage to win over the heart of this monster
 *      This may be empty if this is not a monster card 
 * damage = damage so far ie (30/100)
 *      This may be empty if this is not a monster card
 * cost = The cost to buy the card 
 *      This may be empty if this is not a purchasable card
 * type = purchasable or monster
 * name = name of card ie (1 Gem) or (Grabthrok the Avenger of Thieves)
 * location = the location of the image for the card
 * x = the x location of the card
 * y = the y location of the card
 */

SingleCard::SingleCard(int start_x, int start_y, string &start_name, int start_cost, string &start_location, SDL_Renderer &rend){
    cost = start_cost;
    name = start_name;
    location = start_location;
    x = start_x;
    y = start_y;
    cardTexture = IMG_LoadTexture(rend, location.c_str());
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

