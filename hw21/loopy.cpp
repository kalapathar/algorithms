#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<map>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;
typedef pair<int, int> ipair;
#define INF 0x3f3f3f3f
vector<int> visited;


vector<string> split(const string &line, const char *delim = " \t")
{
  vector<string> word;
  size_t loc0, loc1;
  loc0 = line.find_first_not_of(delim);
  if ( loc0 == string::npos ) return word;
  loc1 = line.find_first_of(delim, loc0);
  while ( loc1 != string::npos ) {
    word.push_back( line.substr(loc0, loc1-loc0) );
    loc0 = line.find_first_not_of(delim, loc1);
    if ( loc0 == string::npos ) break;
    loc1 = line.find_first_of(delim, loc0);
  }
  if ( loc0 != string::npos && loc1 == string::npos ) // one more
    word.push_back( line.substr(loc0, line.size()-loc0) );
  return word;
}


vector<int> readfile(ifstream& file){
  vector<int> p;
  string line;
  getline(file, line);
  vector<string> size = split(line);
  p.push_back(atoi(size[2].c_str()));
  p.push_back(atoi(size[3].c_str()));

  while ( !file.eof()) {
    getline(file, line);
    vector<string> word = split(line);
    for ( unsigned i=1,i_end=word.size(); i<i_end; ++i ){
      p.push_back(atoi(word[i].c_str()));
      

    }
}

  file.close();
  return p;

}


vector<int> vertex(map<int, map<int, int>> g){
  vector <int> allkeys;
  for(map<int, map<int, int>>::iterator i=g.begin();i!=g.end();i++){
    allkeys.push_back(i->first);
  }
  return allkeys;

}

vector<int> vertex(map<int, int> g){
  vector <int> allkeys;
  for(map<int, int>::iterator i=g.begin();i!=g.end();i++){
    allkeys.push_back(i->first);
  }
  return allkeys;

}

vector<int> weight(map<int, int> g){
  vector <int> values;
  for(map<int, int>::iterator i=g.begin();i!=g.end();i++){
    values.push_back(i->second);
  }
  return values;
}


class Graph{
private:
  map<int, map<int, int>> graph;
public:
  void add_edges(int x, int y, int w);
  void print();
  int get_weight(int u, int v);
  vector<int> neighbors(int u);
  bool isvisited(int s);
  void explore(int start);
};

void Graph::add_edges(int x, int y, int w){
  graph[x][y]=w;
  //graph[y][x]=w;
}

int Graph::get_weight(int u, int v){
  return graph[u][v];
}

void Graph::print(){
  for(int i=0;i<vertex(graph).size();i++){
    vector<int> allvertex=vertex(graph);
    cout<<allvertex[i]<<endl;
    map<int, int> adjvertex=graph[vertex(graph)[i]];
    for (int j=0;j<adjvertex.size();++j){
      cout<<vertex(adjvertex)[j]<<":"<<weight(adjvertex)[j]<<endl;
    }
    cout<<"-------------------------------------------------"<<endl;
  }
}

 vector<int> Graph::neighbors(int u){
  vector<int> adjvertex;
  map<int,int> invertex=graph[u];
  adjvertex=vertex(invertex);
  return adjvertex;
}


bool Graph::isvisited(int s){
  for (int i=0;i<visited.size();i++){
    if (s==visited[i]) return true;
  }
  return false;
}













ostream &operator<<(ostream &os,stack<int> stack ){
  while(!stack.empty()){
    
    os<<stack.top();
    stack.pop();
    
    
  }

}

void Graph::explore(int start){
  visited.push_back(start);
  vector<vector<int>> cycles;
  stack<int> s;
  s.push(start);
  int pushed_num=0;
  int pval=0;
  
  int totalcycles=0;
vector<int> acycle;
  while(!s.empty()){
    int ontop=s.top();

    s.pop();
    
    acycle.push_back(ontop);
    vector<int> nbrs=neighbors(ontop);
    //cout<<"Size of neighbors vector of "<<ontop<<"is "<<nbrs.size()<<endl;
    for(int i=0;i<nbrs.size();i++){
      if(!isvisited(nbrs[i])) {
        visited.push_back(nbrs[i]);
       
        pushed_num++;if(pushed_num>1) pval=ontop;
        s.push(nbrs[i]);
        
      }else{
        //cout<<"Vertex: "<<ontop<<"Adj: "<<nbrs[i]<<endl;
        totalcycles=totalcycles+1;
        
        acycle.push_back(nbrs[i]);
        cycles.push_back(acycle);
        acycle.pop_back();
        for(int i=acycle.size()-1;acycle[i]!=pval;i--)
        acycle.pop_back();
        //cycles.push_back(ontop);
      }
    }
    
    if(pushed_num>1){
      vector<int> cycle2;
      for(int i=0;i<acycle.size();i++){
        cycle2.push_back(acycle[i]);
      }
    }
  }
  cout<<"Total Cycles: "<<totalcycles<<endl;
  for(int i=0;i<cycles.size();i++){
    cout<<"A cycle"<<endl;
    for(int j=0;j<cycles[i].size();j++){
      cout<<cycles[i][j];

    }
    
  }



}


int main(){

	ifstream f("file6.txt");
	vector<int> vertexedge;
	vertexedge=readfile(f);
	f.close();

	int vertices=vertexedge[0];
	int edges=vertexedge[1];

  Graph g;


for (int i=2;i+2<vertexedge.size();i+=3){
    int v=vertexedge[i];
    int e=vertexedge[i+1];
    g.add_edges(v,e,vertexedge[i+2]);
}


g.print();

g.explore(0);


}













































