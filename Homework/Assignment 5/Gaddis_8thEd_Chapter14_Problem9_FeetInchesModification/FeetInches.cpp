/* 
 * File:   FeetInches.h
 * Author: Laurie Guimont
 * Created on May 9, 2017, 1:41 PM
 * Purpose: FeetInches Class Implementation
 */

#include "FeetInches.h"

void FeetInches::simplify(){
    if(inches>=12){
        feet+=(inches/12);
        inches=inches%12;
    }
    else if(inches<0){
        feet-=((abs(inches)/12)+1);
        inches=12-(abs(inches)%12);
    }
}

bool FeetInches::operator <=(const FeetInches &right){
    bool status;
    
    if(feet<=right.feet&&inches<=right.inches)
        status=true;
    else 
        status=false;
    
    return status;
}

bool FeetInches::operator >=(const FeetInches &right){
    bool status;
    
    if(feet>=right.feet&&inches>=right.inches)
        status=true;
    else 
        status=false;
    
    return status;
}

bool FeetInches::operator !=(const FeetInches &right){
    bool status;
    
    if(feet!=right.feet&&inches!=right.inches)
        status=true;
    else 
        status=false;
    
    return status;
}