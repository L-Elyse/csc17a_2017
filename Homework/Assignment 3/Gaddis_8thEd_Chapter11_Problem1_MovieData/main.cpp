/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 28, 2017, 12:40 PM
 * Purpose: Movie Data
 */

//System Libraries
#include <iostream>
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
    movie movie1={"Whiplash","Damien Chazelle",2014,107};
    movie movie2={"The Help","Tate Taylor",2011,146};
    
    //Display Information on Movies
    display(movie1);
    cout<<endl;
    display(movie2);
    
    //Exit Stage Right!
    return 0;
}

void display(movie m){
    //Print  Movie Information to the Screen
    cout<<"Movie:         "<<m.title<<endl;
    cout<<"Director:      "<<m.direct<<endl;
    cout<<"Year Released: "<<m.year<<endl;
    cout<<"Running Time:  "<<m.runtime<<" minutes"<<endl;
}