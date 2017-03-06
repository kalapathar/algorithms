#include<iostream>
using namespace std;
#include <time.h>

int* sort(int* m, int length) {
	int tmp;
	for (int i=0; i < length-1; ++i) {
		for (int j=i+1; j < length; ++j)
			if (m[i] > m[j]) {
				tmp = m[i];
				m[i] = m[j];
				m[j] = tmp;
			}
	}
	return m;

}


//without recursion

int binarysearch(int* m, int value, int left, int right){
	while(left<=right){
		if(value<m[left] or value>m[right] ){
			return -1;
		}

		int middle=(left+right)/2;
		if(m[middle]==value){
			return middle;
		}else if(m[middle]>value){
			right=middle-1;
		}else {
			left=middle+1;
		}
		
	}


}

//using recursion
int binarysearch1(int* m, int value, int left, int right){
	int middle=(left+right)/2;
	if(value<m[left] or value>m[right]){
		return -1;
	}
	if(m[middle]==value){
		return middle;
	}else if(m[middle]>value){
		binarysearch1(m, value, left, middle-1);
	}else{
		binarysearch1(m, value,middle+1, right);
	}


}





int main(){
	int *p;
	srand(time(0));
	int length=rand()% 10;
	p=new int[length];
	for(int i=0;i<length;i++){
		p[i]=rand()%1000;
		
	}


	p=sort(p,length);

	cout<<"These are the numbers in the array"<<endl;
	for(int i=0;i<length;i++){
		cout<<p[i]<<endl;
	}
	int find;
	cout<<"What number do you want to search for?"<<endl;
	cin>>find;
	int k=binarysearch1(p,find,0, length-1);
	
    if(k==-1){
		cout<<"Value not found in the array"<<endl;
	}else {
		cout<<"The index from recursion binary search  is:: "<<k<<endl;

	}
	int b=binarysearch(p, find, 0, length-1);
	
	if(b==-1){
		cout<<"Value not found in the array"<<endl;
	}else {
		cout<<"The index from loop-binary search  is:: "<<b<<endl;

	}
	

	




}