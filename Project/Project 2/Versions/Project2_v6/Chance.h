/* 
 * File:   Chance.h
 * Author: Laurie Guimont
 * Created on May 27, 2017, 5:04 PM
 * Purpose: Chance Class Specifications
 */

#ifndef CHANCE_H
#define CHANCE_H

#include "AbsCard.h"
#include "Player.h"

#include <string>
using namespace std;

class Chance:public AbsCard, public Player{
    private:
        string message;
    public:
        Chance();
        void setMess(string);
        void setMess(unsigned short);
        virtual string getMess()const;
};

#endif /* CHANCE_H */