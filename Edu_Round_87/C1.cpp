#include <bits/stdc++.h>
using namespace std;

const double pi = atan(1) * 4;

int main(){
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		double l = 1.0 / tan(pi / n / 2);
		printf("%.10lf\n" , l);
	}
} 
