/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on February 25, 2017, 1:20 AM
 * Purpose: Calculate Amount of Mobile Service Minutes Used
 */

//System Libraries
#include <iostream>  //Input/Output Stream Library
using namespace std; //Iostream uses the standard namespace

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables, no doubles
    char package;
    float minutes,extra;
    float A=39.99, B=59.99, C=69.99;
    
    //Input Data
    cout<<"This program calculates a monthly mobile phone bill."<<endl;
    cout<<"There are three different packages: "<<endl;
    cout<<"Package A: $39.99 per month for 450 minutes. Additional minutes ";
    cout<<"are $0.45 per minute.\n";
    cout<<"Package B: $59.99 per month for 900 minutes. Additional minutes ";
    cout<<"are $0.40 per minute.\n";
    cout<<"Package C: $69.99 per month unlimited\n";
    cout<<"Please enter your package (A, B, or C): ";
    cin>>package;
    cout<<"Now enter the total minutes used this month: ";
    cin>>minutes;
    cout<<endl;
    
    //Process and Output Data
    switch(package){
        case 'a':
        case 'A':
            if(minutes>450){
                extra=minutes-450;
                minutes=A+extra*.45;
                cout<<"Package Price: $"<<A<<endl;
                cout<<"Extra Minutes Used: "<<extra<<endl;
                cout<<"Total Monthly Bill: $"<<minutes<<endl;
            }else
                cout<<"Total Monthly Bill: $"<<A<<endl;
            break;
        case 'b':
        case 'B':
            if(minutes>900){
                extra=minutes-900;
                minutes=B+extra*.40;
                cout<<"Package Price: $"<<B<<endl;
                cout<<"Extra Minutes Used: "<<extra<<endl;
                cout<<"Total Monthly Bill: $"<<minutes<<endl;
            }else
                cout<<"Total Monthly Bill: $"<<B<<endl;
            break;
        case 'c':
        case 'C':
            cout<<"Total Monthly Bill: $"<<C<<endl;
            break;
        default:
            cout<<"Sorry. That is not a valid entry.";
    }
    
    //Exit Stage Right!
    return 0;
}