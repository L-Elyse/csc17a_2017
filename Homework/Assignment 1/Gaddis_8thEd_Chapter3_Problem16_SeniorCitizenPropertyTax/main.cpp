/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on February 26, 2017, 1:10 AM
 * Purpose: Calculate Senior Citizen Property Tax
 */

//System Libraries
#include <iostream>   //Input/Output Stream Library
#include <iomanip>    //Formatting Library
using namespace std;  //Iostream uses the standard namespace

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    float actual,assess1,assess2,taxrate,quarter,proptax;
    float exempt=5000.00;
    
    //Input data
    cout<<"This program assess the amount of property tax a senior citizen ";
    cout<<"will be charged for a property"<<endl;
    cout<<"Please enter the actual value of the property: ";
    cin>>actual;
    cout<<"Now please enter the current tax rate for each $100 of assessed ";
    cout<<"value: ";
    cin>>taxrate;
    
    //Process data
    assess1=actual*.60;
    assess2=assess1-exempt;
    proptax=assess2/100*taxrate;
    quarter=proptax/4;    
        
    //Output data
    cout<<fixed<<setprecision(2)<<showpoint<<endl;
    cout<<"Actual Value:                       $"<<setw(10)<<actual<<endl;
    cout<<"Assessed Value (before exemptions): $"<<setw(10)<<assess1<<endl;
    cout<<"Exemption Amount:                   $"<<setw(10)<<exempt<<endl;
    cout<<"Assessed Value (after exemptions):  $"<<setw(10)<<assess2<<endl;
    cout<<"Property Tax:                       $"<<setw(10)<<proptax<<endl;
    cout<<"Quarterly Tax Bill:                 $"<<setw(10)<<quarter<<endl;
    
    //Exit Stage Right!
    return 0;
}