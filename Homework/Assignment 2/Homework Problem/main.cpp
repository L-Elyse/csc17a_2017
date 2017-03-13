/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 10, 2017, 1:00 pm
 * Purpose: Find Mean, Median, and Mode using Dynamic Memory Allocation
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
void randnum(float *,int);
void sortnum(float *,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    int numbers, count, freq=1, *same=0;
    float *ptr=0, mean, median, mode, total=0;
    
    //Get Size from User
    cout<<"Input a list a numbers and I will tell you the mean, median, and ";
    cout<<"mode of your list"<<endl;
    cout<<"How many numbers would you like to enter? ";
    cin>>numbers;
    cout<<"Thank you. Now please enter the "<<numbers<<" numbers"<<endl;
    
    //Dynamically Allocate Array
    ptr=new float[numbers];
    
    //Call Function for Input Data
    randnum(ptr,numbers);
    
    //Sort the Data
    sortnum(ptr,numbers);
    
    //Process Data - Find Mean, Median, & Mode
    //Mean
    for(count=0;count<numbers;count++){
        total+=ptr[count];
    }
    mean=total/numbers;
    //Median
    if(numbers%2==1)
        median=ptr[numbers/2];
    else if(numbers%2==0)
        median=(ptr[numbers/2]+ptr[numbers/2-1])/2;
    cout<<median<<endl;
    //Mode
    same=new int[numbers];
    for(count=0;count<numbers;count++){
        for(int i=0;i<numbers;i++){
            if(ptr[count]==ptr[i+1]){
                freq++;
                for(int j=0;j<freq;j++)
                    same[j]=ptr[count];
            }
        }  
    }
    cout<<"{";
    for(count=0;count<numbers;count++){
        cout<<same[count];
    }
    cout<<"}";
    
    //DONT FORGET TO DELETE POINTER TO FREE UP MEMORY!!!
    delete [] ptr;
    delete [] same;
    ptr=0;
    same=0;
    
    //Exit Stage Right!
    return 0; 
}

void sortnum(float *input,int size){
    //Declare More Variables
    int start, minindx, minval;
    
    //Sort Values in Array
    for(start=0;start<size-1;start++){
        minindx=start;
        minval=input[start];
        for(int i=start+1;i<size;i++){
            if(input[i]<minval){
                minval=input[i];
                minindx=i;
            }
        }
        input[minindx]=input[start];
        input[start]=minval;
    }
}

void randnum(float *input,int size){
    for(int i=0;i<size;i++){
        cin>>*(input + i);
    }
}