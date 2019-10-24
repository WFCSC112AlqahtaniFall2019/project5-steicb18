#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
    srand(time(0));
    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher;   //declaring boolean variables for while statements
    string response;
    int nWin = 0, nLoss = 0, nTie = 0;
    int numCards = 0;               //Used to keep track of number of cards
    Deck gameDeck;  //Create the game deck object
    Deck discard; //create the discard deck object

    gameDeck.populateDeck();        //Fill game deck array with card values
    gameDeck.shuffle();         //Shuffles the cards in the deck randomly

    play = true;
    while (play) {
        //create assignments for the computer and the user
        Card playerCard = (gameDeck.removeCard());      //removing the players card from the game deck
        Card compCard = gameDeck.removeCard();     //removing the computers card from the game deck

        numCards = numCards + 2; //Update number of cards drawn after every iteration

        // get user's bet
        cout << "Computer's card is " << compCard.print() << endl;
        invalid = true;
        while (invalid) {
            cout << "Do you think your card is higher or lower? (H/L)" << endl;
            cin >> response;          //getting the user's guess
            if (toupper(response.at(0)) ==
                'H') {      //pulling the correct value into guessesHigher and invalid based on the guess
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        // determine outcome
        if ((playerCard > compCard && guessedHigher) ||
            (compCard > playerCard && !guessedHigher)) {          //determines if guess is correct
            cout << "Great! You're right:" << endl;
            nWin++;
        } else if ((compCard > playerCard && guessedHigher) || (playerCard > compCard &&!guessedHigher)) {     //determines if guess is wrong
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        } else {       //if neither of those are true it registers as a tie
            cout << "It's a tie:" << endl;
            nTie++;
        }
        cout << "\tyour value is " << playerCard.print() << endl;   //prints out your card after the guess

        if (numCards ==52) {           //checks if there are any cards left in the game deck
            cout << "No cards remaining" << endl;
            cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;
            return 0;
        }



        // ask user to play again
        invalid = true;
        while (invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {   //if the response is yes do this
                // continue playing


                //adding removed cards to discard pile
                discard.addCard(playerCard);
                discard.addCard(compCard);

                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {  //if the response is no do this
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {                                     //if the response isn't valid
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }
    }

    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;

    return 0;
}
