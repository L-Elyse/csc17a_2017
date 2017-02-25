/* 
 * File: main.cpp
 * Author: Laurie Guimont
 * Created: February 24, 2017, 8:30 PM
 * Purpose: Days in a Month
 */

//System Libraries
#include <iostream>  //Input/Output Stream Library
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    unsigned int month, year;
    
    //Input Data
    cout<<"Enter a month (1-12): ";
    cin>>month;
    cout<<"Enter a year: ";
    cin>>year;
    cout<<endl;
    
    //Process & Output Data
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: 
            cout<<"31 days"<<endl;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout<<"30 days"<<endl;
            break;
        case 2:
            if(year%100==0){
                if(year%400==0)
                    cout<<"29 days"<<endl;
            }else if(year%4==0)
                cout<<"29 days"<<endl;
            else
                cout<<"28 days"<<endl;
            break;
        default:
            cout<<"Not a valid entry. Sorry"<<endl;        
    }
    
    //Exit Stage Right!
    return 0;
}

