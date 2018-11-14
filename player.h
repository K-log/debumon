#ifndef PLAYER_H
#define PlAYER_H

class Player {

    private:
        int health = 0;
        int deckSize = 0;

    public:
        Player();
        ~Player();
        deck getDeck(); // Returns a deck object containing the users cards.
        bool updateDeck(deck cards); // Takes cards of type deck and merges them with the users deck.

}

#endif
