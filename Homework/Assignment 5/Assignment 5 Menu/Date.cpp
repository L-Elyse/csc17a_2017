/* 
 * File:   Date.h
 * Author: Laurie Guimont
 * Created on May 7, 2017, 2:32 PM
 * Purpose: Date Class Implementation
 */

#include <cstdlib>
#include <string>
using namespace std;

#include "Date.h"

void Date::setmnth(int m){
    if(m>=1&&m<=12) month=m;
    else exit(0);
}

void Date::setday(int d){
    if(d>=1&&d<=31) day=d;
    else exit(0);
}

void Date::setyear(int y){
    year=y;
}

int Date::getmnth() const{
    return month;
}

string Date::mname() const{
    string name;
    
    switch(month){
        case 1: name="January";break;
        case 2: name="February";break;
        case 3: name="March";break;
        case 4: name="April";break;
        case 5: name="May";break;
        case 6: name="June";break;
        case 7: name="July";break;
        case 8: name="August";break;
        case 9: name="September";break;
        case 10: name="October";break;
        case 11: name="November";break;
        case 12: name="December";break;        
    }
    return name;
}

int Date::getday() const{
    return day;
}

int Date::getyear() const{
    return year;
}