/**

 * Mega Putra

 * CIS 22C, Lab 8

 */
#include <iostream>
#include "HashTable.h"
#include "Book.h"

using namespace std;

int main()
{
	/*Note to Instructor: endl is added before every printTable() and printBucket(), for readability*/
	/* Output formatting of <----> are not changed since it is acceptable */

	HashTable ht;
	Book pp("Pride and Prejudice", "Jane Austen", 1234567, 4.95);
	Book c("Contact", "Carl Sagan", 99993339, 9.95);
	Book hg("The Hunger Games", "Suzanne Collins", 12388888, 13.55);
	Book hp("Harry Potter", "J.K. Rowlings", 55555678, 12.99);
	Book mhc("The Man in the High Castle", "Philip K Dick", 95959595, 15.95);
	Book bh("Bleak House", "Charles Dickens", 473890238, 8.00);

	ht.insertData(pp);
	ht.insertData(c);
	ht.insertData(hg);
	ht.insertData(mhc);
	ht.insertData(bh);

	cout << "Should print contents of the HT: " << endl;
	ht.printTable();
	cout << "Printing bucket#9. Should print \"hg\" and \"mhc\": " <<endl;
	ht.printBucket(9);

	cout <<"\"mhc\" removed"<<endl;
	int found = ht.searchData(mhc);
	cout << "Should print The Man in the High Castle is found at bucket#9: " << found << endl;
	found = ht.searchData(pp);
	cout << "Should print Pride and Prejudice is found at bucket#2: " << found << endl;
	found = ht.searchData(bh);
	cout << "Should print Bleak House is found at bucket #0: " << found << endl;

	ht.removeData(mhc);
	cout <<"Now it should only print one book at bucket #9: "<<endl;
	ht.printBucket(9);

	Book afk("Away from Keyboard", "Landon Mack", 982618299, 9.99);
	found = ht.searchData(afk);
	cout << "Should print that this \"afk\" book is not found(-1): " << found << endl;
	found = ht.searchData(mhc);
	cout << "Should print that this \"mhc\" book is not found(-1): " << found << endl;
	cout <<"Removing \"c\"" << endl; ht.removeData(c);
	cout << "Should print the contents of table with Bucket 4 being empty, and Bucket 9 with only one book: " <<endl;
	ht.printTable();

	int num = ht.countBucket(1);
	cout << "Should print num of Books in bucket#1 is 0: " << num << endl;
	num = ht.countBucket(4);
	cout << "Should print num of Books in bucket#4 is 0: " << num << endl;
	num = ht.countBucket(2);
	cout << "Should print num of Books in bucket#5 is 1: " << num << endl;
	cout << "\nThank you for using my program, goodbye!";
}
