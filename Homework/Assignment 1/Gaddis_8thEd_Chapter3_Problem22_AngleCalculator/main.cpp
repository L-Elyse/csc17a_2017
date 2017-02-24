/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on February 24, 2017, 12:30 AM
 * Purpose: Calculate Sine, Cosine, and Tangent of Angles
 */

//System Libraries
#include <iostream>   //Input/Output Stream Library
#include <iomanip>    //Formatting Library
#include <cmath>      //Math Library
using namespace std;  //Iostream uses the standard namespace

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    float angle;
    
    //Input data
    cout<<"I love math. You should too. Let's have some fun!"<<endl;
    cout<<"Enter an angle (in rads) and I will show you its Sine, Cosine";
    cout<<" and Tangent\n";
    cout<<"(For pi, please enter 3.14159)"<<endl;
    cin>>angle;
    
    //Process data
    
    //Output data
    cout<<fixed<<setprecision(4)<<showpoint<<endl;
    cout<<"Sine = "<<sin(angle)<<endl;
    cout<<"Cosine = "<<cos(angle)<<endl;
    cout<<"Tangent = "<<tan(angle)<<endl;
    
    //Exit Stage Right!
    return 0;
}