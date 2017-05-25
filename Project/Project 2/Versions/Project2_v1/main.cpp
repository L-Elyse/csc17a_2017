/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 20, 2017, 8:55 PM
 * Purpose: Monopoly Game
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//User Libraries
#include "Die.h"
#include "Board.h"
#include "Property.h"

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Instantiate 2 Dice
    Die die1, die2;
    int sum,houses=5;
    Property test;
    
    //Roll both dice 5 times
    for(int i=0;i<5;i++){
        die1.roll();
        die2.roll();
        sum=die1.getVal()+die2.getVal();
        test.inform(sum,houses);
        cout<<die1.getVal()<<" "<<die2.getVal()<<" "<<sum<<" "<<test.getname()
                <<" "<<test.getprce()<<" "<<test.getcolr()<<" "<<test.getrent()<<endl;
    }
    
    //Exit Stage Right!
    return 0;
}