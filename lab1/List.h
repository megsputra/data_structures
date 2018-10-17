/*
 * List.h
 *
 *  Created on: Apr 13, 2017
 *      Author: megaputra
 * Fill out the pre & post conditions
 */

#ifndef LIST_H_
#define LIST_H_

#include <cstddef> //for NULL

template <class listdata>

class List {
private:
    struct Node {
        int data;
        Node* nextnode;

        Node(int data) : data(data), nextnode(NULL)
        { }
    };

    typedef struct Node* NodePtr;

    NodePtr begin;
    NodePtr end;
    int length;

public:

    /**Constructors and Destructors*/

    List();
    //Default constructor; initializes and empty list
    //Postcondition: Initializes starting values for the data

    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: memory is freed, pointer is pointing to null

    /**Accessors*/

    listdata getBegin() const;
    //Returns the first element in the list
    //Precondition: first element must exist, it is the element that begin is pointing at

    listdata getEnd() const;
    //Returns the last element in the list
    //Precondition: last element must exist, next pointer is null.

    bool empty() const;
    //Determines whether a list is empty.

    int getLength() const;
    //Returns the size of the list

    /**Manipulation Procedures*/

    void deleteEnd();
    //Removes the value of the last element in the list
    //Precondition: list must not be empty, or points to null
    //Postcondition: last element will be removed and the element before that will point to null. End will also point at this last element.

    void deleteBegin();
    //Removes the value of the first element in the list
    //Precondition: list must not be empty
    //Postcondition: begin will now point to that element, and that element will point to the next element in the list

    void insertEnd (listdata data);
    //Inserts a new element at the end of the list
    //If the list is empty, the new element becomes both first and last
    //Postcondition: that new element will point to null. if first and last element, begin and end will point at that element.

    void insertBegin(listdata data);
    //Inserts a new element at the start of the list
    //If the list is empty, the new element becomes both first and last
    //Postcondition: new element will be inserted at the beginning, head will point at that element

    /**Additional List Operations*/

    void print() const;
    //Prints to the console the value of each element in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    //Prints a empty newline character if it's empty..
};
#endif /* LIST_H_ */
