/* 
 * File:   Card.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 6:26 PM
 * Purpose Card Class Specifications
 */

#ifndef CARD_H
#define CARD_H
#include "AbsCard.h"

class Card:public AbsCard{
    private:
        unsigned char cNumber;
    public:
        Card(unsigned char);
        char getSuit();
        char getFVal();
        char getNum();
        char getCNum();
    };

#endif /* CARD_H */