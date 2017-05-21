/* 
 * File:   Coin.h
 * Author: Laurie Guimont
 * Created on May 15, 2017, 10:44 PM
 * Purpose: Coin Class Specifications
 */

#include <string>
using namespace std;

#ifndef COIN_H
#define COIN_H

class Coin{
    private:
        string sideUp;
    public:
        Coin();
        void toss();
        string getSide()const;
};

#endif /* COIN_H */

