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
    float angle,numratr,denom;
    unsigned int choice;
    
    //Input data
    cout<<"I love math. You should too. Let's have some fun!"<<endl;
    cout<<"If you enter an angle (in rads), I will show you its Sine, Cosine ";
    cout<<"and Tangent\n";
    cout<<"First, please choose what type of number you would like to input\n";
    cout<<"Type '1' to input a whole number or decimal"<<endl;
    cout<<"Type '2' to input a fraction"<<endl;
    cin>>choice;
    
    //Process data
    if(choice==1){
        cout<<"What number would you like information on?"<<endl;
        cin>>angle;
    }else if (choice==2){
        cout<<"What is the numerator?\n";
        cin>>numratr;
        cout<<"What is the denominator?\n";
        cin>>denom;
        angle=numratr/denom;
    }else{
        cout<<"Clearly you're not serious about this. Bye."<<endl;
        return 0; //THIS IS AN ISSUE!!!
    }
        
    //Output data
    cout<<fixed<<setprecision(4)<<showpoint<<endl;
    cout<<"Sine = "<<sin(angle)<<endl;
    cout<<"Cosine = "<<cos(angle)<<endl;
    cout<<"Tangent = "<<tan(angle)<<endl;
    
    //Exit Stage Right!
    return 0;
}