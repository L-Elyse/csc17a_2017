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
void check(Player &,Player &,Property &,short &,short &);
void Menu(Property &);
void prcsOpt(int,Player &,Property &);
void automat(Player &,Player &,Property &,short &,short &);
void autochk(Player &,Player &,Property &,short &,short &);

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

void autochk(Player &c,Player &u,Property &prop,short &comindx,short &chnindx){
    ChncCom temp;
    Rules check;
    
    if(prop.getname()=="Chance"){
        temp.setMess(1,chnindx,c,u,check);
        cout<<endl<<temp.getMess()<<endl;
        chnindx++;
        if(c.getSpot()==30)
            check.cGoJail(c);
    }
    else if(prop.getname()=="Community Chest"){
        temp.setMess(2,comindx,c,u,check);
        cout<<endl<<temp.getMess()<<endl;
        comindx++;
    }
    else if(prop.getname()=="Go To Jail")
        check.cGoJail(c);
    else{
        if(u.findPrp(c.getSpot())==true){
            c.payRent(prop.getrent());
            cout<<endl;
            cout<<"You already own "<<prop.getname()<<". Your opponent pays ";
            cout<<"you $"<<prop.getrent()<<" of rent."<<endl;
            u.setMony(u.getMony()+prop.getrent());
        }
        else if(c.findPrp(c.getSpot())==true)
            cout<<"They already own this property."<<endl;
        else{
            int total=c.getMony()-prop.getprce();
            c.setMony(total);
            cout<<" and bought it for "<<prop.getprce()<<endl;
            c.setPrps();
            cout<<"Opponent now has $"<<c.getMony()<<endl;
        }
    }
}

void automat(Player &c,Player &u,Property &prop,short &comindx,short &chnindx){    
    Rules check;
    
    check.restart(dieRoll(),c);
    prop.inform(c.getSpot(),c.getNHse());
    cout<<"Your opponent landed on "<<prop.getname();
    
    autochk(c,u,prop,comindx,chnindx);
}

void prcsOpt(int decide,Player &u,Property &prop){
    bool endturn=true;
    
    //Process the Menu Decision
    if(decide==1){
        cout<<"$"<<prop.getprce()<<" was deducted from your account."<<endl;
        int total=u.getMony()-prop.getprce();
        u.setMony(total);
        u.setPrps();
        cout<<"You now have $"<<u.getMony()<<endl;
        cout<<"Congratulations on your purchase!"<<endl;
    }
    else if(decide==2)
        cout<<"Thanks for the visit!"<<endl;
    else if(decide==3){
        u.setNHse();
    }
    else if(decide==4){
        u.setNHtl(prop);
    }
    cout<<endl;
    
    cout<<"Would you like to end turn? ";
    cin>>endturn;
    if(endturn==false)
        Menu();
}

void Menu(Property &prop){
    //In-Game Menu
    cout<<"What would you like to do?"<<endl;
    cout<<"1. Purchase "<<prop.getname()<<" for $"<<prop.getprce()"."<<endl;
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

void check(Player &u,Player &c,Property &spot,short &comindx,short &chnindx){
    Rules check;
    ChncCom temp;
    int choice;
    
    //Check for Special "Properties"
    if(spot.getname()=="Chance"){
        temp.setMess(1,chnindx,u,c,check);
        cout<<endl<<temp.getMess()<<endl;
        chnindx++;  
        if(u.getSpot()==30)
            check.Go2Jail(u);
    }
    else if(spot.getname()=="Community Chest"){
        temp.setMess(2,comindx,u,c,check);
        cout<<endl<<temp.getMess()<<endl;
        comindx++;
    }
    else if(spot.getname()=="Go To Jail"){
        check.Go2Jail(u);
    }
    else{
        if(c.findPrp(u.getSpot())==true){
            u.payRent(spot.getrent());
            cout<<endl;
            cout<<"Your opponent already owns "<<spot.getname()<<". You owe ";
            cout<<"them $"<<spot.getrent()<<" of rent."<<endl;
            c.setMony(c.getMony()+spot.getrent());
        }
        else if(u.findPrp(u.getSpot()==true))
            cout<<"You already own this property."<<endl;
        else{
            Menu();
            cin>>choice;       //Overload the >> operator to display player info
            //Validate with try/catch
            prcsOpt(choice,u,spot);
        }
    }
}

void play(Player &u,Player &c,Property &spot,short &comindx,short &chnindx){  
    //Declare Menu Choice Variable
    Rules test;
    
    test.restart(dieRoll(),u);
    spot.inform(u.getSpot(),u.getNHse());
    cout<<"You landed on "<<spot.getname();
    
    //Check for Special "Properties"
    check(u,c,spot,comindx,chnindx);
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