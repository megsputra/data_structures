/**

* Mega Putra

* CIS 22C, Lab 5

*/

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <cstddef>
#include <assert.h>

using namespace std;
template <class stackdata>
class Stack
{
    public:

        /**constructors and destructors*/

        Stack();
        //initializes an empty stack
        //postcondition: an empty stack

        Stack(const Stack &S);
        //initializes this stack to have same elements as S
        //postcondition: a copy of stack

        ~Stack();
        //frees memory allocated to the stack
        //postcondition: memory for stack has been freed

        /**manipulation procedures*/

        void pop();
        //removes an element from the top of the stack
        //precondition: size != 0
        //postcondition: an element has been removed from the top of the stack

        void push(stackdata data);
        //adds an element to the top of the stack
        //postcondition: an element added to the top of the stack

        /**accessors*/


       bool operator==(const Stack &S);
       //returns whether this stack is equal to another stack S

       stackdata peek();
       //returns the element at the top of the stack
       //precondition: size != 0

       int getSize();
       //returns the size of the stack

       bool empty();
       //returns whether the stack is empty

       /**additional operations*/

       void print();
       //prints the elements in the stack each element separate by a blank space to stdout

    private:
       struct Node {
           stackdata data;
           Node* link;

           Node(stackdata data):data(data), link(NULL){}
       };

       typedef struct Node* NodePtr;

       NodePtr top;
       int size;

};
#endif /* STACK_H_ */


template <class stackdata>
Stack<stackdata>::Stack()
{
	top = NULL;
	size = 0;
}

template <class stackdata>
Stack<stackdata>::Stack(const Stack &S)
{
	size = S.size;
	if(S.top == NULL)
	{
		top = NULL;
	}
	else
	{
		top = new Node(S.top->data);
		top->link = S.top->link;
		NodePtr temp;
		temp = S.top;
		NodePtr stemp = top;

		while(temp->link!= NULL)
		{
			stemp->link = new Node(temp->data);
			stemp = stemp->link;
			temp = temp->link;
			stemp->data = temp->data;
		}
	}
}

template <class stackdata>
Stack<stackdata>::~Stack()
{
    NodePtr temp = top;
    NodePtr temp2 = top;
    while (temp != NULL){
        temp = temp->link;
        delete temp2;
        temp2 = temp;
    }
}


template <class stackdata>
bool Stack<stackdata>::empty()
{
	return size==0;
}

template <class stackdata>
void Stack<stackdata>::pop() //deletebegin
{
	assert(!empty());
	if(size == 1)
	{
		delete top;
		top = NULL;
	}
	else
	{
		NodePtr temp = top;
		top = top->link;
		delete temp;
		temp = NULL;
	}
	size--;
}

template <class stackdata>
void Stack<stackdata>::push(stackdata data) //insertbegin
{
	NodePtr N = new Node(data);
	if (size ==0)
	{
		top = N;
	}
	else
	{
		N->link = top;
		top = N;
	}
	size++;
}

template <class stackdata>
stackdata Stack<stackdata>::peek()
{
	assert(!empty());
	return top->data;
}
template <class stackdata>
int Stack<stackdata>::getSize()
{
	return size;
}

template <class stackdata>
void Stack<stackdata>::print()
{
	NodePtr temp = top;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->link;
	}
	cout << endl;
}
template <class stackdata>
bool Stack<stackdata>::operator==(const Stack&s)
{
    if(size != s.size)
        return false;
    NodePtr temp1 = top;
    NodePtr temp2 = s.top;
    while(temp1 != NULL)
    {
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->link;
        temp2 = temp2->link;
    }
    return true;
}

