/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 4, 2017, 12:33 AM
 * Purpose: Create Function to Display Temperature Table
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void celsius(float);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float F;
    int times=21;
    
    //Call Function to Display Table 
    cout<<"I will call a function that will display temperatures 0 through 20 ";
    cout<<"in both Celsius and Fahrenheit."<<endl<<endl;
    cout<<"\tFahrenheit\t   Celsius"<<endl;
    cout<<"\t--------------------------"<<endl;
    for(int i=0;i<times;i++)
        celsius(i);
    
    //Exit Stage Right!
    return 0;
}

void celsius(float temp){
    //Declare Variables
    float C;
    
    //Process Data
    C=5/9.0*(temp-32);
    
    //Output Data
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"\t  "<<setw(6)<<temp<<"\t   "<<setw(6)<<C<<endl;
    
    //Return to Main
    return;
}