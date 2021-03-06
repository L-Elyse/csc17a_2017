/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 4, 2017, 9:50 PM
 * Purpose: File Head Program
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    fstream file;
    string name,line;
    
    //Input data
    cout<<"Enter data.txt to see the first 10 lines of the file."<<endl;
    getline(cin,name);
    
    //Process data
    file.open(name, ios::in);

    if(file){
        getline(file, line);
        for(int i=0;i<10;i++){
            cout<<line;
            getline(file, line);
        }
        file.close();
    }
    else
        cout<<"Error. Cannot open file"<<endl;
    
    //Exit Stage Right!
    return 0;
}