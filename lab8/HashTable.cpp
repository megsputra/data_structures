/**

 * Mega Putra

 * CIS 22C, Lab 8

 */

#include <iostream>
#include "HashTable.h"
#include <string>
#include <assert.h>
#include <iomanip>

using namespace std;

int HashTable::hash(string key)
{
	int sum = 0;
	for(int i = 0; i < key.length(); i++)
	{
		sum += (int)key[i];
	}
	return sum % SIZE;
}

int HashTable::countBucket(int index)
{
	assert(0 <= index && index < SIZE);
	return Table[index].getLength();
}

int HashTable::searchData(Book b)
{
    int bucket = hash(b.get_author() + b.get_title());
    if (Table[bucket].getLength() != 0)
    {
    	int index = Table[bucket].linearSearch(b);
    	if(index != -1)
    		return bucket;
    	else
    		return index;
    }
    else
    	return -1;
}

void HashTable::insertData(Book b)
{
   int hashKey = hash(b.get_title() + b.get_author());
   assert(0 <= hashKey && hashKey < SIZE);
   Table[hashKey].insertEnd(b);
}

void HashTable::removeData(Book b)
{
	int bucket = hash(b.get_title() + b.get_author());
	int valueFound = Table[bucket].linearSearch(b);
	assert(valueFound != -1);
	Table[bucket].advanceToIndex(valueFound);
	Table[bucket].deleteIterator();
}

void HashTable::printBucket(int index)
{
	assert(index >= 0 and index < SIZE);
	cout << "Printing index: " << index << endl << endl;
	Table[index].print();
}

void HashTable:: printTable()
{
	for(int i = 0; i < SIZE; i++)
	{
		cout << "<----------------------->" << endl;
		cout << "Bucket: " << i << endl;
		if(!Table[i].empty())
		{
			Book B = Table[i].getBegin();
			cout << B.get_title() << " by " << B.get_author() << endl;
			cout << "$" << B.get_price() <<endl;
			cout << "ISBN: "<<B.get_isbn() <<endl;
		}
		cout << "Number of books at this bucket: " << countBucket(i) << endl;
		cout << "<----------------------->" << endl << endl;
	}
}
