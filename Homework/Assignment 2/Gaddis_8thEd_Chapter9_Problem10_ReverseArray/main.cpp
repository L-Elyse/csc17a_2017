/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 13, 2017, 7:37 PM
 * Purpose: Reverse an Array
 */

//System Libraries
#include <iostream>//Input/Output Stream Library
using namespace std;//Iostream uses the standard namespace

//User Libraries

//Global Constants

//Function Prototypes
int *fillAry(int);
int *copyAry(int *,int);
void *prntAry(int *,int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    const int SIZE=50;
    int *array=fillAry(SIZE);
    int *newAry;
    
    //Copy and Reverse Array
    prntAry(array,SIZE,10);
    newAry=copyAry(array,SIZE);
    
    //Process data
    prntAry(newAry,SIZE,10);
    
    //Delete Array
    delete []newAry;
    
    //Exit Stage Right!
    return 0;
}

int *copyAry(int *a,int n){
    int *b=new int[n];
    for(int j=0;j<n;j++)
        b[j]=a[(n-1)-j];
    delete []a;
    return b;
}

void *prntAry(int *a,int n, int perLine){
    for(int i=0;i<n;i++){
        cout<<(a[i]<10?"  ":" ")<<a[i];
        if(i%perLine==(perLine-1))
            cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++)
        a[i]=i;
    
    return a;
}