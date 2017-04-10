/* 
 * File:   main.cpp
 * Author: Laurie Guimont *
 * Created on April 6, 2017, 7:53 PM
 * Purpose: Just Some Review
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function Prototypes
void escape();
void sizes();
void casting();
void random();

//Execution Starts Here!
int main(int argc, char** argv) {
    //Chapter 2
    escape();
    sizes();
    
    //Chapter 3
    casting();
    random();
    
    //Chapter 5
    
    return 0;
}

void random(){
    int number;
    number=rand();
    cout<<number<<endl;  //A Pseudo Random Number
    cout<<time(0);       //The number of seconds that has passed since
                         //     January 1, 1970
}

void casting(){
    cout<<endl;
    //Type Casting
    char letters='A';
    cout<<"Example 1: "<<endl;
    cout<<letters<<endl;
    cout<<static_cast<int>(letters)<<endl;
    
    int number=100;
    cout<<"Example 2: "<<endl;
    cout<<number<<endl;
    cout<<static_cast<char>(number)<<endl;
    
    cout<<"Example 3: "<<endl;
    cout<<static_cast<short>(4.9)<<endl;
}

void sizes(){
    cout<<endl;
    //Data Type Sizes
    cout<<"Character: "<<sizeof(char)<<" bytes\n";
    cout<<"Short: "<<sizeof(short)<<" bytes\n";
    cout<<"Unsigned Short: "<<sizeof(unsigned short)<<" bytes\n";
    cout<<"Integer: "<<sizeof(int)<<" bytes\n";
    cout<<"Unsigned Integer: "<<sizeof(unsigned int)<<" bytes\n";
    cout<<"Float: "<<sizeof(float)<<" bytes\n";
    cout<<"Double: "<<sizeof(double)<<" bytes\n";
    cout<<"Long Double: "<<sizeof(long double)<<" bytes\n";
    cout<<"Long: "<<sizeof(long)<<" bytes\n";
    cout<<"Unsigned Long: "<<sizeof(unsigned long)<<" bytes\n";
    cout<<"Long Long: "<<sizeof(long long)<<" bytes\n";
    cout<<"Unsigned Long Long: "<<sizeof(unsigned long long)<<" bytes\n";
}

void escape(){
    //Escape Sequences
    cout<<"Some escape sequences here: "<<endl;
    cout<<"Using a newline now: \n";
    cout<<"Using a tab now: \t";
    cout<<"Using an alarm now: \a";
    cout<<"Using a backspace now: \b";
    cout<<"Using a return now: \r";
    cout<<"Printing a backslash now: \\";
    cout<<"Printing a single quote now: \'";
    cout<<"Printing a double quote now: \"";
    cout<<endl;
}