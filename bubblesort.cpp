#include <iostream>
#include "elapsed_time.h"
using namespace std;

void sort(int arr[], int length) {
	int tmp;
	for (int i=0; i < length-1; ++i) {
		for (int j=i+1; j < length; ++j)
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
	}
	for (int i=0; i < length; ++i) {
		cout << arr[i] <<  " ";
	}
}

int main() {
	start_timer();
	int arr[] = {1,0,5,6,3,2};
	int len = 6;
	sort(arr,len);
	cout  << endl;
	double cycles = elapsed_time();
	cout << "Total cycles: " << cycles << endl;
}