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
    int count=0;
    char pause;
    
    //Input data
    cout<<"Select data.txt, data2.txt, or data3.txt to see the file ";
    cout<<"contents"<<endl;
    getline(cin,name);
    
    //Process data
    file.open(name, ios::in);

    if(file){
        getline(file, line);
        while(file){
            count++;
            cout<<line;
            if(count%24!=0)
                getline(file, line);
            else{
                cout<<"Enter any character to see more lines"<<endl;
                cin>>pause;
                getline(file, line);
            }
        }
        file.close();
    }
    else
        cout<<"Error. Cannot open file"<<endl;
    
    //Exit Stage Right!
    return 0;
}