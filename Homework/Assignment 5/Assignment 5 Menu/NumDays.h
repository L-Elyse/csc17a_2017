/* 
 * File:   NumDays.h
 * Author: Laurie Guimont
 * Created on May 9, 2017, 1:33 PM
 * Purpose: NumDays Class Specifications
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays{
    private:
        float workhrs;
    public:
        NumDays(float);
        void setHrs(float);
        float getHrs()const;
        float getDays();
        float operator+(const NumDays &);
        float operator-(const NumDays &);
        float operator++();
        float operator++(int);
        float operator--();
        float operator--(int);       
        
};

#endif /* NUMDAYS_H */