/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 20, 2017, 5:44 PM
 * Purpose: Card Game using Abstraction, Derived and Polymorphism
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Deck.h"

//Executable code begins here!!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare the deck of cards
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
    
    //Testing Derived card properties
    DrvCard test(3);
    cout<<test.getFN()<<endl;
    
    //Testing Polymorphic behavior
    Card *testP=new DrvCard(3);
    cout<<testP->getFVal()<<testP->getSuit()<<endl;
    
    //Exit Stage Right!
    return 0;
}

