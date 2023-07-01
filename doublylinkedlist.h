#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "IntNode.h"
#include "intlistiterator.h"

/*****************************************************************************
* DOUBLYLINKEDLIST CLASS
*_________________________________________________
* This program defines the functions and
* constructors for the DoublyLinkedList Class
*_________________________________________________
* INPUT:
*  "DoublyLinkedList.h": The function and constructor
*	declarations for the DoublyLinkedList class
*
* OUTPUT:
*  None
******************************************************************************/

class DoublyLinkedList
{
public:
/*****************************************************************************
* CONSTRUCTOR DOUBLYLINKEDLIST
*________________________________________________
* This constructor constructs a DoublyLinkedList object
* with a head and tail, each containing a value
* of zero
****************************************************************************/
    DoublyLinkedList();
/*****************************************************************************
* COPY CONSTRUCTOR DOUBLYLINKEDLIST
*________________________________________________
* This is a copy constructor.
****************************************************************************/
    DoublyLinkedList(const DoublyLinkedList &D);
/*****************************************************************************
* DESTRUCTOR DOUBLYLINKEDLIST
*________________________________________________
* This destructs a DoublyLinkedList object and deletes the
* head and tail pointers
****************************************************************************/
    ~DoublyLinkedList();
/*****************************************************************************
* OVERLOADED ASSIGNMENT OPERATOR
*________________________________________________
* This is overloads the assignment operator.
****************************************************************************/
    DoublyLinkedList & operator=(const DoublyLinkedList &D);
/*****************************************************************************
* FUNCTION DISPLAY
*________________________________________________
* This Function prints the values of each object
* in a DoublyLinkedList object
****************************************************************************/
    void display() const;
/*****************************************************************************
* FUNCTION PUSH_FRONT
*________________________________________________
* This Function adds an IntNode object to the
* front of a DoublyLinkedList, after the head pointer.
****************************************************************************/
    void push_front(int value);  // CALC the value in the new intNode object
/*****************************************************************************
* FUNCTION POP_FRONT
*________________________________________________
* This Function removes an IntNode object from the
* front of a DoublyLinkedList, after the head pointer.
****************************************************************************/
    void pop_front();
/*****************************************************************************
* FUNCTION PUSH_BACK
*________________________________________________
* This function inserts a data value (within a new node)
* at the back end of the list.
****************************************************************************/
    void push_back(int value);
/*****************************************************************************
* FUNCTION POP_BACK
*________________________________________________
* This Function removes an IntNode object from the
* back of a DoublyLinkedList, before the tail pointer.
****************************************************************************/
    void pop_back();
/*****************************************************************************
* FUNCTION SORT
*________________________________________________
* This function sorts the list into ascending order
* using the selection sort algorithm.
****************************************************************************/
    void sort();
/*****************************************************************************
* FUNCTION INSERT_SORTED
*________________________________________________
* This function assumes the values in the list are
* in sorted (ascending) order and inserts the data
* into the appropriate position in the list (so that
* the values will still be in ascending order after insertion).
****************************************************************************/
    void insert_sorted(int value);
/*****************************************************************************
* FUNCTION REMOVE
*________________________________________________
* This function removes the value passed from the list. Returns true if removed.
****************************************************************************/
    bool remove(int value);
/*****************************************************************************
* FUNCTION BEGIN
*________________________________________________
* This function returns an iterator at the beginning of the linked list.
****************************************************************************/
    IntListIterator begin();
/*****************************************************************************
* FUNCTION END
*________________________________________________
* This function returns an iterator one element past the last element of the
* linked list.
****************************************************************************/
    IntListIterator end();
/*****************************************************************************
* FUNCTION FRONT
*________________________________________________
* This function returns the data in the head of the linked list.
****************************************************************************/
    int front() const;
/*****************************************************************************
* FUNCTION BACK
*________________________________________________
* This function returns the data in the tail of the linked list.
****************************************************************************/
    int back() const;
/*****************************************************************************
* FUNCTION LENGTH
*________________________________________________
*  This function recursively determines the length of the list.
****************************************************************************/
    int length() const;
/*****************************************************************************
* FUNCTION CLEAR
*________________________________________________
* This function clears the list.
****************************************************************************/
    void clear();
/*****************************************************************************
* FUNCTION EMPTY
*________________________________________________
* This function returns true if the list is empty.
****************************************************************************/
    bool empty() const;

private:
/*****************************************************************************
* FUNCTION FINDLENGTH
*________________________________________________
*  This function recursively determines the length of the list.
****************************************************************************/
    int findLength(IntNode* head) const;

    IntNode* head; // PROC the pointer to the first IntNode
    IntNode* tail; // PROC the pointer to the last IntNode
};

#endif // DOUBLYLINKEDLIST_H
