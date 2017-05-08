/* 
 * File:   Employee.h
 * Author: Laurie Guimont
 * Created on May 7, 2017, 9:38 PM
 * Purpose: Employee Class Implementation
 */

#include <string>
using namespace std;

#include "Employee.h"

Employee::Employee(string n, int i, string d, string p){
    name=n;
    idNum=i;
    dept=d;
    pos=p;
}

Employee::Employee(string n, int i){
    name=n;
    idNum=i;
    dept="";
    pos="";
}

Employee::Employee(){
    name="";
    idNum=0;
    dept="";
    pos="";
}

void Employee::setname(string n){
    name=n;
}

void Employee::setid(int i){
    idNum=i;
}

void Employee::setdept(string d){
    dept=d;
}

void Employee::setpos(string p){
    pos=p;
}

string Employee::getname() const{
    return name;
}

int Employee::getid() const{
    return idNum;
}

string Employee::getdept() const{
    return dept;
}

string Employee::getpos() const{
    return pos;
}