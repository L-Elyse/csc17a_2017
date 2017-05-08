/* 
 * File:   Personal.h
 * Author: Laurie Guimont
 * Created on May 8, 2017, 1:23 AM
 * Purpose: Personal Class Specifications
 */

#ifndef PERSONAL_H
#define PERSONAL_H

class Personal{
    private:
        string name;
        string addy;
        int age;
        string phone;
    public:
        void setname(string);
        void setaddy(string);
        void setage(int);
        void setphne(string);
        string getname()const;
        string getaddy()const;
        int getage()const;
        string getphne()const;
};

#endif /* PERSONAL_H */

