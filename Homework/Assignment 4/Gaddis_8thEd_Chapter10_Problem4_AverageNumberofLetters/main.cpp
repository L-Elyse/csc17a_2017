/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 4, 2017, 1:33 PM
 * Purpose: Average Number of Letters
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float average(char *,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    char *input;
    int length;
    
    //Get the String from User
    cout<<"Enter a string and I tell you the average number of letters ";
    cout<<"in each word."<<endl;
    cin.getline(input,100);
    length=strlen(input);
    
    //Output the String Length
    cout<<endl;
    cout<<"This string has an average of "<<average(input,length)<<" words.\n";
    
    //Exit Stage Right!
    return 0;
}

float average(char *str,int l){
    //Declare Accumulators & Allocate Dynamic Memory
    int count=0, index=0, size=0;
    float sum=0.0;
    int *a=new int[l];
    
    //Count Letters in Each Word
    for(int i=0;i<l;i++){
        if(*(str+i)!=' ')
            count++;
        else if(*(str+i)==' '){
            *(a+index)=count;
            index++;
            size++;
            count=0;
        }
    }
    *(a+index)=count;
    
    //Total and Average
    for(int i=0;i<size+1;i++)
        sum+=*(a+i);
    float average=sum/(size+1);
    
    //Prevent Memory Leak
    delete []a;
    
    cout<<fixed<<setprecision(2)<<showpoint;
    return average;
}