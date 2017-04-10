//Team Members: Nathan Michael Swan, Lucas Joseph Heilman and Deepak Shah
//Huffman Encoding


# include <iostream>
#include <fstream>
# include <vector>
# include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <bits/stdc++.h>
#include <map>
using namespace std;

#define INF 0x3f3f3f3f

string codes=""; //contains the coded sequence

struct Tuple{
	pair<char,int> tup;
	Tuple *leftchild;
	Tuple *rightchild;
	Tuple(char a, int b){
		tup=make_pair(a,b);
		leftchild=NULL;
		rightchild=NULL;
	}
	bool operator==(const Tuple &other){
		if(this->tup.first==other.tup.first && this->tup.second==other.tup.second) return true;
		return false;
	}
	char first(){
		return tup.first;
	}
	int second(){
		return tup.second;

	}

	

};


//required for priority queue
class Compare{
	public: 
		bool operator()(Tuple *a, Tuple *b) {
			return (a->second()>b->second());
		}
};

ostream &operator<<(ostream & os, Tuple t){
	os<<t.tup.first<<" "<<t.tup.second;
}


Tuple combine(Tuple a, Tuple b){
	Tuple c('!',a.tup.second+b.tup.second);
	return c;
}

//counts frequency of each character
int countfreq(char c, string s){
	int count=0;
	for(int i=0;i<s.size();i++){
		if(s[i]==c) count++;
	}
	return count;
}

//creates a vector of tuples of character and its frequency
vector<Tuple> createtuples(string s){
	vector<Tuple> newvec;
	for(int i=0;i<s.size();i++){
		Tuple t(s[i], countfreq(s[i], s));
		if(find(newvec.begin(), newvec.end(),t)!=newvec.end()){
			continue;
		}else if(t.first()==' '){
			continue;
		}else{
			newvec.push_back(t);
		}
	}
	return newvec;
}


int leftchild(int lindex){
	return 2*lindex;

}

int rightchild(int rindex){
	return 2*rindex+1;
}


int leftsibling(int sindex){
	return sindex-1;
}

int rightsibling(int sindex){
	return sindex+1;
}
//stores the codes of each character
map <char, string> codemap;

//prints the encoded sequence
void print(Tuple *top, string s){
	if(!top) return;
	if(top->first()!='#') codemap[top->first()]=s;
	print (top->leftchild,s+"0");
	print (top->rightchild,s+"1");
	
}
//top is the root in the tree which points to two children-leftchild and rightchild
//this function returns the root of the tree which is connected to its children
Tuple huffman(vector<Tuple> t){
	priority_queue<Tuple*, vector<Tuple*>, Compare> pq;
	for(int i=0;i<t.size();i++){
		pq.push(new Tuple(t[i].first(), t[i].second()));
	}
	Tuple *top;
	Tuple *leftchild;
	Tuple *rightchild;
	while(pq.size()!=1){
		

		leftchild=pq.top();
		pq.pop();
		rightchild=pq.top();
		pq.pop();
		top=new Tuple('#', leftchild->second()+rightchild->second());
		top->leftchild=leftchild;
		top->rightchild=rightchild;
		pq.push(top);
	}
	
	print(pq.top(), "");
	return *pq.top();
}

//one is the root; after a character is printed, it goes back to the root to find another character
Tuple one('@',0);
void decode(Tuple top){
	while(codes.size()>0){
		if(top.first()=='#'){
			if(codes[0]=='0'){
				codes.erase(codes.begin());
				decode(*top.leftchild);
			}
			if(codes[0]=='1'){
				codes.erase(codes.begin());
				decode(*top.rightchild);
			}
		}else {
			cout<<top.first();
			decode(one);
		}

		}
}




int main(){
	string line;
	cout<<"This is the code::"<<endl;
	string everything="";

	ifstream f("file.txt");
   //read from file
	while(getline(f, line))
		everything+=line;
	vector<Tuple> v;
	//creates tuples(char,int); int is the frequency of each character
	v=createtuples(everything);
	one=huffman(v); //one is the root of the tree

	for(int i=0;i<everything.size();i++){
		codes+=codemap[everything[i]];
	}
	cout<<codes<<endl;
	int codesize=codes.size();
	cout<<"Decoded::"<<endl;
	decode(one);
	double uncompressed_size=double(everything.size()*8);
	cout<<codesize<<endl;
	cout<<"Decreased by::"<<((uncompressed_size-codesize)/uncompressed_size)*100<<" % "<<endl;
	
}