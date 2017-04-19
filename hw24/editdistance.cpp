#include <iostream>
#include <algorithm>
using namespace std;

	
string m="anagram";
string n="agnar";

int equal(int i, int j){
	if (m[j-1]==n[i-1]) return 0;
	return 1;
}


int main(){

	int length=m.size();
	int breadth=n.size();
	int dist [breadth+1] [length+1];
	for (int i=0;i<=length;i++){
		dist[0][i]=i;
	}

	for (int i=0;i<=breadth;i++){
		dist[i][0]=i;
	}

	for(int i=1;i<=breadth;i++){
		for( int j=1;j<=length;j++){
			dist[i][j]=min(min(dist[i-1][j]+1, dist[i][j-1]+1), dist[i-1][j-1]+equal(i,j));
		}
		
	}

	cout<<"The edit distance for "<<m<<" and "<<n<<" is "<<dist[breadth][length]<<endl;
}