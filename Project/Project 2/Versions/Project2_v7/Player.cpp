/* 
 * File:   Player.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 9:20 PM
 * Purpose: Player Class Implementation
 */

#include <string>
using namespace std;

#include "Player.h"


Player::Player(){
    money=1500;                
    nProps=0;                  
//    proprty=new int[40];   
//    for(int i=0;i<=40;i++)
//        *(proprty+i)=i;
    spot=GO;
    nHouses=0;                 
    nHotels=0;                 
}

void Player::setMony(int mon){
    money=mon;
}


void *Player::setPrps(int prop,int index){
    *(proprty+index)=prop;
}

int Player::getMony()const{
    return money;
}

unsigned short Player::getNPrp()const{
    return nProps;
}

int *Player::getPrps() const{
    return proprty;
}

int Player::getNHse()const{
    return nHouses;
}

int Player::getNHtl()const{
    return nHotels;
}