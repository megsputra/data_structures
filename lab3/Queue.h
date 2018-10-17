    /**

* Mega Putra

* CIS 22C, Lab 3

*/
#ifndef QUEUE_H_
#define QUEUE_H_


#include <iostream>
#include <cstddef>
#include <assert.h>
using namespace std;

template <class queuedata>
class Queue
{
	private:
       struct Node
       {
           queuedata data;
           Node* link;
           Node(queuedata data):  data(data),link(NULL){}

       };

       typedef struct Node* NodePtr;

       NodePtr front;
       NodePtr back;
       int size;

    public:
        /**constructors and destructors*/

        Queue();
        //initializes an empty queue
        //postcondition: an empty queue

        Queue(const Queue &queue);
        //initializes queue to have same elements as another queue
        //postcondition: a copy of queue

        ~Queue();
        //frees memory allocated to the queue
        //postcondition: memory for queue has been freed

        /**manipulation procedures*/

        void dequeue();
        //removes an element from the front of the queue
        //precondition:size!=0
        //postcondition: an element has been removed from the front of the queue

        void enqueue(queuedata data);
        //adds an element to the end of the queue
        //postcondition: an element added to the end of the queue

        /** Accessors */

        bool operator==(const Queue &queue);
        //returns whether this queue is equal to another queue

        queuedata getFront() const;
        //returns the element at the front of the queue
        //precondition: size != 0

        int getSize() const;
        //returns the size of the queue

        bool empty() const;
        //returns whether the queue is empty

        /**additional queue operations*/
        void print();
        //prints the elements in the queue separated by a blank space to stdout
};

template <class queuedata>
Queue<queuedata>::Queue()
{
	front = back = NULL;
	size = 0;
}

template <class queuedata>
Queue<queuedata>::Queue(const Queue &queue)
{
	size = queue.size;
	if(queue.front == NULL)
	{
		back = front = NULL;
	}
	else
	{
		front = new Node(queue.front->data);
		front->data = queue.front->data;
		NodePtr temp;
		temp = queue.front;
		NodePtr qtemp = front; //create temporary iterator

		while(temp->link != NULL)
		{
			qtemp->link = new Node(temp->data);
			qtemp = qtemp->link;
			temp = temp->link;
			qtemp->data = temp->data;
		}
		back = qtemp;
	}
}

template <class queuedata>
Queue<queuedata>::~Queue() //destructor
{
    NodePtr temp = front;
    NodePtr temp2 = front;
    while (temp != NULL)
    {
        temp = temp->link;
        delete temp2;
        temp2 = temp;
    }
}

template <class queuedata>
void Queue<queuedata>:: dequeue()
{
	assert(size!=0);
    if(size == 1)
    {
        delete front;
        front = back = NULL;
        size = 0;
    }
    else
    {
        NodePtr temp = front;
        front = front->link;
        delete temp;
        size--;
    }
}
template <class queuedata>
void Queue<queuedata>:: enqueue(queuedata data)
{
	NodePtr N = new Node(data);
	if (size == 0)
	{
		front = back = N;
	}
	else
	{
		back->link = N;
		back = N;
	}
	size++;
}
//adds an element to the end of the queue
//postcondition: an element added to the end of the queue

/**accessors*/
template <class queuedata>
bool Queue<queuedata>:: operator==(const Queue &queue)
{
	if(size != queue.size)
		return false;
	NodePtr temp1 = front;
	NodePtr temp2 = queue.front;
	while(temp1 != NULL)
	{
		if(temp1->data != temp2->data)
			return false;
		temp1 = temp1->link;
		temp2 = temp2->link;
	}
	return true;
}
//returns whether this queue is equal to another queue

template <class queuedata>
queuedata Queue<queuedata>:: getFront() const
{
	assert(!empty());
	return front->data;
}
//returns the element at the front of the queue
//precondition: size != 0

template <class queuedata>
int Queue<queuedata>::getSize() const
{
	return size;
}
//returns the size of the queue
template <class queuedata>
bool Queue<queuedata>::empty() const
{
	return size==0;
}

/**additional queue operations*/
template <class queuedata>
void Queue<queuedata>::print()
{
    NodePtr temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}

#endif /* QUEUE_H_ */
