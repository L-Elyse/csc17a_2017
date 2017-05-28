/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 25, 2017, 2:50 PM
 * Purpose: Monopoly Game
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//User Libraries
#include "Board.h"
#include "Die.h"
#include "Names.h"
#include "Player.h"
#include "Property.h"

//Function Prototypes
char opening();
int dieRoll();
void prcsOpt(Player,int &);
void Menu();

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Instantiate Players
    Player user, comp;
    
    Names counter;
    int choice;
    int current=0;
    
    //Begin to see who goes first
    char first;
    first=opening();
//    if(first=='c')  
    
    //Begin Playing
    do{
        prcsOpt(user,current);
        Menu();
        cin>>choice;
        //Validate with try/catch
    }while(choice!=5);
    
    //Exit Stage Right!
    return 0;
}

int dieRoll(){
    //Instantiate 2 Dice
    Die die1,die2;
    
    //Roll the dice
    die1.roll();
    die2.roll();
    
    return die1.getVal()+die2.getVal();
}

void Menu(){
    cout<<"What would you like to do?"<<endl;
    cout<<"1. Purchase the Property."<<endl;
    cout<<"2. Just Visit the Property."<<endl;
    cout<<"3. Build a House."<<endl;
    cout<<"4. Build a Hotel."<<endl;
    cout<<"5. End the Game Now."<<endl;
}

void prcsOpt(Player u,int &last){
    Board spot;
  
    last+=dieRoll();    //Overload This Operator to "restart to GO"
    spot.setup(last);
    cout<<"You landed on "<<spot.getname()<<endl;    
}

char opening(){
    //Declare Comparison Variables
    int comp,user;
    
    cout<<"Hello! Welcome to the wonderful game of Monopoly!"<<endl;
    cout<<"Before we begin, do you need to read the instructions?"<<endl;
    //Create a boolean input where if the answer is affirmative, output the
    //instructions, which will be read in from a file
    cout<<"We will begin the game by rolling the dice to see who gets to go ";
    cout<<"first!"<<endl<<endl;
    cout<<"Let's start with your opponent."<<endl;
    
    do{
        comp=dieRoll();
        cout<<"Your opponent rolls "<<comp<<endl;
        cout<<"Now it's your turn."<<endl;
        user=dieRoll();
        cout<<"You roll "<<user<<endl<<endl;

        //Compare to see who goes first
        if(user>comp){
            cout<<"You get to go first!"<<endl; 
            return 'u';
        }
        else if(user<comp){
            cout<<"Your opponent goes first."<<endl; 
            return 'c';
        }
        else cout<<"It's a Tie! Let's try this again."<<endl;
    }while(comp==user);
}