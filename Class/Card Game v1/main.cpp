/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 29, 2017, 8:50 PM
 * Purpose: Card Game
 */


//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Card.h"

//Executable code begins here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare a deck of cards
    Card **card=new Card*[52];
    int *index=new int[52];
    for(int i=0;i<52;i++){
        card[i]=new Card(i);
        index[i]=i;
    }
    
    //Shuffle
    for(int shuffle=1;shuffle<=7;shuffle++){
        for(int eachCrd=0;eachCrd<52;eachCrd++){
            int rnd=rand()%52;
            int temp=index[eachCrd];
            index[eachCrd]=index[rnd];
            index[rnd]=temp;
        }
    }
    
    //Process by mapping inputs to outputs
    for(int i=0;i<52;i++){
        cout<<i<<" "<<card[index[i]]->getFVal()<<card[index[i]]->getSuit()
                <<" "<<static_cast<int>(card[index[i]]->getNum())
                <<" "<<static_cast<int>(card[index[i]]->getCNum())<<endl;
    }
    
    //Clean up
    for(int i=0;i<52;i++){
        delete card[i];
    }
    delete []card;
    delete []index;
    
    //Exit Stage Right!
    return 0;
}