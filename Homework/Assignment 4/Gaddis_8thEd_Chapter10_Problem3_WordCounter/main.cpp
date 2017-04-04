/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 4, 2017, 1:30 PM
 * Purpose: Word Counter
 */

//System Libraries
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int counter(char *,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    char *input;
    int length;
    
    //Get the String from User
    cout<<"Enter a string and I will count the words"<<endl;
    cin.getline(input,100);
    length=strlen(input);
    
    //Output the String Length
    cout<<endl;
    cout<<"This string has "<<counter(input,length)<<" words."<<endl;
    
    //Exit Stage Right!
    return 0;
}

int counter(char *str,int l){
    int count=0;
    for(int i=0;i<l;i++){
        if(*(str+i)==' ')
            count++;
    }
    return count+1;
}