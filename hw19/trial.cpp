#include <iostream>
#include <vector>
#include<map>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

int capacity[] = {10,7,4};
//map < Node, int> dist;

struct Node {
	int state[4];

	Node(int i, int j, int k, int t) {
		state[0] = i;
		state[1] = j;
		state[2] = k; 
		state[3]=t;
	}

	bool operator==(const Node&n) const {
		return (state[0] == n.state[0] &&
		state[1] == n.state[1] &&
		state[2] == n.state[2]&&
		state[3]==n.state[3]);
	}
	vector <Node> neighbors() const;
	void print(ostream &os) const {
		os << state[0] << " " << state[1] << " " << state[2]<<" "<<state[3];
	}
	void dijikstra(const Node &n);
};

ostream &operator<<(ostream &os, const Node &n) {
	n.print(os);
	return os;
}


vector <Node> Node::neighbors() const {
	vector <Node> result;
	for (int from = 0; from < 3; ++from) {
		for (int to=0; to < 3; ++to) {
			int howMuch = state[from];
			if (howMuch + state[to] > capacity[to]) {
				howMuch = capacity[to] - state[to];
			}
			if (howMuch > 0) {
				Node n(*this);
				n.state[to] += howMuch;
				n.state[from] -= howMuch;
				n.state[3]=howMuch;
				result.push_back(n);
			}
		}
	}
	return result;
}

vector <Node> thingsIveSeen;
bool haveIseen(const Node &n) {
	for (int i=0, i_end = thingsIveSeen.size(); i < i_end; ++i) {
		if (n==thingsIveSeen[i]) {
			return true;
		}
	}
	return false;
}

string spaces(int n) {
	string result;
	for (int i=0; i < n; ++i) {
		result += " ";
	}
	return result;
}

bool isGoal(const Node &n);
vector<Node> lnodes; vector<int> dist;

void explore(const Node &n) {
	int counter=0;

	thingsIveSeen.push_back(n);
	queue<Node> Q;
	Q.push(n);
	while(!Q.empty()){

		Node yonode=Q.front();
		cout<<yonode<<endl;
		Q.pop();

		if (isGoal(yonode)) {
			cout << "Yes! Found it after "<<counter<< " traversals" << endl;
		return;
	}
	vector <Node> nbr = yonode.neighbors();
			for (int i=0, i_end = nbr.size(); i < i_end; ++i) {
			if (!haveIseen(nbr[i])) {
				Q.push(nbr[i]);
				thingsIveSeen.push_back(nbr[i]);
				counter++;
			}
			
		}
	}

}

void dijikstra(const Node& n){
	cout<<"Ok Coming here"<<endl;
}



bool isGoal(const Node &n) {
	return (n.state[1] == 2 || n.state[2] == 2);
}

int main(int argc, char const *argv[])
{
	Node start(0,7,4,0);
	explore(start);

	//cout<<"The number of moves that were necessary were "<<thingsIveSeen.size()-2<<endl;
}