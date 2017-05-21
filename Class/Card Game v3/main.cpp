/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 19, 2017, 4:19 PM
 * Purpose: Card Game
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Deck.h"

//Executable Code Begins Here!!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare a deck of cards
    Deck deck;
    
    //Deal
    int fiveCrd=5;
    deck.shuffle();
    Card **hand=deck.deal(fiveCrd);
    
    //Take a look at the hand contents
    for(int i=0;i<fiveCrd;i++){
        cout<<hand[i]->getFVal()<<hand[i]->getSuit()<<endl;
    }
    
    //Clean up
    deck.cleanup(hand,fiveCrd);
    
    //Exit Stage Right!
    return 0;
}