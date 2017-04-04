/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 3, 2017, 8:50 PM
 * Purpose: Create a String that Reverses Another
 */

//System Libraries
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void reverse(char *,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    char *input;
    int length;
    
    //Input data
    cout<<"Enter a string and I will output it in reverse!"<<endl;
    cin.getline(input,100);
    
    //Determine Length and Output Results
    length=strlen(input);
    reverse(input,length);
    
    //Exit Stage Right!
    return 0;
}

void reverse(char *c,int n){
    cout<<"The reversed string is: "<<endl;
    for(int i=n-1;i>=0;i--){
        cout<<*(c+i);
    }
    //Put Null Terminator
    for(int i=n;i<n+1;i++){
        *(c+i)='\0';
    }
}