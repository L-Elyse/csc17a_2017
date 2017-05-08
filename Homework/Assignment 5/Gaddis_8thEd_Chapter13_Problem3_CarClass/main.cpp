/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 7, 2017, 10:34 PM
 * Purpose: Problem 3
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "Car.h"

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int y;
    string m;
    
    //Get Car's Model Year & Make
    cout<<"Please enter the car's year model: ";
    cin>>y;
    cin.ignore();
    cout<<"Enter the car's make: ";
    getline(cin,m);
    
    //Declare Class Object
    Car object(y,m);
    
    //Adjust and Output the Speed
    cout<<endl;
    cout<<object.getmake()<<" "<<object.getyear()<<endl;
    cout<<"Accelerating Now!"<<endl;
    for(int i=0;i<5;i++){
        object.accelerate();
        cout<<object.getspd()<<endl;
    }
    cout<<endl;
    cout<<"Decelerating Now!"<<endl;
    for(int i=0;i<5;i++){
        cout<<object.brake()<<endl;
    }

    //Exit Stage Right!
    return 0;
}