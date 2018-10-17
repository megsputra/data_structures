/**

* Mega Putra

* CIS 22C, Lab 2

*/

#include "List.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

    List<string> Food;
    List<int> Numbers;

    Food.insertBegin("butter");
    Food.insertEnd("lentils");
    Food.insertEnd("papaya");
    Food.beginIterator();
    cout << "Should print butter: ";
    cout << "We put *" << Food.getIterator() << "* on our toast." << endl;

    Food.deleteEnd();
    Food.deleteBegin();
    Food.deleteBegin();
    cout << "Should print empty list and that List is empty: " ;
    Food.print();
    if (Food.empty())
            cout << "List is empty" << endl;
        else
            cout << "List is not empty" << endl;

    cout << "~~~The following 4 functions will trigger assertion, comment out after testing" << endl;
    Food.deleteBegin();
    Food.deleteEnd();
    Food.getBegin();
    Food.getEnd();

    Numbers.insertBegin(39);
    Numbers.insertEnd(15);
    Numbers.insertEnd(42);
    Numbers.insertEnd(27);
    Numbers.insertEnd(38);

    Numbers.beginIterator();
    Numbers.advanceIterator();
    Numbers.advanceIterator();
    Numbers.reverseIterator();
    Numbers.deleteIterator();
    cout << "should print 39 42 27 38: ";
    Numbers.print();
    cout << "Should print 4 elems: " <<endl;
    cout << "The list has " << Numbers.getLength() <<" elements."<<endl;

    List<int> NumbersCopy(Numbers);
    cout << "Should print 39 42 27 38: ";
    NumbersCopy.print();

    cout << "Should print lists are equal: ";
    if (Numbers == NumbersCopy)
        cout << "Lists are equal" << endl;
    else
        cout << "Lists are not equal" << endl;

    cout << "Should print iterator is off end: ";
    if(NumbersCopy.offEnd())
        cout <<"Iterator is off end!\n" << endl;
    else
        cout <<"Iterator is not off end!\n" << endl;

    cout<< "~~~The following 2 functions will trigger assertion, comment out after testing" << endl;
    NumbersCopy.getIterator();
    NumbersCopy.deleteIterator();

    cout << "Should print the list with numbers: "<<endl;
    NumbersCopy.printNumberedList();

    NumbersCopy.beginIterator();
    NumbersCopy.advanceIterator();
    NumbersCopy.insertIterator(100);
    cout<<"Should print that 100 is on the 3rd element" << endl;
    NumbersCopy.printNumberedList();
    cout << "Should print first and last element, 39 and 38: "<< NumbersCopy.getBegin()<< " " <<NumbersCopy.getEnd() <<endl;
    cout << "Thank you for using my program, goodbye!" << endl;

}
/* PROGRAM OUTPUT - PLEASE NOTE: functions that trigger assertion is commented out on this output, therefore they won't appear.
 *
 *
 * Should print butter: We put *butter* on our toast.
Should print empty list and that List is empty:
List is empty
~~~The following 4 functions will trigger assertion, comment out after testing
should print 39 42 27 38: 39 42 27 38
Should print 4 elems:
The list has 4 elements.
Should print 39 42 27 38: 39 42 27 38
Should print lists are equal: Lists are equal
Should print iterator is off end: Iterator is off end!

~~~The following 2 functions will trigger assertion, comment out after testing
Should print the list with numbers:
1. 39
2. 42
3. 27
4. 38

Should print that 100 is on the 3rd element
1. 39
2. 42
3. 100
4. 27
5. 38

Should print first and last element, 39 and 38: 39 38
Thank you for using my program, goodbye!*/
 */
