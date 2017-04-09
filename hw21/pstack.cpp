#include<iostream>
#include<stack>
using namespace std;

ostream &operator<<(ostream &os,stack<int> s ){
	while(!s.empty()){
		os<<s.top();
		s.pop();
	}
	return (os);
}


int main(){
	stack<int> stack1;
	stack1.push(5);
	stack1.push(4);
	cout<<stack1;

	
}