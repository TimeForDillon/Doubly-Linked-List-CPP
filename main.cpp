/*******************************************************************************
* AUTHOR       : Dillon Welsh, David Dang
* LAB15        : DOUBLYLINKEDLIST
* CLASS        : CS 3A
* SECTION      : 71206
* DUE DATE     : 11/01/2020
*******************************************************************************/

#include "doublylinkedlist.h"

/*
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
*/


int main()
{
    DoublyLinkedList L1;
    DoublyLinkedList L3;

    IntListIterator it;

    int testNum;

    cout << "Enter test number: " << endl;
    cin >> testNum;

    for (unsigned i = 0; i < testNum; i++){
        L1.push_front(i);
    }

    cout<< "L1: ";
    for (it = L1.begin(); it != L1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl << endl;

    cout << "TESTING: L1 front and back functions" << endl;
    cout << L1.front() << "\t" << L1.back() << endl << endl;

    cout << "TESTING: length" << endl;
    cout << "Length: " << L1.length() << endl;

    //for testing copy constructor (testNum == 4)
    DoublyLinkedList L2(L1);

    for (unsigned i = 0; i < 5; i++){
        L2.push_front(i);
    }

    cout<< "L2: ";
    for (it = L2.begin(); it != L2.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl << endl;

    //for testing assignment operator (testNum == 5)
    L3 = L2;
    for (unsigned i = 0; i < 5; i++){
        L2.push_front(i);
    }

    cout << "TESTING: Assign operator (L3 = L2 ; empty L3): " << endl;
    cout << "L3: ";
    for (it = L3.begin(); it != L3.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl << endl;

    cout << "TESTING: L3 front and back functions" << endl;
    cout << L3.front() << "\t" << L3.back() << endl << endl;

    cout << "TESTING: length" << endl;
    cout << "Length: " << L3.length() << endl;

    DoublyLinkedList L4;
    int count = 0;

    cout << "Testing: Iterator copying elements of L1 into L4:" << endl;
    for (it = L1.begin(); it != L1.end(); ++it, count++ )
    {
        if ((*it)%3 == 0)
            L4.push_back(*it);
        if (count%2 == 0)
            L4.push_front(*it);
    }

    cout << "L4: ";
    for (it = L4.begin(); it != L4.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl << endl;

    cout << "TESTING: L4 front and back functions" << endl;
    cout << L4.front() << "\t" << L4.back() << endl << endl;

    return 0;
}

