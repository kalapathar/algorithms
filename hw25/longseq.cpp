#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int lis_length(vector<int> a){
	int n=a.size();
	vector<int> q;

	for(int k=0;k<n;k++){
		int max=0;
		for(int j=0;j<k;j++){
			if(a[k]>a[j]){
				if(q[j]>max) {
					max=q[j];
				}
			}
		}
		q[k]=max+1;
	}
	
	int max=0;
	for(int i=0;i<n;i++){
		if (q[i]>max) max=q[i];
	}
	
	return max;
}

int main(){
ifstream f("file.txt");
int x;

vector<int> input;
while(!f.eof()){
	f>>x;
	input.push_back(x);
}
f.close();

lis_length(input);

	
}