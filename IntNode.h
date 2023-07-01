#ifndef INTNODE_H
#define INTNODE_H

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

/******************************************************************************
* INTNODE STRUCT
*_________________________________________________
* This program defines and declares the variables
* and constructor for the InNode struct
*_________________________________________________
* INPUT:
*  None
*
* OUTPUT:
*  None
******************************************************************************/

struct IntNode
{
    int data;       // CALC & OUT the value conatined in the IntNode
    IntNode* next;  // PROC the ponter to the next IntNode object
    IntNode* prev;  // PROC the ponter to the previous IntNode object
/*****************************************************************************
* CONSTRUCTOR INTNODE
*________________________________________________
* This constructor constructs an IntNode object
* with a data value from the constructor call,
* and a next pointer of NULL
*________________________________________________
* PRE-CONDITIONS
* data: the value conatined in the IntNode
*
* POST-CONDITIONS
* constructs an IntNode object
* with a data value from the constructor call,
* and a next pointer of NULL
****************************************************************************/
    IntNode(int data) : data(data), // CALC & OUT the value conatined in the IntNode
                        next(0),    // PROC the ponter to the next IntNode object
                        prev(0) {}  // PROC the ponter to the previous IntNode object
};

#endif // INTNODE_H
