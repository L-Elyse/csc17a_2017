/* 
 * File:   Rules.h
 * Author: Laurie Guimont
 * Created on May 29, 2017, 2:04 PM
 * Purpose: Rules Class Specifications
 */

#ifndef RULES_H
#define RULES_H
#include "ChncCom.h"

class Player;   

class Rules{
    private:
        int leftovr;       //Used in "Pass Go" instructions
        int extra;         //Used in "Pass Go" instructions
    public:
        void Go2Jail(Player &);
        void cGoJail(Player &);
        void restart(int,Player &);  //Friend 
        bool gameEnd(Player &);
        friend void ChncCom::setMess(unsigned short,short,Player &,Player &,
            Rules &);
};

#endif /* RULES_H */