#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double max = 0.0;
	int aa, bb, cc, dd, ee;
	for (int a = 1; a <= 21; ++a) {
		for (int b = 1; b <= 21; ++b) {
			for (int c = 1; c <= 21; ++c) {
				for (int d = 2; d <= 21; ++d) {
					for (int e = 1; e <= 21; ++e) {
						if (a+b+c+d+e == 21) {
							double prob = a/21.0 * pow(b,2)/450.0 * sqrt(c)/sqrt(21.0) * log10(d)/2.0 * pow(1.2, e)/50.0;
							if (prob > max) {
								max = prob;
								aa = a;
								bb = b;
								cc = c;
								dd = d;
								ee = e;
							}
						}
					}
				}
			}
		}
	}

	cout << aa << " " << bb << " " << cc << " " << dd << " " << ee << " max: " << max << endl;

	return 0;
}