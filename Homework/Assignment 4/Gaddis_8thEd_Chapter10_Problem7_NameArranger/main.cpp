/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 4, 2017, 2:20 PM
 * Purpose: Name Arranger
 */

//System Libraries
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void arrange(char [],int);


//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    int size=100;
    char name[size];
    int length;
    
    //Get the String from User
    cout<<"Enter your first, middle, and last name."<<endl;
    cin.getline(name,size);
    length=strlen(name);
    
    //Output the String Length
    cout<<endl;
    cout<<"Here is your name rearranged: ";
    arrange(name,length);
    
    //Exit Stage Right!
    return 0;
}

void arrange(char c[],int l){
    char first[l],middle[l],last[l];
    int count=1,index=0;
    for(int i=0;i<l;i++){
        if(c[i]!=' '){
            if(count==1)
                first[index]=c[i];
            else if(count==2)
                middle[index]=c[i];
            else if(count==3)
                last[index]=c[i]; 
            index++;
        }
        else{
            count++;
            index=0;
        }
    }
    //Now Arrange into One Array
    int size=strlen(first)+strlen(middle)+strlen(last)+1;
    char combine[size];
}