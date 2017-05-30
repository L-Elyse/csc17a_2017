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
#include "Property.h"


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

void Player::setNHse(){
    Property prop;
    int colors[10];
    int count=0;
    bool add=true;
    int numHse;
    
    for(int i=0;i<10;i++){
        for(int j=0;j<nProps;j++){
            prop.inform(*(proprty+j),nHouses);
            if(prop.getcolr()==prop.colList(i))
                count++;
        }
        colors[i]=count;
        count=0;
    }
    cout<<"You currently own: "<<endl;
    for(int i=0;i<10;i++){
        cout<<colors[i]<<" "<<prop.colList(i)<<" contains ";
        cout<<prop.setcMax(prop.colList(i))<<" total properties"<<endl;
        if(colors[i]==prop.setcMax(prop.colList(i))){
            cout<<"Would you like to add houses here? The cost per house is $";
            cout<<prop.getHseC()<<endl;
            cin>>add;
            if(add==true){
                cout<<"How many would you like to purchase? ";
                cin>>numHse;
                nHouses+=numHse;
                cout<<"You now own "<<nHouses<<" houses. Due to this change, ";
                cout<<"the rent of all properties in the community go up. \n";
            }
        }       
    }
    if(nHouses==0){
        cout<<"You can only purchase houses if you have obtained all ";
        cout<<"properties in a color group!"<<endl;
    }
}

void Player::setNHtl(Property &prop){
    int number;
    
    if(nHouses<4){
        cout<<"You can only purchase hotels if you have first purchased ";
        cout<<"4 houses!"<<endl;
    }
    else{
        cout<<"Hotels cost $"<<prop.getHtlC()<<". How many would you like? \n";
        cin>>number;
        nHotels+=number;
    }
}

void Player::payRent(int rent){
    money-=rent;
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

bool Player::findPrp(int num){
    for(int i=0;i<nProps;i++){
        if(num==*(proprty+i))
            return true;  
    }  
    return false;
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