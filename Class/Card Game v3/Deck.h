/* 
 * File:   Deck.h
 * Author: Laurie Guimont
 * Created on May 19, 2017, 4:25 PM
 * Purpose: Deck Class Specifications
 */

#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck{
    private:
        int *index;     //index of the 52 card
        Card **card;    //Array of cards in the deck
        int dealt;       //Count of how many cards have been dealt
        int nCrds;      //Number of cards in the deck
        float pctShuf;  //Percentage cards dealt, when to Shuffle
        int nShufle;    //Number of shuffles to give random results
    public:
        Deck();
        ~Deck();
        Card **deal(int);
        void shuffle();
        void cleanup(Card **,int);
};

#endif /* DECK_H */