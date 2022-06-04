#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--) {
		ll x,y;
		cin >> x >> y;
		x -= y;
		if (x > 1) printf("YES\n"); else printf("NO\n");
	} 
} 

