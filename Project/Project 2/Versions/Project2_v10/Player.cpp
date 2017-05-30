/* 
 * File:   Player.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 9:20 PM
 * Purpose: Player Class Implementation
 */

#include <iostream>
#include <string>
using namespace std;

#include "Player.h"


Player::Player(){
    money=1500;                
    nProps=0;                  
    proprty=new int[40];   
    for(int i=0;i<=40;i++)
        *(proprty+i)=0;
    spot=GO;
    outJail=0;
    nHouses=0;                 
    nHotels=0;                 
}

void Player::setMony(int mon){
    money=mon;
}

void *Player::setPrps(){
    proprty[nProps]=spot;
    nProps++;
}

void Player::setNew(int s){   //OR!!!!!! POLYMORPHISM!!!
    spot=s;
}

void Player::setSpot(int s){
    spot+=s;
}

void Player::setNHse(int num){
    nHouses=num;
}

void Player::setNHtl(int num){
    nHotels=num;
}

int Player::getMony()const{
    return money;
}

unsigned short Player::getNPrp()const{
    return nProps;
}

void *Player::getPrps(){
    for(int i=0;i<nProps;i++)
        cout<<*(proprty+i)<<" ";
}

int Player::getSpot() const{
    return spot;
}

int Player::getNHse()const{
    return nHouses;
}

int Player::getNHtl()const{
    return nHotels;
}