/* 
 * File:   Card.h
 * Author: Laurie Guimont
 * Created on April 29, 2017, 10:10 PM
 * Purpose: Card Class Specifications
 */
         
#include "Card.h"

Card::Card(unsigned char num){
    cNumber=(num>=0&&num<=51)?num:0;
}

char Card::getSuit(){
    if(cNumber<13) return 'S';
    else if(cNumber<26) return 'D';
    else if (cNumber<39) return 'C';
    else return 'H';
}

char Card::getFVal(){
    char fv[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    return fv[cNumber%13];
}

char Card::getNum(){
    if(cNumber%13+1<10) return cNumber%13+1;
    else return 10;
}

char Card::getCNum(){
    return cNumber;
}