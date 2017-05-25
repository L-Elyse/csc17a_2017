/* 
 * File:   AbsCard.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 9:14 PM
 * Purpose: AbsCard Class Specifications
 */

#ifndef ABSCARD_H
#define ABSCARD_H

#include <string>
using namespace std;

class AbsCard{
    private:
        string message;
    public:
        string getMess();
};

#endif /* ABSCARD_H */