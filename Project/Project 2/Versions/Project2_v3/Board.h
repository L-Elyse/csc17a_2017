/* 
 * File:   Board.h
 * Author: Laurie Guimont
 * Created on May 21, 2017, 5:46 PM
 * Purpose: Board Class Specifications
 */

#ifndef BOARD_H
#define BOARD_H

#include <string>

#include "Names.h"
using namespace std;

class Board:public Names{
    private:
        int space;
    protected:
        string name;       //Property Names
        int price;         //Purchase Price for Properties 
        string color;      //Colors for Property Color Groups
    public:
        Board();
        int getSpce()const;
        string getname()const;
        int getprce()const;
        string getcolr()const;
        
    template <class T>
    void setup(T &title){
        switch(title)
        {
            case Names::GO: 
                name="Go";
                price=0;
                color="";
                break;
            case Names::MDTRRNN: 
                name="Mediterranean Avenue";
                price=60;
                color="purple";
                break;
            case Names::COMMCH1: 
                name="Community Chest";
                price=0;
                color="";
                break;
            case Names::BALTIC:
                name="Baltic Avenue";
                price=60;
                color="purple";
                break;
            case Names::INCOME:
                name="Income Tax";
                price=0;
                color="";
                break;
            case Names::READRR:
                name="Reading Railroad";
                price=200;
                color="RR";
                break;
            case Names::ORIENTL:
                name="Oriental Avenue";
                price=100;
                color="lilac";
                break;
            case Names::CHANCE1:
                name="Chance";
                price=0;
                color="";
                break;
            case Names::VERMONT:
                name="Vermont Avenue";
                price=100;
                color="lilac";
                break;
            case Names::CONNECT:
                name="Connecticut Avenue";
                price=120;
                color="lilac";
                break;
            case Names::JAIL:
                name="Jail";
                price=0;
                color="";
                break;
            case Names::STCHRLS:
                name="St. Charles Avenue";
                price=140;
                color="pink";
                break;
            case Names::ELECTRC:
                name="Electric Company";
                price=150;
                color="Utility";
                break;
            case Names::STATES:
                name="States Avenue";
                price=140;
                color="pink";
                break;
            case Names::VIRGNIA:
                name="Virginia Avenue";
                price=160;
                color="pink";
                break;
            case Names::PENNRR:
                name="Pennsylvania Railroad";
                price=200;
                color="RR";
                break;
            case Names::STJAMES:
                name="St. James Place";
                price=180;
                color="orange";
                break;
            case Names::COMMCH2:
                name="Community Chest";
                price=0;
                color="";
                break;
            case Names::TENNESE:
                name="Tennessee Avenue";
                price=180;
                color="orange";
                break;
            case Names::NEWYORK:
                name="New York Avenue";
                price=200;
                color="orange";
                break;
            case Names::PARKING:
                name="Free Parking";
                price=0;
                color="";
                break;
            case Names::KENTCKY:
                name="Kentucky Avenue";
                price=220;
                color="red";
                break;
            case Names::CHANCE2:
                name="Chance";
                price=0;
                color="";
                break;
            case Names::INDIANA:
                name="Indiana Avenue";
                price=220;
                color="red";
                break;
            case Names::ILLNOIS:
                name="Illinois Avenue";
                price=240;
                color="red";
                break;
            case Names::BNORR:
                name="B & O Railroad";
                price=200;
                color="RR";
                break;
            case Names::ATLANTC:
                name="Atlantic Avenue";
                price=260;
                color="yellow";
                break;
            case Names::VENTNOR:
                name="Ventnor Avenue";
                price=260;
                color="yellow";
                break;
            case Names::WATERWK:
                name="Water Works";
                price=150;
                color="utility";
                break;
            case Names::MARVIN:
                name="Marvin Gardens";
                price=280;
                color="yellow";
                break;
            case Names::GO2JAIL:
                name="Go To Jail";
                price=0;
                color="";
                break;
            case Names::PACIFIC:
                name="Pacific Avenue";
                price=300;
                color="green";
                break;
            case Names::NCARLNA:
                name="North Carolina Avenue";
                price=300;
                color="green";
                break;
            case Names::COMMCH3:
                name="Community Chest";
                price=0;
                color="";
                break;
            case Names::PENNSYL:
                name="Pennsylvania Avenue";
                price=320;
                color="green";
                break;
            case Names::SHORTLN:
                name="Short Line";
                price=200;
                color="RR";
                break;
            case Names::CHANCE3:
                name="Chance";
                price=0;
                color="";
                break;
            case Names::PARK:
                name="Park";
                price=350;
                color="blue";
                break;
            case Names::LUXTAX:
                name="Luxury Tax";
                price=0;
                color="";
                break;
            case Names::BRDWALK:
                name="Boardwalk";
                price=400;
                color="blue";
                break;
        }
    }
};

#endif /* BOARD_H */