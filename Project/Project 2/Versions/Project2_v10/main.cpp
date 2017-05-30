/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 28, 2017, 11:15 PM
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
#include "ChncCom.h"
#include "Die.h"
#include "Player.h"
#include "Property.h"

//Function Prototypes
char opening();
int dieRoll();
void play(Player &,Player &,Property &,short &,short &);
void Menu();
void prcsOpt(int,Player &,Property &);
void automat(Player &,Player &,Property &,short &,short &);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Instantiate Players, Property Object & Local Reference Variables
    Player user, comp;
    Property prop;
    short chance=1,comchst=1;
    bool again=true;  //Maybe make a char instead to use cctype!!
    
    //Begin to see who goes first
    char first;
    first=opening();
    if(first=='c') 
        automat(comp,user,prop,chance,comchst);
    cout<<"----------------------------------------"<<endl;
    
    //Begin Playing
    do{
        play(user,comp,prop,chance,comchst);
        automat(comp,user,prop,chance,comchst);
        cout<<"----------------------------------------"<<endl;
        cout<<"Would you like to continue playing the game?"<<endl;
        cin>>again;
    }while(again==true);
    
    cout<<"Thank you for playing!!"<<endl;
    
    //Exit Stage Right!
    return 0;
}

void automat(Player &c,Player &u,Property &prop,short &comindx,short &chnindx){
    ChncCom temp;
    Rules check;
    
    check.restart(dieRoll(),c);
    prop.inform(c.getSpot(),c.getNHse());
    int total=c.getMony()-prop.getprce();
    c.setMony(total);
    cout<<"Your opponent landed on "<<prop.getname();
    if(prop.getname()=="Chance"){
        temp.setMess(1,chnindx,c,u,check);
        cout<<endl<<temp.getMess()<<endl;
        chnindx++;
    }
    else if(prop.getname()=="Community Chest"){
        temp.setMess(2,comindx,c,u,check);
        cout<<endl<<temp.getMess()<<endl;
        comindx++;
    }
    else if(prop.getname()=="Go To Jail")
        check.cGoJail(c);
    if(c.getSpot()==30)
        check.cGoJail(c);
    else{
        cout<<" and bought it for "<<prop.getprce()<<endl;
        c.setPrps();
        cout<<"Opponent now has $"<<c.getMony()<<endl;
    }
}

void prcsOpt(int decide,Player &u,Property &prop){
    //Process the Menu Decision
    if(decide==1){
        cout<<"$"<<prop.getprce()<<" was deducted from your account."<<endl;
        int total=u.getMony()-prop.getprce();
        u.setMony(total);
        u.setPrps();
        cout<<"You now have $"<<u.getMony()<<endl;
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
    //In-Game Menu
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
    die2.roll();           //Don't forget about the doubles procedure!!
    
    cout<<"Die 1: "<<die1.getVal()<<"  Die 2: "<<die2.getVal()<<endl;
    
    return die1.getVal()+die2.getVal();
}

void play(Player &u,Player &c,Property &spot,short &comindx,short &chnindx){  
    //Declare Menu Choice Variable
    int choice;
    ChncCom temp;
    Rules check;
    
    check.restart(dieRoll(),u);
    spot.inform(u.getSpot(),u.getNHse());
    cout<<"You landed on "<<spot.getname()<<" which is worth $"
            <<spot.getprce()<<endl;
    
    //Check for Special "Properties"
    if(spot.getname()=="Chance"){
        temp.setMess(1,chnindx,u,c,check);
        cout<<endl<<temp.getMess()<<endl;
        chnindx++;
    }
    else if(spot.getname()=="Community Chest"){
        temp.setMess(2,comindx,u,c,check);
        cout<<endl<<temp.getMess()<<endl;
        comindx++;
    }
    else if(spot.getname()=="Go To Jail"){
        check.Go2Jail(u);
    }
    if(u.getSpot()==30)
        check.Go2Jail(u);
    else{
        Menu();
        cin>>choice;       //Overload the >> operator to display player info
        //Validate with try/catch
        prcsOpt(choice,u,spot);
    }
}

char opening(){
    //Declare Comparison Variables
    int comp,user;
    
    cout<<"Hello! Welcome to the wonderful game of Monopoly!"<<endl;
    cout<<"Before we begin, do you need to read the instructions?"<<endl;
    //Create a boolean input where if the answer is affirmative, output the
    //instructions, which will be read in from a file & validate with t/c
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