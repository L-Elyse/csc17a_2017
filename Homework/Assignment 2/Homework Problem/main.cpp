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

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    int numbers;
    float *ptr=0;
    //Get Size from User
    cout<<"Input a list a numbers and I will tell you the mean, median, and ";
    cout<<"mode of your list"<<endl;
    cout<<"How many numbers would you like to enter?";
    cin>>numbers;
    cout<<"Thank you. Now please enter the "<<numbers<<" numbers"<<endl;
    //Dynamically Allocate Array
    ptr=new float[numbers];
    
    //Call Function to collect numbers
    randnum(ptr,numbers);
    
    //Process data
    
    //DONT FORGET TO DELETE POINTER TO FREE UP MEMORY!!!
    delete [] ptr;
    ptr=0;
    
    //Exit Stage Right!
    return 0; 
}

void randnum(float *input,int size){
    for(int i=0;i<size;i++){
        cin>>*(input + i);
    }
}