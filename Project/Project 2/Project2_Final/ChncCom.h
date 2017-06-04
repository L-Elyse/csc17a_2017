/* 
 * File:   ChncCom.h
 * Author: Laurie Guimont
 * Created on May 27, 2017, 8:09 PM
 * Purpose: ChncCom Class Specifications
 */

#ifndef CHNCCOM_H
#define CHNCCOM_H

#include <string>
using namespace std;

class Player;
class Rules;

class ChncCom{
    private:
        string message;   //Message displayed on Chance/Community Chest cards
    public:
        ChncCom();
        void setMess(unsigned short,short,Player &,Player &,Rules &);
        string getMess()const;
};

#endif /* CHNCCOM_H */