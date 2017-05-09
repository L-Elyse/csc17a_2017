/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 8, 2017, 1:23 AM
 * Purpose: Problem 4
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "Personal.h"

//Execution Begins Here!
int main(int argc, char** argv) {
    Personal people[3];
    string n,a,p;
    int g;
    
    //Fill Array
    cout<<"Enter the following information for yourself and then two others\n";
    for(int i=0;i<3;i++){
        cout<<"Person "<<i+1<<": "<<endl;
        cout<<"Name: ";
        getline(cin,n);
        cout<<"Address: ";
        getline(cin,a);
        cout<<"Age: ";
        cin>>g;
        cin.ignore();
        cout<<"Phone: ";
        getline(cin,p);
        
        cout<<endl;
        cout<<"Here are what you input: \n";
        //Set the Information
        people[i].setname(n);
        people[i].setaddy(a);
        people[i].setage(g);
        people[i].setphne(p);
        
        //Get the Information
        cout<<"Name: "<<people[i].getname()<<endl;
        cout<<"Address: "<<people[i].getaddy()<<endl;
        cout<<"Age: "<<people[i].getage()<<endl;
        cout<<"Phone: "<<people[i].getphne()<<endl<<endl;
    }

    //Exit Stage Right!
    return 0;
}