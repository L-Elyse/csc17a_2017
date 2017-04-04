/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 3, 2017, 10:30 PM
 * Purpose: Sentence Capitalizer
 */

//System Libraries
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void capital(char *,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    char *input;
    int length;
    
    //Input data
    cout<<"Enter a couple sentences with proper punctuation. Do NOT capitalize";
    cout<<" the first word of each sentence though."<<endl;
    cout<<"I will do that for you."<<endl;
    cin.getline(input,200);
    
    //Get the Length of the string and output
    length=strlen(input);
    capital(input,length);
    
    //Exit Stage Right!
    return 0;
}

void capital(char *c,int n){
    *(c+0)=toupper(*(c+0));
    for(int i=1;i<n;i++){
        if(*(c+i)==' '&&*(c+i-1)=='.'){
            *(c+i+1)=toupper(*(c+i+1));
            i++;
        }
    }
    for(int i=0;i<n;i++)
        cout<<*(c+i);
}