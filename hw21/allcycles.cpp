#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

class Graph {
	map <int, vector<int> > graph;
	int path;
	vector<vector<int>> pmap;
public:
	Graph(void){
		path = 0;
	}

	void add_edge(int u, int v) {
		graph[u].push_back(v);
	}


	vector <int> nbrs(int vertex) {
		vector <int> nbr;
		return graph[vertex];
	}

	int explore(int st, int v, int counter, vector<int> vec){
		vec.push_back(v);
		//cout << "counter : " << counter << endl;
		if (counter == graph.size()+1){
			//cout << "a" << endl;
			return path;
		}
		if (counter != 0 && v == st){
			pmap.push_back(vec);
			path++;
			//cout <<"b"<<endl;
			//cout <<"path : "<<path<<endl;
			return path;
		}
		counter++;
		vector<int> neighbors = this->nbrs(v);
		for (int i=0, size = neighbors.size(); i<size; i++){
			//cout <<"c"<<endl;
			//cout <<"vertex : "<<neighbors[i] << endl;
			explore(st, neighbors[i], counter, vec);
		}
		return path;
	}


	void printroutes(void){
		cout<<"Cycle Routes: "<<endl;
		for (int i=0, i_end = pmap.size(); i<i_end; i++){
			for (int j=0, sz= pmap[i].size(); j<sz; j++)
				cout<<pmap[i][j]<< " ";
			cout<<endl;
	}
	}
};

int main() {
	Graph g;

	g.add_edge(0,1);
	g.add_edge(1,2);
	g.add_edge(2,3);
	g.add_edge(3,0);
	g.add_edge(1,0);
	g.add_edge(2,1);
	g.add_edge(3,2);
	g.add_edge(0,3);



	int start = 1;

	int count = 0;
	vector<int> vec;
	int paths=  g.explore(start, start, count, vec);
	cout << "Total cycles : " <<paths<< endl;;
	g.printroutes();
}
