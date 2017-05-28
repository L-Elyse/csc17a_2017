/* 
 * File:   Player.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 9:20 PM
 * Purpose: Player Class Specifications
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "ChncCom.h"

class Player{
    private:
        unsigned short nProps;  //Number of properties owned by player
//        int *proprty;          //Array of property names owned by player
        int nHouses;            //Number of houses owned by player
        int nHotels;            //Number of hotels owned by player
    protected:
        int money;              //Amount of money player has
    public:
        Player();
//        ~Player();
        void setMony(int);
        int getMony()const;
        unsigned short getNPrp()const;
//        int *getPrps();
        int getNHse()const;
        int getNHtl()const;
        friend void ChncCom::setMess(unsigned short,Player &,Player &);
};

#endif /* PLAYER_H */