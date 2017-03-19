/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on June 20, 2016, 12:27 PM
 * Purpose: First Program
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
const int COLS=5;

//Function Prototypes
void fillAry(int [][COLS],int);
void prntAry(int [][COLS],int);
void prntAds(int [][COLS],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the Random Number Generator Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and Initialize all Variables Here
    const int ROWS=10;
    int table[ROWS][COLS]={};
    
    //Output the Tabled
    prntAry(table,ROWS);
    
    //Fill the Array with Trouble
    fillAry(table,ROWS);
    
    //Print out the Copied/Resized Array
    prntAry(table,ROWS);
    prntAds(table,ROWS);
    
    //Exit Stage Right!
    return 0;
}

void prntAds(int a[][COLS],int rows){
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            cout<<&a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void fillAry(int a[][COLS],int rows){
    //Fill with Random 2 Digit Numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            a[row][col]=rand()%90+10;
        }
    }
}

void prntAry(int a[][COLS],int rows){
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}