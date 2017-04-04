/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 4, 2017, 2:20 PM
 * Purpose: Name Arranger
 */

//System Libraries
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void arrange(char []);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    int size=100;
    char name[size];
    
    //Get the String from User
    cout<<"Enter your first, middle, and last name."<<endl;
    cin.getline(name,size);
    
    //Output the String Length
    cout<<endl;
    cout<<"Here is your name rearranged: "<<arrange(name)<<endl;
    
    //Exit Stage Right!
    return 0;
}

void arrange(char c[]){
    
}