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
#include <string>
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
        virtual string getPos(int named) const{
            string postion;
            
            if(named==READRR)
                postion="first";
            else if(named==PENNRR)
                postion="second";
            else if(named==BNORR)
                postion="third";
            else if(named==SHORTLN)
                postion="fourth";
            return postion;
        }
};

#endif /* RAILROAD_H */