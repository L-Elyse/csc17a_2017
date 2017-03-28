/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 28th, 2017, 9:00 PM
 * Purpose: Structure with Corporate Sales Data
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "Sales.h"

//Global Constants

//Function Prototypes
void first(Sales);
void second(Sales);
void third(Sales);
void fourth(Sales);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    Sales dvsion1={"East"}, dvsion2={"West"}, dvsion3={"North"}, 
            dvsion4={"South"};
    
    //Get the Information for each division
    cout<<"This program stores data about a company's divisions"<<endl;
    first(dvsion1);
    second(dvsion2);
    third(dvsion3);
    fourth(dvsion4);
      
    //Exit Stage Right!
    return 0;
}

void first(Sales d1){
    //Get the Amount of Sales
    cout<<"Please enter the following information for "<<d1.name<<":\n";
    cout<<"First-Quarter Sales: ";
    cin>>d1.Q1;
    cout<<"Second-Quarter Sales: ";
    cin>>d1.Q2;
    cout<<"Third-Quarter Sales: ";
    cin>>d1.Q3;
    cout<<"Fourth-Quarter Sales: ";
    cin>>d1.Q4;
    cout<<endl;
    
    //Calculate the total & average sales
    d1.total=d1.Q1+d1.Q2+d1.Q3+d1.Q4;
    d1.average=d1.total/4;
    
    //Output results
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Here are the results for the "<<d1.name<<" sales:"<<endl;
    cout<<"Total Sales:   $"<<setw(5)<<d1.total<<endl;
    cout<<"Average Sales: $"<<setw(5)<<d1.average<<endl;
}

void second(Sales d2){
    cout<<endl;
    //Get the Amount of Sales
    cout<<"Please enter the following information for "<<d2.name<<":\n";
    cout<<"First-Quarter Sales: ";
    cin>>d2.Q1;
    cout<<"Second-Quarter Sales: ";
    cin>>d2.Q2;
    cout<<"Third-Quarter Sales: ";
    cin>>d2.Q3;
    cout<<"Fourth-Quarter Sales: ";
    cin>>d2.Q4;
    cout<<endl;
    
    //Calculate the total & average sales
    d2.total=d2.Q1+d2.Q2+d2.Q3+d2.Q4;
    d2.average=d2.total/4;
    
    //Output results
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Here are the results for the "<<d2.name<<" sales:"<<endl;
    cout<<"Total Sales:   $"<<setw(5)<<d2.total<<endl;
    cout<<"Average Sales: $"<<setw(5)<<d2.average<<endl;
}

void third(Sales d3){
    cout<<endl;
    //Get the Amount of Sales
    cout<<"Please enter the following information for "<<d3.name<<":\n";
    cout<<"First-Quarter Sales: ";
    cin>>d3.Q1;
    cout<<"Second-Quarter Sales: ";
    cin>>d3.Q2;
    cout<<"Third-Quarter Sales: ";
    cin>>d3.Q3;
    cout<<"Fourth-Quarter Sales: ";
    cin>>d3.Q4;
    cout<<endl;
    
    //Calculate the total & average sales
    d3.total=d3.Q1+d3.Q2+d3.Q3+d3.Q4;
    d3.average=d3.total/4;
    
    //Output results
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Here are the results for the "<<d3.name<<" sales:"<<endl;
    cout<<"Total Sales:   $"<<setw(5)<<d3.total<<endl;
    cout<<"Average Sales: $"<<setw(5)<<d3.average<<endl;
}

void fourth(Sales d4){
    cout<<endl;
    //Get the Amount of Sales
    cout<<"Please enter the following information for "<<d4.name<<":\n";
    cout<<"First-Quarter Sales: ";
    cin>>d4.Q1;
    cout<<"Second-Quarter Sales: ";
    cin>>d4.Q2;
    cout<<"Third-Quarter Sales: ";
    cin>>d4.Q3;
    cout<<"Fourth-Quarter Sales: ";
    cin>>d4.Q4;
    cout<<endl;
    
    //Calculate the total & average sales
    d4.total=d4.Q1+d4.Q2+d4.Q3+d4.Q4;
    d4.average=d4.total/4;
    
    //Output results
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Here are the results for the "<<d4.name<<" sales:"<<endl;
    cout<<"Total Sales:   $"<<setw(5)<<d4.total<<endl;
    cout<<"Average Sales: $"<<d4.average<<endl;
}