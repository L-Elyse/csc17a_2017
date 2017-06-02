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
    hseCost=0;
    htlCost=hseCost*5;
}

int Property::getrent() const{
    return rent;
}

int Property::getHseC()const{
    return hseCost;
}

int Property::getHtlC()const{
    return htlCost;
}

int Property::setcMax(string col){
    if(col=="purple"||col=="blue"||col=="Utility")
        maxColr=2;
    else if(col=="RR")
        maxColr=4;
    else
        maxColr=3;
    
    return maxColr;
}

void Property::inform(int title,int number){
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
            if(number==0)rent=2;
            else if(number==1)rent=10;
            else if(number==2)rent=30;
            else if(number==3)rent=90;
            else if(number==4)rent=160;
            else rent=250;
            hseCost=50;
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
            if(number==0)rent=4;
            else if(number==1)rent=20;
            else if(number==2)rent=60;
            else if(number==3)rent=180;
            else if(number==4)rent=320;
            else rent=450;
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
            else if(number>=4)rent=200;
            hseCost=0;
            break;
        case ORIENTL:
            name="Oriental Avenue";
            price=100;
            color="lilac";
            if(number==0)rent=6;
            else if(number==1)rent=30;
            else if(number==2)rent=90;
            else if(number==3)rent=270;
            else if(number==4)rent=400;
            else rent=550;
            hseCost=50;
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
            if(number==0)rent=6;
            else if(number==1)rent=30;
            else if(number==2)rent=90;
            else if(number==3)rent=270;
            else if(number==4)rent=400;
            else rent=550;
            hseCost=50;
            break;
        case CONNECT:
            name="Connecticut Avenue";
            price=120;
            color="lilac";
            if(number==0)rent=8;
            else if(number==1)rent=40;
            else if(number==2)rent=100;
            else if(number==3)rent=300;
            else if(number==4)rent=450;
            else rent=600;
            hseCost=50;
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
            if(number==0)rent=10;
            else if(number==1)rent=50;
            else if(number==2)rent=150;
            else if(number==3)rent=450;
            else if(number==4)rent=625;
            else rent=750;
            hseCost=100;
            break;
        case ELECTRC: //FLAG!
            name="Electric Company";
            price=150;
            color="Utility";
            hseCost=0;
            break;
        case STATES:
            name="States Avenue";
            price=140;
            color="pink";
            if(number==0)rent=10;
            else if(number==1)rent=50;
            else if(number==2)rent=150;
            else if(number==3)rent=450;
            else if(number==4)rent=625;
            else rent=750;
            hseCost=100;
            break;
        case VIRGNIA:
            name="Virginia Avenue";
            price=160;
            color="pink";
            if(number==0)rent=12;
            else if(number==1)rent=60;
            else if(number==2)rent=180;
            else if(number==3)rent=500;
            else if(number==4)rent=700;
            else rent=900;
            hseCost=100;
            break;
        case PENNRR:
            name="Pennsylvania Railroad";
            price=200;
            color="RR";
            if(number==1)rent=25;
            else if(number==2)rent=50;
            else if(number==3)rent=100;
            else if(number>=4)rent=200;
            hseCost=0;
            break;
        case STJAMES:
            name="St. James Place";
            price=180;
            color="orange";
            if(number==0)rent=14;
            else if(number==1)rent=70;
            else if(number==2)rent=200;
            else if(number==3)rent=550;
            else if(number==4)rent=750;
            else rent=950;
            hseCost=100;
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
            if(number==0)rent=14;
            else if(number==1)rent=70;
            else if(number==2)rent=200;
            else if(number==3)rent=550;
            else if(number==4)rent=750;
            else rent=950;
            hseCost=100;
            break;
        case NEWYORK:
            name="New York Avenue";
            price=200;
            color="orange";
            if(number==0)rent=16;
            else if(number==1)rent=80;
            else if(number==2)rent=220;
            else if(number==3)rent=600;
            else if(number==4)rent=800;
            else rent=1000;
            hseCost=100;
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
            if(number==0)rent=18;
            else if(number==1)rent=90;
            else if(number==2)rent=250;
            else if(number==3)rent=700;
            else if(number==4)rent=875;
            else rent=1050;
            hseCost=150;
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
            if(number==0)rent=18;
            else if(number==1)rent=90;
            else if(number==2)rent=250;
            else if(number==3)rent=700;
            else if(number==4)rent=875;
            else rent=1050;
            hseCost=150;
            break;
        case ILLNOIS:
            name="Illinois Avenue";
            price=240;
            color="red";
            if(number==0)rent=20;
            else if(number==1)rent=100;
            else if(number==2)rent=300;
            else if(number==3)rent=750;
            else if(number==4)rent=925;
            else rent=1100;
            hseCost=150;
            break;
        case BNORR:
            name="B & O Railroad";
            price=200;
            color="RR";
            if(number==1)rent=25;
            else if(number==2)rent=50;
            else if(number==3)rent=100;
            else if(number>=4)rent=200;
            hseCost=0;
            break;
        case ATLANTC:
            name="Atlantic Avenue";
            price=260;
            color="yellow";
            if(number==0)rent=22;
            else if(number==1)rent=110;
            else if(number==2)rent=330;
            else if(number==3)rent=800;
            else if(number==4)rent=975;
            else rent=1150;
            hseCost=150;
            break;
        case VENTNOR:
            name="Ventnor Avenue";
            price=260;
            color="yellow";
            if(number==0)rent=22;
            else if(number==1)rent=110;
            else if(number==2)rent=330;
            else if(number==3)rent=900;
            else if(number==4)rent=975;
            else rent=1150;
            hseCost=150;
            break;
        case WATERWK:
            name="Water Works";
            price=150;
            color="Utility";
            hseCost=0;
            break;
        case MARVIN:
            name="Marvin Gardens";
            price=280;
            color="yellow";
            if(number==0)rent=24;
            else if(number==1)rent=120;
            else if(number==2)rent=360;
            else if(number==3)rent=850;
            else if(number==4)rent=1025;
            else rent=1200;
            hseCost=150;
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
            if(number==0)rent=26;
            else if(number==1)rent=130;
            else if(number==2)rent=390;
            else if(number==3)rent=900;
            else if(number==4)rent=1100;
            else rent=1275;
            hseCost=200;
            break;
        case NCARLNA:
            name="North Carolina Avenue";
            price=300;
            color="green";
            if(number==0)rent=26;
            else if(number==1)rent=130;
            else if(number==2)rent=390;
            else if(number==3)rent=900;
            else if(number==4)rent=1100;
            else rent=1275;
            hseCost=200;
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
            if(number==0)rent=28;
            else if(number==1)rent=150;
            else if(number==2)rent=450;
            else if(number==3)rent=1000;
            else if(number==4)rent=1200;
            else rent=1400;
            hseCost=200;
            break;
        case SHORTLN:
            name="Short Line";
            price=200;
            color="RR";
            if(number==1)rent=25;
            else if(number==2)rent=50;
            else if(number==3)rent=100;
            else if(number>=4)rent=200;
            hseCost=0;
            break;
        case CHANCE3:
            name="Chance";
            price=0;
            color="";
            break;
        case PARK:
            name="Park Place";
            price=350;
            color="blue";
            if(number==0)rent=35;
            else if(number==1)rent=175;
            else if(number==2)rent=500;
            else if(number==3)rent=1100;
            else if(number==4)rent=1300;
            else rent=1500;
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
            if(number==0)rent=50;
            else if(number==1)rent=200;
            else if(number==2)rent=600;
            else if(number==3)rent=1400;
            else if(number==4)rent=1700;
            else rent=2000;
            hseCost=200;
            break;
    }
}