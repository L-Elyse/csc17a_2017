/* 
 * File:   FeetInches.h
 * Author: Laurie Guimont
 * Created on May 9, 2017, 1:41 PM
 * Purpose: FeetInches Class Specifications
 */

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
        bool operator<=(const FeetInches &);
        bool operator>=(const FeetInches &);
        bool operator!=(const FeetInches &);
};

#endif /* FEETINCHES_H */