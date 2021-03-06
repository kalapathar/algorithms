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
  void dijkstra(int start);
  pair<int, ipair> vertex_minweight(int u);
  bool isvisited(int s);
  int minindex(vector<int>);
  void explore(int start);
  void kruskal();
  bool cycle(int u, int v);
  pair<int,ipair> ultimate_min_pair(vector<pair<int,ipair>> v);
  pair<int,ipair> min_weight(vector<int> v);
  pair<int, ipair> min_weight();
  bool allvisited();
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


pair<int, ipair> Graph::vertex_minweight(int u){
  
  pair<int, int>min;
  map<int, int> adjvertex=graph[u];
  int vertex;int weight=INF;

for(map<int, int>::iterator i=adjvertex.begin();i!=adjvertex.end();i++){
    
     
    if(!isvisited(i->first)){     
     
    
    if (i->second<weight){
      weight=i->second;
      vertex=i->first;
     
      
    }

    }
    

  }
  min=make_pair(vertex, weight);
  return make_pair(u, min);
}


bool Graph::isvisited(int s){
  for (int i=0;i<visited.size();i++){
    if (s==visited[i]) return true;
  }
  return false;
}


int Graph::minindex(vector<int> v){
  int index=0;int temp=v[0];
  for (int i=0;i<v.size();i++){
    if(!isvisited(v[i])){
      if(v[i]<temp) {
      temp=v[i];
      index=i;
    }
}
}
  return temp;
}

pair<int, ipair> Graph::ultimate_min_pair(vector<pair<int, ipair>> v){
  pair<int, ipair> lowest=v[0];
  for(int i=0;i<v.size();i++){
    if(v[i].second.second<lowest.second.second) lowest=v[i];
  }
  return lowest;
}


bool Graph::cycle(int u, int v){
  if(isvisited(u) && isvisited(v)) return true;
  return false;
}

pair<int,ipair> Graph::min_weight(vector<int> v){
  pair<int,ipair> min;
  vector<pair<int, ipair>> allpairs;
  for(int i=0;i<v.size();i++){
      pair<int,ipair> minpair=vertex_minweight(v[i]);
    allpairs.push_back(minpair);
  }
   min=ultimate_min_pair(allpairs);
  return min;
}




pair<int, ipair> Graph::min_weight(){
  pair<int, ipair> min;
  vector<pair<int, ipair>> allpairs;
    for(int i=0;i<vertex(graph).size();i++){
    vector<int> allvertex=vertex(graph);
    pair<int, ipair> minpair=vertex_minweight(allvertex[i]);
    allpairs.push_back(minpair);
  }
  min=ultimate_min_pair(allpairs);
  return min;
}



void Graph::kruskal(){
  vector<int> k_edges;
  vector<ipair> v_edges; 
  pair<int, ipair> min=min_weight();
  int mincost=0;
  while(!allvisited()){
  mincost=mincost+min.second.second;
  k_edges.push_back(min.first);k_edges.push_back(min.second.first);
  v_edges.push_back(make_pair(min.first, min.second.first));
  if(!isvisited(min.first)) visited.push_back(min.first);
  if(!isvisited(min.second.first))visited.push_back(min.second.first);
  min=min_weight(k_edges);

}

cout<<"------------------------------------"<<endl;
cout<<"Edges Visit Sequence"<<endl;

for(int i=0;i<v_edges.size();i++){
  cout<<"Visited:: "<<v_edges[i].first<<v_edges[i].second<<endl;
}
cout<<"------------------------------------"<<endl;
cout<<"Minimum cost is: "<<mincost<<endl;

}



bool Graph::allvisited(){
  vector<int> allvertex=vertex(graph);
  for(int i=0;i<allvertex.size();i++){
        if(!isvisited(allvertex[i])) return false;
  }
  return true;

}

void Graph::dijkstra(int start){
  priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
  vector<int> dist(graph.size(), INF);
  pq.push(make_pair(start,0));
  dist[start]=0;
  while(!pq.empty()){
    int u=pq.top().first;
    pq.pop();
    map<int,int>::iterator i;
    for(i=graph[u].begin();i!=graph[u].end();i++){
      int v=i->first;
      int weight=i->second;
      if(dist[v]>dist[u]+weight){
        dist[v]=dist[u]+weight;
        pq.push(make_pair(v,dist[v]));
      }
    }


  }
  for(int i=0;i<graph.size();i++){
    cout<<i<<"----------------"<<dist[i]<<endl;
  }
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
        cout<<"Value about to pushed is::"<<nbrs[i]<<endl;
        pushed_num++;
        s.push(nbrs[i]);
        
      }else{
        //cout<<"Vertex: "<<ontop<<"Adj: "<<nbrs[i]<<endl;
        totalcycles=totalcycles+1;
        
        acycle.push_back(nbrs[i]);
        cycles.push_back(acycle);
        //cycles.push_back(ontop);
      }
    }
    for(int i=0;i<acycle.size();i++) cout<<"values in acycle"<<acycle[i];
    if(pushed_num>1){
      vector<int> cycle2;
      for(int i=0;i<acycle.size();i++){
        cycle2.push_back(acycle[i]);
      }
    }
  }
  cout<<"Total Cycles: "<<totalcycles<<endl;

  for(int i=0;i<cycles.size();i++){
    cout<<"Size of cycle"<<cycles[i].size()<<endl;
  }


}


int main(){

	ifstream f("file5.txt");
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
//g.dijkstra(0);
g.explore(0);
//g.kruskal();

}













































