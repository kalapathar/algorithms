#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string m = "ANAGRAM";
	string n = "AGNAR";

	int matrix [m.size()+1][n.size()+1];

	for (int i=0; i <=m.size(); i++) {
		for (int j=0;j <= n.size(); j++) {
			if (i == 0|| j == 0) {
				matrix[i][j] = 0;
			} else if (m[i] == n[j]) {
				matrix[i][j] = 1 + matrix[i-1][j-1];
			} else {
				matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
			}
		}
	}

cout<<"This one::"<<matrix[m.size()][n.size()];
/*
for (int i=0;i<=m.size();i++){
	for(int j=0;j<=n.size();j++){

	}
}
*/


	vector <char> Sequence;
	int i = m.size();
	int j = n.size();

	while (i >= 0 && j >= 0) {
		if (m[i] == n[j]) {
			Sequence.push_back(m[i]);
			--i;
			--j;
		} else if (matrix[i][j-1] >= matrix[i-1][j]) {
			cout<<"Value of i is "<<i<<" "<<j-1<<endl;
			--j;
		} else {
			cout<<"Value of i is "<<i-1<<" "<<j<<endl;
			--i;
		}
	}

	cout << "The longest common substring between " << m << " and " << n << " is: ";
	for (int i=0; i < Sequence.size(); ++i) {
		cout << Sequence[i];
	}
	cout << endl;
}





































































































































































































































































































































