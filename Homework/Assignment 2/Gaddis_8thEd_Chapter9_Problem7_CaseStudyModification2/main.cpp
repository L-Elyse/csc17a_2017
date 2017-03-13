/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 12, 2017, 10:50 PM
 * Purpose: Sort Array in Descending Order
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *fillAry(int);
int *loopPtr(int);
void arrSort(int *, int);
void showAry(int *,int);
void showPtr(int *,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    int donate;
    int *array,*ptr;
    
    //Ask for Size & Fill the Array
    cout<<"How many donations would you like to input?"<<endl;
    cin>>donate; 
    array=fillAry(donate);
    
    //Pointer array
    ptr=loopPtr(donate);
    
    //Process data
    for(int count=0;count<donate;count++)
        ptr[count]=array[count];
    
    //Sort the Data
    arrSort(ptr,donate);
    
    //Output the Data
    cout<<"The donations,sorted in descending order are: \n";
    showPtr(ptr,donate);
    
    cout<<"The donations, sorted in their original order are: \n";
    showAry(array,donate);
    
    //Exit Stage Right!
    return 0;
}

void showAry(int *a,int size){
    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void showPtr(int *a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void arrSort(int *a,int n){
    int start, minIndx;
    int minElem;
    
    for(start=0;start<n-1;start++){
        minIndx=start;
        minElem=a[start];
        for(int i=start+1;i<n;i++){
            if(a[i]>minElem){
                minElem=a[i];
                minIndx=i;
            }
        }
        a[minIndx]=a[start];
        a[start]=minElem;
    }
}

int *loopPtr(int size){
    int *b=new int[size];
    for(int j=0;j<size;j++){
        b[j]=0;
    }
    return b;
}

int *fillAry(int size){
    int *a=new int[size];
    for(int i=0;i<size;i++){
        cout<<"Donation #"<<i+1<<" : ";
        cin>>a[i];
    }
    return a;
}