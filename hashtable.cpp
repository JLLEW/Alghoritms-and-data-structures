#include <string>
#include <iostream>
#include <list>

using namespace std;



class HashTable {

	struct node {
		int value;
		string name;
	};


	list<node> *table;
	int tableSize ;

public:

	HashTable() {
		tableSize = 100;
		table = new list<node>[tableSize];
	}


	void addValue(string a, string b, int value) {
		string name = a + " " + b;
		int stringSize = name.size();
		int hash = 0;
		int val = 7;
		for (int i = 0; i < stringSize; i++) {
			hash += (int)name[i] * val;
			val += 2;
		}
		hash = hash * 17;
		hash = hash % tableSize;
		bool added = false;

		for (list<node>::iterator iterator = table[hash].begin(), end = table[hash].end(); iterator != end; ++iterator) {
			if (iterator->name == name) {
				iterator->value += value;
				added = true;
			}
		}
		if (added == false) {
			node newNode;
			newNode.name = name;
			newNode.value = value;
			table[hash].push_front(newNode);
		}
	}

	int getValue(string a, string b) {
		string name = a + " " + b;
		int stringSize = name.size();
		int hash = 0;

		int val = 7;
		for (int i = 0; i < stringSize; i++) {
			hash += (int)name[i] * val;
			val += 2;
		}
		hash = hash * 17;
		hash = hash % tableSize;
		int value;
		bool found = false;
		for (list<node>::iterator iterator = table[hash].begin(), end = table[hash].end(); iterator != end; ++iterator) {
			if (iterator->name == name) {
				value = iterator->value;
				found = true;
			}
		}

		if (found)
			return value;
		else
			return 0;
	}

};


int main() {

	HashTable basicTable;
	char command;
	string a;
	string b;
	int value;
	int i = 0;
	while (cin >> command) {

		cin >> a;
		cin >> b;
		if (command == '+') {
			cin >> value;
			basicTable.addValue(a, b, value);
		}
		else if (command == '?') {
			cout << basicTable.getValue(a, b);
			cout << endl;
		}
		i++;

	}
	
	return 0;
}