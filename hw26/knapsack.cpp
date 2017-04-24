#include <iostream>
#include <vector>
using namespace std;

#define INF -0x3f3f3f3f
const int MAX_WEIGHT=4;
const int n_objects=4;
int table [MAX_WEIGHT+1][n_objects];



struct Item{

	int n[3];

	Item(int a, int b, int c){
		n[0]=a;n[1]=b;n[2]=c;
	}
	int number() {
		return n[0];
	}
	int weight() {
		return n[1];
	}
	int value() {
		return n[2];
	}
	void print(ostream &os)const {
		os<<n[0]<<n[1]<<n[2];
	}

	Item& operator =( const Item& i ){
		
		n[0]=i.n[0];
		n[1]=i.n[1];
		n[2]=i.n[2];
		return *this;

	}

};
ostream& operator<<(ostream& os, const Item&i){
	i.print(os);
	return os;
}
vector<Item> allitems;


int fillval(int i, int j){

	if (i<0){
		return INF;
	}else if (i>=0 and j<0){
		return 0;
	}else{
		return max(fillval(i,j-1),allitems[j].value()+fillval(i-allitems[j].weight(),j-1));
	}
}





void knapsack(){
	for(int i=1;i<=MAX_WEIGHT;i++){
		for(int j=0;j<n_objects;j++){
			table[i][j]=fillval(i,j);
		}
	}


}





int main(){
	
	Item a(0,1,2);
	Item b(1,1,3);
	Item c(2,2,1);
	Item d(3,3,3);
	
	allitems.push_back(a);
	allitems.push_back(b);
	allitems.push_back(c);
	allitems.push_back(d);
	for(int i=0;i<n_objects;i++) table[0][i]=0;
	knapsack();
	for(int i=0;i<=MAX_WEIGHT;i++){
		cout<<"-----------------------------------------"<<endl;
		for(int j=0;j<n_objects;j++){
			cout<<table[i][j]<<endl;
		}
		cout<<"-----------------------------------------"<<endl;
	}
	cout<<"Maxmimum Possible Value== "<<table[MAX_WEIGHT][n_objects-1]<<endl;

    




}