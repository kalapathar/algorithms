#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string m="anagram";
string n="agnar";
vector<string> seq;
//bool repeated()
bool repeated(string a, string b){
	for(int i=0;i<seq.size();i++){
		if (seq[i]==b) return true;
	}
	return false;
}

int main(){

	for (int i=0;i<m.size();i++){
		
		for(int j=0;j<n.size();j++){
			if m[i]==n[j]
		}
	}

}