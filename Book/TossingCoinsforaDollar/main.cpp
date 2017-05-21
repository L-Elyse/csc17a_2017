/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 15, 2017, 11:13 PM
 * Purpose: Tossing Coins for a Dollar
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Coin.h"
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Instantiate Class Object
    bool again;
    float qval=0.25,dval=0.10,nval=0.05;
    Coin quarter;
    Coin dime;
    Coin nickel;
    
    //Begin Flipping Coins
    do{
        //Toss and Set Balance
        quarter.toss();
        quarter.setBal(qval);
        dime.toss();
        dime.setBal(dval);
        nickel.toss();
        nickel.setBal(nval);
        
        //Results
        cout<<"Quarter: "<<quarter.getSide()<<endl;
        cout<<"Dime: "<<dime.getSide()<<endl;
        cout<<"Nickel: "<<nickel.getSide()<<endl<<endl;
        
        again=quarter.loop();
    }while(!again);
    
    cout<<fixed<<setprecision(2)<<showpoint;
    if(quarter.getBal()==1)
        cout<<"You won!"<<endl;
    else
        cout<<"Sorry. You lost. Your ending balance is $"<<quarter.getBal()<<endl;
    
    //Exit Stage Right!
    return 0;
}