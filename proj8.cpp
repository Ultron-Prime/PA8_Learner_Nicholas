/* -------------------------------------------------
FILE:           proj8.cpp
DESCRIPTION:    proj8 C++ file for Project 8 for Fall 2019 CS 202-1001 at UNR
COMPILER:       g++ compiler
NOTES:

MODIFICATION HISTORY:
Author              Date        Version
----------------    --------    -------
Version 1           YYYY-MM-DD  x.x Description
Nick Learner        2019-11-10  1.0 Created this file
Nick Learner        2019-11-13  1.1 Implemented tests for Arraylist and NodeList
*/

#include "ArrayList.h"
#include "NodeList.h"

using namespace std;

int main()
{
	DataType data[10];
	
	for (size_t i = 0; i < 10; ++i)
	{
		data[i].setIntVal((int)i);
		data[i].setDoubleVal(-1.1 * (double)i);
		//cout << data[i] << endl;
	}
	
	ArrayList arr1;
	NodeList n1;
	cout << "Testing ArrayList << and dflt ctor" << endl;
	cout << arr1;
	cout << "Testing NodeList << and dflt ctor" << endl;
	cout << n1 << endl;
	
	ArrayList arr2(7, data[4]);
	NodeList n2(9, data[2]);
	cout << "Testing ArrayList << and para ctor" << endl;
	cout << arr2;
	cout << "Testing NodeList << and para ctor" << endl;
	cout << n2;
	
	ArrayList arr3(arr2);
	cout << "Testing ArrayList << and copy ctor" << endl;
	cout << arr3;
	NodeList n3 = n2;
	cout << "Testing NodeList << and copy ctor" << endl;
	cout << n3;
	
	cout << "Testing ArrayList insertAfter()" << endl;
	arr3.insertAfter(data[4], data[5]);
	cout << arr3 << endl;
	
	cout << "Testing NodeList insertAfter()" << endl;
	n3.insertAfter(data[2], data[9]);
	cout << n3 << endl;
	
	return 0;
}
