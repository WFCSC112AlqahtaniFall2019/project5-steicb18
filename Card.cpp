#include "Card.h"
#include <iostream>
using namespace std;



Card::Card(){       //Default constructor for card class
    ranksIndex = 0;
    suitsIndex = 0;
}

Card::Card(int RI, int SI){     //Card class constructor
    ranksIndex = RI;
    suitsIndex = SI;

}

bool Card::operator<(Card drawnCard){       //Overload operator for rank and index comparison
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

bool Card::operator>(Card drawnCard){       //Overload operator for rank and index comparison
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



string Card::print(){       //Print card info
    return ranks[ranksIndex] + " of "+ suits[suitsIndex];
}
