/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 8, 2017, 2:46 PM
 * Purpose: Problem 5
 */

#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "RetailItem.h"

//Function Prototypes
void prntPtr(RetailItem);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare & Initialize Class Variables
    string d="";
    int u=0;
    float p=0;
    RetailItem item1={d,u,p},item2={d,u,p},item3={d,u,p};
    
    //Set Item 1 Info
    item1.setdesc("Jacket\t");
    item1.setunit(12);
    item1.setprce(59.95);
    
    //Set Item 2 Info
    item2.setdesc("Designer Jeans");
    item2.setunit(40);
    item2.setprce(34.95);
    
    //Set Item 3 Info
    item3.setdesc("Shirt\t");
    item3.setunit(20);
    item3.setprce(24.95);
    
    //Display All Information
    cout<<"\tDecription\t\tUnits on Hand\t\tPrice"<<endl;
    cout<<"\t-----------------------------------------------------\n";
    cout<<"Item #1\t";
    prntPtr(item1);
    cout<<"Item #2\t";
    prntPtr(item2);
    cout<<"Item #3\t";
    prntPtr(item3);
    
    //Exit Stage Right!
    return 0;
}

void prntPtr(RetailItem i){
    cout<<i.getdesc()<<"\t\t      "<<i.getunit()<<"\t\t"<<i.getprce()<<endl;
}