/* 
 * File:   Rules.h
 * Author: Laurie Guimont
 * Created on May 29, 2017, 2:04 PM
 * Purpose: Rules Class Implementation
 */

#include <iostream>
#include <cctype>
using namespace std;

#include "Rules.h"
#include "Player.h"
#include "Die.h"

void Rules::Go2Jail(Player &player){
    Die die1,die2;
    char use,choice;
    int count=0;
    
    if(player.outJail>0){
        cout<<"Would you like to use your Get out of Jail Free card? (Y/N)";
        cin>>use;
        if(toupper(use)=='Y'){
            player.outJail=0;
            cout<<"Get Out of Jail Free Card used!"<<endl;
        }
        else{
            cout<<"Would you like to pay the $50 fine now? (Y/N)";
            cin>>choice;
            if(toupper(choice)=='Y'){
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

int Rules::gameEnd(Player &player){
    if(player.getMony()<0){
        cout<<"Oh no! You are in debt!"<<endl;
        cout<<"Sorry. Maybe next time you will make better decisions.";
        cout<<"The game is over!! We have a winner!"<<endl;
    }
    
    return 0;    
}