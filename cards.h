#include <vector>
#include "singleCard.h"
#ifndef CARDS_H
#define CARDS_H

class Cards{
    public:
        // You will create a new type of card. For example all monster cards or all punch cards. Whatev's
        Cards(string &new_type);
        void addCard(int start_x, int start_y, string &start_name, int start_cost, string &start_location, SDL_Renderer *rend);
        void displayCards(int begin, int end, SDL_Renderer *rend);
        void displayCards(string &name, SDL_Renderer *rend);
    private:
        vector<SingleCard> allCards; 
        string type;
};
#endif
