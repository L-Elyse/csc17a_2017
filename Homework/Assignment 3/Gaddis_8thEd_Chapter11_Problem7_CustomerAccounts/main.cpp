/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 29, 2017, 1:27 AM
 * Purpose: Customer Accounts
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "Account.h"

//Global Constants

//Function Prototypes
int Menu();
void process(int,account [],int);
account *adjust(account [],int);
account *fill(account [],int,int);
void display(account [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    int SIZE=10;
    account custmer[SIZE];
    int choice,index=0;
    
    //Input data
    fill(custmer,SIZE,index);
    do{
    choice=Menu();
    process(choice,custmer,SIZE);
    }while(choice!=3);
    
    //Exit Stage Right!
    return 0;
}

void display(account c[],int n){
    for(int i=0;i<n;i++){
        cout<<endl;
        cout<<c[i].name<<endl;
        cout<<c[i].address<<endl;
        cout<<c[i].city<<", "<<c[i].state<<", "<<c[i].zip<<endl;
        cout<<c[i].telphne<<endl;
        cout<<"$"<<c[i].balance<<endl;
        cout<<c[i].lpyment;
        cout<<endl;
    }
}

account *fill(account c[],int n,int index){
    cout<<"Please enter: "<<endl;
    for(int i=index;i<n;i++){
        cout<<"Name "<<i+1<<": ";
        getline(cin,c[i].name);
        cout<<"Address: ";
        getline(cin,c[i].address);
        cout<<"City: ";
        getline(cin,c[i].city);
        cout<<"State: ";
        getline(cin,c[i].state);
        cout<<"Zip Code: ";
        cin>>c[i].zip;
        cin.ignore();
        cout<<"Telephone Number: ";
        getline(cin,c[i].telphne);
        cout<<"Account Balance: ";
        cin>>c[i].balance;
        cin.ignore();
        cout<<"Date of Last Payment (Month & Year): ";
        getline(cin,c[i].lpyment);
    }
    return c;
}

account *adjust(account c[],int n){
    int choose;
    cout<<"Which element (0-9) would you like to change?"<<endl;
    cin>>choose;
    cin.ignore();
    
    fill(c,choose+1,choose);
    
    return c;
}

void process(int choice,account c[],int n){
    switch(choice){
        case 1: adjust(c,n); break;
        case 2: display(c,n); break;
        default: return;
    }
}

int Menu(){
    int choice;
    //Display Menu
    cout<<"Now choose what you would like to do with the information you ";
    cout<<"have input"<<endl;
    cout<<"1. Change the Data"<<endl;
    cout<<"2. Display the Data"<<endl;
    cout<<"3. Absolutely Nothing"<<endl;
    
    cin>>choice;
    while(choice<1||choice>3){
        cout<<"Only select options 1 through 3: ";
        cin>>choice;
    }
    
    return choice;
}