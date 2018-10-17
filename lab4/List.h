/**

* Mega Putra

* CIS 22C, Lab 4

*/

#ifndef LIST_H_
#define LIST_H_

#include <cstddef> //for NULL
#include <iostream>
#include <assert.h>
using namespace std;

template <class listdata>

class List {
private:
    struct Node {
        listdata data;
        Node* nextnode;
        Node* previousnode;

        Node(listdata data) : data(data), nextnode(NULL), previousnode(NULL)
        { }
    };

    typedef struct Node* NodePtr;

    NodePtr begin;
    NodePtr end;
    NodePtr iterator;
    int length;

    void reverse(NodePtr node);
    //Helper function for the public printReverse() function.
    //Recursively prints the data in a List in reverse.

    bool isSorted(NodePtr node);
    //Helper function for the public isSorted() function.
    //Recursively determines whether a list is sorted in ascending order.

    int binarySearch(int low, int high, listdata data);
    //Recursively search the list by dividing the search space in half
    //Returns the index of the element, if it is found in the List
    //Returns -1 if the element is not in the List



public:

    /**Constructors and Destructors*/

    List();
    //Default constructor; initializes and empty list
    //Postcondition: Initializes starting values for the data

    List(const List &list);
    //copy ctor

    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: memory is freed, pointer is pointing to null

    /**Accessors*/

    int getIndex();
    //Indicates the index of the Node where the iterator is currently pointing
    //Nodes are numbered from 1 to size of the list
    //Pre: length != 0
    //Pre: !offEnd()

    listdata getBegin() const;
    //Returns the first element in the list
    //Precondition: first element must exist, it is the element that begin is pointing at

    listdata getEnd() const;
    //Returns the last element in the list
    //Precondition: last element must exist, next pointer is null.

    listdata getIterator() const;

    bool empty() const;
    //Determines whether a list is empty.

    int getLength() const;
    //Returns the size of the list

    bool offEnd() const;

    void beginIterator();

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

    bool isSorted();
    //Wrapper function that calls the isSorted helper function to determine whether
    //a list is sorted in ascending order.
    //We will consider that a list is trivially sorted if it is empty.
    //Therefore, no precondition is needed for this function

    void advanceToIndex(int index);
    //Moves the iterator to the node whose index number is specified in the parameter
    //Pre: length != 0
    //Pre: index <= length

    int linearSearch(listdata data);
    //Searchs the list, element by element, from the start of the List to the end of the List
    //Returns the index of the element, if it is found in the List
    //Calls the above indexing functions in its implementation
    //Returns -1 if the element is not in the List
    //Pre: length != 0

    int binarySearch(listdata data);
    //Returns the index where data is located in the List
    //Calls the private helper function binarySearch to perform the search
    //Pre: length != 0
    //Pre: List is sorted (must test on a sorted list)

    /**Additional List Operations*/

    void print() const;
    //Prints to the console the value of each element in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    //Prints a empty newline character if it's empty..

    void insertIterator(listdata data);
    //Inserts element at iterator.
    //Pre: Iterator not pointing to NULL


    void deleteIterator();
    //Deletes element at iterator.
    //Pre: Iterator not pointing to NULL

    void advanceIterator();
    //Makes iterator point to the next node on the list.

    void reverseIterator();
    //Makes iterator point to the previous node on the list.

    /**Additional Operations*/

    void printReverse() ;
    //Wrapper function that calls the reverse helper function to print a list in reverse
    //prints nothing if the List is empty
    void printNumberedList() const;
    //: prints the contents of the linked list to the screen in the format #. <element> followed by a newline
    bool operator==(const List &list);
    //==: compares two lists to see if they are equal.

};
#endif /* LIST_H_ */

template <class listdata>
List<listdata>::List()
{
    begin = NULL;
    end = NULL;
    iterator = NULL;
    length = 0;
}

template <class listdata>
List<listdata>::List(const List &list)
{
    if(list.begin == NULL) //If the original list is empty, make an empty list for this list
    {
        begin = end = iterator = NULL;
    }
    else
    {
        begin = new Node(list.begin->data); //calling Node constructor
        NodePtr temp = list.begin; //set a temporary node pointer to point at the first of the original list
        iterator = begin; //set iterator to point to first node of the new list

        while(temp->nextnode != NULL)
        {
            temp = temp->nextnode; //advance up to the next node in the original list
            iterator->nextnode = new Node(temp->data); //using node constructor to create new node w/ copy of data
            iterator = iterator->nextnode; //advance to this new node
        }
        end = iterator; //Why do I need this line of code?
        iterator = NULL;
    }
    length = list.length;
}

template <class listdata>
List<listdata>::~List()
{
    NodePtr after = begin;
    NodePtr before = NULL;
    while (after != NULL)
    {
        before = after->nextnode;
        delete after;
        after = before;
    }
}
template <class listdata>
listdata List<listdata>::getBegin() const
{
    assert (!empty());
    return begin->data;
}

template <class listdata>
listdata List<listdata>::getEnd() const
{
    assert (!empty());
    return end->data;
}

template <class listdata>
listdata List<listdata>::getIterator() const
{
    assert (iterator !=NULL);
    return iterator->data;
}

template <class listdata>
void List<listdata>::advanceIterator()
{
    assert (iterator !=NULL);
    iterator = iterator->nextnode;
}

template <class listdata>
void List<listdata>::reverseIterator()
{
    assert (iterator !=NULL);
    iterator = iterator->previousnode;
}

template <class listdata>
void List<listdata>::beginIterator()
{
    iterator = begin;
}

template <class listdata>
bool List<listdata>::empty() const
{
    return length == 0;
}

template <class listdata>
int List<listdata>::getLength() const
{
    return length;
}

template <class listdata>
void List<listdata>::print() const
{
    NodePtr temp = begin;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->nextnode;
    }
    cout << endl;
}

template <class listdata>
void List<listdata>::printNumberedList() const
{
    NodePtr temp = begin;
    int i = 1;
    while (temp != NULL)
    {
        cout << i << ". " << temp->data << " " << endl;
        temp = temp->nextnode;
        i++;
    }
    cout << endl;
}

template <class listdata>
bool List<listdata>::operator==(const List& list)
{
    if(length != list.length)
        return false;
    NodePtr temp1 = begin;
    NodePtr temp2 = list.begin;
    while(temp1 != NULL)
    {
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->nextnode;
        temp2 = temp2->nextnode;
    }
    return true;
}

///**Manipulation Procedures*/

template <class listdata>
void List<listdata>::deleteEnd()
{
    assert(length!=0);
    if (length == 1)
    {
        delete end;
        begin = end = NULL;
        length--;
    }
    else
    {
        NodePtr temp = begin;
        while(temp->nextnode != end)
        {
            temp = temp->nextnode;
        }
        delete end;
        end = temp;
        end->nextnode = NULL;
        length--;
    }
}

template <class listdata>
void List<listdata>::deleteBegin()
{
    assert(length!=0);
    if(length == 1)
    {
        delete begin;
        begin = end = NULL;
        length = 0;
    }
    else
    {
        NodePtr temp = begin;
        begin = begin->nextnode;
        delete temp;
        length--;
    }
}

template <class listdata>
void List<listdata>::deleteIterator()
{
    assert(iterator != NULL);
    if(iterator == begin)
    {
        deleteBegin();
    }
    else if(iterator == end)
    {
        deleteEnd();
    }
    else
    {
        NodePtr temp2 = iterator->previousnode;
        NodePtr temp3 = iterator->nextnode;
        temp3->previousnode = temp2;
        temp2->nextnode = temp3;
        delete iterator;
        iterator = NULL;
        length--;
    }
}

template <class listdata>
void List<listdata>::insertEnd(listdata data)
{
    NodePtr N = new Node(data);
    if (length == 0) //list is empty, create new node
    {
        begin = end = N;
    }
    else
    {
        N->previousnode = end;
        end->nextnode = N;
        end = N;
    }
    length++;
}

template <class listdata>
void List<listdata>::insertBegin(listdata data)
{
    NodePtr N = new Node(data);
    if (length == 0)
    {
        begin = N;
        end = N;
    }
    else
    {
        NodePtr N = new Node(data);
        N->nextnode = begin;
        begin->previousnode = N;
        begin = N;
    }
    length++;
}

template <class listdata>
bool List<listdata>::offEnd() const
{
    return (iterator == NULL);
}

template <class listdata>
void List<listdata>::insertIterator(listdata data)
{
    assert(!offEnd()); // it cannot insert data at the very front of the list.
    if (iterator == end)
    {
        insertEnd(data);
    }
    else
    {
        NodePtr N = new Node(data);
        N->nextnode = iterator->nextnode;
        N->previousnode = iterator;
        (iterator->nextnode)->previousnode = N;
        iterator->nextnode = N;
        length++;
    }
}

template <class listdata>
void List<listdata>::printReverse()
{
    reverse(end);
    cout << endl;

}
template <class listdata>
void List<listdata>::reverse(NodePtr node)
{
    if (node == NULL)
        return;
    if (node != NULL)
    {
        cout << node->data << " ";
        reverse(node->previousnode);
    }

}

template <class listdata>
bool List<listdata>::isSorted(NodePtr node)
{
    if(node->nextnode==NULL)
        return true;
    else if(node->data > node->nextnode->data)
        return false;
    else
        return isSorted(node->nextnode);
}

template <class listdata>
bool List<listdata>::isSorted()
{
    if(isSorted(begin))
        return true;
    else
        return false;
}

template <class listdata>
int List<listdata>::getIndex()
{
    assert(length!=0);
    assert(!offEnd());
    NodePtr temp = begin;
    int index = 1;

    while (temp != NULL)
    {
        if(iterator == temp)
            return index;
        ++index;
        temp = temp->nextnode;
    }
    return -1; //not found

}

template <class listdata>
void List<listdata>::advanceToIndex(int index)
{
    assert(length!=0);
    assert(index<=length);

    NodePtr temp = begin;
    int count = 1;

    while (temp != NULL)
    {
        if (count == index)
            iterator = temp;
        count++;
        temp = temp->nextnode;
    }
}

template <class listdata>
int List<listdata>::linearSearch(listdata data)
{
	assert(length!=0);
	int orgPos = getIndex();

	NodePtr temp = begin;
	int index = 1;
	while (temp != NULL)
	{
	   if (temp->data == data)
	   {
		   advanceToIndex(index);
		   int pos = getIndex();
		   advanceToIndex(orgPos);
		   return pos;
	   }
	   index++;
	   temp = temp->nextnode;
	}
	return -1;//not found
}

template <class listdata>
int List<listdata>:: binarySearch(int low, int high, listdata data)
{
    assert(isSorted());
    assert(length != 0);

    int orgPos = getIndex();

    if(high < low)
        return -1;
    int mid = (low + high) / 2;
    advanceToIndex(mid);

    if(iterator->data == data)
    {
    	advanceToIndex(orgPos); //reset position
    	return mid;
    }

    else if(data < iterator->data)
    {
    	advanceToIndex(orgPos);//reset position
        return binarySearch(low, mid-1, data);
    }
    else
    {
    	advanceToIndex(orgPos);//reset position
        return binarySearch(mid+1, high, data);
    }
}

template <class listdata>
int List<listdata>::binarySearch(listdata data)
{
    return binarySearch(1, length, data);
}
