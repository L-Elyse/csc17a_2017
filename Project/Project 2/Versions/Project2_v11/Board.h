/* 
 * File:   Board.h
 * Author: Laurie Guimont
 * Created on May 21, 2017, 5:46 PM
 * Purpose: Board Class Specifications
 */

#ifndef BOARD_H
#define BOARD_H

#include <string>
using namespace std;

class Board{
    protected:
        string name;       //Property Names
        int price;         //Purchase Price for Properties 
        string color;      //Colors for Property Color Groups
    public:
        Board(){
            name="";
            price=0;
            color="";
        }
        string getname()const{
            return name;
        }
        int getprce()const{
            return price;
        }
        string getcolr()const{
            return color;
        }
        string colList(int index){
            string colors[10]={"purple","RR","lilac","pink","Utility","orange",
                                "red","yellow","green","blue"};
            
            return colors[index];
        }
        virtual void inform(int,int)=0;
};

#endif /* BOARD_H */