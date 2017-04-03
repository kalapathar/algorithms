#include<iostream>
#include<vector>
using namespace std;



int parent(int index){
	return (index/2);
}

class Heap{
private:
	vector<int> yovector;
public:
	Heap(int size);
	void insert(int value);
	void print();

};


Heap::Heap(int size){
	yovector.push_back(size);
}

int index(vector<int> v, int value){
	for(int i=0;i<v.size();i++){
		if(v[i]==value) return i;
	}
return -1;

}

void Heap::insert(int value){
	yovector.push_back(value);
	int yoindex=index(yovector, value);
	cout<<"yoindex is"<<yoindex<<endl;
	for(int i=yoindex;i>1;i=i/2){
		if(yovector[parent(i)]>value){
			int tmp=yovector[parent(i)];
			yovector[parent(i)]=value;
			yovector[i]=tmp;
		}
	}
}

void Heap::print(){
	for(int i=1;i<yovector.size();i++){
		cout<<yovector[i]<<endl;
	}
}



int main(){
	Heap h(10);
	
	h.insert(7);
	h.insert(5);
	h.insert(8);
	h.insert(10);
	h.insert(6);
	h.insert(2);
	h.insert(-1);
	h.insert(0);

	h.print();


}