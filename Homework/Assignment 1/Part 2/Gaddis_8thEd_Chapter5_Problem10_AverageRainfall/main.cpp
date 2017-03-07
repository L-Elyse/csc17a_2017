/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 3, 2017, 11:50 PM
 * Purpose: Calculate Average Rainfall
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int months=12,years;
    float rain,average,sum=0;
    
    //Input data
    cout<<"This program is designed to calculate the average rainfall over ";
    cout<<"a given period of time."<<endl;
    cout<<"Please enter the number of years you would like to calculate. \n";
    cin>>years;
    //Input Validation
    while(years<1){
        cout<<"Sorry. No numbers less than 1. Please try again."<<endl;
        cin>>years;
    }
    
    //Process data
    for(int i=0;i<years;i++){
        cout<<"For Year "<<i+1<<": "<<endl;
        cout<<"----------"<<endl;
        for(int i=0;i<months;i++){
            cout<<"How many inches of rainfall in month #"<<i+1<<"? ";
            cin>>rain;
            //Input Validation
            while(rain<0){
                cout<<"Sorry. You cannot have a negative number represent the ";
                cout<<"amount of rainfall in any month. Please try again.\n";
                cin>>rain;
            }
            sum+=rain;
        }
    }
    average=sum/(years*12);
        
    //Output data
    cout<<fixed<<setprecision(1)<<showpoint;
    cout<<endl;
    cout<<"Average Rainfall over "<<years<<" year(s) is "<<average<<" inches\n";
    
    //Exit Stage Right!
    return 0;
}