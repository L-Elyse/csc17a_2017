/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 5, 2017, 1:05 AM
 * Purpose: Case Manipulator
 */

//System Libraries
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void upper(char *);
void lower(char *);
void reverse(char *);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    char *input;
    
    //Get the String from User
    cout<<"Enter a string and I will manipulate all the cases."<<endl;
    cin.getline(input,100);
    
    //Output the String Manipulated
    upper(input);
    lower(input);
    reverse(input);
    
    //Exit Stage Right!
    return 0;
}

void reverse(char *c){
    cout<<endl;
    cout<<"All Original Cases Switched: ";
    for(int i=0;i<strlen(c);i++){
        if(islower(*(c+i)))
            cout<<static_cast<char>(toupper(*(c+i)));
        else if(isupper(*(c+i)))
            cout<<static_cast<char>(tolower(*(c+i)));
        else
            cout<<*(c+i);
    }
}

void lower(char *c){
    cout<<endl;
    cout<<"All Lowercase:               ";
    for(int i=0;i<strlen(c);i++){
        cout<<static_cast<char>(tolower(*(c+i)));
    } 
}

void upper(char *c){
    cout<<endl;
    cout<<"All Uppercase:               ";
    for(int i=0;i<strlen(c);i++){
        cout<<static_cast<char>(toupper(*(c+i)));
    }
}