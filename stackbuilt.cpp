#include <iostream>
using namespace std;

class Stack {
	int *arr;
	int upper;
	int max;
public:
	Stack(int size);
	void push(int val);
	void pop();
	bool isEmpty();
	bool isFull();
	void print();
};

Stack::Stack(int size) {
	upper = -1;
	max= size - 1;             
	arr = new int [size];
}

bool Stack::isEmpty() {
	if (upper == -1)
		return true;
	else 
		return false;
}

bool Stack::isFull() {
	if (upper == max)
		return true;
	else 
		return false;
}

void Stack::push(int val) {
	if (isFull()) {
		cout << "Stack is full" << endl;
		return;
	} else {
		++upper;
		arr[upper] = val;
	}
	cout << val << " has been pushed!" << endl;
}

void Stack::pop() {
	int tmp;
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
		return;
	} else {
		tmp = arr[upper];
		--upper;
	}
	cout << tmp << " has been deleted!" << endl;
}

void Stack::print() {
	cout << "The current stack is: ";
	for (int i=upper; i>=0; --i)
		cout << arr[i] << " ";
	cout << endl;
}


int main() {
	Stack f(50);
	for(int i=0; i<50;i++){
		f.push(i+20);
	}
	f.print();
    f.push(60);
	f.pop();
	f.print();
	f.pop();
	f.print();
}