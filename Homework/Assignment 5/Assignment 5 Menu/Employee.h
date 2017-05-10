/* 
 * File:   Employee.h
 * Author: Laurie Guimont
 * Created on May 7, 2017, 9:38 PM
 * Purpose: Employee Class Specification
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee{
    private:
        string name;
        int idNum;
        string dept;
        string pos;
    public:
        Employee(string,int,string,string);
        Employee(string,int);
        Employee();
        void setname(string);
        void setid(int);
        void setdept(string);
        void setpos(string);
        string getname() const;
        int getid() const;
        string getdept() const;
        string getpos() const;
};

#endif /* EMPLOYEE_H */