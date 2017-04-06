#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include<bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

int capacity[] = {10,7,4};


struct Node {
	int state[4];

	Node(int i, int j, int k, int l) {
		state[0] = i;
		state[1] = j;
		state[2] = k;
		state[3] = l; 
		
	}

	bool operator==(const Node&n) const {
		return (state[0] == n.state[0] &&
		state[1] == n.state[1] &&
		state[2] == n.state[2] &&
		state[3] == n.state[3]);
	}
	vector <Node> neighbors() const;
	void print(ostream &os) const {
		os << state[0] << " " << state[1] << " " << state[2] << " " << state[3];
	}

	bool operator<(const Node&n) const {
		return (this->state[3] < n.state[3]);
	}
};


class Compare {
public:
	bool operator()(const Node &a, const Node &b) const {
		return (a.state[3] > b.state[3]);
	}
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
				n.state[3] = howMuch;
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

bool isGoal(const Node &n);

void conserve_water(Node src) {

	vector <Node> all_nodes;

	
	for (int i=0; i <= 10; ++i) {
		
		for (int j=0; j <= 7; ++j) {
			
			for (int k=0; k <=4; ++k) {
				
				for (int w=0; w<=7; ++w) {
					Node one_node(i,j,k,w);
					all_nodes.push_back(one_node);
				}
			}
		}
	}

	

	priority_queue <Node, vector <Node>, Compare> pq;
	map <Node, int> dist;
	


	for (int i=0; i < all_nodes.size(); ++i) {
		dist[all_nodes[i]] = INF;
	}


	for(int i=0;i<all_nodes.size();i++){
		if (all_nodes[i].state[3]==0 ){
			dist[all_nodes[i]]=INF;
		}
		
	}

	pq.push(src);
	
	dist[src] = 0;
	for(int i=0;i<all_nodes.size();i++){
		if (all_nodes[i].state[2]==4 && all_nodes[i].state[3]==4){
			
			//cout<<"Distance of "<<all_nodes[i]<<"is "<<dist[all_nodes[i]]<<endl;

		}
		
	}
	

		
	while (!pq.empty()) {
		Node current_node = pq.top();
		//cout << current_node << endl;
		pq.pop();

		if (isGoal(current_node)) {
			cout << "Yes. found it. The total water used is " << current_node.state[3]  << endl;
			return;
		}

/*
		vector <Node> nbr = current_node.neighbors();
		for (int i=0; i < nbr.size(); ++i) {
			Node neighbor = nbr[i];
			int new_distance = dist[current_node] + neighbor.state[3];
			if (new_distance < dist[neighbor]) {
				dist[neighbor] = new_distance;
				pq.push(neighbor);
			}
		}
*/		
		vector <Node> nbr = current_node.neighbors();
		cout<<"Current Node is "<<current_node<<endl;
		cout<<"-----------------------------------------------------"<<endl;
		for (int i=0; i < nbr.size(); ++i) {
			Node neighbor = nbr[i];
			
			int new_distance = dist[current_node] + neighbor.state[3];
			cout<<"New Distance of "<<neighbor<<"is "<<new_distance<<" "<<endl;
			cout<<"    Dist[neighbor]=="<<dist[neighbor]<<endl;
			if (new_distance <= dist[neighbor]) {

				dist[neighbor] = new_distance;
				cout<<"        Distance of"<<neighbor<<"is "<<new_distance<<endl;
				pq.push(neighbor);
			}
		}
		cout<<"----------------------------------------------------------"<<endl;
	}


}


bool isGoal(const Node &n) {
	return (n.state[1] == 2 || n.state[2] == 2);
}

int main(int argc, char const *argv[]) {
	Node start(0,7,4,0);
	vector <Node> nbr = start.neighbors();
	conserve_water(start);
	
}