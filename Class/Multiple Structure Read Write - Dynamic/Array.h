/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 31, 2017, 11:27 PM
 * Purpose: Create a Database of Array Data
 */

#ifndef ARRAY_H
#define ARRAY_H

struct Array{
    int size;   //Size of the array
    int *data;  //Data in the array
    int *index; //Index used in sorting the array
};

#endif /* ARRAY_H */