/* 
 * File:   ChncCom.h
 * Author: Laurie Guimont
 * Created on May 27, 2017, 8:09 PM
 * Purpose: ChncCom Class Specifications
 */

#ifndef CHNCCOM_H
#define CHNCCOM_H
#include "Property.h"

#include <string>
using namespace std;

class Player;

class ChncCom{
    private:
        string message;
    public:
        ChncCom();
        void setMess(unsigned short,short,Player &,Player &,int,int);  //Friend
        string getMess()const;
};

#endif /* CHNCCOM_H */