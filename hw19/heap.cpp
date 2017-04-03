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
	int delmin();

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
	for(int i=yoindex;i>1;i=i/2){
		if(yovector[parent(i)]>value){
			int tmp=yovector[parent(i)];
			yovector[parent(i)]=value;
			yovector[i]=tmp;
		}
	}
}

int Heap::delmin(){
	int hatam=yovector[1];
	int aantim=yovector[yovector.size()-1];
	int yoindex=parent(yovector.size()-1);
	//cout<<"Yoindex"<<yoindex<<endl;

	//cout<<"aantim"<<aantim<<endl;
	yovector.pop_back();
	yovector[1]=aantim;
	aantim=yovector[yovector.size()-1];

	//cout<<"aantim"<<aantim<<endl;
	
	for(int i=1;i<=yoindex;i=i*2){
		if (parent(i)!=0){
			if(yovector[parent(i)]>yovector[i]){
			int tmp=yovector[parent(i)];
			yovector[parent(i)]=yovector[i];
			yovector[i]=tmp;
		}

		}

	}

return hatam;

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
	h.insert(6);
	h.insert(100);
	h.insert(3);
	h.insert(-1);



	h.print();
	cout<<h.delmin()<<endl;
	cout<<h.delmin()<<endl;
	cout<<h.delmin()<<endl;
	cout<<h.delmin()<<endl;
	cout<<h.delmin()<<endl;
	cout<<h.delmin()<<endl;
	cout<<h.delmin()<<endl;

	h.print();


}