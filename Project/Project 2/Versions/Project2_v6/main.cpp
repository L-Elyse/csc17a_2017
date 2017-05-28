/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 27, 2017, 3:45 PM
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
void play(Player,Player,int &,Property,string &,int &);
void Menu();
void prcsOpt(int,Player,Property,int &);
void automat(Player,Player,int &,Property,int &);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Instantiate Players, Property Object & Local Reference Variables
    Player user, comp;
    Property prop;
    int current=0,compcur=0;
    int userMon=user.getMony(),compMon=comp.getMony();
    string land;
    bool again=true;  //Maybe make a char instead to use cctype!!
    
    //Begin to see who goes first
    char first;
    first=opening();
    if(first=='c') automat(comp,user,compcur,prop,compMon);
    cout<<"----------------------------------------"<<endl;
    
    //Begin Playing
    do{
        play(user,comp,current,prop,land,userMon);
        automat(comp,user,compcur,prop,compMon);
        cout<<"----------------------------------------"<<endl;
        cout<<"Would you like to continue playing the game?"<<endl;
        cin>>again;
    }while(again==true);
    
    cout<<"Thank you for playing!!"<<endl;
    
    //Exit Stage Right!
    return 0;
}

void automat(Player c,Player u,int &last,Property prop,int &mon){
    ChncCom temp;
    
    last+=dieRoll();
    prop.inform(last,c.getNHse());
    int total=mon-prop.getprce();
    c.setMony(total);
    mon=c.getMony();
    cout<<"Your opponent landed on "<<prop.getname();
//    if(prop.getname()=="Chance")
//        temp.setMess(1,c,u);
//    else if(prop.getname()=="Community Chest")
//        temp.setMess(2,c,u);
    cout<<" and bought it for "<<prop.getprce()<<endl;
    cout<<"Opponent now has $"<<mon<<endl;
}

void prcsOpt(int decide,Player u,Property prop,int &mon){
    //Process the Menu Decision
    if(decide==1){
        cout<<"$"<<prop.getprce()<<" was deducted from your account."<<endl;
        int total=mon-prop.getprce();
        u.setMony(total);
        mon=u.getMony();
        cout<<"You now have $"<<mon<<endl;
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
    die2.roll();           //Need to show dice!!
    
    return die1.getVal()+die2.getVal();
}

void play(Player u,Player c,int &last,Property spot,string &land,int &money){  
    //Declare Menu Choice Variable
    int choice;
    ChncCom temp;
    
    last+=dieRoll();    //Write "restart to GO" procedure
    spot.inform(last,u.getNHse());
    land=spot.getname();
    cout<<"You landed on "<<land<<" which is worth $"<<spot.getprce()<<endl;
    
    //Check for Chance or Community Chest Card
//    if(land=="Chance")
//        temp.setMess(1,u,c);
//    else if(land=="Community Chest")
//        temp.setMess(2,u,c);
    Menu();
    cin>>choice;       //Overload the >> operator to display player info
    //Validate with try/catch
    prcsOpt(choice,u,spot,money);
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