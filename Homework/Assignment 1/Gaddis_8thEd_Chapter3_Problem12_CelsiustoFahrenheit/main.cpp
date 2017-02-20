/* 
 * File: main.cpp
 * Author: Laurie Guimont
 * Created: February 19, 2017, 8:24 PM
 * Purpose: Convert Celsius to Fahrenheit
 */

//System Libraries
#include <iostream> //Input/Output Stream Library
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float temp, F;
    
    //Input Data
    cout<<"Let's convert from Celsius to Fahrenheit!"<<endl;
    cout<<"Please enter a temperature and I will convert it for you."<<endl;
    cin>>temp;
    
    //Process Data
    F=(9/5.0*temp)+32;
    
    //Output Data
    cout<<"Celsius: "<<temp<<" -> Fahrenheit: "<<F<<endl;
    
    //Exit Stage Right!
    return 0;
}

