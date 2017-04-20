#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string m="polynomial";
string n="exponential";
vector<char> seq;
//bool repeated()
/*
bool repeated(string a, string b){
	for(int i=0;i<seq.size();i++){
		if (seq[i]==b) return true;
	}
	return false;
}
*/

int main(){
	int k=0;

	for (int i=0;i<m.size();i++){
		
		for(int j=k;j<n.size();j++){
			if (m[i]==n[j]){
				seq.push_back(n[j]);
				k=j+1;
				break;
			}
		}
	}
	for(int i=0;i<seq.size();i++){
		cout<<seq[i]<<endl;
	}

}