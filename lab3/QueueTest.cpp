///**
//
//* Mega Putra
//
//* CIS 22C, Lab 3
//
//*/
//#include <iostream>
//#include <string>
//#include <assert.h>
//#include "Queue.h"
//using namespace std;
//
//int main()
//{
//	Queue <string> Q;
//	cout << "***The following functions should trigger assert; comment out after testing.***" <<endl;
//	//Q.dequeue();
//	//Q.getFront();
//
//	cout<< "Should print Hello World: ";
//	Q.enqueue("Hello");
//	Q.enqueue("World");
//	Q.print();
//
//	cout<< "Should print World Tour: ";
//	Q.dequeue();
//	Q.enqueue("Tour");
//	Q.print();
//
//	cout<< "Should print list size is 2: " << Q.getSize() << endl;
//
//	Queue<string> Qu(Q); //copy ctor
//	cout<< "Should print copy of \" World Tour \" and show the queue is equal: ";
//
//	if (Qu==Q){
//		cout <<"Queues are equal!" << endl;
//		Qu.print();
//	}
//	else
//		cout <<"Not two queues are the same."<<endl;
//
//	if (Qu.empty())
//		cout << "Queue is empty" << endl;
//	else
//		cout << "Queue is not empty" << endl;
//
//
//	cout <<"New queue\nInt queue is empty: " << endl;
//	Queue<int> Qi;
//	if (Qi.empty())
//		cout << "Queue is empty" << endl;
//	else
//		cout << "Queue is not empty" << endl;
//
//	cout << "adding elements..."<<endl;
//	Qi.enqueue(1);
//	Qi.enqueue(3);
//	Qi.enqueue(5);
//	Qi.enqueue(7);
//	Qi.print();
//	cout<< "Should print list size is 4: " << Qi.getSize() << endl;
//	cout << "First number in the queue: " << Qi.getFront() << endl;
//
//	cout << "Removing 3 elements, should print 7: ";
//	Qi.dequeue();
//	Qi.dequeue();
//	Qi.dequeue();
//	Qi.print();
//
//
//}
