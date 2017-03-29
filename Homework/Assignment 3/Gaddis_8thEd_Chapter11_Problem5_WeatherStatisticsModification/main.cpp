/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 28, 2017, 12:45 AM
 * Purpose: Gather Weather Statistics Modification
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "Weather.h"

//Global Constants
enum Months {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST,
                 SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

//Function Prototypes
void display(Months);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    const int SIZE=12;
    weather array[SIZE];
    float totalr=0,avrgr,avgtemp=0;
    
    //Input data
    cout<<"This program computes weather statistics for the year. \n";
    for(Months i=JANUARY;i<SIZE;i=static_cast<Months>(i+1)){
        cout<<"Please enter the following for ";
        display(i);
        cout<<": "<<endl;
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
    cout<<endl;
    cout<<"Here are the results: "<<endl;
    cout<<fixed<<setprecision(1)<<showpoint;
    cout<<"Average Temperature: "<<avgtemp<<endl;
    cout<<"Total Rainfall: "<<totalr<<endl;
    cout<<"Average Rainfall: "<<avrgr<<endl;
    
    //Exit Stage Right!
    return 0;
}

void display(Months m){
    switch(m){
        case JANUARY: cout<<"January"; break;
        case FEBRUARY: cout<<"February";break;
        case MARCH: cout<<"March";break;
        case APRIL: cout<<"April";break;
        case MAY: cout<<"May";break;
        case JUNE: cout<<"June";break;
        case JULY: cout<<"July";break;
        case AUGUST: cout<<"August";break;
        case SEPTEMBER: cout<<"September";break;
        case OCTOBER: cout<<"October";break;
        case NOVEMBER: cout<<"November";break;
        case DECEMBER: cout<<"December";break;
    }
}