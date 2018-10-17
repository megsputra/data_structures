/**

* Mega Putra

* CIS 22C, Lab 3

*/
//#include <iostream>
//#include <string>
//#include <assert.h>
//#include "Stack.h"
//using namespace std;
//
//int main(){
//
//
//	cout << "This stack contains some cash:" << endl;
//	Stack<string> S;
//	S.push("$10");
//	S.push("$5");
//	S.push("$1");
//	cout << "Should print $1 $5 $10: ";
//	S.print();
//
//	cout << "\nCreating copy..."<< endl;
//	Stack <string> S1(S);
//	if (S1==S)
//	{
//		cout <<"Same stack! Here's what in the copy:" << endl;
//		S1.print();
//	}
//	else
//		cout <<"Not two stacks are the same."<<endl;
//
//	if (S.empty())
//		cout << "Main Stack is empty" << endl;
//	else
//		cout << "Main Stack is not empty" << endl;
//
//	S1.push("$20");
//	cout << "\nI just got paid...! ($20 added to stack)" << endl;
//	cout << "The first element of the stack is now: " << S1.peek() << endl;
//	cout << "Size of this stack: " << S1.getSize()<<endl;
//
//	cout <<"\nRemoving all elements" << endl;
//	while (!S1.empty())
//	{
//		S1.pop();
//	}
//	cout << "Should print empty stack: ";
//	S1.print();
//	cout << "Size of this stack is now: " << S1.getSize()<<endl;
//	if (S1.empty())
//		cout << "Stack is empty" << endl;
//	else
//		cout << "Stack is not empty" << endl;
//	cout << "\n~~~The following 2 functions will trigger assertion, comment out after testing" << endl;
//	S1.peek();
//	S1.pop();
//
//}
