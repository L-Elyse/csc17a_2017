/* 
 * File:   Car.h
 * Author: Laurie Guimont
 * Created on May 7, 2017, 10:35 PM
 * Purpose: Car Class Specification
 */

#include <string>
using namespace std;

#include "Car.h"

Car::Car(int y, string m){
    yearMod=y;
    make=m;
    speed=0;
}

int Car::getyear() const{
    return yearMod;
}

string Car::getmake() const{
    return make;
}

int Car::getspd() const{
    return speed;
}

int Car::accelerate(){
    return speed+=5;
}

int Car::brake(){
    return speed-=5;
}