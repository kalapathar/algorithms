#include<vector>
#include<iostream>
#include<fstream>
#include<string>
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
  while (  !file.eof()) {
    getline(file, line);
    vector<string> word = split(line);
    for ( unsigned i=1,i_end=word.size(); i<i_end; ++i ){
      
        p.push_back(atoi(word[i].c_str()));

      

      
      //cout << atoi(word[i].c_str());
    
    }
    //cout << endl;
  }
  file.close();
  return p;

}

struct node{
	int n;
	node* link;

};

class graph{
private:
	int length;
	node **vertex;
	node **head;
	
public:
	graph(int l);
	void add_edges(int v, int e);
	void print();
	//bool isvertexinlist(int v);
};

graph::graph(int l){
	length=l;
	vertex=new node*[length];
	
	for(int i=0;i<length;i++){
		vertex[i]=new node;
		
	vertex[i]->link=NULL;
	
	vertex[i]->n=-1;
	
	}
	
	
}



void graph::add_edges(int v, int e){
	node* current=new node;

	
if(vertex[v]->n==-1){
		vertex[v]->n=v;
		current->link=vertex[v];
		current->n=e;
		head[v]=current;
}else{
	current->n=e;
	current->link=head[v];
	head[v]=current;

}




	
}

void graph::print(){

	
	int i=0;
	while(vertex[i]->n!=-1){
		cout<<"Vertex is:: " <<vertex[i]->n<<endl;
		node* current=new node;
		current=head[i];


	    while(current->link!=NULL){
	    	cout<<"Edge is: ";
	    	cout<<current->n<<endl;
	    	current=current->link;
	    	

	    }
	    //cout<<"Vertex is "<<current->n;
	    

	i++;
}
}
	

/*
bool graph::isvertexinlist(int v){
	//int* check=vertex;

	for(int i=0;i<length;i++){
	node* current=new node;
	current=head[i];
	if (current->n==v) return true;
	if(current->link!=NULL){
		//cout<<current->n<<"Value of n"<<endl;
		current=current->link;
	}
	
	}
	return false;
}
*/

int main(){
	
	graph g1(10);
  

/*
  for (int i=0;i+1<vertexedge.size();i+=2){
   g1.add_edges(vertexedge[i],vertexedge[i+1]);
    //cout<<vertexedge[i]<<vertexedge[i+1]<<endl;
  }
  */
  // cout<<"Coming here"<<endl;
   g1.add_edges(0,1);
  // cout<<"Coming here"<<endl;
   g1.add_edges(0,2);
  // cout<<"Coming here"<<endl;
   g1.add_edges(1,2);
  // cout<<"Coming here"<<endl;
   g1.add_edges(2,3);
   //g1.add_edges(0,1);
	
	//g1.add_edges(0,1);
	//g1.add_edges(0,2);
	//g1.add_edges(1,4);
	//g1.add_edges(1,5);
	//g1.add_edges(0,6);
	g1.print();
	vector<int> vertexedge;
	ifstream f("file.txt");
	vertexedge=readfile(f);
   	f.close();

}







