#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"

class Deck {

public:     //public functions
    Deck();
    ~Deck();
    Deck(const Deck &newDeck);
    void shuffle();
    Card removeCard();
    bool addCard(Card c);
    void populateDeck();
    Deck& operator= (Deck assignment );

private:        //private variables
    Card* cards;
    int arraySize;
    int cardsLeft;
};


#endif //BLINDMANSBLUFF_DECK_H
