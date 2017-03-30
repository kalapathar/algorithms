#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int capacity[] = {23,29,31,37,41};

struct Node {
	int state[5];

	Node(int i, int j, int k, int l, int m) {
		state[0] = i;
		state[1] = j;
		state[2] = k; 
		state[3] = l;
		state[4] = m; 
	}

	bool operator==(const Node&n) const {
		return (state[0] == n.state[0] &&
		state[1] == n.state[1] &&
		state[2] == n.state[2])&&
		state[3] == n.state[3]&&
		state[4] == n.state[4];
	}
	vector <Node> neighbors() const;
	void print(ostream &os) const {
		os << state[0] << " " << state[1] << " " << state[2]<<" "<<state[3]<<" "<<state[4];
	}
};

ostream &operator<<(ostream &os, const Node &n) {
	n.print(os);
	return os;
}

vector <Node> Node::neighbors() const {
	vector <Node> result;
	for (int from = 0; from < 5; ++from) {
		for (int to=0; to < 5; ++to) {
			int howMuch = state[from];
			if (howMuch + state[to] > capacity[to]) {
				howMuch = capacity[to] - state[to];
			}
			if (howMuch > 0) {
				Node n(*this);
				n.state[to] += howMuch;
				n.state[from] -= howMuch;
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

void explore(const Node &n, int level=0) {
	//cout << spaces(2*level) << n << endl;
	thingsIveSeen.push_back(n);
	queue<Node> Q;
	Q.push(n);
	int counter=0;
	while(!Q.empty()){
		Node yonode=Q.front();
		if (isGoal(yonode)) {

			cout<<yonode.state[0]<<" "<<yonode.state[1]<<" "<<yonode.state[2]<<" "<<yonode.state[3]<<" "<<yonode.state[4]<<endl;
		cout << "Yes! Found it after "<<counter<<" traversals" << endl;
		return;
	}
	Q.pop();
	vector <Node> nbr = yonode.neighbors();
		for (int i=0, i_end = nbr.size(); i < i_end; ++i) {
			if (!haveIseen(nbr[i])) {
				Q.push(nbr[i]);
				counter++;
				
				thingsIveSeen.push_back(nbr[i]);
		}

	}
}
}

	 bool isGoal(const Node &n) {
		return (n.state[2] == 4 && n.state[3] == 4 && n.state[4] == 4);
		}
		

int main(int argc, char const *argv[])
{
	Node start(23,0,0,0,41);


	explore(start);
}