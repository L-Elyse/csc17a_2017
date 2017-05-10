/* 
 * File:   FeetInches.h
 * Author: Laurie Guimont
 * Created on May 9, 2017, 1:41 PM
 * Purpose: FeetInches Class Specifications
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef FEETINCHES_H
#define FEETINCHES_H

class FeetInches{
    private:
        int feet;
        int inches;
        void simplify();
    public:
        FeetInches(int f=0,int i=0){
            feet=f;
            inches=i;
            simplify();
        }
        FeetInches(FeetInches &obj){
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
        void multiply(FeetInches &obj){
            feet*=obj.feet;
            inches*=obj.inches;
            simplify();
        }
        
};

#endif /* FEETINCHES_H */