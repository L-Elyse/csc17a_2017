/* 
 * File:   Player.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 9:20 PM
 * Purpose: Player Class Specifications
 */

#ifndef PLAYER_H
#define PLAYER_H


class Player{
    private:
        int money;              //Amount of money player has
        unsigned short nProps;  //Number of properties owned by player
//        int *proprty;          //Array of property names owned by player
        string piece;           //Playing "piece" chosen by player
        int nHouses;            //Number of houses owned by player
        int nHotels;            //Number of hotels owned by player
    public:
        Player();
//        ~Player();
        void setMony(int);
        int getMony()const;
        unsigned short getNPrp()const;
//        int *getPrps();
        string getPce()const;
        int getNHse()const;
        int getNHtl()const;
};

#endif /* PLAYER_H */