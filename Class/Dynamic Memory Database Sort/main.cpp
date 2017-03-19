/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 8th, 2017, 1:30 PM
 * Purpose: Database Sort
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void fillAry(int *,int *,int,int);
void prntAry(int *,int,int);
void prntAry(int *,int *,int,int);
void markSrt(int *,int*,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    int SIZE=100;
    int *array, *indx;
    array=new int[SIZE];
    indx=new int[SIZE];
    fillAry(array,indx,SIZE,10);
    
    //Output the created array
    prntAry(array,SIZE,10);
    prntAry(indx,SIZE,10);
    
    //Sort the Array
    markSrt(array,indx,SIZE);
    
    //Print our the Sorted Array
    prntAry(array,SIZE,10);
    prntAry(indx,SIZE,10);
    prntAry(array,indx,SIZE,10);
    
    //Delete the Arrays
    delete []array;
    delete []indx;
    
    //Exit Stage Right!
    return 0;
}

void prntAry(int *a,int *indx,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<(a[indx[i]]<10?"  ":" ")<<a[indx[i]];
        if(i%perLine==(perLine-1))
            cout<<endl;
    }
    cout<<endl;
}

void markSrt(int *a,int *indx,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[indx[i]]>a[indx[j]]){
                int temp=indx[i];
                indx[i]=indx[j];
                indx[j]=temp;
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

void fillAry(int *a,int *indx,int n,int mod){
    for(int i=0;i<n;i++){
        a[i]=i%mod;
        indx[i]=i;
    }
}