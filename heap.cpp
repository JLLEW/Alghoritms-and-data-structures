#include <vector>
#include <iostream>
#include <cstdio>



using namespace std;

class heap {
public:
	vector <int> A;
	int sCounter;
	void add(int i) {
		A.push_back(i);
		if ((sCounter / 2) * 2 == sCounter)
			buildMaxHeap();
		else
			buildMinHeap();
	}

	void heapifyMax(int i, int heapsize) {
		int left, right, max;

		if (i > 0) {
			left = 2 * i + 1;
			right = 2 * i + 2;
		}
		else {
			left = 1;
			right = 2;
		}

		if (left < heapsize && A[left] > A[i])
			max = left;
		else
			max = i;
		if (right < heapsize && A[right] > A[max])
			max = right;
		if (max != i) {
			int temp = A[i];
			A[i] = A[max];
			A[max] = temp;
			heapifyMax(max, heapsize);
		}
	}

	void heapifyMin(int i, int heapsize) {
		int left, right, min;

		if (i > 0) {
			left = 2 * i + 1;
			right = 2 * i + 2;
		}
		else {
			left = 1;
			right = 2;
		}

		if (left < heapsize && A[left] < A[i])
			min = left;
		else
			min = i;
		if (right < heapsize && A[right] < A[min])
			min = right;
		if (min != i) {
			int temp = A[i];
			A[i] = A[min];
			A[min] = temp;
			heapifyMin(min, heapsize);
		}
	}
	
	void buildMinHeap() {
		int heapsize = A.size();
		for (int i = A.size() / 2 - 1; i >= 0; i--)
			heapifyMin(i, heapsize);
	}

	void buildMaxHeap() {
		int heapsize = A.size();
		for (int i = A.size()/2 - 1 ; i >= 0; i--)
			heapifyMax(i, heapsize);
	}

	void popMax() {
		cout << A[0] << endl;
		A[0] = A[A.size() - 1];
		A.pop_back();
		if ((sCounter / 2) * 2 == sCounter)
			buildMaxHeap();
		else
			buildMinHeap();
	}

	void popAll() {
		while (A.size() != 0) {
			A.pop_back();
		}
	}

	void newHeap(int arr[], int size) {
		for (int i = 0; i < size; i++)
			A.push_back(arr[i]);
		if ((sCounter / 2) * 2 == sCounter)
			buildMaxHeap();
		else
			buildMinHeap();
	}

	void print() {
		for (int i = 0; i < A.size(); i++)
			cout << A[i] << " ";
		cout << endl;
	}


	

};

int main() {
	heap h;
	int action, value, quit = 1, seqLength;
	int *seq;
	h.sCounter = 0;



	do {
		action = getchar();
		switch (action) {
		case '+':
			scanf_s("%d", &value);
			h.add(value);
			break;
		case '-':
			h.popMax();
			break;
		case 'p':
			h.print();
			break;
		case 's':
			h.sCounter++;
			if ((h.sCounter / 2) * 2 == h.sCounter)
				h.buildMaxHeap();
			else
				h.buildMinHeap();
			break;
		case 'r':
			h.popAll();
			scanf_s("%d", &seqLength);
			seq = (int*)malloc(sizeof(int)*seqLength);
			for (int i = 0; i < seqLength; i++)
				scanf_s("%d", &seq[i]);
			h.newHeap(seq, seqLength);
			break;
		case 'q':
			quit = 0;
			break;
		}
	} while (quit);
	return 0;
}