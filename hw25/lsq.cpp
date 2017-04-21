#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main(){
	ifstream f("file.txt");
	int x;
	vector<int> input; vector<int> seq;

	while(!f.eof()) {
		f>>x;
		input.push_back(x);
	}
	f.close();
	int current=input[0];
	
	
	seq.push_back(current);
	for(int i=1;i<input.size();i++){
		if (input[i]>current){
			current=input[i];
			seq.push_back(current);
			
		}
	}
	cout<<"Longest subsequence is::"<<endl;
	for(int i=0;i<seq.size();i++){
		cout<<seq[i]<<endl;
	}
	cout<<"Total length::"<<seq.size()<<endl;






}

