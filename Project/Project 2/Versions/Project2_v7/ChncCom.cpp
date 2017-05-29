/* 
 * File:   Chance.h
 * Author: Laurie Guimont
 * Created on May 27, 2017, 5:04 PM
 * Purpose: ChncCom Class Implementation
 */

#include "ChncCom.h"
#include "Player.h"

#include <iostream>
#include <string>
using namespace std;

ChncCom::ChncCom(){
    message="";
}

void ChncCom::setMess(unsigned short pick,short index,Player &player,
        Player &opp,int mon,int compmon){
    if(pick==1){
        switch(index){
            case 1:{
                message="Advance token to the nearest Railroad and pay owner "
                        "TWICE the rental to which he/she is otherwise "
                        "entitled. If Railroad is UNOWNED, you may buy it "
                        "from the Bank.";
                //Insert Procedure
                break;            
            }
            case 2:{
                message="Go directly TO JAIL. Do not pass Go, do not collect "
                        "$200.";
                break;
            }
            case 3:{
                message="Take a ride on the Reading. If you pass Go, collect "
                        "$200.";
                break;
            }
            case 4:{
                message="Advance to Illinois Ave.";
                break;
            }
            case 5:{
                message="Bank pays you dividend of $50.";
                player.money=mon+50;
                player.setMony(player.money);
                break;
            }
            case 6:{
                message="Advance token to the nearest Railroad and pay owner "
                        "TWICE the rental to which he/she is otherwise "
                        "entitled. If Railroad is UNOWNED, you may buy it "
                        "from the Bank.";
                break;
            }
            case 7:{
                message="Take a walk on the Boardwalk. Advance token to "
                        "Boardwalk.";
                break;
            }
            case 8:{
                message="Get out of Jail Free!! This card may be kept until "
                        "needed, or sold.";
                break;
            }
            case 9:{
                message="You have been elected Chairman of the Board. Pay each "
                        "player $50.";
                break;
            }
            case 10:{
                message="Advance to St. Charles Place. If you pass Go, collect "
                        "$200.";
                break;
            }
            case 11:{
                message="Make general repairs on all your property. For each "
                        "House, pay $25. For each Hotel, pay $100.";
                if(player.nHouses>=1){
                    player.money=mon-(player.nHouses*25);
                    player.setMony(player.money);
                }
                if(player.nHotels>=1&&player.nHouses>=1){
                    player.money-=(player.nHotels*100);
                    player.setMony(player.money);
                }
                else if(player.nHotels>=1){
                    player.money=mon-(player.nHotels*100);
                    player.setMony(player.money);
                }
                break;
            }
            case 12:{
                message="Your building and loan matures. Collect $150.";
                player.money=mon+150;
                player.setMony(player.money);
                break;
            }
            case 13:{
                message="Pay Poor Tax of $15.";
                player.money=mon-15;
                player.setMony(player.money);
                break;
            }
            case 14:{
                message="Advance to Go. Collect $200.";
                break;
            }
            case 15:{
                message="Go back 3 spaces.";
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
                player.money=mon-100;
                player.setMony(player.money);
                break;            
            }
            case 2:{
                message="Christmas Fund matures. Collect $100.";
                player.money=mon+100;
                player.setMony(player.money);
                break;
            }
            case 3:{
                message="Advance to Go. Collect $200.";
                break;
            }
            case 4:{
                message="Get out of Jail free!!! This card may be kept until "
                        "needed, or sold.";
                break;
            }
            case 5:{
                message="Go TO JAIL. Go directly to Jail. Do not pass Go, do "
                        "not collect $200.";
                break;
            }
            case 6:{
                message="Bank error in your favor. Collect $200.";
                player.money=mon+200;
                player.setMony(player.money);
                break;
            }
            case 7:{
                message="You are assessed for street repairs. $40 per House, "
                        "$115 per Hotel.";
                if(player.nHouses>=1){
                    player.money=mon-(player.nHouses*40);
                    player.setMony(player.money);
                }
                if(player.nHotels>=1&&player.nHouses>=1){
                    player.money-=(player.nHotels*115);
                    player.setMony(player.money);
                }
                else if(player.nHotels>=1){
                    player.money=mon-(player.nHotels*115);
                    player.setMony(player.money);
                }
                break;
            }
            case 8:{
                message="You have won second prize in a beauty contest. "
                        "Collect $10.";
                player.money=mon+10;
                player.setMony(player.money);
                break;
            }
            case 9:{
                message="Income Tax refund. Collect $20.";
                player.money=mon+20;
                player.setMony(player.money);
                break;
            }
            case 10:{
                message="Grand Opera Opening. Collect $50 from every player "
                        "for opening night seats.";
                player.money=mon+50;
                player.setMony(player.money);
                opp.money=compmon-50;
                opp.setMony(opp.money);
                break;
            }
            case 11:{
                message="From sale of stock you get $45.";
                player.money=mon+45;
                player.setMony(player.money);
                break;
            }
            case 12:{
                message="Pay school tax of $150.";
                player.money=mon-150;
                player.setMony(player.money);
                break;
            }
            case 13:{
                message="You inherit $100.";
                player.money=mon+100;
                player.setMony(player.money);
                break;
            }
            case 14:{
                message="Receive for services $25.";
                player.money=mon+25;
                player.setMony(player.money);
                break;
            }
            case 15:{
                message="Life insurance matures. Collect $100.";
                player.money=mon+100;
                player.setMony(player.money);
                break;
            }
            case 16:{
                message="Doctor's fee. Pay $50.";
                player.money=mon-50;
                player.setMony(player.money);
                break;
            }
        }
    }
}

string ChncCom::getMess() const{
    return message;
}