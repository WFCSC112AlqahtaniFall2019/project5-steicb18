#include "Deck.h"
#include <iostream>
using namespace std;

Deck::Deck(){
    arraySize = 52;
    cardsLeft = 0;
    cards = new Card[arraySize];
}
Deck::Deck(const Deck &newDeck){
    arraySize = newDeck.arraySize;
    cardsLeft = newDeck.cardsLeft;
    cards = new Card[arraySize];
    for (int i = 0; i < arraySize; i++) {
        cards[i] = newDeck.cards[i];
    }
}
void Deck::shuffle(){
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

void Deck::populateDeck() {
    int k = 0;
    for(int i=0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            cards[k] = Card(i,j);
            cout << k << " " << Card(i,j).print() << endl;
            k++;
            cardsLeft++;
        }
    }
}
Card Deck::removeCard(){
    cardsLeft --;
    return cards[cardsLeft];
}

bool Deck::addCard(Card c) {
    if(cardsLeft == 52){
        return false;
    }
    else{
        cards[cardsLeft] = c;
        cardsLeft++;
        return true;
    }
}

Deck::~Deck(){
    cout<< "Called destructor"<<endl;
    delete[] cards;
    cards = nullptr;
}




