/* 
 * File:   Chance.h
 * Author: Laurie Guimont
 * Created on May 27, 2017, 5:04 PM
 * Purpose: ChncCom Class Implementation
 */

#include "ChncCom.h"
#include "Player.h"
#include "Rules.h"

#include <iostream>
#include <string>
using namespace std;

ChncCom::ChncCom(){
    message="";
}

void ChncCom::setMess(unsigned short pick,short index,Player &player,
        Player &opp,Rules &rule){
    if(pick==1){
        switch(index){
            case 1:{
                message="Advance token to the nearest Railroad and pay owner "
                        "TWICE the rental to which he/she is otherwise "
                        "entitled. If Railroad is UNOWNED, you may buy it "
                        "from the Bank.";
                if(player.getSpot()==CHANCE1)
                    player.setNew(PENNRR);
                else if(player.getSpot()==CHANCE2)
                    player.setNew(BNORR);
                else if(player.getSpot()==CHANCE3){
                    player.setNew(READRR);
                    player.money+=200;
                }
                break;            
            }
            case 2:{
                message="Go directly TO JAIL. Do not pass Go, do not collect "
                        "$200.";
                player.setNew(GO2JAIL);
                break;
            }
            case 3:{
                message="Take a ride on the Reading. If you pass Go, collect "
                        "$200.";
                player.setNew(READRR);
                player.money+=200;
                break;
            }
            case 4:{
                message="Advance to Illinois Ave.";
                if(player.getSpot()==CHANCE3)
                    player.money+=200;
                player.setNew(ILLNOIS);
                break;
            }
            case 5:{
                message="Bank pays you dividend of $50.";
                player.money+=50;
                break;
            }
            case 6:{
                message="Advance token to the nearest Railroad and pay owner "
                        "TWICE the rental to which he/she is otherwise "
                        "entitled. If Railroad is UNOWNED, you may buy it "
                        "from the Bank.";
                if(player.getSpot()==CHANCE1)
                    player.setNew(PENNRR);
                else if(player.getSpot()==CHANCE2)
                    player.setNew(BNORR);
                else if(player.getSpot()==CHANCE3){
                    player.setNew(READRR);
                    player.money+=200;
                }
                break;
            }
            case 7:{
                message="Take a walk on the Boardwalk. Advance token to "
                        "Boardwalk.";
                player.setNew(BRDWALK);
                break;
            }
            case 8:{
                message="Get out of Jail Free!! This card may be kept until "
                        "needed, or sold.";
                player.outJail++;
                break;
            }
            case 9:{
                message="You have been elected Chairman of the Board. Pay each "
                        "player $50.";
                player.money-=50;
                opp.money+=50;
                break;
            }
            case 10:{
                message="Advance to St. Charles Place. If you pass Go, collect "
                        "$200.";
                if(player.getSpot()==CHANCE2||player.getSpot()==CHANCE3){
                    player.money+=200;
                }
                player.setNew(STCHRLS);
                break;
            }
            case 11:{
                message="Make general repairs on all your property. For each "
                        "House, pay $25. For each Hotel, pay $100.";
                if(player.nHouses>=1){
                    player.money-=(player.nHouses*25);
                }
                if(player.nHotels>=1&&player.nHouses>=1){
                    player.money-=(player.nHotels*100);
                }
                else if(player.nHotels>=1){
                    player.money-=(player.nHotels*100);
                }
                break;
            }
            case 12:{
                message="Your building and loan matures. Collect $150.";
                player.money+=150;
                break;
            }
            case 13:{
                message="Pay Poor Tax of $15.";
                player.money-=15;
                break;
            }
            case 14:{
                message="Advance to Go. Collect $200.";
                player.setNew(GO);
                player.money+=200;
                break;
            }
            case 15:{
                message="Go back 3 spaces.";
                player.setNew(player.getSpot()-3);
                break;
            }
            case 16:{
                message="Advance token to nearest Utility. If UNOWNED you may "
                        "buy it from the Bank. If OWNED, throw dice and pay "
                        "owner a total ten times the amount thrown.";
                break;
            }
        }
    }
    else if(pick==2){
        switch(index){
            case 1:{
                message="Pay Hospital $100.";
                player.money-=100;
                break;            
            }
            case 2:{
                message="Christmas Fund matures. Collect $100.";
                player.money+=100;
                break;
            }
            case 3:{
                message="Advance to Go. Collect $200.";
                player.setNew(GO);
                player.money+=200;
                break;
            }
            case 4:{
                message="Get out of Jail free!!! This card may be kept until "
                        "needed, or sold.";
                player.outJail++;
                break;
            }
            case 5:{
                message="Go TO JAIL. Go directly to Jail. Do not pass Go, do "
                        "not collect $200.";
                player.setNew(GO2JAIL);
                break;
            }
            case 6:{
                message="Bank error in your favor. Collect $200.";
                player.money+=200;
                break;
            }
            case 7:{
                message="You are assessed for street repairs. $40 per House, "
                        "$115 per Hotel.";
                if(player.nHouses>=1){
                    player.money-=(player.nHouses*40);
                }
                if(player.nHotels>=1&&player.nHouses>=1){
                    player.money-=(player.nHotels*115);
                }
                else if(player.nHotels>=1){
                    player.money-=(player.nHotels*115);
                }
                break;
            }
            case 8:{
                message="You have won second prize in a beauty contest. "
                        "Collect $10.";
                player.money+=10;
                break;
            }
            case 9:{
                message="Income Tax refund. Collect $20.";
                player.money+=20;
                break;
            }
            case 10:{
                message="Grand Opera Opening. Collect $50 from every player "
                        "for opening night seats.";
                player.money+=50;
                opp.money-=50;
                break;
            }
            case 11:{
                message="From sale of stock you get $45.";
                player.money+=45;
                break;
            }
            case 12:{
                message="Pay school tax of $150.";
                player.money-=150;
                break;
            }
            case 13:{
                message="You inherit $100.";
                player.money+=100;
                break;
            }
            case 14:{
                message="Receive for services $25.";
                player.money+=25;
                break;
            }
            case 15:{
                message="Life insurance matures. Collect $100.";
                player.money+=100;
                break;
            }
            case 16:{
                message="Doctor's fee. Pay $50.";
                player.money-=50;
                break;
            }
        }
    }
}

string ChncCom::getMess() const{
    return message;
}