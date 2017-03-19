/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 8th, 2017, 1:30 PM
 * Purpose: Code to Test Your Mode
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *fillAry(int,int);
void prntAry(int *,int,int);
void markSrt(int *,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    int size=100;
    int *array=fillAry(size,10);
    
    //Output the created array
    prntAry(array,size,10);
    
    //Sort the array
    markSrt(array,size);
    
    //Printout the sorted array
    prntAry(array,size,10);
    
    //Delete the array
    delete []array;
    
    //Exit Stage Right!
    return 0;
}

void markSrt(int *a,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<(a[i]<10?"  ":" ")<<a[i];
        if(i%perLine==(perLine-1))
            cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n,int mod){
    int *a=new int[n];
    for(int i=0;i<n;i++)
        a[i]=i%mod;
    
    return a;
}