#include <iostream>
using namespace std;


class PQ {
	int *arr;
	int TOP;
	int SIZE;
public:
	PQ(int size);
	void insert(int val);
	void delete_max();
	void print();
};

PQ::PQ(int size) {
	arr = new int [size];
	TOP = -1;
	SIZE = size - 1;
}

void PQ::print() {
	cout << "The current priority queue is: ";
	for (int i=0; i <= TOP; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void PQ::insert(int val) {
	if (TOP == SIZE) {
		cout << "Priority queue is full!" << endl;
		return;
	}
	++TOP;
	arr[TOP] = val;
	cout << val << " has been inserted" << endl;
}

void PQ::delete_max() {
	int index = 0;
	for (int i=0; i <= TOP; ++i) {
		if (arr[i] > arr[index]) {
			index = i;
		}
	}
	int max = arr[index];
	cout << max << " has been deleted!" << endl;

	for (int i=index; i <= TOP; ++i) {
		arr[i] = arr[i+1];
	}
	arr[TOP] = max;
	--TOP;

}

int main() {
	PQ q(5);
	q.insert(1);
	q.insert(3);
	q.insert(10);
	q.insert(9);
	q.print();
	q.delete_max();
	q.print();
	q.insert(2);
	q.insert(4);
	q.print();
	q.delete_max();
	q.print();
}