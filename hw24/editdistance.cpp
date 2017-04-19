#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	string m="anagram";
	string n="agnar";
	int dist  [n.size()+1] [m.size()+1];
	for (int i=0;i<m.size();i++){
		dist[0][i]=i;
	}
	for (int i=0;i<n.size();i++){
		dist[i][0]=i;
	}

	for(int i=1;i<n.size();i++){
		for( int j=1;j<m.size();j++){
			dist[i][j]=min(min(dist[i-1][j]+1, dist[i][j-1]+1), dist[i-1][j-1]+abs(i-j));
		}
	}

	for(int i=0;i<n.size();i++){
		cout<<"--------------------------------------------"<<endl;
		for( int j=0;j<m.size();j++){
			cout<<dist[i][j];
		}
		cout<<"----------------------------------------------"<<endl;
	}


}