#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main(){
	ifstream f("file.txt");
	string m;

	while(!f.eof()) {
		getline(f,m);
		
	}
	f.close();
	string n="123456789";
	
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

	cout << "The longest common substring between " << m << " and " << n << " is: ";
	for (int i=Sequence.size(); i > 0; i--) {
		cout << Sequence[i];
	}
	cout << endl;





}

