#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename T>


ostream & operator<<(std::ostream & os, std::vector <T> vec) {
    os << "{ ";
	copy(vec.begin(), vec.end(), ostream_iterator <T> (os, " "));
    os << "}";
    return os;
}



struct Tuple  {

	pair <int, int> ipair;

	Tuple(int a, int b) {
		ipair = make_pair(a,b);
	}

	int first() {
		return ipair.first;
	}

	int second() {
		return ipair.second;
	}
};

ostream& operator<<(ostream& os, Tuple& t) {
	os << t.first() << " " << t.second();
	return os;		
}



struct Graph {

	int V;
	vector <Tuple> E;

	Graph(int v) {
		V = v;
	}

	void add_Edge(Tuple t) {
		E.push_back(t);
	}

	void print() {
		cout << "The Graph is as follows: " << endl;
		cout << "Number of Vertices: " << V << endl;
		cout << "These are Edges: " << endl;
		for (int i=0; i < E.size(); ++i) {
			cout << E[i] << endl;
		}
	}
};



bool isvertexcover(Graph g, vector <int> cover) {
	map <int, bool> M;
	for (int i=0; i < g.V; ++i) {
		M[i] = false;
	}

	for (int i=0; i < cover.size(); ++i) {
		M[cover[i]] = true;
	}
	
	bool final = true;
	for (int i=0; i < g.E.size(); ++i) {
		if (!(M[g.E[i].first()] || M[g.E[i].second()])) {
			final = false;
		}
	}
	return final;
}


//finds all combinations of a set of r-length vectors from n vertices


vector <vector <int> > all_comb(int n, int r) {
    vector <vector <int> > final;

    vector <bool> v(n);
    fill(v.end() - r, v.end(), true);

    do {
        vector <int> a_comb;
        for (int i=0; i < n; ++i) {
            if (v[i]) {
                a_comb.push_back(i);
            }
        }
        final.push_back(a_comb);
    } while (next_permutation(v.begin(), v.end()));

    return final;
}



int main() {

	
	Graph g(5);
	g.add_Edge(Tuple(0,2));
	g.add_Edge(Tuple(1,2));
	g.add_Edge(Tuple(4,1));
	g.add_Edge(Tuple(4,2));
	g.add_Edge(Tuple(3,2));
	g.print();
	

	
	vector <vector <int> > possible_vertexCover;
	for (int i=1; i <= g.V; ++i) {
		vector <vector <int> > all_combinations = all_comb(g.V, i);
		for (int i=0; i < all_combinations.size(); ++i) {
			vector <int> solution = all_combinations[i];
			if (isvertexcover(g, solution)) {
				possible_vertexCover.push_back(solution);
			}	
		}
	}
	
	
	vector <int> vertexCover = possible_vertexCover[0];
	for (int i=0; i < possible_vertexCover.size(); ++i) {
		if (vertexCover.size() > possible_vertexCover[i].size())
			vertexCover = possible_vertexCover[i];
	}

	cout << "-----------------------------------------------------------------------" << endl;
	cout << "The vertex cover for the graph is: " << vertexCover << endl;
	

}



