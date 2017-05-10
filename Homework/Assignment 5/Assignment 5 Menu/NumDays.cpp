/* 
 * File:   NumDays.h
 * Author: Laurie Guimont
 * Created on May 9, 2017, 1:33 PM
 * Purpose: NumDays Class Implementation
 */

#include <cstdlib>
using namespace std;

#include "NumDays.h"

NumDays::NumDays(float h){
    workhrs=h;
}

void NumDays::setHrs(float h){
    workhrs=h;
}

float NumDays::getHrs() const{
    return workhrs;
}

float NumDays::getDays(){
    return workhrs/8;
}

float NumDays::operator +(const NumDays &right){
    return workhrs+right.workhrs;
}

float NumDays::operator -(const NumDays &right){    
    return workhrs-right.workhrs;
}

float NumDays::operator ++(){
    return ++workhrs;
}

float NumDays::operator ++(int){
    return workhrs++;
}

float NumDays::operator --(){
    return --workhrs;
}

float NumDays::operator --(int){
    return workhrs--;
}