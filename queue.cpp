#include<iostream>
using namespace std;

class queue{
private:
	int bottom=-1;
	int max_size;
	int top=0;
	int *pointer;
public:
	queue(int size);
	void add_data(int n);
	int topmost();
	bool isfull();

};

queue::queue(int size){
	max_size=size;
	pointer=new int[size];
}

void queue::add_data(int n){
	if(!isfull()){
		pointer[++bottom]=n;
	}else{
		int * temp=pointer;
		pointer=new int[2*max_size];
		max_size=2*max_size;
		for(int i=0;i<max_size-1;i++){
			pointer[i]=temp[i];
		}
		
		
	}
	
	
}

int queue::topmost(){
	return pointer[top++];
}
bool queue::isfull(){
	if(bottom==max_size-1)return true;
}

int main(){
	queue q(5);
	q.add_data(3);
	q.add_data(5);
	q.add_data(7);
	q.add_data(9);
	q.add_data(32);
	q.add_data(45);
	cout<<q.topmost()<<endl;
	cout<<q.topmost()<<endl;
	cout<<q.topmost()<<endl;
	cout<<q.topmost()<<endl;
	cout<<q.topmost()<<endl;
	cout<<q.topmost()<<endl;
	


}