/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 7, 2017, 6:15 PM
 * Purpose: War Card Game
 */

#ifndef CARD_H
#define CARD_H


struct Card{
    enum deck {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, 
           JACK, QUEEN, KING, ACE};
    char suite;
};

#endif /* CARD_H */