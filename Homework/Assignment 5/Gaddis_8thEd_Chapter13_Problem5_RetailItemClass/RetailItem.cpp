/* 
 * File:   RetailItem.h
 * Author: Laurie Guimont
 * Created on May 8, 2017, 2:47 PM
 * Purpose: RetailItem Class Implementation
 */

#include <string>
using namespace std;

#include "RetailItem.h"

RetailItem::RetailItem(string d, int u, float p){
    descrpt=d;
    units=u;
    price=p;
}

void RetailItem::setdesc(string d){
    descrpt=d;
}

void RetailItem::setunit(int u){
    units=u;
}

void RetailItem::setprce(float p){
    price=p;
}

string RetailItem::getdesc() const{
    return descrpt;
}

int RetailItem::getunit() const{
    return units;
}

float RetailItem::getprce() const{
    return price;
}