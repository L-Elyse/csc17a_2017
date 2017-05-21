/* 
 * File:   Deck.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 5:45 PM
 * Purpose: Deck Class Specifications
 */

#ifndef DECK_H
#define DECK_H
#include "DrvCard.h"

class Deck{
    private:
        int *index;      //Index of the 52 cards
        Card **card;     //Array of cards in the deck
        int dealt;       //Count of how many cards have been dealt
        int nCrds;       //Number of cards in the deck
        float pctShuf;   //Percentage cards dealt, when to Shuffle
        int nShufle;     //Number of shuffles to give random results
    public:  
        Deck();                     //Construct the Deck
        ~Deck();                    //Destroy the Deck
        Card **deal(int);           //Deal the cards
        void shuffle();             //Shuffle the index
        void cleanup(Card **,int);  //Clean up the cards dealt
};

#endif /* DECK_H */