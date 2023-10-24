// Jordan Scott 
// CST-201
// Double link list
#include <iostream> 
using namespace std;
#include "DLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>
string cleanUp(string str);

int main() {

	DLinkedList<string> lst1;
	DLinkedList<string> lst2;

	ifstream fin("/Users/bignola/Library/Mobile Documents/com~apple~TextEdit/Documents/bob.txt");

	string str;

	while (fin>>str) 
    {		
		str = cleanUp(str);
		lst1.insertOrderUnique(str);
	}
	fin.close();

	fin.open("/Users/bignola/Library/Mobile Documents/com~apple~TextEdit/Documents/bob2.txt");
	while (fin>>str) {
		str = cleanUp(str);
		lst2.insertOrderUnique(str);
	}

	cout << "List 1: " << lst1 << endl;
	cout << "List 2: " << lst2 << endl;
	

	DLinkedList<string> combined = lst1.merge(lst2);

	cout << "\nAFTER MERGE" << endl;
	cout << "List 1: " << lst1 << endl;
	cout << "List 2: " << lst2 << endl;
	cout << "\nCombined: " << combined << endl;


	return 0;
}

/**
* ASSIGNED
* @param str
* @return str in all lower case with LEADING and TRAILING non-alpha
* chars removed
*/
string cleanUp(string str) // O(n)
{
    //use regualr expression 
	str = regex_replace(str, regex("[^a-zA-Z0-9']"), "");
	return str;
}