/* 
 * File:   Rules.h
 * Author: Laurie Guimont
 * Created on May 29, 2017, 2:04 PM
 * Purpose: Rules Class Implementation
 */

#include <iostream>
using namespace std;

#include "Rules.h"
#include "Player.h"
#include "Die.h"

void Rules::Go2Jail(Player &player){
    Die die1,die2;
    bool use=true,choice=true;
    int count=0;
    
    if(player.outJail>0){
        cout<<"Would you like to use your Get out of Jail Free card?";
        cin>>use;
        if(use)
            player.outJail=0;
        else{
            cout<<"Would you like to pay the $50 fine now?";
            cin>>choice;
            if(choice){
                player.money-=50;
            }
            else{
                do{
                    die1.roll();
                    die2.roll();
                    cout<<"Die 1: "<<die1.getVal()<<"  Die 2: "<<die2.getVal()<<"\n";
                    count++;
                }while(die1.getVal()!=die2.getVal()&&count<3);
                if(count=3&&die1.getVal()!=die2.getVal())
                    player.money-=50;
            }
        }
    }
    else{
        cout<<"Would you like to pay the $50 fine now?";
        cin>>choice;
        if(!choice){
            do{
                die1.roll();
                die2.roll();
                cout<<"Die 1: "<<die1.getVal()<<"  Die 2: "<<die2.getVal()<<"\n";
                count++;
            }while(die1.getVal()!=die2.getVal()&&count<3);
            if(count=3&&die1.getVal()!=die2.getVal()){
                player.money-=50;
                cout<<"Fine paid!"<<endl;
            }
        }
        else{
            player.money-=50;
            cout<<"Fine paid!"<<endl;
        }
    }
    player.setNew(JAIL);
}

void Rules::cGoJail(Player &comp){
    Die die1,die2;
    int count=0;
    
    if(comp.outJail>0)
        comp.outJail=0;
    else{
        do{
            die1.roll();
            die2.roll();
            cout<<"Die 1: "<<die1.getVal()<<"  Die 2: "<<die2.getVal()<<"\n";
            count++;
        }while(die1.getVal()!=die2.getVal()&&count<=3);
        if(count=3&&die1.getVal()!=die2.getVal()){
            comp.money-=50;
            cout<<"Fine paid!"<<endl;
        }
    }
    comp.setNew(JAIL);
}

void Rules::restart(int num,Player &player){
    if((player.spot+num)>BRDWALK){
        leftovr=BRDWALK-player.spot;
        extra=(num-leftovr)-1;
        player.setNew(extra);
        player.money+=200;
    }
    else
        player.setSpot(num);
}