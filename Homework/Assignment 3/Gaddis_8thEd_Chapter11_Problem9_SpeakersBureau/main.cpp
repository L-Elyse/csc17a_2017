/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 29, 2017, 2:30 AM
 * Purpose: Speakers' Bureau
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "Speaker.h"

//Global Constants

//Function Prototypes
int Menu();
void process(int,speaker [],int);
speaker *adjust(speaker [],int);
speaker *fill(speaker [],int,int);
void display(speaker [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    int SIZE=10;
    speaker person[SIZE];
    int choice,index=0;
    
    //Input data
    fill(person,SIZE,index);
    //Menu
    do{
    choice=Menu();
    process(choice,person,SIZE);
    }while(choice!=3);
    
    //Exit Stage Right!
    return 0;
}

void display(speaker s[],int n){
    for(int i=0;i<n;i++){
        cout<<endl;
        cout<<s[i].name<<endl;
        cout<<s[i].telphne<<endl;
        cout<<s[i].topic<<endl;
        cout<<"$"<<s[i].fee<<endl;
        cout<<endl;
    }
}

speaker *fill(speaker s[],int n,int index){
    cout<<"Please enter: "<<endl;
    for(int i=index;i<n;i++){
        cout<<"Speaker Name "<<i+1<<": ";
        getline(cin,s[i].name);
        cout<<"Telephone Number: ";
        getline(cin,s[i].telphne);
        cout<<"Topic: ";
        getline(cin,s[i].topic);
        cout<<"Speaker Fee: ";
        cin>>s[i].fee;
        cin.ignore();
    }
    return s;
}

speaker *adjust(speaker s[],int n){
    int choose;
    cout<<"Which element (0-9) would you like to change?"<<endl;
    cin>>choose;
    cin.ignore();
    
    fill(s,choose+1,choose);
    
    return s;
}

void process(int choice,speaker s[],int n){
    switch(choice){
        case 1: adjust(s,n); break;
        case 2: display(s,n); break;
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