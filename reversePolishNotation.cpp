#include <iostream>
#include <string>
using namespace std;



struct element {
	element *previous;
	int value;
};

class myStack1 {

private:
	element *top;

public:
	myStack1() {
		top = NULL;
	}
	~myStack1() {
		while (!isEmpty())
			pop();
	}
	void push(int value) {
		element* current = new element;
		current->previous = top;
		current->value = value;
		top = current;
	}
	
	int topV() {
		if (!isEmpty())
			return top->value;
		else {
			cout << "stack empty nothing on top ";
			return 0;
		}
	}

	void pop() {
		if (!isEmpty()) {
			element *topToPop = top;
			top = topToPop->previous;
			delete topToPop;
		}
		else {
			cout << "stack empty nothing to pop";
		}
	}

	int isEmpty() {
		return (top == NULL);
	}
};

char RPN(string s) {
	myStack1 myStack;
	int o1, o2;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 't')
			myStack.push(1);
		else if (s[i] == 'f')
			myStack.push(0);
		else if (s[i] == 'K') {
			o1 = myStack.topV();
			myStack.pop();
			o2 = myStack.topV();
			myStack.pop();
			myStack.push(o1 & o2);
		}
		else if (s[i] == 'A') {
			o1 = myStack.topV();
			myStack.pop();
			o2 = myStack.topV();
			myStack.pop();
			myStack.push(o1 | o2);
		}
		else if (s[i] == 'N') {
			o1 = myStack.topV();
			myStack.pop();
			myStack.push(!o1);
		}
	}

	return (myStack.topV()) ? 't' : 'f';
}
int main() {
	string s;
	int i;
	cin >> i;
	for(i; i>0; i--) {
		cin >> s;
		cout << RPN(s) << endl;
	}
	
	return 0;
}