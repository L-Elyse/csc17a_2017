/* 
 * File:   Coin.h
 * Author: Laurie Guimont
 * Created on May 15, 2017, 11:13 PM
 * Purpose: Coin Class Specifications
 */

#include <string>
using namespace std;

#ifndef COIN_H
#define COIN_H

class Coin{
    private:
        string sideUp;
        static float balance;
    public:
        Coin();
        void toss();
        void setBal(float);
        string getSide()const;
        float getBal()const;
        bool loop()const;
};

#endif /* COIN_H */

