/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 10, 2017, 3:15 PM
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
#include "Opponent.h"

//Global Constants--ONLY for 2D Array

//Function Prototypes
string intro(oppnent);
unsigned short facdDwn(unsigned short &);
unsigned int menu();
int pckCard(char &);

//Execution Begins Here!
int main(int argc, char** argv){
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned short warcnt;
    oppnent comp;
    char cchoice;
        
    //Get Name of Opponent & Establish Number of "Faced Down" Cards
    intro(comp);
    facdDwn(warcnt);
    pckCard(cchoice);
    
    //Exit Stage Right
    return 0;
}

int pckCard(char &card){
    //Declare Variable
    unsigned int choice=menu();
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
        while(card!=isupper('a')&&card!=isupper('k')&&card!=isupper('q')&&
                card!=isupper('j')&&card!=isupper('t')){
            cout<<"Invalid entry! Please enter one of the choices above"<<endl;
            cin>>card;
        }
    }
    return card;
}

unsigned int menu(){
    //Declare Variable
    unsigned int choice;
    
    cout<<endl;
    cout<<"What type of card would you like to play?"<<endl;
    cout<<"1. Number Card"<<endl;
    cout<<"2. Face Card"<<endl;
    cout<<"3. End Game"<<endl<<endl;
    cin>>choice;
    
    return choice;
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

string intro(oppnent c){
    cout<<"The name of the game? WAR!"<<endl;
    cout<<"First give your opponent a name. You didn't think you were playing ";
    cout<<"against the computer did you?"<<endl; 
    getline(cin,c.name);
}