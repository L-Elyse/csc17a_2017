/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 15, 2017, 10:43 PM
 * Purpose: Coin Toss Simulator Game
 */

#include <iostream>
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
    Coin coin;
    
    //Initial Side
    cout<<"The Initial Side Up of the coin: "<<coin.getSide()<<endl;
    cout<<"Now to toss the coin 20 times..."<<endl<<endl;
    
    //Toss 20 Times
    for(int i=0;i<20;i++){
        coin.toss();
        cout<<"Side Up: "<<coin.getSide()<<endl;
    }
    
    //Exit Stage Right!
    return 0;
}

