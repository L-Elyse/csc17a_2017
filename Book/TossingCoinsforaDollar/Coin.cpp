/* 
 * File:   Coin.h
 * Author: Laurie Guimont
 * Created on May 15, 2017, 11:13 PM
 * Purpose: Coin Class Implementation
 */

#include <cstdlib>
using namespace std;

#include "Coin.h"

Coin::Coin(){
    sideUp="";
}

void Coin::toss(){
    int choice=(rand()%2)+1;
    
    if(choice==1)
        sideUp="heads";
    else
        sideUp="tails";
}

void Coin::setBal(float val){
    if(sideUp=="heads")
        balance+=val;
    else
        return;
}

string Coin::getSide() const{
    return sideUp;
}

float Coin::getBal() const{
    return balance;
}

bool Coin::loop() const{
    bool status;
    
    if(balance>=1)
        status=true;
    else
        status=false;
    
    return status;
}

float Coin::balance=0;