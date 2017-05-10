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
    
    //Copy the first object to the second
    second=first;
    
    //Multiply the two objects together
    first.multiply(second);
    cout<<endl;
    cout<<"After multiplying the distance by itself: "<<endl;
    cout<<first.getFeet()<<"ft. "<<first.getInch()<<"in."<<endl;
    
    //Exit Stage Right!
    return 0;
}