#include<iostream>
using namespace std;
#include<vector>


#include<iostream>
using namespace std;
#include<string>
#include<vector>



void binarysearch(vector<string>f, const char* search, int left, int right){
	int middle=(left+right)/2;
	if(search<f[left] or search >f[right]){
		cout<<"Not found"<<endl;
		exit(0);
	}
	if(f[middle]==search){
		cout<<"Found"<<endl;
	}else if(f[middle]<search){
		binarysearch(f, search, middle+1, right);
	}else {
		binarysearch(f, search, left, middle-1);
	}
}






int main(){
	vector<string> my_vector;
	//int* p;
	string list[]={"apple","banana","carrot","dog","elephant","finger","ginger","horse","icecream","jockey","king","little"};
	for (int i=0;i<12;i++){
		my_vector.push_back(list[i]);
		
	}
	binarysearch(my_vector, "banana", 0, my_vector.size()-1);


}
