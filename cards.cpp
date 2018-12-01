#include "cards.h"

Cards::Cards(string &new_type){
    type = new_type;
}
void Cards::addCard(int start_x, int start_y, string &start_name, int start_cost, string &start_location, SDL_Renderer *rend){
    SingleCard newCard(start_x, start_y, start_name, start_cost, start_location, rend);
    allCards.push_back(newCard);
}
void Cards::displayCards(int begin, int end, SDL_Renderer *rend){
    if(begin >= 0 && end < allCards.size()){
        for(int i = begin; i <= end; i++){
            allCards[i].display(rend);
        }
    }
}
void Cards::displayCards(string &name){
    
}
