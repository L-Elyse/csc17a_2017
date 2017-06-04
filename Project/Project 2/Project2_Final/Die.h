/* 
 * File:   Die.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 8:56 PM
 * Purpose: Die Class Specifications
 */

#ifndef DIE_H
#define DIE_H

#include <cstdlib>
using namespace std;

class Die{
    private:
        int value;                 //Value shown on one die
    public:
        Die(){
            value=0;
        }
        void roll(){
            int MIN=1, MAX=6;
            value=(rand()%(MAX-MIN+1))+MIN;
        }
        int getVal(){
            return value;
        }
};

#endif /* DIE_H */