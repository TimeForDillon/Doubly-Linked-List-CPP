#include "doublylinkedlist.h"

/*******************************************************************************
* DOUBLYLINKEDLIST CLASS
*_______________________________________________________________________________
* This program defines the functions and
* constructors for the DoublyLinkedList Class
*_______________________________________________________________________________
* INPUT:
*  "DoublyLinkedList.h": The function and constructor
*	declarations for the DoublyLinkedList class
*
* OUTPUT:
*  None
*******************************************************************************/

/*******************************************************************************
* CONSTRUCTOR DOUBLYLINKEDLIST
*_______________________________________________________________________________
* This constructor constructs a DoublyLinkedList object
* with a head and tail as null.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

/*******************************************************************************
* DESTRUCTOR DOUBLYLINKEDLIST
*_______________________________________________________________________________
* This destructs a DoublyLinkedList object and deltes the
* head and tail pointers
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

DoublyLinkedList::~DoublyLinkedList()
{
    IntNode* temp = head;
    IntNode* curr = nullptr;

    //deallocate the memory
    //reallocated to the list.
    while(temp != nullptr)
    {
        curr = temp;
        temp = temp->next;
        delete curr;
    }

    head = nullptr;
    tail = nullptr;
}

/*******************************************************************************
* COPY CONSTRUCTOR
*_______________________________________________________________________________
* This is a copy constructor.
*_______________________________________________________________________________
* PRE-CONDITIONS
* const DoublyLinkedList &D
*
* POST-CONDITIONS
* DoublyLinkedList
*******************************************************************************/

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &D)
{
    head=0;
    tail=0;

    if(!D.empty())
    {
        IntNode* temp = D.head;
        while(temp!=0)
        {
            push_back(temp->data);
            temp = temp->next;
        }
    }
}

/*******************************************************************************
* OVERLOADED ASSIGNMENT OPERATOR
*_______________________________________________________________________________
* This is overloads the assignment operator.
*_______________________________________________________________________________
* PRE-CONDITIONS
* const DoublyLinkedList &D
*
* POST-CONDITIONS
* DoublyLinkedList &
*******************************************************************************/

DoublyLinkedList & DoublyLinkedList::operator=(const DoublyLinkedList &D)
{
    if(this == &D) return  *this;
    else if(D.empty())
    {
        head = 0;
        tail = 0;
    }
    else
    {
        clear();
        IntNode* temp = D.head;
        while(temp!=0)
        {
            push_back(temp->data);
            temp=temp->next;
        }
    }
    return *this;
}

/*******************************************************************************
* FUNCTION DISPLAY
*_______________________________________________________________________________
* This Function prints the values of each object
* in a DoublyLinkedList object
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

void DoublyLinkedList::display() const
{
    IntNode * temp = head;

    //display the elements of the list.
    while(temp != nullptr)
    {
        cout << temp->data;
        //checks if this is the last pointer
        if (temp->next != NULL) cout << " ";
        temp = temp->next;
    }
}

/*******************************************************************************
* FUNCTION PUSH_FRONT
*_______________________________________________________________________________
* This Function adds an IntNode object to the
* front of a DoublyLinkedList, after the head pointer.
*_______________________________________________________________________________
* PRE-CONDITIONS
* int value
*
* POST-CONDITIONS
* None
*******************************************************************************/

void DoublyLinkedList::push_front(int value)
{
    IntNode *n_node = new IntNode(value);
    n_node->next = nullptr;

    //Insert the node at the front of the list.
    if(head == nullptr)
    {
        head = n_node;
        tail = head;
    }
    else
    {
        n_node->next = head;
        head = n_node;
    }
}

/*******************************************************************************
* FUNCTION POP_FRONT
*_______________________________________________________________________________
* This Function removes an IntNode object from the
* front of a DoublyLinkedList, after the head pointer.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

void DoublyLinkedList::pop_front()
{
    if(head == tail && head != nullptr)
    {
        head = nullptr;
        delete tail;
        tail = nullptr;
    }
    else if(head != nullptr)
    {
        IntNode * temp = head;
        head = head->next;
        delete temp;
    }
}

/*******************************************************************************
* FUNCTION PUSH_BACK
*_______________________________________________________________________________
* This function inserts a data value (within a new node)
* at the back end of the list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* int value
*
* POST-CONDITIONS
* None
*******************************************************************************/

void DoublyLinkedList::push_back(int value)
{
    IntNode* n_node = new IntNode(value);
    n_node->next = nullptr;

    //Insert the node at the back of the list.
    if(tail == NULL)
    {
        tail = n_node;
        head = tail;
    }
    else
    {
        tail->next = n_node;
        tail = n_node;
    }
}

/*******************************************************************************
* FUNCTION POP_BACK
*_______________________________________________________________________________
* This Function removes an IntNode object from the
* back of a DoublyLinkedList, before the tail pointer.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

void DoublyLinkedList::pop_back()
{


}

/*******************************************************************************
* FUNCTION SORT
*_______________________________________________________________________________
* This function sorts the list into ascending order
* using the selection sort algorithm.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

void DoublyLinkedList::sort()
{
    IntNode* temp = head,
    * min_node, * curr_node;

    //If the list is not empty then, perform the selection sort.
    if(head != nullptr)
    {
        while(temp->next != nullptr)
        {
            min_node = temp;
            curr_node = temp->next;

            while(curr_node != nullptr)
            {
                if(curr_node->data < min_node->data) min_node = curr_node;
                curr_node = curr_node->next;
            }

            int temp_swap = min_node->data;
            min_node->data = temp->data;
            temp->data = temp_swap;
            temp = temp->next;
        }
    }
}

/*******************************************************************************
* FUNCTION INSERT_SORTED
*_______________________________________________________________________________
* This function assumes the values in the list are
* in sorted (ascending) order and inserts the data
* into the appropriate position in the list (so that
* the values will still be in ascending order after insertion).
*_______________________________________________________________________________
* PRE-CONDITIONS
* int value
*
* POST-CONDITIONS
* None
*******************************************************************************/

void DoublyLinkedList::insert_sorted(int value)
{
    IntNode* n_node = new IntNode(value);
    IntNode* curr = head;
    IntNode* prev = nullptr;

    //find the correct postion to insert the node.

    while(curr != nullptr && curr->data < n_node->data)
    {
        prev = curr;
        curr = curr->next;
    }

    //Insert the node
    if(prev == nullptr)
    {
        n_node->next = curr;
        head = n_node;
    }
    else
    {
        prev->next = n_node;
        n_node->next = curr;
    }

    if(curr == nullptr) tail = n_node;
}

/*******************************************************************************
* FUNCTION REMOVE
*_______________________________________________________________________________
* This function removes the value (actually removes the node that contains the
* value). Return true if the remove was successful (value exists in the list),
* false otherwise.
*_______________________________________________________________________________
* PRE-CONDITIONS
* int value
*
* POST-CONDITIONS
* bool
*******************************************************************************/

bool DoublyLinkedList::remove(int value)
{

}

/*******************************************************************************
* FUNCTION BEGIN
*_______________________________________________________________________________
* This function returns an iterator at the beginning of the linked list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* IntListIterator
*******************************************************************************/

IntListIterator DoublyLinkedList::begin()
{
    return head;
}

/*******************************************************************************
* FUNCTION END
*_______________________________________________________________________________
* This function returns an iterator one element past the last element of the
* linked list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* IntListIterator
*******************************************************************************/

IntListIterator DoublyLinkedList::end()
{
    return tail->next;
}

/*******************************************************************************
* FUNCTION FRONT
*_______________________________________________________________________________
* This function returns the data in the head of the linked list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* int
*******************************************************************************/

int DoublyLinkedList::front() const
{
    return head->data;
}

/*******************************************************************************
* FUNCTION BACK
*_______________________________________________________________________________
* This function returns the data in the tail of the linked list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* int
*******************************************************************************/

int DoublyLinkedList::back() const
{
    return tail->data;
}

/*******************************************************************************
* FUNCTION LENGTH
*_______________________________________________________________________________
* This function recursively determines the length of the list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* int
*******************************************************************************/

int DoublyLinkedList::length() const
{
    findLength(head);
}

/*******************************************************************************
* FUNCTION FINDLENGTH
*_______________________________________________________________________________
* This function recursively determines the length of the list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* IntNode*
*
* POST-CONDITIONS
* int
*******************************************************************************/

int DoublyLinkedList::findLength(IntNode* head) const
{
    // Base case
    if (head == nullptr) return 0;

    // count is 1 + count of remaining list
    return 1 + findLength(head->next);
}

/*******************************************************************************
* FUNCTION CLEAR
*_______________________________________________________________________________
* This function clears the list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

void DoublyLinkedList::clear()
{
    //clear the list.
    IntNode* temp = head;
    IntNode* curr;

    while(temp != nullptr)
    {
        curr = temp;
        temp = temp->next;
        delete curr;
    }
}

/*******************************************************************************
* FUNCTION EMPTY
*_______________________________________________________________________________
* This function returns true if the list is empty.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* bool
*******************************************************************************/

bool DoublyLinkedList::empty() const
{
    if(head == nullptr) return true;
    else return false;
}
