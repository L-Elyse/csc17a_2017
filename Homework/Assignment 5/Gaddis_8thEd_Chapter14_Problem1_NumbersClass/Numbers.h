/* 
 * File:   Numbers.h
 * Author: Laurie Guimont
 * Created on May 8, 2017, 8:45 PM
 * Purpose: Numbers Class Specifications
 */

#ifndef NUMBERS_H
#define NUMBERS_H

class Numbers{
    private:
        int number;
        static string less20[20];
        static string hundred;
        static string thousnd;
    public:
        Numbers(int n){
            if(n>0&&n<10000) number=n;
            else exit(0);
        };
        string convert();
        void print(string);
};

#endif /* NUMBERS_H */

