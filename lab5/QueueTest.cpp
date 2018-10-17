/**

* Mega Putra

* CIS 22C, Lab 5

*/
#include <iostream>
#include <string>
#include <assert.h>
#include "Queue.h"
using namespace std;

int main()
{
	Queue Q;
	cout << "Should print size is 0: " << Q.getSize() << endl;
	if(Q.empty())
		cout << "Queue is empty" << endl;
	else
		cout << "Queue is not empty" << endl;

	Q.enqueue("Hello");
	Q.enqueue("How");
	Q.enqueue("Are");
	Q.enqueue("You");
	Q.enqueue("Today");
	Q.print();
	cout << "First element of the queue is: " << Q.getFront() << endl;

	cout << "\nDequeueing 3 elements" << endl;
	Q.dequeue();
	Q.dequeue();
	Q.dequeue();
	cout << "Should print You Today: ";
	Q.print();
	if(Q.empty())
	{
		cout << "\nQueue is empty" << endl;
	}
	else
		cout << "\nQueue is not empty" << endl;

	cout << "Should print size is 2: " << Q.getSize() << endl;
	cout << "First element of the queue is (You): " << Q.getFront() << endl;

	cout << "\nRemoving some elements.." <<endl;
	Q.dequeue();
	if(Q.empty())
	{
		cout << "\nQueue is empty" << endl;
	}
	else
		cout << "\nQueue is not empty" << endl;

	cout << "**Next functions should trigger assertion, comment out after testing.."<< endl;
	Q.dequeue();
	Q.getFront();

	cout << "\nShould print that there is 1 element and Today: " << Q.getSize() << " ";
	Q.print();
	cout << "Inserting new element while not empty" << endl;
	Q.enqueue("Is");
	Q.enqueue("A");
	Q.enqueue("Good");
	Q.enqueue("Day");

	cout << "Should print Today Is A Good Day: ";
	Q.print();
	cout << "Should print size is 5: " << Q.getSize() << endl;
	cout << "\nThank you for using my program, goodbye!" << endl;
}
