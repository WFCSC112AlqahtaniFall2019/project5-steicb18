#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"
#include <ctime>
using namespace std;

int main() {
    Deck gameDeck;
    Deck discard;

    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher;
    string response;
    int nWin = 0, nLoss = 0, nTie = 0;
    srand(time(0));
    int numCards = 0;

    play = true;
    while (invalid = true) {
        Card cardComputer;
        Card cardPlayer;

        numCards = numCards + 2;

        gameDeck.populateDeck();
        gameDeck.shuffle();

        cardComputer = gameDeck.removeCard();
        cardPlayer = gameDeck.removeCard();
        cout<<"The computer drew a: "<<cardComputer.print()<<endl;

       // cout<< cardplayer.print();


        // assign values to computer and user
        invalid = true;
        while(invalid) {
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
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
        if((cardComputer < cardPlayer && guessedHigher) || (cardComputer > cardPlayer && !guessedHigher)) {
            cout << "Great! You're right:" << endl;
            nWin++;
        } else if((cardComputer > cardPlayer && guessedHigher) || (cardComputer < cardPlayer && !guessedHigher)) {
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        } else {
            cout << "It's a tie:" << endl;
            nTie++;
        }
        cout << "\tyour value is " << cardPlayer.print() << endl;

        // ask user to play again
        invalid = true;
        while(invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;

               // discard.addCard(cardComputer);
               // discard.addCard(cardPlayer);

            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {
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