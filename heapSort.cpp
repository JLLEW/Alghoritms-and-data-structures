#include <string>
#include <iostream>
using namespace std;

bool ifBigger(string s1, string s2) {
	if (s1.length() > s2.length())
		return true;
	else if (s1.length() < s2.length())
		return false;
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] > s2[i])
				return true;
			if (s1[i] < s2[i])
				return false;
		}
	}
			return false;
}

void heapify(string A[], int i, int heapsize) {
	int left, right, max;
	max = i;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < heapsize && ifBigger(A[left], A[max]))
		max = left;
	if (right < heapsize && ifBigger(A[right], A[max]))
		max = right;
	if (max != i) {
		string temp = A[i];
		A[i] = A[max];
		A[max] = temp;
		heapify(A, max, heapsize);
	}
}

void heapsort(string A[], int heapsize){
	int n = heapsize;
	int k = n / 2 - 1;
	for (int i = k; i >= 0; i--) { //max heap
		heapify(A, i, n);
	}
	for (int i = heapsize - 1; i >= 0; i--) {
		string temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		heapify(A, 0, i);
	}
}


int main() {
	int size;
	cin >> size;
	string *arr = new string[size];
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	heapsort(arr, size);
	/*for (int i = 0; i < size - 1; i++)
		cout << arr[i] << endl;
	cout << arr[size - 1];*/
	for (int i = 0; i < size; i++)
		printf("%s\n", arr[i].c_str());
	return 0;
}