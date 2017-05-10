/* 
 * File:   RetailItem.h
 * Author: Laurie Guimont
 * Created on May 8, 2017, 2:47 PM
 * Purpose: RetailItem Class Specifications
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H

class RetailItem{
    private:
        string descrpt;
        int units;
        float price;
    public:
        RetailItem (string,int,float);
        void setdesc(string);
        void setunit(int);
        void setprce(float);
        string getdesc()const;
        int getunit()const;
        float getprce()const;
};

#endif /* RETAILITEM_H */