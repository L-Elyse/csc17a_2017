/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 4, 2017, 12:00 PM
 * Purpose: Password Verifier
 */

//System Libraries
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void verify(char *,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    char *passwrd;
    int length;
    
    //Input data
    cout<<"Enter any password of your choice. The password should contain ";
    cout<<"at least: "<<endl;
    cout<<"Six characters"<<endl;
    cout<<"One uppercase"<<endl;
    cout<<"One lowercase"<<endl;
    cout<<"One digit"<<endl;
    cin.getline(passwrd,50);
    
    //Process data
    length=strlen(passwrd);
    verify(passwrd,length);
    
    //Exit Stage Right!
    return 0;
}

void verify(char *c,int l){
    //Declare Variables
    int upper=0,lower=0,digit=0;
    //Test and Output Results
    cout<<endl;
    cout<<"Results: "<<endl;
    //Check Length
    if(l<6){
        cout<<"I'm sorry. Your password must be at least six characters. Your ";
        cout<<"password only contains "<<l<<" characters."<<endl;
    }
    else if(l>=6){
        //Search for Uppercase, Lowercase, and Digit
        for(int i=0;i<l;i++){
            if(isupper(*(c+i)))
                upper++;
            if(islower(*(c+i)))
                lower++;
            if(isdigit(*(c+i)))
                digit++;
        }
        if(upper>0&&lower>0&&digit>0)
            cout<<"The password is valid"<<endl;
        else{
            if(upper==0)
                cout<<"No uppercase."<<endl;
            if(lower==0)
                cout<<"No lowercase."<<endl;
            if(digit==0)
                cout<<"No digit."<<endl;
            cout<<"The password is invalid"<<endl;
        }
    }
}