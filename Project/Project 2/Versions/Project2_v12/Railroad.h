/* 
 * File:   Railroad.h
 * Author: Laurie Guimont
 * Created on May 30, 2017, 10:55 PM
 * Purpose: 
 */

#ifndef RAILROAD_H
#define RAILROAD_H
#include "Property.h"
#include "Player.h"

#include <iostream>
using namespace std;

class Railroad:public Property{
    public:
        int setrent(Player &player,int current){
            Railroad RR;
            int count=0;
            if(player.findPrp(READRR)==true)
                count++;
            if(player.findPrp(PENNRR)==true)
                count++;
            if(player.findPrp(BNORR)==true)
                count++;
            if(player.findPrp(SHORTLN)==true)
                count++;
            RR.inform(current,count);
            
            return RR.rent;
        };
};

#endif /* RAILROAD_H */