/* 
 * File:   Property.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 10:01 PM
 * Purpose: Property Class Specifications
 */

#ifndef PROPERTY_H
#define PROPERTY_H
#include "Board.h"

enum Name {GO,MDTRRNN,COMMCH1,BALTIC,INCOME,READRR,ORIENTL,CHANCE1,
            VERMONT,CONNECT,JAIL,STCHRLS,ELECTRC,STATES,VIRGNIA,PENNRR,
            STJAMES,COMMCH2,TENNESE,NEWYORK,PARKING,KENTCKY,CHANCE2,INDIANA,
            ILLNOIS,BNORR,ATLANTC,VENTNOR,WATERWK,MARVIN,GO2JAIL,PACIFIC,
            NCARLNA,COMMCH3,PENNSYL,SHORTLN,CHANCE3,PARK,LUXTAX,BRDWALK};

class Property : public Board{
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
       
        virtual void inform(int,int);
};

#endif /* PROPERTY_H */