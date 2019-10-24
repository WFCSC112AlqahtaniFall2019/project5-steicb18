#include "Card.h"
#include <iostream>
using namespace std;



Card::Card(){
    ranksIndex = 0;
    suitsIndex = 0;
}

Card::Card(int RI, int SI){
    ranksIndex = RI;
    suitsIndex = SI;

}

bool Card::operator<(Card drawnCard){
    if(this->ranksIndex < drawnCard.ranksIndex)
        return true;
    else if(this->ranksIndex == drawnCard.ranksIndex){
        if (this->suitsIndex < drawnCard.suitsIndex){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }

}

bool Card::operator>(Card drawnCard){
    if(this->ranksIndex > drawnCard.ranksIndex)
        return true;
    else if(this->ranksIndex == drawnCard.ranksIndex){
        if (this->suitsIndex > drawnCard.suitsIndex){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }

}



string Card::print(){
    //cout << suitsIndex << endl;
    return ranks[ranksIndex] + " of "+ suits[suitsIndex];
}
