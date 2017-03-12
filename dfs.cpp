#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<stack>
#include<map>

using namespace std;


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


map<int,int> previsitlist;
int counter = 1;
void previsit(int vertex) {
  previsitlist[vertex] = counter;
  ++counter;
}
map<int, int> postvisitlist;
void postvisit(int vertex) {
  postvisitlist[vertex] = counter;
  ++counter;
}
map<int,bool> visited;
void explore(vector<vector<int>> Graph, int svertex){
	visited[svertex]=true;
	previsit(svertex);
	for (int i=0;i<Graph[svertex].size();++i){
		if(!visited[Graph[svertex][i]]) explore(Graph, Graph[svertex][i]);
	}
postvisit(svertex);

}

void dfs(vector<vector<int>> Graph){
	for(int i=0;i<Graph.size();i++){
		visited[i]=false;
	}
	for(int i=0;i<Graph.size();i++){
		if(!visited[i]){
			explore(Graph, i);
		}
	}
}


int main(){
	ifstream f("file.txt");
	vector<int> vertexedge;
	vertexedge=readfile(f);
	f.close();
	vector<vector<int>> Graph;
	int vertices=vertexedge[0];
	int edges=vertexedge[1];
	Graph.resize(vertices);

	for (int i=2;i+1<vertexedge.size();i+=2){
    int v=vertexedge[i];
    int e=vertexedge[i+1];
    Graph[v].push_back(e);
    Graph[e].push_back(v); //In case the graph is directed, works in both cases.
}

    //DIMACS Format 
   cout<<"p edge \t"<<vertices<<"\t"<<edges<<endl;
   for(int i=0;i<vertices;++i){
   	for(int j=0;j<Graph[i].size();++j){
   		cout<<"e\t"<<i<<"\t"<<Graph[i][j]<<endl;
   	}
   	}
   	dfs(Graph);
   	cout<<"(Previsit, Postvisit)"<<endl;
   	for(int i=0;i<vertices;i++){
   		cout<<i<<"\t"<<"("<<previsitlist[i]<<","<<postvisitlist[i]<<")"<<endl;
   	}
}