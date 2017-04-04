/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 3, 2017, 8:30 PM
 * Purpose: String Length Calculation
 */

//System Libraries
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int length(char *);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    char *input;
    
    //Get the String from User
    cout<<"Enter a string and I will tell you how long it is"<<endl;
    cin.getline(input,100);
    
    //Output the String Length
    cout<<endl;
    cout<<"This string is "<<length(input)<<" characters long."<<endl;
    
    //Exit Stage Right!
    return 0;
}

int length(char *str){
    int length=strlen(str);
    return length;
}