#include "intlistiterator.h"

/*******************************************************************************
* INTLISTITERATOR CLASS
*_______________________________________________________________________________
* This program defines the functions and
* constructors for the IntListIterator Class
*_______________________________________________________________________________
* INPUT:
*  "intListIterator.h": The function and constructor
*	declarations for the IntList class
*
* OUTPUT:
*  None
*******************************************************************************/

/*******************************************************************************
* CONSTRUCTOR INTLISTITERATOR
*_______________________________________________________________________________
* This constructor constructs an IntListIterator object
* with current set to null pointer.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

IntListIterator::IntListIterator()
{
    current = nullptr;
}

/*******************************************************************************
* CONSTRUCTOR INTLISTITERATOR
*_______________________________________________________________________________
* This constructor constructs an IntListIterator object
* with current set to passed variable.
*_______________________________________________________________________________
* PRE-CONDITIONS
* IntNode*
*
* POST-CONDITIONS
* None
*******************************************************************************/

IntListIterator::IntListIterator(IntNode* ptr)
{
    current = ptr;
}

/*******************************************************************************
* OVERLOADED * OPERATOR
*_______________________________________________________________________________
* This is overloads the * operator.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* int
*******************************************************************************/

int IntListIterator::operator*()
{
    return current->data;
}

/*******************************************************************************
* OVERLOADED ++ OPERATOR
*_______________________________________________________________________________
* This is overloads the ++ operator.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* IntListIterator
*******************************************************************************/

IntListIterator IntListIterator::operator++()
{
    current = current->next;
    return *this;
}

/*******************************************************************************
* OVERLOADED -- OPERATOR
*_______________________________________________________________________________
* This is overloads the -- operator.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* IntListIterator
*******************************************************************************/

IntListIterator IntListIterator::operator--()
{
    current = current->prev;
    return *this;
}

/*******************************************************************************
* OVERLOADED == OPERATOR
*_______________________________________________________________________________
* This is overloads the == operator.
*_______________________________________________________________________________
* PRE-CONDITIONS
* const IntListIterator&
*
* POST-CONDITIONS
* bool
*******************************************************************************/

bool IntListIterator::operator==(const IntListIterator& right) const
{
    if(this->current==right.current||right.current==this->current) return true;
    else return false;
}

/*******************************************************************************
* OVERLOADED != OPERATOR
*_______________________________________________________________________________
* This is overloads the != operator.
*_______________________________________________________________________________
* PRE-CONDITIONS
* const IntListIterator&
*
* POST-CONDITIONS
* bool
*******************************************************************************/

bool IntListIterator::operator!=(const IntListIterator& right) const
{
    if(this->current==right.current||right.current==this->current) return false;
    else return true;
}

