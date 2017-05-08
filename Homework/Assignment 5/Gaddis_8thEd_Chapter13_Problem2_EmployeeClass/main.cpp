/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on May 7, 2017, 9:34 PM
 * Purpose: Problem 2
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries

#include "Employee.h"

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    Employee emp1,emp2,emp3;
    
    //Store Data in each object
    //Employee 1
    emp1.setname("Susan Meyers");
    emp1.setid(47899);
    emp1.setdept("Accounting");
    emp1.setpos("Vice President");
    
    //Employee 2
    emp2.setname("Mark Jones");
    emp2.setid(39119);
    emp2.setdept("IT");
    emp2.setpos("Programmer");
    
    //Employee 3
    emp3.setname("Joy Rogers");
    emp3.setid(81774);
    emp3.setdept("Manufacturing");
    emp3.setpos("Engineer");
    
    //Output the Data
    cout<<"Name\t\tID Number\tDepartment\tPosition"<<endl;
    cout<<emp1.getname()<<"\t"<<emp1.getid()<<"\t\t"<<emp1.getdept()<<"\t"
            <<emp1.getpos()<<endl;
    cout<<emp2.getname()<<"\t"<<emp2.getid()<<"\t\t"<<emp2.getdept()<<"\t\t"
            <<emp2.getpos()<<endl;
    cout<<emp3.getname()<<"\t"<<emp3.getid()<<"\t\t"<<emp3.getdept()<<"\t"
            <<emp3.getpos()<<endl;
    
    //Exit Stage Right!
    return 0;
}