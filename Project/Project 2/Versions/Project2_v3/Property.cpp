/* 
 * File:   Property.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 10:01 PM
 * Purpose: Property Class Implementation
 */

#include "Property.h"

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