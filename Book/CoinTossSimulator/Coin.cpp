/* 
 * File:   Coin.h
 * Author: Laurie Guimont
 * Created on May 15, 2017, 10:44 PM
 * Purpose: Coin Class Implementation
 */

#include <cstdlib>
#include <string>
using namespace std;

#include "Coin.h"

Coin::Coin(){
    sideUp="";
    toss();
}

void Coin::toss(){
    int choice=(rand()%2)+1;
    
    if(choice==1)
        sideUp="heads";
    else
        sideUp="tails";
}

string Coin::getSide() const{
    return sideUp;
}