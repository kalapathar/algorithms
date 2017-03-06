#include<iostream>
using namespace std;
#include<vector>

int* sort(int* m, int length){
	int tmp;
	for(int i=0;i<length-1;++i){
		for(int j=i+1;j<length;++j)
			if(m[i]>m[j]){
				tmp=m[i];
				m[i]=m[j];
				m[j]=tmp;
			}
	}
	return m;
}


const char* binarysearch(vector<string> f, const char* search, int left, int right){
	int middle=(left+right)/2;
	if(search<f[left] or search>f[right]){
		return "Not found";
	}
	if(f[middle]==search){
		return "Found";
	}else if(f[middle]>search){
		binarysearch(f,search, left,middle-1);
	}else{
		binarysearch(f,search, middle+1, right);
	}
	
}
	
int main(){
	vector<string> my_vector;
	//int* p;
	string list[]={"apple","banana","carrot","dog","elephant","finger","ginger","horse","icecream","jockey","king","little"};
	for (int i=0;i<12;i++){
		my_vector.push_back(list[i]);
		
	}
	const char* boolfind;
	boolfind=binarysearch(my_vector, "apple", 0, 11);
	//cout<<"Index of x is::"<<x<<endl;
    cout<<"Boolfind"<<boolfind[1]<<endl;
	

}

