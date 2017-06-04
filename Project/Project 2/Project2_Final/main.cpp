/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on June 2, 2017, 12:15 AM
 * Purpose: Monopoly Game
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

//User Libraries
#include "ChncCom.h"
#include "Die.h"
#include "Player.h"
#include "Property.h"
#include "Railroad.h"
#include "Rules.h"

//Function Prototypes
char opening(Player &,Player &);
void rdInstr();
int dieRoll();
void play(Player &,Player &,Property &,short &,short &);
void check(Player &,Player &,Property &,short &,short &);
void Menu(Property &,Player &);
void prcsOpt(int,Player &,Property &);
void automat(Player &,Player &,Property &,short &,short &);
void autochk(Player &,Player &,Property &,short &,short &);
int validte(int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Instantiate Players, Property & Rules Object, & Local Reference Variables
    Player user, comp;
    Property prop;
    Rules check;
    short chance=1,comchst=1;       //Chance/Community Chest card index
    char again;                     //Continue Play option
    
    //Begin to see who goes first
    char first;
    first=opening(user,comp);
    if(first=='c') 
        automat(comp,user,prop,comchst,chance);        //Comp's Turn
    cout<<"----------------------------------------"<<endl;
    
    //Begin Playing
    do{
        play(user,comp,prop,comchst,chance);            //Player's Turn
        automat(comp,user,prop,comchst,chance);         //Comp's Turn
        cout<<"----------------------------------------"<<endl;
        cout<<"Would you like to continue playing the game? (Y/N)"<<endl;
        cin>>again;
        cout<<"----------------------------------------"<<endl;
    }while(toupper(again)=='Y'&&check.gameEnd(user)==false&&
            check.gameEnd(comp)==false);
    
    cout<<"Thank you for playing!!"<<endl;
    
    //Exit Stage Right!
    return 0;
}

void autochk(Player &c,Player &u,Property &prop,short &comindx,short &chnindx){
    ChncCom temp;
    Rules check;
    Railroad RR;
    
    if(prop.getname()=="Chance"){
        temp.setMess(1,chnindx,c,u,check);
        cout<<temp.getMess()<<endl;
        chnindx++;
        check.indxset(chnindx);
        if(c.getSpot()==30)
            check.cGoJail(c);
    }
    else if(prop.getname()=="Community Chest"){
        temp.setMess(2,comindx,c,u,check);
        cout<<temp.getMess()<<endl;
        comindx++;
        check.indxset(comindx);
        if(c.getSpot()==30)
            check.Go2Jail(c);
    }
    else if(prop.getname()=="Go To Jail")
        check.cGoJail(c); 
    else if(prop.getcolr()=="")
        cout<<"Just Visiting!!"<<endl;
    else if(prop.getcolr()=="tax"){
        c.setMony(c.getMony()-prop.getprce());
        cout<<c.getName()<<" just paid "<<prop.getname()<<" of $";
        cout<<prop.getprce()<<endl;
    }
    else{
        if(u.findPrp(c.getSpot())==true){
            if(prop.getcolr()=="RR"){
                c.payRent(RR.setrent(u,c.getSpot()));
                cout<<"You already own "<<prop.getPos(c.getSpot());
                cout<<" which is the "<<RR.getPos(c.getSpot())<<" railroad. ";
                cout<<c.getName()<<" pays you $"<<RR.setrent(u,c.getSpot());
                cout<<" of rent."<<endl;
                u.setMony(u.getMony()+RR.setrent(u,c.getSpot()));
            }
            else if(prop.getcolr()=="Utility"){
                int number;
                int total=dieRoll();
                if(u.findPrp(WATERWK)^u.findPrp(ELECTRC)==true)
                    number=1;
                else number=2;
                prop.utilRnt(number,total);
                c.payRent(prop.getrent());
                cout<<c.getName()<<"'s new roll is "<<total<<endl;
                cout<<"You already own "<<prop.getname()<<". "<<c.getName();
                cout<<" pays you $"<<prop.getrent()<<" of rent."<<endl;
                u.setMony(u.getMony()+prop.getrent());
            }
            else{
                c.payRent(prop.getrent());
                cout<<"You already own "<<prop.getname()<<". "<<c.getName();
                cout<<" pays you $"<<prop.getrent()<<" of rent."<<endl;
                u.setMony(u.getMony()+prop.getrent());
            }
        }
        else if(c.findPrp(c.getSpot())==true)
            cout<<c.getName()<<" already owns this property."<<endl;
        else{
            int total=c.getMony()-prop.getprce();
            c.setMony(total);
            cout<<"and bought it for $"<<prop.getprce()<<endl;
            c.setPrps();
        }
    }
    cout<<c;
}

void automat(Player &c,Player &u,Property &prop,short &comindx,short &chnindx){    
    Rules check;
    
    check.restart(dieRoll(),c);
    prop.inform(c.getSpot(),u.getNHse());
    cout<<"Your opponent landed on "<<prop.getname()<<endl;
    
    autochk(c,u,prop,comindx,chnindx);
}

void prcsOpt(int decide,Player &u,Property &prop){
    char endturn;
    
    //Process the Menu Decision
    if(decide==1){
        if(u.findPrp(u.getSpot())==true)
            cout<<"You already own this property "<<u.getName()<<endl;
        else{
            cout<<"$"<<prop.getprce()<<" was deducted from your account."<<endl;
            int total=u.getMony()-prop.getprce();
            u.setMony(total);
            u.setPrps();
            cout<<"Congratulations on your purchase!"<<endl;
        }
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
    
    cout<<"Would you like to end turn? (Y/N) ";
    cin>>endturn;
    if(toupper(endturn)=='N')
        Menu(prop,u);
}

int validte(int option){
    cin>>option;          
    if(option<1||option>4){
        string except = "ERROR: That is not a valid entry!\n";
        throw except;
    }
    else
        return option;
}

void Menu(Property &prop,Player &u){
    int choice;
    
    //In-Game Menu
    cout<<"What would you like to do?"<<endl;
    cout<<"1. Purchase "<<prop.getname()<<" for $"<<prop.getprce()<<"."<<endl;
    cout<<"2. Just Visit the Property."<<endl;
    cout<<"3. Build a House."<<endl;
    cout<<"4. Build a Hotel."<<endl;
    
    try{
        choice=validte(choice);
        prcsOpt(choice,u,prop);
    }
    catch(string except){
        cout<<except;
        cout<<"Please enter a valid Menu option. ";
        cin>>choice;
    }      
}

int dieRoll(){
    //Instantiate 2 Dice
    Die die1,die2;
    
    //Roll the dice        
    die1.roll();
    die2.roll(); 
    
    cout<<"Rolling..."<<endl;
    cout<<"Die 1: "<<die1.getVal()<<" Die 2: "<<die2.getVal()<<endl;
    
    return die1.getVal()+die2.getVal();
}
    
void check(Player &u,Player &c,Property &spot,short &comindx,short &chnindx){
    Rules check;
    ChncCom temp;
    Railroad RR;
    
    //Check for Special "Properties"
    if(spot.getname()=="Chance"){
        temp.setMess(1,chnindx,u,c,check);
        cout<<temp.getMess()<<endl;
        chnindx++;  
        check.indxset(chnindx);
        if(u.getSpot()==30)
            check.Go2Jail(u);
    }
    else if(spot.getname()=="Community Chest"){
        temp.setMess(2,comindx,u,c,check);
        cout<<temp.getMess()<<endl;
        comindx++;
        check.indxset(comindx);
        if(u.getSpot()==30)
            check.Go2Jail(u);
    }
    else if(spot.getname()=="Go To Jail"){
        check.Go2Jail(u);
    }
    else if(spot.getcolr()=="")
        cout<<"Just Visiting!!"<<endl;
    else if(spot.getcolr()=="tax"){
        u.setMony(u.getMony()-spot.getprce());
        cout<<"You just paid "<<spot.getname()<<" of $"<<spot.getprce()<<endl;
    }
    else{
        if(c.findPrp(u.getSpot())==true){
            if(spot.getcolr()=="RR"){
                u.payRent(RR.setrent(c,u.getSpot()));
                cout<<c.getName()<<" already owns "<<spot.getPos(u.getSpot());
                cout<<" which is the "<<RR.getPos(u.getSpot())<<" railroad. ";
                cout<<"You owe them $"<<RR.setrent(c,u.getSpot());
                cout<<" of rent."<<endl;
                c.setMony(c.getMony()+RR.setrent(c,u.getSpot()));
            }
            else if(spot.getcolr()=="Utility"){
                int number;
                int total=dieRoll();
                if(c.findPrp(WATERWK)^c.findPrp(ELECTRC)==true)
                    number=1;
                else number=2;
                spot.utilRnt(number,total);
                u.payRent(spot.getrent());
                cout<<c.getName()<<" already owns "<<spot.getname()<<". ";
                cout<<"You owe them $"<<spot.getrent()<<" of rent."<<endl;
                c.setMony(c.getMony()+spot.getrent());
            }
            else{
                u.payRent(spot.getrent());
                cout<<c.getName()<<" already owns "<<spot.getname()<<". ";
                cout<<"You owe them $"<<spot.getrent()<<" of rent."<<endl;
                c.setMony(c.getMony()+spot.getrent());
                
            }
        }
        else if(u.findPrp(u.getSpot())==true)
            cout<<"You already own this property "<<u.getName()<<endl;
        else{
            Menu(spot,u);
        }
    }
    cout<<u;
}

void play(Player &u,Player &c,Property &spot,short &comindx,short &chnindx){  
    //Declare Menu Choice Variable
    Rules test;
    
    test.restart(dieRoll(),u);
    spot.inform(u.getSpot(),c.getNHse());
    cout<<"You landed on "<<spot.getname()<<endl;
    
    //Check for Special "Properties"
    check(u,c,spot,comindx,chnindx);
}

void rdInstr(){
    fstream instrct;
    string lines;
    
    //Open the file
    instrct.open("Instructions.txt",ios::in);
    
    if(instrct){
        getline(instrct,lines);
        while(instrct){
            cout<<lines<<endl;          
            getline(instrct,lines);
        }
        cout<<endl;
        
        //Close the file
        instrct.close();
    }
    else
        cout<<"Error. Cannot open file"<<endl;
}

char opening(Player &u,Player &c){
    //Declare Comparison Variables
    int comp,user;
    char seeIns;
    
    //Get & Set Names
    cout<<"Hello! Welcome to the wonderful game of Monopoly!"<<endl;
    cout<<"Before we begin, please enter your name. ";
    u.setName();
    cout<<"And also enter the name of your opponent. ";
    c.setName();
    
    cout<<"Do you need to read the instructions? (Y/N)"<<endl;
    cin>>seeIns;
    if(toupper(seeIns)=='Y'){
        rdInstr();
        cout<<endl;
    }
    cout<<"We will begin the game by rolling the dice to see who gets to go ";
    cout<<"first!"<<endl<<endl;
    cout<<"Let's start with "<<c.getName()<<endl;
    
    do{
        comp=dieRoll();
        cout<<c.getName()<<" rolls "<<comp<<endl<<endl;
        cout<<"Now it's your turn "<<u.getName()<<endl;
        user=dieRoll();
        cout<<"You roll "<<user<<endl<<endl;

        //Compare to see who goes first
        if(user>comp){
            cout<<"You get to go first!"<<endl; 
            return 'u';
        }
        else if(user<comp){
            cout<<c.getName()<<" goes first."<<endl; 
            return 'c';
        }
        else cout<<"It's a Tie! Let's try this again."<<endl;
    }while(comp==user);
}