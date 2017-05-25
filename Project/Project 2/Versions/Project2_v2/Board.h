/* 
 * File:   Board.h
 * Author: Laurie Guimont
 * Created on May 21, 2017, 5:46 PM
 * Purpose: Board Class Specifications
 */

#ifndef BOARD_H
#define BOARD_H

#include <string>
using namespace std;

enum Name {GO,MDTRRNN,COMMCH1,BALTIC,INCOME,READRR,ORIENTL,CHANCE1,
            VERMONT,CONNECT,JAIL,STCHRLS,ELECTRC,STATES,VIRGNIA,PENNRR,
            STJAMES,COMMCH2,TENNESE,NEWYORK,PARKING,KENTCKY,CHANCE2,INDIANA,
            ILLNOIS,BNORR,ATLANTC,VENTNOR,WATERWK,MARVIN,GO2JAIL,PACIFIC,
            NCARLNA,COMMCH3,PENNSYL,SHORTLN,CHANCE3,PARK,LUXTAX,BRDWALK};

class Board{
    private:
        int SPACES;
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
            case GO: 
                name="Go";
                price=0;
                color="";
                break;
            case MDTRRNN: 
                name="Mediterranean Avenue";
                price=60;
                color="purple";
                break;
            case COMMCH1: 
                name="Community Chest";
                price=0;
                color="";
                break;
            case BALTIC:
                name="Baltic Avenue";
                price=60;
                color="purple";
                break;
            case INCOME:
                name="Income Tax";
                price=0;
                color="";
                break;
            case READRR:
                name="Reading Railroad";
                price=200;
                color="RR";
                break;
            case ORIENTL:
                name="Oriental Avenue";
                price=100;
                color="lilac";
                break;
            case CHANCE1:
                name="Chance";
                price=0;
                color="";
                break;
            case VERMONT:
                name="Vermont Avenue";
                price=100;
                color="lilac";
                break;
            case CONNECT:
                name="Connecticut Avenue";
                price=120;
                color="lilac";
                break;
            case JAIL:
                name="Jail";
                price=0;
                color="";
                break;
            case STCHRLS:
                name="St. Charles Avenue";
                price=140;
                color="pink";
                break;
            case ELECTRC:
                name="Electric Company";
                price=150;
                color="Utility";
                break;
            case STATES:
                name="States Avenue";
                price=140;
                color="pink";
                break;
            case VIRGNIA:
                name="Virginia Avenue";
                price=160;
                color="pink";
                break;
            case PENNRR:
                name="Pennsylvania Railroad";
                price=200;
                color="RR";
                break;
            case STJAMES:
                name="St. James Place";
                price=180;
                color="orange";
                break;
            case COMMCH2:
                name="Community Chest";
                price=0;
                color="";
                break;
            case TENNESE:
                name="Tennessee Avenue";
                price=180;
                color="orange";
                break;
            case NEWYORK:
                name="New York Avenue";
                price=200;
                color="orange";
                break;
            case PARKING:
                name="Free Parking";
                price=0;
                color="";
                break;
            case KENTCKY:
                name="Kentucky Avenue";
                price=220;
                color="red";
                break;
            case CHANCE2:
                name="Chance";
                price=0;
                color="";
                break;
            case INDIANA:
                name="Indiana Avenue";
                price=220;
                color="red";
                break;
            case ILLNOIS:
                name="Illinois Avenue";
                price=240;
                color="red";
                break;
            case BNORR:
                name="B & O Railroad";
                price=200;
                color="RR";
                break;
            case ATLANTC:
                name="Atlantic Avenue";
                price=260;
                color="yellow";
                break;
            case VENTNOR:
                name="Ventnor Avenue";
                price=260;
                color="yellow";
                break;
            case WATERWK:
                name="Water Works";
                price=150;
                color="utility";
                break;
            case MARVIN:
                name="Marvin Gardens";
                price=280;
                color="yellow";
                break;
            case GO2JAIL:
                name="Go To Jail";
                price=0;
                color="";
                break;
            case PACIFIC:
                name="Pacific Avenue";
                price=300;
                color="green";
                break;
            case NCARLNA:
                name="North Carolina Avenue";
                price=300;
                color="green";
                break;
            case COMMCH3:
                name="Community Chest";
                price=0;
                color="";
                break;
            case PENNSYL:
                name="Pennsylvania Avenue";
                price=320;
                color="green";
                break;
            case SHORTLN:
                name="Short Line";
                price=200;
                color="RR";
                break;
            case CHANCE3:
                name="Chance";
                price=0;
                color="";
                break;
            case PARK:
                name="Park";
                price=350;
                color="blue";
                break;
            case LUXTAX:
                name="Luxury Tax";
                price=0;
                color="";
                break;
            case BRDWALK:
                name="Boardwalk";
                price=400;
                color="blue";
                break;
        }
    }
};

#endif /* BOARD_H */