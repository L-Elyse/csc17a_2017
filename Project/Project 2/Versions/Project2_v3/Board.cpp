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
    space=0;
    name="";
    price=0;
    color="";
}
int Board::getSpce()const{
    return space;
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