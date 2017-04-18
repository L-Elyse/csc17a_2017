/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 7, 2017, 6:15 PM
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
#include "Card.h"
#include "Opponent.h"

//Global Constants--ONLY for 2D Array

//Function Prototypes
string intro(oppnent);
unsigned short facdDwn(unsigned short &);
unsigned int menu();

//Execution Begins Here!
int main(int argc, char** argv){
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned short warcnt;
    oppnent comp;
    
        
    //Get Name of Opponent & Establish Number of "Faced Down" Cards
    intro(comp);
    facdDwn(warcnt);    
    
    //Exit Stage Right
    return 0;
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