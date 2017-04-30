/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 29, 2017, 9:24 PM
 * Purpose: Card Game
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Card.h"
#include "Deck.h"

//Executable code begins here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare a deck of cards
    Deck deck;
    
    //Deal
    int fiveCrd=5;
    deck.shuffle();
    int *hand=deck.deal(fiveCrd);
    
    //Process by mapping inputs to outputs
    for(int i=1;i<=fiveCrd;i++){
        Card card(hand[i-1]);
        cout<<card.getFVal()<<card.getSuit()<<endl;
    }
    
    //Clean up
    delete []hand;

    //Exit Stage Right
    return 0;
}

