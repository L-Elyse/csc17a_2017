/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 10, 2017, 4:00 PM
 * Purpose: War Card Game
 */

//System Libraries
#include <iostream> //Input/Output Stream Library
#include <iomanip>  //Formatting Library
#include <ctime>    //Unique Seed Value Library
#include <cstdlib>  //Random Value Library
#include <string>   //String Library
#include <fstream>  //File I/O
#include <cmath>    //Math Library
#include <cctype>
#include <cstring>  
using namespace std;

//User Libraries
#include "Player.h"

//Global Constants--ONLY for 2D Array

//Function Prototypes
string intro();
unsigned short facdDwn(unsigned short &);
unsigned int menu(unsigned int &);
char pckCard(unsigned int &);

//Execution Begins Here!
int main(int argc, char** argv){
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned short warcnt;
    unsigned int choice;
    player comp,user;
        
    //Get Name of Opponent & Establish Number of "Faced Down" Cards
    comp.name=intro();
    facdDwn(warcnt);
    
    do{
        menu(choice);
        if(choice!=3){
            user.card=pckCard(choice);            
        }    
    }while(choice!=3);
    
    //Exit Stage Right
    return 0;
}

char pckCard(unsigned int &choice){
    //Declare Variable
    char card;
    
    if(choice==1){
        cout<<"Please enter the number of your choice(2-9)"<<endl;
        cin>>card;
        //Validate
        while(card<'2'||card>'9'){
            cout<<"Invalid entry! Please enter (2-9)"<<endl;
            cin>>card;
        }
    }    
    else if(choice==2){
        cout<<"Please enter T, J, Q, K, or A"<<endl;
        cin>>card;
        //Validate
        while(toupper(card)!='A'&&toupper(card)!='K'&&toupper(card)!='Q'&&
                toupper(card)!='J'&&toupper(card)!='T'){
            cout<<"Invalid entry! Please enter one of the choices above"<<endl;
            cin>>card;
        }
    }
    return card;
}

unsigned int menu(unsigned int &option){    
    cout<<endl;
    cout<<"What type of card would you like to play?"<<endl;
    cout<<"1. Number Card"<<endl;
    cout<<"2. Face Card"<<endl;
    cout<<"3. End Game"<<endl<<endl;
    cin>>option;
    
    return option;
}

unsigned short facdDwn(unsigned short &number){
    cout<<endl;
    cout<<"When war is waged, How many cards do you want to put down before ";
    cout<<"the war card is flipped?"<<endl;
    cout<<"(Please pick a number from 2-4)"<<endl;
    cin>>number;
    
    //Validation
    while(number<2||number>4){
        cout<<"Error. Please enter 2, 3 or 4"<<endl;
        cin>>number;
    }
    return number;
}

string intro(){
    //Declare Variables
    string c;
    cout<<"The name of the game? WAR!"<<endl;
    cout<<"First give your opponent a name. You didn't think you were playing ";
    cout<<"against the computer did you?"<<endl; 
    getline(cin,c);
    return c;
}