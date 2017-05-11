/* 
 * File:   Circle.h
 * Author: Laurie Guimont
 * Created on May 10, 2017, 7:35 PM
 * Purpose: Circle Class Specifications
 */

//Global Constants
const float PI=3.14159;

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle{
    private:
        float radius;
    public:
        Circle(){
            radius=0;
        }
        Circle(float r){
            radius=r;
        }
        void setRad(float r){
            radius=r;
        }
        float getRad()const{
            return radius;
        }
        float getArea(){
            return radius*radius*PI;
        }
        float getDiam(){
            return radius*2;
        }
        float getCrcm(){
            return radius*2*PI;
        }
};

#endif /* CIRCLE_H */