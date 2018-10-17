///**
//
//* Mega Putra
//
//* CIS 22C, Lab 4
//
//*/
//#include "List.h"
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//
//	cout << "Welcome! This test file show whether the functions are working properly.\nGeneral and edge cases will also be tested.\nFunctions may be tested more than once to show those cases.\n" << endl;
//    List<string> Food;
//    List<int> Numbers;
//
//    Food.insertBegin("butter");
//    Food.insertEnd("lentils");
//    Food.insertEnd("papaya");
//    Food.beginIterator();
//    cout << "Should print butter: ";
//    cout << "We put *" << Food.getIterator() << "* on our toast." << endl;
//
//    Food.deleteEnd();
//    Food.deleteBegin();
//    Food.deleteBegin();
//    cout << "Should print empty list and \"List is empty:\" " ;
//    Food.print();
//    if (Food.empty())
//    		cout << "List is empty" << endl;
//    	else
//    		cout << "List is not empty" << endl;
//
//
//    cout << "~~~The following 4 functions will trigger assertion, comment out after testing" << endl;
////    Food.deleteBegin();
////    Food.deleteEnd();
////    Food.getBegin();
////    Food.getEnd();
//
//    Numbers.insertBegin(39);
//    Numbers.insertEnd(15);
//    Numbers.insertEnd(42);
//    Numbers.insertEnd(27);
//    Numbers.insertEnd(38);
//
//    Numbers.beginIterator();
//    Numbers.advanceIterator();
//    Numbers.advanceIterator();
//    Numbers.reverseIterator();
//    Numbers.deleteIterator();
//
//    cout <<"\nShould print list is not sorted: " << endl;
//	if (Numbers.isSorted()) {
//		cout << "List is sorted!" << endl;
//	} else {
//		cout << "The list is not sorted" << endl;
//	}
//	cout << endl;
//	cout << "hould print 39 42 27 38: ";
//    Numbers.print();
//    cout << "This is the reverse print: ";
//    Numbers.printReverse();
//
//    cout << endl;
//
//    cout << "Should print 4 elements: " <<endl;
//    cout << "The list has " << Numbers.getLength() <<" elements."<<endl;
//
//    Numbers.beginIterator();
//    cout << "Iterator is pointing at the first node now; Index " << Numbers.getIndex() << endl;
//    cout << "Linear Search - Should print index 3: " <<  Numbers.linearSearch(27) << endl;
//    cout << "Linear Search - Should print index -1: " <<  Numbers.linearSearch(55) << endl;
//
//    List<int> NumbersCopy(Numbers);
//	cout << "\nShould print 39 42 27 38: ";
//	NumbersCopy.print();
//
//	cout << "Should print lists are equal: ";
//	if (Numbers == NumbersCopy)
//		cout << "Lists are equal" << endl;
//	else
//		cout << "Lists are not equal" << endl;
//
//	cout << "Should print iterator is off end: ";
//	if(NumbersCopy.offEnd())
//		cout <<"Iterator is off end!" << endl;
//	else
//		cout <<"Iterator is not off end!" << endl;
//
//	cout<< "~~~The following 3 functions will trigger assertion, comment out after testing" << endl;
////	cout << Numbers.binarySearch(99) << endl;
////	NumbersCopy.getIterator();
////	NumbersCopy.deleteIterator();
//
//	cout << "Should print the list with numbers: "<<endl;
//	NumbersCopy.printNumberedList();
//
//	NumbersCopy.beginIterator();
//	NumbersCopy.advanceIterator();
//	NumbersCopy.insertIterator(100);
//	cout<<"Should print that 100 is on the 3rd element" << endl;
//	NumbersCopy.printNumberedList();
//	cout << "Should print first and last element, 39 and 38: "<< NumbersCopy.getBegin()<< " " <<NumbersCopy.getEnd() <<endl;
//
//
//	List<int> NN;
//	cout <<"Should trigger assertion, comment out after testing."<<endl;
////	NN.getIndex();
////	NN.advanceToIndex(2);
////	NN.linearSearch(12);
//
//	cout << "Should print empty list (reverse): " << endl;
//	NN.printReverse();
//	for (int i = 110; i < 151; i+=10){
//		NN.insertEnd(i);
//	}
//
//	cout << "Should print 110 120 130 140 150 (numbered) " << endl;
//	NN.printNumberedList();
//	cout << "Should print its reverse without numbers " << endl;
//	NN.printReverse();
//	cout << endl;
//	cout << "Should show that list is sorted: " << endl;
//
//	if (NN.isSorted()) {
//		cout << "List is sorted!" << endl;
//	} else {
//		cout << "The list is not sorted" << endl;
//	}
//
//	NN.advanceToIndex(1);
//	cout << "Should print index 1 and value 110: " << NN.getIndex() << " " << NN.getIterator() << endl;
//	cout << "Iterator is currently pointing at index " << NN.getIndex() << endl;
//	NN.advanceToIndex(5);
//	cout << "Should print index 5 and value 150: " << NN.getIndex() << " " << NN.getIterator() << endl;
//	cout << "Iterator is currently pointing at index " << NN.getIndex() << endl;
//	cout << "~*~*~Index that does not exist. Should trigger assertion, comment out after testing." << endl;
//	//NN.advanceToIndex(15);
//
//	cout <<"\n\n\nShould show that index stays at #5 from above and did not change after each Search algorithm used"<<endl;
//	cout << "\nBinary Search - Should print index -1 (not found): " <<  NN.binarySearch(55) << endl;
//	cout << "Iterator is currently pointing at index " << NN.getIndex() << endl;
//	cout << "Binary Search - Should print index 4: " <<  NN.binarySearch(140) << endl;
//	cout << "Iterator is currently pointing at index " << NN.getIndex() << endl;
//	cout << "Binary Search - Should print index 2: " <<  NN.binarySearch(120) << endl;
//	cout << "Iterator is currently pointing at index " << NN.getIndex() << endl;
//	cout << "Linear Search - Should print index 3: " <<  NN.binarySearch(130) << endl;
//	cout << "Iterator is currently pointing at index " << NN.getIndex() << endl;
//	cout << "Linear Search - Should print index -1 (not found): " <<  NN.binarySearch(1110) << endl;
//	cout << "Iterator is currently pointing at index " << NN.getIndex() << endl;
//
//	cout << "\nThank you for using my program, goodbye!" << endl;
//}




