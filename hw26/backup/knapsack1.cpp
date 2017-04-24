#include <iostream>
#include <vector>
using namespace std;

#define INF -0x3f3f3f3f
const int MAX_WEIGHT=5;
const int n_objects=5;
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
		/*
			if(i<0){
				table[i][j]=INF;
			}else if(i>=0 and j<0){
				table[i][j]=0;

			}else{
				cout<<"i== "<<i<<"j== "<<j<<endl;
				cout<<"table[i][j-1]== "<<table[i][j-1]<<"allitems[j].value()== "<<allitems[j].value()<<"table[i-allitems[j].weight()][j-1]== "<<table[i-allitems[j].weight()][j-1]<<endl;
				table[i][j]=max(table[i][j-1],allitems[j].value()+table[i-allitems[j].weight()][j-1]);
			}
		*/
			table[i][j]=fillval(i,j);
		}
	}


}





int main(){
	
	Item a(0,2,2);
	Item b(1,1,3);
	Item c(2,3,5);
	Item d(3,3,4);
	Item e(4,4,2);

	
	allitems.push_back(a);
	allitems.push_back(b);
	allitems.push_back(c);
	allitems.push_back(d);
	allitems.push_back(e);
	/*for(int i=0;i<=MAX_WEIGHT;i++){
		for(int j=0;j<n_objects;j++){
			table[i][j]=INF;
		}
	}
	*/
	for(int i=0;i<n_objects;i++) table[0][i]=0;
	cout<<"After here"<<endl;
	knapsack();
	for(int i=0;i<=MAX_WEIGHT;i++){
		cout<<"-----------------------------------------"<<endl;
		for(int j=0;j<n_objects;j++){
			cout<<table[i][j]<<endl;
		}
		cout<<"-----------------------------------------"<<endl;
	}

    




}