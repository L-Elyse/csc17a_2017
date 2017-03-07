/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 5, 2017, 4:20 PM
 * Purpose: Conduct a Binary String Search
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void sort(string[],int);
int binsrch(string[],int,string);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    const int SIZE=20;
    int results;
    string value;
    string names[SIZE]={"Collins, Bill","Smith, Bart","Allen, Jim",
                        "Griffin, Jim","Stamey, Marty","Rose, Geri",
                        "Taylor, Terri","Johnson, Jill","Allison, Jeff",
                        "Looney, Joe","Wolfe, Bill","James, Jean","Weaver, Jim",
                        "Pore, Bob","Rutherford, Greg","Javens, Renee",
                        "Harrison, Rose","Setzer, Cathy","Pike, Gordon",
                        "Holland, Beth"};
    
    //Sort Array
    sort(names,SIZE);
    
    //Perform driver test for binsrch
    cout<<"Enter a name you would like to search for and I will tell ";
    cout<<"you if it is in the list."<<endl;
    getline(cin,value);
    results=binsrch(names,SIZE,value);
    
    //Output Results
    if(results==-1)
        cout<<"Sorry. That name is not in the list."<<endl;
    else
        cout<<"That name is found at element "<<results<<" in the array\n";
    
    //Exit Stage Right!
    return 0;
}

int binsrch(string names[],int size, string value){   
    //Declare Variables
    int first=0,
       last=size-1,
       middle,
       position=-1;
   bool found=false;
   
   //Search Array
   while (!found && first<=last){
       middle=(first+last)/2;
       if(names[middle]==value){
           found=true;
           position=middle;
       }
       else if(names[middle]>value)
           last=middle-1;
       else
           first=middle+1;
   }
   
   //Exit Function and Return Position
   return position;
}

void sort(string names[],int size){
    //Declare Variables
    int start,mindx;
    string minval;
    
    //Sort
    for(start=0;start<(size-1);start++){
        mindx=start;
        minval=names[start];
        for(int i=start+1;i<size;i++){
            if(names[i]<minval){
                minval=names[i];
                mindx=i;
            }
        }
        names[mindx]=names[start];
        names[start]=minval;
    }
    
    //Display Array
    cout<<"Here is a list of names alphabetized by last name:"<<endl;
    cout<<"--------------------------------------------------"<<endl;
    for(int j=0;j<size;j++)
        cout<<names[j]<<endl;
    cout<<endl;
    //Exit Function
    return;
}