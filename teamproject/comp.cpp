#include <iostream>
#include <math.h>
using namespace std;

struct config {
	int* n;
	double prob;
	config(int a, int b, int c, int d, int e) {
		n = new int [5];
		n[0] = a;
		n[1] = b;
		n[2] = c;
		n[3] = d;
		n[4] = e;
		prob = a/21.0 * pow(b,2)/450.0 * sqrt(c)/sqrt(21.0) * log10(d)/2.0 * pow(1.2, e)/50.0;
		//prob = a/21.0 + pow(b,2)/450.0 + sqrt(c)/sqrt(21.0) + log10(d)/2.0 + pow(1.2, e)/50.0;
	}
	config(config prev, int add_person_to_alg_number) {
		n = new int [5];
		for (int i = 0; i < 5; ++i) {
			n[i] = prev.n[i];
		}
		n[add_person_to_alg_number-1] += 1;
		prob = n[0]/21.0 * pow(n[1],2)/450.0 * sqrt(n[2])/sqrt(21.0) * log10(n[3])/2.0 * pow(1.2, n[4])/50.0;
		//prob = n[0]/21.0 + pow(n[1],2)/450.0 + sqrt(n[2])/sqrt(21.0) + log10(n[3])/2.0 + pow(1.2, n[4])/50.0;
	}
	config(config &prev) {
		n = new int [5];
		for (int i = 0; i < 5; ++i) {
			n[i] = prev.n[i];
		}
		prob = n[0]/21.0 * pow(n[1],2)/450.0 * sqrt(n[2])/sqrt(21.0) * log10(n[3])/2.0 * pow(1.2, n[4])/50.0;
		//prob = n[0]/21.0 + pow(n[1],2)/450.0 + sqrt(n[2])/sqrt(21.0) + log10(n[3])/2.0 + pow(1.2, n[4])/50.0;
	}
	config() {
		n = new int [5];
		for (int i = 0; i < 5; ++i) {
			n[i] = 0;
		}
		prob = -1;
		//cout << prob << " ";
	}
	void print() {
		cout << n[0];
		for (int i = 1; i < 5; ++i) {
			cout << "," << n[i];
		}
	}
};

double comp() {
	config *** dp = new config ** [21+1];
	for (int i = 0; i <= 21; ++i) {
		dp[i] = new config * [5+1];
		dp[i][0] = new config();
	}

	int start = 11;

	for (int j = 0; j <= 5; ++j) {
		config * a = new config(2,5,1,2,1);
		dp[start][j] = a;
	}
	//dp[6][0] = new config();
	//dp[6][1] = new config(1,1,1,1,1);
	
	for (int i = start; i <= 21; ++i) {
		dp[i][0]->print(); cout << "  ";
	}
	cout << endl;
	for (int j = 1; j <=5; ++j) {
		dp[start][j]->print(); cout << "  ";
		for (int i = start+1; i <=21; ++i) {
			config * chosen = new config(*(dp[i-1][j]), j);
			config * not_chosen = dp[i][j-1];
			dp[i][j] = (chosen->prob > not_chosen->prob)? chosen : not_chosen;
			dp[i][j]->print(); cout << "  ";
		}
		cout << endl;
	}

	dp[21][5]->print();
	cout << " should be 5,9,2,4,1" << endl;


	return dp[21][5]->prob;
}

int main() {
	cout << comp() << endl;
	int a, b, c, d, e;
	a = 5; b = 9; c = 2; d = 4; e = 1;
	double sum = (a/21.0 + pow(b,2)/450.0 + sqrt(c)/sqrt(21.0) + log10(d)/2.0 + pow(1.2, e)/50.0);
	double product = (a/21.0 * pow(b,2)/450.0 * sqrt(c)/sqrt(21.0) * log10(d)/2.0 * pow(1.2, e)/50.0);
	cout << "Product of sqrts: " << sqrt(sum)*sqrt(product) << endl;
	cout << "Sum of sqrts: " << sqrt(sum)+sqrt(product) << endl;
	cout << "Sqrt of sum+product: " << sqrt(sum+product) << endl;
	cout << "Sqrt of sum*product: " << sqrt(sum*product) << endl;
	return 0;
}