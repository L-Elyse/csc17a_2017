/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 28, 2017, 1:00 PM
 * Purpose: Movie Data with Profit or Loss
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "Movie Data.h"

//Global Constants

//Function Prototypes
void display(movie);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    movie movie1={"Whiplash","Damien Chazelle",2014,107,3300000,33000000};
    movie movie2={"The Help","Tate Taylor",2011,146,25000000,213000000};
    
    //Display Information on Movies
    display(movie1);
    cout<<endl;
    display(movie2);
    
    //Exit Stage Right!
    return 0;
}

void display(movie m){
    //Print  Movie Information to the Screen
    cout<<"Movie:            "<<m.title<<endl;
    cout<<"Director:         "<<m.direct<<endl;
    cout<<"Year Released:    "<<m.year<<endl;
    cout<<"Running Time:     "<<m.runtime<<" minutes"<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Production Cost:  $"<<setw(12)<<m.product<<endl;
    cout<<"Revenue:          $"<<setw(12)<<m.revenue<<endl;
}