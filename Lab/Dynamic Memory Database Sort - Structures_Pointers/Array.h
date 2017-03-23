/* 
 * Author: Laurie Guimont
 * Created on March 20, 2017, 1:30 PM
 * Purpose: Database Sort Using Structures
 */

#ifndef ARRAY_H
#define ARRAY_H

struct Array{
    int size;  //Size of the array
    int *data; //Data in the array
    int *index; //Index used in sorting the array
};

#endif /* ARRAY_H */