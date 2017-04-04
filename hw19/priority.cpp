#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int state[4];
	Node(int i, int j, int k, int l){
		state[0]=i;
		state[1]=j;
		state[2]=k;
		state[3]=l;

	}
	void print(ostream &os) const {
		os << state[0] << " " << state[1] << " " << state[2] << " " << state[3];
	}

};
	ostream &operator<<(ostream &os, const Node &n){
		n.print(os);
		return os;
	}


class Compare {
public:
	bool operator()(const Node &a, const Node &b) const {
		return (a.state[3] > b.state[3]);
	}
};




int main(){
	priority_queue <Node, vector <Node>, Compare> pq;
	Node start(0,7,4,0);
	pq.push(start);
	Node next1(7,0,4,7);
	Node next2(4,7,0,4);
	pq.push(next1);
	pq.push(next2);
	Node currentnode=pq.top();
	cout<< currentnode <<endl;


}