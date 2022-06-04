#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--) {
		int x,y;
		cin >> x >> y;
		if (x >= y) { printf("YES\n"); continue; }
		if (x == 2 && y == 3) { printf("YES\n"); continue; }
		if (x <= 3) { printf("NO\n"); continue; }
		printf("YES\n");
	}
} 

