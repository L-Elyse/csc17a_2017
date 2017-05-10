/* 
 * File:   Date.h
 * Author: Laurie Guimont
 * Created on May 7, 2017, 2:32 PM
 * Purpose: Date Class Specification
 */

#ifndef DATE_H
#define DATE_H

class Date{
    private:
        int month;
        int day;
        int year;
    public:
        void setmnth(int);
        void setday(int);
        void setyear(int);
        int getmnth() const;
        string mname() const;
        int getday() const;
        int getyear() const;
};

#endif /* DATE_H */