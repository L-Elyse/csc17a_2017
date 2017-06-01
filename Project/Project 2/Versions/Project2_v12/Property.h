/* 
 * File:   Property.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 10:01 PM
 * Purpose: Property Class Specifications
 */

#ifndef PROPERTY_H
#define PROPERTY_H
#include "Board.h"

#include <string>
using namespace std;

enum Name {GO,MDTRRNN,COMMCH1,BALTIC,INCOME,READRR,ORIENTL,CHANCE1,
            VERMONT,CONNECT,JAIL,STCHRLS,ELECTRC,STATES,VIRGNIA,PENNRR,
            STJAMES,COMMCH2,TENNESE,NEWYORK,PARKING,KENTCKY,CHANCE2,INDIANA,
            ILLNOIS,BNORR,ATLANTC,VENTNOR,WATERWK,MARVIN,GO2JAIL,PACIFIC,
            NCARLNA,COMMCH3,PENNSYL,SHORTLN,CHANCE3,PARK,LUXTAX,BRDWALK};

class Property : public Board{ 
    private:
        int hseCost;       //Cost per house
        int htlCost;       //Cost per hotel
        int maxColr;       //Number of properties in a color group
    protected:
        int rent;          //Amount of rent to charge players
    public:
        Property();
        int getrent()const;
        int getHseC()const;
        int getHtlC()const;
        int setcMax(string);
        
        template <class T1,class T2>
        void utilRnt(T1 &number,T2 &util){
            if(number==1)rent=4*util;
            else rent=10*util;
        }
        
        virtual string getPos(int named)const{
            string postion;
            if(named==READRR)
                postion="Reading";
            else if(named==PENNRR)
                postion="Pennsylvania";
            else if(named==BNORR)
                postion="B & O";
            else if(named==SHORTLN)
                postion="Short Line";
            
            return postion;
        }
        
        virtual void inform(int,int);
};

#endif /* PROPERTY_H */