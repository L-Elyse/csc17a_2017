/* 
 * File:   Property.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 10:01 PM
 * Purpose: Property Class Specifications
 */

#ifndef PROPERTY_H
#define PROPERTY_H
#include "Board.h"

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
        
        template <class T1,class T2>
        void inform(T1 &deed,T2 &number){
            Board::setup(deed);
            switch(deed)
            {
                case GO:
                    break;
                case MDTRRNN:
                    if(number==1)rent=10;
                    else if(number==2)rent=30;
                    else if(number==3)rent=90;
                    else if(number==4)rent=160;
                    else if(number==5)rent=250;
                    else rent=2;
                    mortgge=30;
                    hseCost=50;
                    break;
                case COMMCH1:
                    break;
                case BALTIC:
                    if(number==1)rent=20;
                    else if(number==2)rent=60;
                    else if(number==3)rent=180;
                    else if(number==4)rent=320;
                    else if(number==5)rent=450;
                    else rent=4;
                    mortgge=30;
                    hseCost=50;
                    break;
                case INCOME:
                    break;
                case READRR:
                    if(number==1)rent=25;
                    else if(number==2)rent=50;
                    else if(number==3)rent=100;
                    else if(number==4)rent=200;
                    mortgge=100;
                    hseCost=0;
                    break;
                case ORIENTL:
                    if(number==1)rent=30;
                    else if(number==2)rent=90;
                    else if(number==3)rent=270;
                    else if(number==4)rent=400;
                    else if(number==5)rent=550;
                    else rent=6;
                    mortgge=50;
                    hseCost=50;
                    break;
                case CHANCE1:
                    break;
                case VERMONT:
                    if(number==1)rent=30;
                    else if(number==2)rent=90;
                    else if(number==3)rent=270;
                    else if(number==4)rent=400;
                    else if(number==5)rent=550;
                    else rent=6;
                    mortgge=50;
                    hseCost=50;
                    break;
                case CONNECT:
                    if(number==1)rent=40;
                    else if(number==2)rent=100;
                    else if(number==3)rent=300;
                    else if(number==4)rent=450;
                    else if(number==600);
                    else rent=8;
                    mortgge=60;
                    hseCost=50;
                    break;
                case JAIL:
                    break;
                case STCHRLS:
                    if(number==1)rent=50;
                    else if(number==2)rent=150;
                    else if(number==3)rent=450;
                    else if(number==4)rent=625;
                    else if(number==5)rent=750;
                    else rent=10;
                    mortgge=70;
                    hseCost=100;
                    break;
                case ELECTRC:
                    mortgge=75;
                    break;
                case STATES:
                    if(number==1)rent=50;
                    else if(number==2)rent=150;
                    else if(number==3)rent=450;
                    else if(number==4)rent=625;
                    else if(number==5)rent=750;
                    else rent=10;
                    mortgge=70;
                    hseCost=100;
                    break;
                case VIRGNIA:
                    if(number==1)rent=60;
                    else if(number==2)rent=180;
                    else if(number==3)rent=500;
                    else if(number==4)rent=700;
                    else if(number==5)rent=900;
                    else rent=12;
                    mortgge=80;
                    hseCost=100;
                    break;
                case PENNRR:
                    if(number==1)rent=25;
                    else if(number==2)rent=50;
                    else if(number==3)rent=100;
                    else if(number==4)rent=200;
                    mortgge=100;
                    hseCost=0;
                    break;
                case STJAMES:
                    if(number==1)rent=70;
                    else if(number==2)rent=200;
                    else if(number==3)rent=550;
                    else if(number==4)rent=750;
                    else if(number==5)rent=950;
                    else rent=14;
                    mortgge=90;
                    hseCost=100;
                    break;
                case COMMCH2:
                    break;
                case TENNESE:
                    if(number==1)rent=70;
                    else if(number==2)rent=200;
                    else if(number==3)rent=550;
                    else if(number==4)rent=750;
                    else if(number==5)rent=950;
                    else rent=14;
                    mortgge=90;
                    hseCost=100;
                    break;
                case NEWYORK:
                    if(number==1)rent=80;
                    else if(number==2)rent=220;
                    else if(number==3)rent=600;
                    else if(number==4)rent=800;
                    else if(number==5)rent=1000;
                    else rent=16;
                    mortgge=100;
                    hseCost=100;
                    break;
                case PARKING:
                    break;
                case KENTCKY:
                    if(number==1)rent=90;
                    else if(number==2)rent=250;
                    else if(number==3)rent=700;
                    else if(number==4)rent=875;
                    else if(number==5)rent=1050;
                    else rent=18;
                    mortgge=110;
                    hseCost=150;
                    break;
                case CHANCE2:
                    break;
                case INDIANA:
                    if(number==1)rent=90;
                    else if(number==2)rent=250;
                    else if(number==3)rent=700;
                    else if(number==4)rent=875;
                    else if(number==5)rent=1050;
                    else rent=18;
                    mortgge=110;
                    hseCost=150;
                    break;
                case ILLNOIS:
                    if(number==1)rent=100;
                    else if(number==2)rent=300;
                    else if(number==3)rent=750;
                    else if(number==4)rent=925;
                    else if(number==5)rent=1100;
                    else rent=20;
                    mortgge=120;
                    hseCost=150;
                    break;
                case BNORR:
                    if(number==1)rent=25;
                    else if(number==2)rent=50;
                    else if(number==3)rent=100;
                    else if(number==4)rent=200;
                    mortgge=100;
                    hseCost=0;
                    break;
                case ATLANTC:
                    if(number==1)rent=110;
                    else if(number==2)rent=330;
                    else if(number==3)rent=800;
                    else if(number==4)rent=975;
                    else if(number==5)rent=1150;
                    else rent=22;
                    mortgge=130;
                    hseCost=150;
                    break;
                case VENTNOR:
                    if(number==1)rent=110;
                    else if(number==2)rent=330;
                    else if(number==3)rent=900;
                    else if(number==4)rent=975;
                    else if(number==5)rent=1150;
                    else rent=22;
                    mortgge=130;
                    hseCost=150;
                    break;
                case WATERWK:
                    break;
                case MARVIN:
                    if(number==1)rent=120;
                    else if(number==2)rent=360;
                    else if(number==3)rent=850;
                    else if(number==4)rent=1025;
                    else if(number==5)rent=1200;
                    else rent=24;
                    mortgge=140;
                    hseCost=150;
                    break;
                case GO2JAIL:
                    break;
                case PACIFIC:
                    if(number==1)rent=130;
                    else if(number==2)rent=390;
                    else if(number==3)rent=900;
                    else if(number==4)rent=1100;
                    else if(number==5)rent=1275;
                    else rent=26;
                    mortgge=150;
                    hseCost=200;
                    break;
                case NCARLNA:
                    if(number==1)rent=130;
                    else if(number==2)rent=390;
                    else if(number==3)rent=900;
                    else if(number==4)rent=1100;
                    else if(number==5)rent=1275;
                    else rent=26;
                    mortgge=150;
                    hseCost=200;
                    break;
                case COMMCH3:
                    break;
                case PENNSYL:
                    if(number==1)rent=150;
                    else if(number==2)rent=450;
                    else if(number==3)rent=1000;
                    else if(number==4)rent=1200;
                    else if(number==5)rent=1400;
                    else rent=28;
                    mortgge=160;
                    hseCost=200;
                    break;
                case SHORTLN:
                    if(number==1)rent=25;
                    else if(number==2)rent=50;
                    else if(number==3)rent=100;
                    else if(number==4)rent=200;
                    mortgge=100;
                    hseCost=0;
                    break;
                case CHANCE3:
                    break;
                case PARK:
                    if(number==1)rent=175;
                    else if(number==2)rent=500;
                    else if(number==3)rent=1100;
                    else if(number==4)rent=1300;
                    else if(number==5)rent=1500;
                    else rent=35;
                    mortgge=175;
                    hseCost=200;
                    break;
                case LUXTAX:
                    break;
                case BRDWALK:
                    if(number==1)rent=200;
                    else if(number==2)rent=600;
                    else if(number==3)rent=1400;
                    else if(number==4)rent=1700;
                    else if(number==5)rent=2000;
                    else rent=50;
                    mortgge=200;
                    hseCost=200;
                    break;
            }
        }
};

#endif /* PROPERTY_H */