#include <iostream>
#include <map>
using namespace std;

map <int, int> m;
int F(int n) {
	if (m.find(n) == m.end())
		m[n] = F(n-2) + F(n-4) + F(n-6);
	return m[n];
}

int main(){
	m[0] = 0;
	m[1] = -9;
	m[2] = -6;
	m[3] = -13;
	m[4] = -12;
	m[5] = -23;
	m[6] = -18;
	cout<<F(100)<<endl;
}
