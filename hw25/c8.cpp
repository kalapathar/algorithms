#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	ifstream f("file2.txt");
	string s;
	vector<string> words;

	while(!f.eof()){
		getline(f,s);
		words.push_back(s);
	}

	f.close();

	string m = words[0];
	string n = words[1];

	int length=m.size();
	int breadth=n.size();

	int matrix [length+1][breadth+1];

	for (int i=0; i <=length; i++) {
		for (int j=0;j <= breadth; j++) {
			if (i == 0|| j == 0) {
				matrix[i][j] = 0;
			} else if (m[i] == n[j]) {
				matrix[i][j] = 1 + matrix[i-1][j-1];
			} else {
				matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
			}
		}
	}



for (int i=0;i<=length;i++){
	for(int j=0;j<=breadth;j++){
		cout<<matrix[i][j]<<" ";

	}
	cout<<endl;
}



	vector <char> Sequence;
	int i = length;
	int j = breadth;

	while (i >= 0 && j >= 0) {
		
		if (m[i] == n[j]) {
			Sequence.push_back(m[i]);
			--i;
			--j;
		} else if (matrix[i][j-1] >= matrix[i-1][j]) {
			
			--j;
		} else {
			
			--i;
		}
	}


	cout << "The longest common substring between " <<endl<< m << " and " << n << " is: "<<endl;
	for (int i=0; i < Sequence.size(); ++i) {
		cout << Sequence[i];
	}
	cout << endl;
}





































































































































































































































































































































