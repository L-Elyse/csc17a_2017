/* 
 * File:   Property.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 10:01 PM
 * Purpose: Property Class Implementation
 */

#include "Property.h"
#include "Board.h"

Property::Property(){
    rent=0;
    mortgge=0;
    hseCost=0;
    htlCost=hseCost*5;
}

int Property::getrent() const{
    return rent;
}

int Property::getmrgg() const{
    return mortgge;
}

int Property::getHseC() const{
    return hseCost;
}

int Property::getHtlC() const{
    return htlCost;
}

void Property::inform(int title,int number){
    switch(title)
    {
        case GO:
            name="Go";
            break;
        case MDTRRNN:
            name="Mediterranean Avenue";
            price=60;
            color="purple";
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
            name="Community Chest";
            break;
        case BALTIC:
            name="Baltic Avenue";
            price=60;
            color="purple";
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
            name="Income Tax";
            price=200;
            color="tax";
            break;
        case READRR:
            name="Reading Railroad";
            price=200;
            color="RR";
            if(number==1)rent=25;
            else if(number==2)rent=50;
            else if(number==3)rent=100;
            else if(number==4)rent=200;
            mortgge=100;
            hseCost=0;
            break;
        case ORIENTL:
            name="Oriental Avenue";
            price=100;
            color="lilac";
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
            name="Chance";
            break;
        case VERMONT:
            name="Vermont Avenue";
            price=100;
            color="lilac";
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
            name="Connecticut Avenue";
            price=120;
            color="lilac";
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
            name="Jail";
            break;
        case STCHRLS:
            name="St. Charles Avenue";
            price=140;
            color="pink";
            if(number==1)rent=50;
            else if(number==2)rent=150;
            else if(number==3)rent=450;
            else if(number==4)rent=625;
            else if(number==5)rent=750;
            else rent=10;
            mortgge=70;
            hseCost=100;
            break;
        case ELECTRC: //FLAG!
            name="Electric Company";
            price=150;
            color="Utility";
            mortgge=75;
            break;
        case STATES:
            name="States Avenue";
            price=140;
            color="pink";
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
            name="Virginia Avenue";
            price=160;
            color="pink";
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
            name="Pennsylvania Railroad";
            price=200;
            color="RR";
            if(number==1)rent=25;
            else if(number==2)rent=50;
            else if(number==3)rent=100;
            else if(number==4)rent=200;
            mortgge=100;
            hseCost=0;
            break;
        case STJAMES:
            name="St. James Place";
            price=180;
            color="orange";
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
            name="Community Chest";
            break;
        case TENNESE:
            name="Tennessee Avenue";
            price=180;
            color="orange";
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
            name="New York Avenue";
            price=200;
            color="orange";
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
            name="Free Parking";
            break;
        case KENTCKY:
            name="Kentucky Avenue";
            price=220;
            color="red";
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
            name="Chance";
            break;
        case INDIANA:
            name="Indiana Avenue";
            price=220;
            color="red";
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
            name="Illinois Avenue";
            price=240;
            color="red";
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
            name="B & O Railroad";
            price=200;
            color="RR";
            if(number==1)rent=25;
            else if(number==2)rent=50;
            else if(number==3)rent=100;
            else if(number==4)rent=200;
            mortgge=100;
            hseCost=0;
            break;
        case ATLANTC:
            name="Atlantic Avenue";
            price=260;
            color="yellow";
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
            name="Ventnor Avenue";
            price=260;
            color="yellow";
            if(number==1)rent=110;
            else if(number==2)rent=330;
            else if(number==3)rent=900;
            else if(number==4)rent=975;
            else if(number==5)rent=1150;
            else rent=22;
            mortgge=130;
            hseCost=150;
            break;
        case WATERWK: //FLAG!!
            name="Water Works";
            price=150;
            color="Utility";
            break;
        case MARVIN:
            name="Marvin Gardens";
            price=280;
            color="yellow";
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
            name="Go To Jail";
            break;
        case PACIFIC:
            name="Pacific Avenue";
            price=300;
            color="green";
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
            name="North Carolina Avenue";
            price=300;
            color="green";
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
            name="Community Chest";
            break;
        case PENNSYL:
            name="Pennsylvania Avenue";
            price=320;
            color="green";
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
            name="Short Line";
            price=200;
            color="RR";
            if(number==1)rent=25;
            else if(number==2)rent=50;
            else if(number==3)rent=100;
            else if(number==4)rent=200;
            mortgge=100;
            hseCost=0;
            break;
        case CHANCE3:
            name="Chance";
            break;
        case PARK:
            name="Park Place";
            price=350;
            color="blue";
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
            name="Luxury Tax";
            price=75;
            color="tax";
            break;
        case BRDWALK:
            name="Boardwalk";
            price=400;
            color="blue";
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