/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 12, 2017 7:00 PM
 * Purpose: Test Scores
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *gettest(int);
int *sort(int *,int);
void average(int *,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    int scores;
    int *tests, *list;
    
    //Get Size from User
    cout<<"How many test scores would you like to enter? ";
    cin>>scores;
    tests=gettest(scores);
    
    //Sort & Display Test Scores
    list=sort(tests,scores);
    cout<<"The "<<scores<<" tests that you would like to average are: { ";
    for(int i=0;i<scores;i++)
        cout<<tests[i]<<" ";
    cout<<"}"<<endl;
    
    //Calculate & Display Average
    average(tests,scores);
    
    //Exit Stage Right!
    return 0;
}

void average(int *a,int n){
    float sum=0, mean;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    mean=sum/n;
    cout<<fixed<<setprecision(1)<<showpoint;
    cout<<"The average of your values is: "<<mean<<endl;
}

int *sort(int *a,int n){
    int start,minIndx,minVal;
    for(start=0;start<(n-1);start++){
        minIndx=start;
        minVal=a[start];
        for(int i=start+1;i<n;i++){
            if(a[i]<minVal){
                minVal=a[i];
                minIndx=i;
            }
        }
        a[minIndx]=a[start];
        a[start]=minVal;
    }
    return a;
}

int *gettest(int size){
    //Declare new array with pointer
    int *a=new int[size];
    for(int i=0;i<size;i++){
        cout<<"Test Score #"<<i+1<<" : ";
        cin>>a[i];
        while(a[i]<0){
            cout<<"Invalid Entry. No negative values please.";
            cin>>a[i];
        }
    }
    cout<<endl;
    return a;
}