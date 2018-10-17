/**

* Mega Putra

* CIS 22C, Lab 5

*/

#include <iostream>
#include <string>
#include <assert.h>
#include "Queue.h"
using namespace std;

void Queue::dequeue()
{
	assert(!empty());
	s2.pop();
}

void Queue::enqueue(string data)
{
	if(s2.empty())
	{
		s1.push(data);
		while(!s1.empty())
		{
			s2.push(s1.peek());
			s1.pop();
		}
	}
	else
	{
		while(!s2.empty())
		{
			s1.push(s2.peek());
			s2.pop();
		}
		s1.push(data);
		while(!s1.empty())
		{
			s2.push(s1.peek());
			s1.pop();
		}
	}

}

string Queue::getFront()
{
	assert(!empty());
	return s2.peek();
}

int Queue::getSize()
{
	return s2.getSize();
}

bool Queue::empty()
{
	return s2.getSize() == 0;
}

void Queue::print()
{
	s2.print();
}

