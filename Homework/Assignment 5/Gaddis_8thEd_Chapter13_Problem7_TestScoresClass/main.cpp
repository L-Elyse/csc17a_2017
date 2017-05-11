/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 10, 2017, 2:19 PM
 * Purpose: Problem 7
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "TestScores.h"

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    TestScores object;
    float s1,s2,s3;
    
    cout<<"Please enter three test scores: ";
    cin>>s1>>s2>>s3;
    
    //Set & Get Test Scores
    object.setTest(s1,s2,s3);
    
    cout<<"The test scores you entered were: "<<endl;
    cout<<fixed<<setprecision(1)<<showpoint;
    cout<<"Test #1: "<<object.getTst1()<<endl;
    cout<<"Test #2: "<<object.getTst2()<<endl;
    cout<<"Test #3: "<<object.getTst3()<<endl;
    cout<<"The average of these is: ";
    cout<<object.average()<<endl<<endl;
    
    //Exit Stage Right!
    return 0;
}

