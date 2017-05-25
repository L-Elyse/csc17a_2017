/* 
 * File:   Board.h
 * Author: Laurie Guimont
 * Created on May 21, 2017, 5:46 PM
 * Purpose: Board Class Specifications
 */

#include <string>
using namespace std;

#include "Board.h"

Board::Board(){
    SPACES=40;
    name="";
    price=0;
    color="";
}
int Board::getSpce()const{
    return SPACES;
}
string Board::getname()const{
    return name;
}
int Board::getprce()const{
    return price;
}
string Board::getcolr()const{
    return color;
}