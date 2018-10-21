#include <iostream>
#include <string>
using namespace std;

class trieTree {
	struct node {
		node* array[26];
		bool isWord;
		string translation;
	};

	node* head;
public:

	trieTree() {
		head = getNode();
	}



	node* getNode() {
		node* temp = new node;
		temp->isWord = false;
		temp->translation = "";

		for (int i = 0; i < 26; i++)
			temp->array[i] = nullptr;
		return temp;
	}

	void insert(string s, string trans) {
		node* temp = head;
		for (int i = 0; i < s.length() - 1; i++) {
			if (temp->array[s[i] - 'a'] == nullptr)
				temp->array[s[i] - 'a'] = getNode();
			temp = temp->array[s[i] - 'a'];
		}
		if (temp->array[s[s.length() - 1] - 'a'] == nullptr)
			temp->array[s[s.length() - 1] - 'a'] = getNode();
		temp->array[s[s.length() - 1] - 'a']->isWord = true;
		temp->array[s[s.length() - 1] - 'a']->translation = trans;
	}

	void find(string s) {
		node* temp = head;
		for (int i = 0; i < s.length() - 1; i++) {
			if (temp->array[s[i] - 'a'] == nullptr) {
				cout << "-" << endl;
				return;
			}	
			temp = temp->array[s[i] - 'a'];
		}
		if (temp->array[s[s.length() - 1] - 'a'] != nullptr && temp->array[s[s.length() - 1] - 'a']->translation != "")
			cout << temp->array[s[s.length() - 1] - 'a']->translation << endl;
		else
			cout << "-" << endl;
		return;
	}

	void findByPrefix(string prefix) {
		node* temp = head;
		for (int i = 0; i < prefix.length(); i++) {
			if (temp->array[prefix[i] - 'a'] == nullptr) {
				cout << "-" << endl;
				return;
			}
			temp = temp->array[prefix[i] - 'a'];
		}
		
		findWordsInArray(temp);
	}

	void findWordsInArray(node* head) {
		
		if (head->isWord)
			cout << head->translation << endl;

		for (int i = 0; i < 26; i++) {
			if (head->array[i] != nullptr)
				findWordsInArray(head->array[i]);
		}
		
	}


};

int main() {
	trieTree t;
	char command;
	string word;
	string translation;


	while (cin >> command) {
		switch (command) {
		case '+':
			cin >> word;
			cin >> translation;
			t.insert(word, translation);
			break;
		case '?':
			cin >> word;
			t.find(word);
			break;
		case '*':
			cin >> word;
			t.findByPrefix(word);
			break;
		default:
			break;

		}


	}

	return 0;
}