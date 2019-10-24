#include "Deck.h"
#include <iostream>

using namespace std;
Deck::Deck(){       //Constructor class to create 52 card deck array
    arraySize = 52;
    cardsLeft = 0;
    cards = new Card[arraySize];
}
Deck::Deck(const Deck &newDeck){        //copy constructor
    arraySize = newDeck.arraySize;
    cardsLeft = newDeck.cardsLeft;
    cards = new Card[arraySize];
    for (int i = 0; i < arraySize; i++) {
        cards[i] = newDeck.cards[i];
    }
}
void Deck::shuffle(){       //Randomly shuffles cards cardsLeft^2 times
    Card temp;
    int card1;
    int card2;
    for(int i = 0; i<cardsLeft * cardsLeft; i++){
        card1 = rand()% cardsLeft;
        card2 = rand()% cardsLeft;
        temp = cards[card1];
        cards[card1] = cards[card2];
        cards[card2] = temp;
    }
}

Deck &Deck::operator=(Deck assignment) {          //copy assignment
    swap(cards, assignment.cards);
    arraySize = assignment.arraySize;
    cardsLeft = assignment.cardsLeft;
    return *this;
}

void Deck::populateDeck() { //fill deck array with cards with suit and rank values
    int k = 0;
    for(int i=0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            cards[k] = Card(i,j);
            k++;
            cardsLeft++;
        }
    }
}
Card Deck::removeCard(){    //remove cards from deck
    cardsLeft --;
    return cards[cardsLeft];
}

bool Deck::addCard(Card c) {    //adds cards to deck and checks if there is still space
    if(cardsLeft == 52){
        return false;
    }
    else{
        cards[cardsLeft] = c;
        cardsLeft++;
        return true;
    }
}

Deck::~Deck(){  //destructor
    cout<< "Called destructor"<<endl;
    delete[] cards;
    cards = nullptr;
}




