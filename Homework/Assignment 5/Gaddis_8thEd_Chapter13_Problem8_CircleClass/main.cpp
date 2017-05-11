/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 10, 2017, 7:35 PM
 * Purpose: Problem 8
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Circle.h"

//Execution Begins Here!
int main(int argc, char** argv) {
    //Instantiate Class Object
    float r;
    Circle circle;
    
    //Get Radius from User
    cout<<"Enter the radius of a circle: "<<endl;
    cin>>r;
    
    //Set Radius and Begin Getting Information
    circle.setRad(r);
    
    cout<<"Thank you. Here is some information that you can obtain:"<<endl;
    cout<<"Radius:        "<<circle.getRad()<<endl;
    cout<<"Diameter:      "<<circle.getDiam()<<endl;
    cout<<"Area:          "<<circle.getArea()<<endl;
    cout<<"Circumference: "<<circle.getCrcm()<<endl;
    
    //Exit Stage Right!
    return 0;
}

