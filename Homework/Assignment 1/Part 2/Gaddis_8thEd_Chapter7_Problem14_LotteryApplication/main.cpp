/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 5, 2017, 7:31 PM
 * Purpose: Lottery Simulation using Parallel Arrays
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function Prototypes
void random(int [],int);
void guess(int [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    const int SIZE=5;
    int winning[SIZE];
    int user[SIZE];
    bool match=true;
    
    //Input data
    cout<<"Do you like to play the lottery? Think you can win?"<<endl;
    cout<<"Enter five numbers separated by spaces."<<endl;
    guess(user,SIZE);
    
    //Display Winning Numbers
    cout<<endl;
    cout<<"The winning numbers are:"<<endl;
    cout<<"------------------------"<<endl;
    random(winning,SIZE);
    cout<<endl<<endl;
    
    //Determine Win or Loss
    for(int j=0;j<SIZE;j++){
        if(user[j]==winning[j])
            match;
        else match=false;
    }
    if(match)
        cout<<"YOU WON!!!!! Congratulations!"<<endl;
    else
        cout<<"Sorry. You lost. Maybe you'll win next time!"<<endl;
    
    //Exit Stage Right!
    return 0;
}

void guess(int user[],int size){
   //Accept User Input
    for(int i=0;i<size;i++){
        cin>>user[i];
    }
    
    //Return to Main
    return;
}

void random(int winning[],int size){
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int MIN=0, MAX=9;
    
    //Generate & Display Array
    for(int i=0;i<size;i++){
        winning[i]=(rand()%(MAX-MIN+1))+MIN;
        cout<<winning[i]<<" ";
    }
       
    //Return to Main
    return;
}