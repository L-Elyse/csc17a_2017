/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 12, 2016, 9:27 PM
 * Purpose: Mean, Median, Mode with Dynamic Memory Allocation
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int randDgt();
int *fillAry(int);
void *prntAry(int *,int,int);
void *sortAry(int *,int);
void mean(int *,int);
void median(int *,int);
void mode(int *,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Array & Randomized Size
    const int SIZE=randDgt();
    cout<<"Here is an array of size "<<SIZE<<":"<<endl;
    int *array=fillAry(SIZE);
    
    //Display Randomized Array
    prntAry(array,SIZE,10);
    sortAry(array,SIZE);
    
    //Sort & Display Array
    cout<<"Sorted Array: \n";
    prntAry(array,SIZE,10);
    
    //Calculate Mean, Median, Mode
    mean(array,SIZE);
    median(array,SIZE);
    mode(array,SIZE);
    
    //Delete Pointer
    delete []array;
    
    //Exit Stage Right!
    return 0;
}

void mode(int *a,int n){
    int count=1,nmodes=0;
    int *b=new int [n];
    
    for(int i=0;i<n;i++) 
        *(b+i)=1;
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if (*(a+i)==*(a+j)){
                b[i]++;
            }
        if(b[i]>count)
            count=*(b+i);
        }
    }
    
    //Modes
    if(count>1){
        cout<<"The mode set is { ";
        for(int j=0;j<n;j++)
            if(*(b+j)==count){
                cout<<*(a+j)<<" ";
                nmodes++;
            }
        cout<<"}"<<endl;
        cout<<"The frequency of each is: "<<count<<endl;
        cout<<"The number of modes is: "<<nmodes;
    }
    else
        cout<<"No Mode!!"<<endl;
    
    //Delete Array
    delete []b;
}

void median(int *a,int n){
    float median;
    if(n%2==1)
        median=(a[n/2])/1.0;
    else if(n%2==0)
        median=(a[n/2]+a[n/2-1])/2.0;
    cout<<fixed<<setprecision(1)<<showpoint;
    cout<<"The median is: "<<median<<endl;
}

void mean(int *a,int n){
    int total=0;
    int average;
    for(int i=0;i<n;i++){
        total+=a[i];
    }
    average=total/n;
    cout<<"The average is: "<<average<<endl;
}

void *sortAry(int *a,int n){
    //Declare More Variables
    int start, minindx, minval;
    
    //Sort Values in Array
    for(start=0;start<n-1;start++){
        minindx=start;
        minval=a[start];
        for(int i=start+1;i<n;i++){
            if(a[i]<minval){
                minval=a[i];
                minindx=i;
            }
        }
        a[minindx]=a[start];
        a[start]=minval;
    }
}

void *prntAry(int *a,int n,int perLine){
    for(int i=0;i<n;i++){
        cout<<setw(4)<<a[i];
        if(i%perLine==(perLine-1))
            cout<<endl;
    }
    cout<<endl<<endl;
}

int *fillAry(int n){
    int *a=new int[n];
    for(int i;i<n;i++)
        a[i]=randDgt();
    return a;
}

int randDgt(){
    const int MIN=1, MAX=100;
    return (rand()%(MAX-MIN+1)+MIN);
}