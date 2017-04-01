/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 24, 2017, 1:30 PM
 * Purpose: Create a Database of Array Data
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <valarray>
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants

//Function Prototypes
Array *fillAry(int,int);
void prntAry(Array *,int);
void wrtTxt(fstream &,Array *,int);
void wrtBin(fstream &,Array *);
Array *readBin(fstream &);
void markSrt(Array *);
void destroy(Array *);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Open the Text and binary files
    fstream txtFile,binFile;
    txtFile.open("data.txt",ios::in|ios::out);
    binFile.open("data.bin",ios::in|ios::out|ios::binary);
    
    //Declare all Variables Here
    int size=rand()%90+10; //[10-99]
    int perLine=10,record=99; //[00-99]
    Array *array=fillAry(size,record);
    
    //Sort the Array
    markSrt(array);
    
    //Printout the sorted array
    prntAry(array,perLine);
    wrtTxt(txtFile,array,perLine);
    wrtBin(binFile,array);
    
    //Read back in the array, then print out
    Array *brray=readBin(binFile);
    prntAry(brray,perLine);
    
    //Delete the array
    destroy(array);
    destroy(brray);
    
    //Close the files
    txtFile.close();
    binFile.close();
    
    //Exit Stage Right!
    return 0;
}

void destroy(Array *a){
    delete []a->data;
    delete []a->index;
    delete a;
}

Array *readBin(fstream &in){
    in.seekg(0L,in.beg);
    Array *a=new Array;
    in.read(reinterpret_cast<char *>(&a->size),sizeof(a->size));
    a->data=new int[a->size];
    in.read(reinterpret_cast<char *>(a->data),a->size*sizeof(a->data));
    a->index=new int[a->size];
    in.read(reinterpret_cast<char *>(a->index),a->size*sizeof(a->index));
    return a;
}

void wrtBin(fstream &out,Array *a){
    out.write(reinterpret_cast<char *>(&a->size),sizeof(a->size));
    out.write(reinterpret_cast<char *>(a->data),a->size*sizeof(a->data));
    out.write(reinterpret_cast<char *>(a->index),a->size*sizeof(a->index));
}

void wrtTxt(fstream &out,Array *a,int perLine){
    out<<endl;
    out<<"Array Size = "<<a->size<<endl;
    for(int i=0;i<a->size;i++){
        out<<setw(6)<<a->data[a->index[i]];
        if(i%perLine==(perLine-1))out<<endl;
    }
    out<<endl;
}

void prntAry(Array *a,int perLine){
    cout<<endl;
    cout<<"Array Size = "<<a->size<<endl;
    for(int i=0;i<a->size;i++){
        cout<<setw(6)<<a->data[a->index[i]];
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void markSrt(Array *a){
    for(int i=0;i<a->size-1;i++){
        for(int j=0;j<a->size;j++){
            if(a->data[a->index[i]]>a->data[a->index[j]]){
                int temp=a->index[i];
                a->index[i]=a->index[j];
                a->index[j]=temp;
            }
        }
    }
}

Array *fillAry(int n,int mod){
    //Declare the array and its components
    Array *a=new Array;
    a->size=n>1?n:2;
    a->data=new int[a->size];
    a->index=new int[a->size];
    //Fill the components with data
    for(int i=0;i<a->size;i++){
        a->data[i]=mod*1000+rand()%100;
        a->index[i]=i;
    }
    //Return the Array
    return a;
}