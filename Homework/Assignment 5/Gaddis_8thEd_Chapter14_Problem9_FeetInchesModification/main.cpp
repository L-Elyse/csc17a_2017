/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 9, 2017, 1:41 PM
 * Purpose: Problem 9
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "FeetInches.h"

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int feet, inches;
    
    FeetInches first,second;
    
    cout<<"Enter a distance in feet and inches: ";
    cin>>feet>>inches;
    
    //Store the distance in first
    first.setFeet(feet);
    first.setInch(inches);
    
    cout<<"Enter another distance in feet and inches: ";
    cin>>feet>>inches;
    
    //Store the distance in second
    second.setFeet(feet);
    second.setInch(inches);
    
    //Compare the two objects
    cout<<endl<<"Facts:"<<endl;
    if(first<=second)
        cout<<"first is less than or equal to second"<<endl;
    if(first>=second)
        cout<<"first is greater than or equal to second"<<endl;
    if(first!=second)
        cout<<"first does not equal second"<<endl;
    
    //Exit Stage Right!
    return 0;
}