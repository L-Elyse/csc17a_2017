/* 
 * File:   Card.h
 * Author: Laurie Guimont
 * Created on May 19, 2017, 4:20 PM
 * Purpose: Card Class Specifications
 */

#ifndef CARD_H
#define CARD_H

class Card{
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