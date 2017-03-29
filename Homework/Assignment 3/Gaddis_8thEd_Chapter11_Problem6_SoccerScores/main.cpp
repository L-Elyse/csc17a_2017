/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 28, 2017, 1:20 PM
 * Purpose: Soccer Scores
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "Soccer.h"

//Global Constants

//Function Prototypes
scores *fillAry(scores [],int);
void display(scores [],int);
void teampts(scores [],int);
void highest(scores [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    int SIZE=12;
    scores points[SIZE];
    int total;
    
    //Input data
    fillAry(points,SIZE);
    display(points,SIZE);
    teampts(points,SIZE);
    highest(points,SIZE);
    
    //Process data
    
    //Output data
    
    //Exit Stage Right!
    return 0;
}

void highest(scores p[],int n){
    int highest=1,index;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].points>p[j].points){
                if(p[i].points>highest){
                    highest=p[i].points;
                    index=i;
                }
            }
        }
    }
    cout<<endl;
    cout<<"The player who scored the most points is: "<<endl;
    cout<<p[index].name<<endl;
    cout<<p[index].number<<endl;
    cout<<"They scored "<<highest<<" points. Congratulate them!"<<endl;
}

void teampts(scores p[],int n){
    int total=0;
    for(int i=0;i<n;i++){
        total+=p[i].points;
    }
    cout<<"Total Team Points: "<<total<<endl;
}

void display(scores p[],int n){
    cout<<endl;
    cout<<"Here is the Team Roster"<<endl;
    cout<<"-----------------------"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Name:   "<<p[i].name<<endl;
        cout<<"Number: "<<p[i].number<<endl;
        cout<<"Points: "<<p[i].points<<endl;
        cout<<endl;
    }
    cout<<endl;
}

scores *fillAry(scores p[],int n){
    for(int i=0;i<n;i++){
        cout<<"Player "<<i+1<<":"<<endl;
        cout<<"Name: ";
        getline(cin,p[i].name);
        cout<<"Number: ";
        cin>>p[i].number;
        cout<<"Points Scores: ";
        cin>>p[i].points;
        cin.ignore();
    }
    return p;
}