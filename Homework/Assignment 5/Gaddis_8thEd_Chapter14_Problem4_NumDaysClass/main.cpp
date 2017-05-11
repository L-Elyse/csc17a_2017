/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 9, 2017, 1:33 PM
 * Purpose: Problem 4
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "NumDays.h"

//Execution Starts Here!
int main(int argc, char** argv) {
    //Instantiate Class Objects
    NumDays first(40);
    NumDays second(28);
    
    //First's Hours & Number of Days
    cout<<"First:"<<endl;
    cout<<"Number of Hours: "<<first.getHrs()<<endl;
    cout<<"Number of Days:  "<<first.getDays()<<endl;
    
    //Second's Hours & Number of Days
    cout<<"Second: "<<endl;
    cout<<"Number of Hours: "<<second.getHrs()<<endl;
    cout<<"Number of Days:  "<<second.getDays()<<endl;
    
    //Instantiate Class Object
    NumDays third(0);
    
    //Demonstrating Operator Overload
    cout<<"Testing Operator Overloading Now:"<<endl;
    third=first+second;
    cout<<"First + Second = "<<third.getDays()<<endl;
    third=first-second;
    cout<<"First - Second = "<<third.getDays()<<endl; 
    cout<<"Testing first++:    "<<first++<<endl;
    cout<<"First's hours now:  "<<first.getHrs()<<endl;
    cout<<"Testing ++second:   "<<++second<<endl;
    cout<<"Second's hours now: "<<second.getHrs()<<endl;
    cout<<"Testing first--:    "<<first--<<endl;
    cout<<"First's hours now:  "<<first.getHrs()<<endl;
    cout<<"Testing --second:   "<<--second<<endl;
    cout<<"Second's hours now: "<<second.getHrs()<<endl;    
    
    //Exit Stage Right!
    return 0;
}