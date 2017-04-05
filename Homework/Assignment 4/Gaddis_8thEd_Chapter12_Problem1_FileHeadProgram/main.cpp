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
    string name;
    char ch;
    
    //Input data
    cout<<"Enter data.txt to see the file."<<endl;
    getline(cin,name);
    
    //Process data
    file.open(name.c_str(), ios::in);

    if(file){
        file.get(ch);
        while(file){
            cout<<ch;
            file.get(ch);
        }
        file.close();
        cout<<endl<<endl;
        cout<<"File has been displayed and is now ended"<<endl;
    }
    
    //Exit Stage Right!
    return 0;
}