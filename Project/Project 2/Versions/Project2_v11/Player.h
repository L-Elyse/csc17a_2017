/* 
 * File:   Player.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 9:20 PM
 * Purpose: Player Class Specifications
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "ChncCom.h"
#include "Rules.h"
#include "Property.h"

class Player{
    private:
        unsigned short nProps;  //Number of properties owned by player
        int *proprty;           //Array of property names owned by player
        int spot;               //Property Player has landed on
        int outJail;            //Get Out of Jail Free Card
        int nHouses;            //Number of houses owned by player
        int nHotels;            //Number of hotels owned by player
    protected:
        int money;              //Amount of money player has
    public:
        Player();
        ~Player(){delete []proprty;};
        void setMony(int);
        void *setPrps();
        void setNew(int);
        void setSpot(int);
        void setNHse();
        void setNHtl(Property &);
        void payRent(int);
        int getMony()const;
        unsigned short getNPrp()const;
        int getSpot()const;
        void *getPrps();
        bool findPrp(int);
        int getNHse()const;
        int getNHtl()const;
        
        //Friends
        friend void ChncCom::setMess(unsigned short,short,Player &,Player &,Rules &);
        friend void Rules::Go2Jail(Player &);
        friend void Rules::cGoJail(Player &);
        friend void Rules::restart(int,Player &);
};

#endif /* PLAYER_H */