/* 
 * File: main.cpp
 * Author: Laurie Guimont
 * Created: February 19, 2017, 11:16 PM
 * Purpose: Convert Currency
 */

//System Libraries
#include <iostream> //Input/Output Stream Library
#include <iomanip>  //Formatting Library
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float dollar, yconv, econv;
    float yen=98.93;
    float euro=.74;
    
    //Input Data
    cout<<"Let's do some currency conversions"<<endl;
    cout<<"Enter the USD amount and I will convert it"<<endl;
    cin>>dollar;
    
    //Process Data
    yconv=dollar*yen;
    econv=dollar*euro;
    
    //Output Data
    cout<<fixed<<setprecision(2)<<showpoint<<endl;
    cout<<dollar<<" Dollar(s) = "<<setw(2)<<yconv<<" Yen"<<endl;
    cout<<dollar<<" Dollar(s) = "<<setw(2)<<econv<<" Euros"<<endl;
    
    //Exit Stage Right!
    return 0;
}

