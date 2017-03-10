#include<iostream>
using namespace std;

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
	bool isvertexinlist(int v);
};

graph::graph(int l){
	length=l;
	vertex=new node*[length];
	for(int i=0;i<length;i++){
	vertex[i]->link=NULL;
	vertex[i]->n=-1;
	//cout<<vertex[i]<<endl;	
	}
	
}




void graph::add_edges(int v, int e){

	if(vertex[v]->n==-1){
	vertex[v]->n=v;
	node* current=new node;
	
	current->n=e;
	current->link=vertex[v];
	head[v]=current;
	//vertex[v]=head[v];
}else{
	node* current=new node;
	current->n=e;
	current->link=head[v];
	head[v]=current;
	//vertex[v]=head[v];

}
	
}

void graph::print(){
	
	int i=0;
	while(vertex[i]->n!=-1){
		cout<<"Vertex is:: " <<vertex[i]->n<<endl;
		node* current=new node;
		current=head[i];

		cout<<"Edge is:"<<current->n<<endl;
		
	    //current=head;
	    while(current->link!=NULL){
	    	cout<<current->n<<endl;
	    	current=current->link;

	    }
	    //cout<<"Vertex is "<<current->n;
	    

	i++;
}
}
	


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

int main(){
	graph g1(10);
	g1.add_edges(0,1);
	g1.add_edges(0,2);
	g1.add_edges(1,4);
	g1.add_edges(1,5);
	g1.print();

}







