/* 
 * File:   FeetInches.h
 * Author: Laurie Guimont
 * Created on May 9, 2017, 1:41 PM
 * Purpose: FeetInch Class Specifications
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef FEETINCH_H
#define FEETINCH_H

class FeetInch{
    private:
        int feet;
        int inches;
        void simplify();
    public:
        FeetInch(int f=0,int i=0){
            feet=f;
            inches=i;
            simplify();
        }
        FeetInch(FeetInch &obj){
            feet=obj.feet;
            inches=obj.inches;
            simplify();
        }
        void setFeet(int f){
            feet=f;
        }
        void setInch(int i){
            inches=i;
            simplify();
        }
        int getFeet()const{
            return feet;
        }
        int getInch()const{
            return inches;
        }
        void multiply(FeetInch &obj){
            feet*=obj.feet;
            inches*=obj.inches;
            simplify();
        }
        
};

#endif /* FEETINCH_H */