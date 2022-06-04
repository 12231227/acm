#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b) { return b == 0 ? a : gcd(b , a % b); }

int main(){
	int t;
	cin >> t;
	while (t--) {
		int r,b,k;
		cin >> r >> b >> k;
		if (r > b) swap(r , b);
		int g = gcd(r , b);
		r /= g; b /= g;
		int p = (b - 1) / r - ((b - 1) % r == 0) + 1;
		if (p < k) printf("OBEY\n"); else printf("REBEL\n");
	}
} 

