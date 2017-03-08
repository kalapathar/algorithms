#include<iostream>
using namespace std;
#include "elapsed_time.h"

class stack{
private:
	int *ptr;
	int max;
	int upper;
public:
	stack(int size);
	void push(int x);
	int pop();
	bool isempty();
	bool isfull();
	void print();
};

stack::stack(int size){
 upper=-1;
 max=size-1;
 ptr=new int[size];
}

bool stack::isempty(){
	if(upper==-1){
		return true;
	}else {
		return false;
	}
}

bool stack::isfull(){
	if(upper==max){
		return true;
	}else {
		return false;
	}

}


void stack::push(int x){
	if(isfull()){
		int *temp;
		temp=ptr;
		ptr=new int[101+upper];
		for(int i=0;i<=upper;i++){
			ptr[i]=temp[i];
		}
		max=100+upper;
		delete temp;

	}
		upper++;
		ptr[upper]=x;
		
	}


int stack::pop(){
	upper--;
	return ptr[upper+1];
	//upper--;
	//ptr--;
}
	
void stack::print(){
	cout<<"Values in stack are:: "<<endl;
	for(int i=0;i<=upper;i++){
		
		cout<<ptr[i]<<endl;
	}
}

int main(){
	stack s(1);
	start_timer();
	for(int i=0;i<1000;i++){
		s.push(i);

	}
	double cycles=elapsed_time();
	cout<<"Cycles taken for a push (100+Initial Stack) "<<cycles<<endl;
	
	s.push(8);
	s.pop();

	

	//cout<<"HERE"<<endl;
	s.print();


	//stack* pointer;
	//pointer=&s;
	//cout<<*pointer.print()<<endl;
	//stack *p;
	//p=new stack (4,5);
	//f.add(4,5);

}





























