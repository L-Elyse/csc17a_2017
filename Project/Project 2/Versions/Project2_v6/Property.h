/* 
 * File:   Property.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 10:01 PM
 * Purpose: Property Class Specifications
 */

#ifndef PROPERTY_H
#define PROPERTY_H
#include "Board.h"
#include "Names.h"

class Property : public Board , public Names{
    private:
        int rent;          //Amount of rent to charge players
        int mortgge;       //Amount of mortgage to pay the bank if necessary
        int hseCost;       //Cost per house
        int htlCost;       //Cost per hotel
    public:
        Property();
        int getrent()const;
        int getmrgg()const;
        int getHseC()const;
        int getHtlC()const;
        
        template <class T1,class T2>
        void utilRnt(T1 &number,T2 &util){
            if(number==1)rent=4*util;
            else rent=10*util;
        }
        virtual void inform(int title,int number);
};

#endif /* PROPERTY_H */