#include <bits/stdc++.h>
using namespace std;

const double pi = atan(1) * 4;

int main(){
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		double l = cos(pi / n / 4) / sin(pi / n / 2);
		printf("%.10lf\n" , l);
	}
} 
