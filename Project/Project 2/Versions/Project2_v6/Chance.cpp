/* 
 * File:   Chance.h
 * Author: Laurie Guimont
 * Created on May 27, 2017, 5:04 PM
 * Purpose: Chance Class Implementation
 */

#include "Chance.h"
#include "Player.h"

#include <string>
using namespace std;

Chance::Chance(){
    message="";
}

void Chance::setMess(string mess){
    message=mess;
}

void Chance::setMess(unsigned short index){
    switch(index){
        case 1:{
            message="Advance token to the nearest Railroad and pay owner TWICE "
                    "the rental to which he/she is otherwise entitled. If "
                    "Railroad is UNOWNED, you may buy it from the Bank.";
            //Insert Procedure
            break;            
        }
        case 2:{
            message="Go directly TO JAIL. Do not pass Go, do not collect $200.";
            break;
        }
        case 3:{
            message="Take a ride on the Reading. If you pass Go, collect $200.";
            break;
        }
        case 4:{
            message="Advance to Illinois Ave.";
            break;
        }
        case 5:{
            message="Bank pays you dividend of $50.";
            money+=50;
            break;
        }
        case 6:{
            message="Advance token to the nearest Railroad and pay owner TWICE "
                    "the rental to which he/she is otherwise entitled. If "
                    "Railroad is UNOWNED, you may buy it from the Bank.";
            break;
        }
        case 7:{
            message="Take a walk on the Boardwalk. Advance token to Boardwalk.";
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
            break;
        }
        case 12:{
            message="Your building and loan matures. Collect $150.";
            money+=150;
            break;
        }
        case 13:{
            message="Pay Poor Tax of $15.";
            money-=15;
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
            message="Advance token to nearest Utility. If UNOWNED you may buy "
                    "it from the Bank. If OWNED, throw dice and pay owner a "
                    "total ten times the amount thrown.";
            break;
        }
    }
}

string Chance::getMess() const{
    return message;
}