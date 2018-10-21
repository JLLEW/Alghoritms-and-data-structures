#include <iostream>
using namespace std;
void bin(int n, int bits) {
	int* ptr;
	ptr = new int[bits];
	for (int i = bits - 1; i >= 0; i--) { //tworzenie binarnej
		ptr[i] = n % 2;
		n /= 2;
	}
	int flag = 0; // sprawdzenie czy jest palindromem
	for (int i = 0; i < bits; i++) {
		if (ptr[i] == ptr[bits - 1 - i])
			flag = 1;
		else {
			flag = 0;
			break;
		}
	}
	if (flag) { // wypisanie palindromu
		for (int i = 0; i < bits; i++) {
			cout << ptr[i];
		}
	}
	delete[] ptr;
}

int power(int number, int pow) {
	if (pow == 1) {
		return number;
	}
	return number * power(number, --pow);
}


void printAllBin(int number) {
	int max = power(2, number) - 1;
	for (int i = max; i >= 0; i--) {
		bin(i, number);
	}

}

int main() {
	int x;
	while (cin >> x) {
		printAllBin(x);
		cout << endl;
	}
	return 0;
}