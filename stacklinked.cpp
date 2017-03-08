#include<iostream>
using namespace std;
#include "elapsed_time.h"

struct Node{
	int x;
	Node* ptr;

};


class stack{
	Node* upper;
	Node* root;
public:
	stack();
	void push(int val);
	bool isempty();
	//bool isfull();
	//print();
	void pop();
	void print();
	//~stack();

};


stack::stack(){
	root=new Node;
	root->x=0;
	root->ptr=NULL;
	/*
	for(int i=0;i<size;i++){
		
		node--;
		node->ptr=node;
		node->x=0;
		cout<<"Ptr value::"<<node->ptr<<endl;
		
	}
	*/
	
	//cout<<"Upper's node is"<<root<<endl;
}

bool stack::isempty(){
	if(upper->x==0){
		return true;
	}else{
		return false;
	}
}


void stack::push(int val){
	upper=new Node;
	upper->x=val;
	upper->ptr=root;
	root=upper;
	//cout<<"Current's address::"<<upper<<endl;

}

void stack::print(){
	cout<<"Values in stack are::"<<endl;

	while(upper->ptr!=NULL){
		cout<<upper->x<<endl;
		upper--;
	}
}

/*stack::~stack(){
	delete upper;
	delete root;
}
*/




int main(){
	stack s;
	start_timer();
	for(int i=0;i<1000;i++){
		s.push(i);

	}
	double cycles=elapsed_time();
	cout<<"Cycles taken for a push in Linked List"<<cycles<<endl;
	s.push(6);
	s.print();
	//s.print();

}

