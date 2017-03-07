/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 4, 2017, 12:27 PM
 * Purpose: Rain or Shine Program
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//Global Constants
const int COL=30;     //Columns for 2-Dimensional Array

//Function Prototypes
void readin(string [],char [][COL], int);
void process(char [][COL], int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    const int ROW=3;
    char rcs[ROW][COL];
 
    //Process & Output the Data
    process(rcs,ROW);
    
    //Exit Stage Right!
    return 0;
}

void process(char rcs [][COL],int r){
    //Declare Variables
    int rain=0,cloud=0,sun=0;      //Overall rain, cloud, or sun over period
    int juner=0,julyr=0,augustr=0; //total rain per month
    int junec=0,julyc=0,augustc=0; //total cloud per month
    int junes=0,julys=0,augusts=0; //total sun per month
    string months[r]={"June  ", "July  ", "August"};
    
    //Call Function to Display Array
    readin(months,rcs,r);
    
    //Process the Data
    for(int i=0;i<r;i++){
        for(int j=0;j<COL;j++){
            if(rcs[i][j]=='R'){
                rain++;
                if(i==0) juner++;
                else if(i==1) julyr++;
                else augustr++;
            }
            if(rcs[i][j]=='C'){
                cloud++;
                if(i==0) junec++;
                else if(i==1) julyc++;
                else augustc++;
            }
            if(rcs[i][j]=='S'){
                sun++;
                if(i==0) junes++;
                else if(i==1) julys++;
                else augusts++;
            }
        }
    }
    
    //Display Stats
    cout<<endl<<"\tRain\t Cloud\t  Sun"<<endl;
    cout<<"        ---------------------"<<endl;
    cout<<"June:    "<<juner<<"\t  "<<junec<<"\t  "<<junes<<endl;
    cout<<"July:    "<<julyr<<"\t  "<<julyc<<"\t  "<<julys<<endl;
    cout<<"August:  "<<augustr<<"\t  "<<augustc<<"\t  "<<augusts<<endl<<endl;
    cout<<"Total number of rainy days over three months:   "<<rain<<"\n";
    cout<<"Total number of cloudy days over three months:  "<<cloud<<"\n";
    cout<<"Total number of sunny days over three months:   "<<sun<<"\n";
    
    //Exit Function
    return;
}

void readin(string months[],char rcs[][COL], int r){
    //Declare the File
    ifstream in;
    
    //Open the Input File
    in.open("RainorShine.txt");
    
    //Read In the File
    for(int i=0;i<r;i++){
        cout<<months[i]<<":  ";
        for(int j=0;j<COL;j++){
            in>>rcs[i][j];
            cout<<rcs[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //Close the Input File
    in.close();
    
    //Exit Function
    return;
}