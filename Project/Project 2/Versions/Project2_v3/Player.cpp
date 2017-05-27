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
    piece="";                  
    nHouses=0;                 
    nHotels=0;                 
}

//Player::~Player(){
//    delete []proprty;
//}

int Player::getMony()const{
    return money;
}

unsigned short Player::getNPrp()const{
    return nProps;
}

//int *Player::getPrps(){
//    return proprty;
//}

string Player::getPce()const{
    return piece;
}

int Player::getNHse()const{
    return nHouses;
}

int Player::getNHtl()const{
    return nHotels;
}