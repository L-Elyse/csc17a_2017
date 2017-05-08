/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 7, 2017, 2:30 PM
 * Purpose: Date Program
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "Date.h"

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    Date date;
    int m,d,y;
    
    //Input Data
    cout<<"Please enter a month, day, and year."<<endl;
    cin>>m>>d>>y;
    
    //Process Data
    date.setmnth(m);
    date.setday(d);
    date.setyear(y);
    
    //Output Date in 3 Formats
    cout<<"Here is what you entered: "<<endl;
    cout<<date.getmnth()<<"/"<<date.getday()<<"/"<<date.getyear()<<endl;
    cout<<date.mname()<<" "<<date.getday()<<", "<<date.getyear()<<endl;
    cout<<date.getday()<<" "<<date.mname()<<" "<<date.getyear()<<endl;
    
    //Exit Stage Right!
    return 0;
}