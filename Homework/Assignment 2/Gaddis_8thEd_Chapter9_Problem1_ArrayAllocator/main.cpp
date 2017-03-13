/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 12, 2016, 9:27 PM
 * Purpose: Array Allocator
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *fillAry(int);
void *prntAry(int *,int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    int size=50;
    int *array=fillAry(size);
    
    //Print Array
    prntAry(array,size,10);
    
    //Exit Stage Right!
    return 0;
}

void *prntAry(int *a,int n,int perLine){
    for(int i=0;i<n;i++){
        cout<<(a[i]<10?"  ":" ")<<a[i];
        if(i%perLine==(perLine-1))
            cout<<endl;
    }
}

int *fillAry(int n){
    //Declare New Array
    int *a=new int[n];
    for(int i;i<n;i++)
        a[i]=i*2;
    return a;
}