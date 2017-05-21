/* 
 * File:   AbsCard.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 6:23 PM
 * Purpose: AbsCard Class Specifications
 */

#ifndef ABSCARD_H
#define ABSCARD_H

class AbsCard{
    public:
        virtual char getSuit()=0;
        virtual char getFVal()=0;
        virtual char getCNum()=0;
};

#endif /* ABSCARD_H */