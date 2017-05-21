/* 
 * File:   DrvCard.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 6:26 PM
 * Purpose: DrvCard Class Specifications
 */

#ifndef DRVCARD_H
#define DRVCARD_H

#include <string>
using namespace std;

#include "Card.h"

class DrvCard:public Card{
private:
    string fileNme;
public:
    DrvCard(unsigned char cNum):Card(cNum){
        fileNme=".jpg";
        fileNme=getSuit()+fileNme;
        fileNme=getFVal()+fileNme;
    }
    string getFN(){
        return fileNme;
    }
};

#endif /* DRVCARD_H */