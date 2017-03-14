/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 13, 2014, 8:00 PM
 * Purpose: Array Expander
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *fillAry(int);
int *copyAry(int *,int);
void *prntAry(int *,int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    const int SIZE=100;
    int *array=fillAry(SIZE);
    int *newAry;
    
    //Copy & Expand Array
    cout<<"Array Expanded: \n";
    newAry=copyAry(array,SIZE);
    
    //Delete Array
    delete []newAry;
    
    //Exit Stage Right!
    return 0;
}

int *copyAry(int *a,int n){
    int size=n*2;
    int *b=new int[size];
    for(int i=0;i<size;i++)
        i>(n-1)?(b[i]=0):(b[i]=a[i]);
    
    //Print the Array
    prntAry(b,size,10);
    
    delete []a;
    return b;
}

void *prntAry(int *a,int n,int perLine){
    for(int i=0;i<n;i++){
        cout<<setw(4)<<a[i];
        if((i%perLine)==(perLine-1))
            cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=i*5;
    }
    //Print the Array
    prntAry(a,n,10);
    
    return a;
}
