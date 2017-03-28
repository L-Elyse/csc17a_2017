/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 27, 2017, 10:27 PM
 * Purpose: Gather Weather Statistics
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "Weather.h"

//Global Constants

//Function Prototypes
void highest(weather,int);
void lowest(weather,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    const int SIZE=12;
    weather array[SIZE];
    float totalr=0,avrgr,avgtemp=0;
    
    //Input data
    cout<<"This program computes weather statistics for the year. \n";
    for(int i=0;i<SIZE;i++){
        cout<<"Please enter the following for Month: "<<i+1<<endl;
        cout<<"Total Rainfall: ";
        cin>>array[i].rain;
        cout<<"High Temperature: ";
        cin>>array[i].high;
        while((array[i].high)<-100||(array[i].high)>140){
            cout<<"Sorry. Only values between -100 and 140 degrees Fahrenheit ";
            cout<<"are allowed."<<endl;
            cin>>array[i].high;
        }
        cout<<"Low Temperature: ";
        cin>>array[i].low;
        while((array[i].low)<-100||(array[i].low)>140){
            cout<<"Sorry. Only values between -100 and 140 degrees Fahrenheit ";
            cout<<"are allowed."<<endl;
            cin>>array[i].low;
        }
        //Calculate Averages
        totalr+=array[i].rain;
        array[i].average=(array[i].high+array[i].low)/2;
        avgtemp+=array[i].average;
    }
    
    //Process data
    avrgr=totalr/12;
    avgtemp/=12;
    
    //Output data
    cout<<fixed<<setprecision(1)<<showpoint;
    cout<<"Here are the results: "<<endl;
    cout<<"Total Rainfall: "<<totalr<<endl;
    cout<<"Average Rainfall: "<<avgtemp<<endl;
    highest(array,SIZE);
    
    //Exit Stage Right!
    return 0;
}

void highest(weather a,int n){
    cout<<"Hello"<<endl;
}