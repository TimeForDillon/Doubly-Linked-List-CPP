#ifndef INTLISTITERATOR_H
#define INTLISTITERATOR_H

#include "IntNode.h"

/*****************************************************************************
* INTLISTITERATOR CLASS
*_________________________________________________
* This program defines the functions and
* constructors for the IntListIterator Class
*_________________________________________________
* INPUT:
*  "intListIterator.h": The function and constructor
*	declarations for the IntListIterator class
*
* OUTPUT:
*  None
******************************************************************************/

class IntListIterator
{
public:
/*****************************************************************************
* CONSTRUCTOR INTLISTITERATOR
*________________________________________________
* This constructor constructs an IntListIterator object
* with current set to null pointer.
****************************************************************************/
    IntListIterator();
/*****************************************************************************
* CONSTRUCTOR INTLISTITERATOR
*________________________________________________
* This constructor constructs an IntListIterator object
* with current set to passed variable.
****************************************************************************/
    IntListIterator(IntNode* ptr);
/*****************************************************************************
* FUNCTION OPERATOR*
*________________________________________________
* This is overloads the * operator.
****************************************************************************/
    int operator*();
/*****************************************************************************
* FUNCTION OPERATOR++
*________________________________________________
* This is overloads the ++ operator.
****************************************************************************/
    IntListIterator operator++();
/*****************************************************************************
* FUNCTION OPERATOR--
*________________________________________________
* This is overloads the -- operator.
****************************************************************************/
    IntListIterator operator--();
/*****************************************************************************
* FUNCTION OPERATOR==
*________________________________________________
* This is overloads the == operator.
****************************************************************************/
    bool operator==(const IntListIterator& right) const;
/*****************************************************************************
* FUNCTION OPERATOR!=
*________________________________________________
* This is overloads the != operator.
****************************************************************************/
    bool operator!=(const IntListIterator& right) const;

private:
    IntNode* current;   // PROC pointer to the current node
};

#endif // INTLISTITERATOR_H
