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
    money=1500;                //All players begin the game with $1500
    nProps=0;                  //No properties possessed at beginning of game
//    proprty=new Property*[40]; //Names of properties player owns
//    for(int i=0;i<40;i++){
//        proprty[i]=new Property(i);
//    }
    piece="";                  //Wait for player to choose piece
    nHouses=0;                 //Houses and Hotels are purchased once a player
    nHotels=0;                 //   has obtained all properties in a bracket
}

//Player::~Player(){
//    for(int i=0;i<40;i++){
//        delete proprty[i];
//    }
//    delete []proprty;
//}

int Player::getMony()const{
    return money;
}

unsigned short Player::getNPrp()const{
    return nProps;
}

//Property **Player::getPrps(){
//    Property **own=new Property*[40];
//    return own;
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

//void Player::clean(Property** own){
//    for(int i=0;i<40;i++){
//        delete own[i];
//    }
//    delete []own;
//}