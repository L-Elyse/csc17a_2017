/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 20, 2017, 8:55 PM
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
//void play(Player,int &,Board);
void Menu();
void prcsOpt(int,Player,Property);
void automat(Player,int &,Property);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Instantiate Players
    Player user, comp;
    Property prop;
    
    Names counter;
    int choice;
    int current=0,compcur=0;
    bool again=true;
    
    //Begin to see who goes first
    char first;
    first=opening();
    if(first=='c') automat(comp,compcur,prop);
    cout<<"----------------------------------------"<<endl;
    
    //Begin Playing
    do{
//        play(user,current,spot);
        current+=dieRoll();    //Write "restart to GO" procedure
        prop.setup(current);
        cout<<"You landed on "<<prop.getname()<<" which is worth $";
        cout<<prop.getprce()<<endl;;
        Menu();
        cin>>choice;       //Overload the >> operator to display player info
        //Validate with try/catch
        prcsOpt(choice,user,prop);
        automat(comp,compcur,prop);
        cout<<"----------------------------------------"<<endl;
        //Keep Playing?
    }while(again==true);
    
    cout<<"Thank you for playing!!"<<endl;
    
    //Exit Stage Right!
    return 0;
}

void automat(Player c,int &last,Property prop){
    last+=dieRoll();
    prop.setup(last);
    int total=c.getMony()-prop.getprce();
    c.setMony(total);
    cout<<"Your opponent landed on "<<prop.getname();
    //Check to see if landed on any non-properties
    cout<<" and bought it for "<<prop.getprce()<<endl;
    cout<<"Opponent now has $"<<c.getMony()<<endl;
}

void prcsOpt(int decide,Player u,Property prop){
    //Process the Decision
    if(decide==1){
        cout<<"$"<<prop.getprce()<<" was deducted from your account."<<endl;
        int total=u.getMony()-prop.getprce();
        u.setMony(total);
        cout<<"Congratulations on your purchase!"<<endl;
    }
    else if(decide==2)    //This is where auction would occur
        cout<<"Thanks for the visit!"<<endl;
    else if(decide==3){   //Error-catching Function needs to be written
        cout<<"You can only purchase houses if you have obtained all the ";
        cout<<"properties in the "<<prop.getcolr()<<" color group!"<<endl;
    }
    else if(decide==4){   //Error-catching Function needs to be written
        cout<<"You can only purchase hotels if you have first purchased ";
        cout<<"4 houses!"<<endl;
    }
    cout<<endl;
}

void Menu(){
    cout<<"What would you like to do?"<<endl;
    cout<<"1. Purchase the Property."<<endl;
    cout<<"2. Just Visit the Property."<<endl;
    cout<<"3. Build a House."<<endl;
    cout<<"4. Build a Hotel."<<endl;
}

int dieRoll(){
    //Instantiate 2 Dice
    Die die1,die2;
    
    //Roll the dice
    die1.roll();
    die2.roll();
    
    return die1.getVal()+die2.getVal();
}

//void play(Player u,int &last,Board spot){  
//    last+=dieRoll();    //Write "restart to GO" procedure
//    spot.setup(last);
//    cout<<"You landed on "<<spot.getname()<<endl;
//}

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