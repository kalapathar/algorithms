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
	int leftchild(int l);
	int rightchild(int r);
	void minheap(int index);
	int minchild(int pindex);
	int minchildindex(int pindex);

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
	yovector.pop_back();
	yovector[1]=aantim;

/*	
	aantim=yovector[yovector.size()-1];
	for(int i=1;i<=yoindex;i=i*2){
		if (parent(i)!=0){
			if(yovector[parent(i)]>yovector[i]){
			int tmp=yovector[parent(i)];
			yovector[parent(i)]=yovector[i];
			yovector[i]=tmp;
		}

		}

	}
	*/
	minheap(1);

return hatam;

}
void  Heap::minheap(int index ){
	int left=leftchild(index);
	int right=rightchild(index);
	int least;
	int size=yovector.size();
	if (left<=size and yovector[left]<yovector[index]){
		least=left;
	}else {
		least=index;
	}
	if (right<=size and yovector[right]<yovector[least]) least=right;

	if (least!=index){
		int temp=yovector[index];
		yovector[index]=yovector[least];
		yovector[least]=temp;
		minheap(least);
	}


}

int Heap::minchildindex(int pindex){
	if (leftchild(pindex)>rightchild(pindex)) return leftchild(pindex);
	return rightchild(pindex);
}

int Heap::leftchild(int lindex){
	return 2*lindex;

}

int Heap::rightchild(int rindex){
	return 2*rindex+1;

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
	//h.print();
	h.delmin();
	h.print();

	
}