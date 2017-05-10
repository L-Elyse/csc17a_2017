/* 
 * File:   FeetInches.h
 * Author: Laurie Guimont
 * Created on May 9, 2017, 1:41 PM
 * Purpose: FeetInch Class Implementation
 */

#include "FeetInch.h"

void FeetInch::simplify(){
    if(inches>=12){
        feet+=(inches/12);
        inches=inches%12;
    }
    else if(inches<0){
        feet-=((abs(inches)/12)+1);
        inches=12-(abs(inches)%12);
    }
}