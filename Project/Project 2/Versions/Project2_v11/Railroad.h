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

class Railroad:public Property{
    private:
        int rent;
    public:
        int setrent(Player &player){
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
            RR.inform(player.getSpot(),count);
            
            rent=RR.getrent();
            
            return rent;
        };
};

#endif /* RAILROAD_H */