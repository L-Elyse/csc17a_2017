/* 
 * File:   Car.h
 * Author: Laurie Guimont
 * Created on May 7, 2017, 10:35 PM
 * Purpose: Car Class Specification
 */

#ifndef CAR_H
#define CAR_H

class Car{
    private:
        int yearMod;
        string make;
        int speed;
    public:
        Car(int,string);
        int getyear()const;
        string getmake()const;
        int getspd()const;
        int accelerate();
        int brake();
};

#endif /* CAR_H */