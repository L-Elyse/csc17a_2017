/* 
 * File:   Personal.h
 * Author: Laurie Guimont
 * Created on May 8, 2017, 1:23 AM
 * Purpose: Personal Class Implementation
 */

#include <string>
using namespace std;

#include "Personal.h"

void Personal::setname(string n){
    name=n;
}

void Personal::setaddy(string a){
    addy=a;
}

void Personal::setage(int g){
    age=g;
}

void Personal::setphne(string p){
    phone=p;
}

string Personal::getname() const{
    return name;
}

string Personal::getaddy() const{
    return addy;
}

int Personal::getage() const{
    return age;
}

string Personal::getphne() const{
    return phone;
}