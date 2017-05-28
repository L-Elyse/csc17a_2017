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
        int pick;
    public:
        ChncCom();
        void setMess(string);
        void setMess(unsigned short,Player &,Player &);  //Friend
        string getMess()const;
};

#endif /* CHNCCOM_H */