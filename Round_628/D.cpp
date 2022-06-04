#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll u,v;
	cin >> u >> v;
	if (u > v) cout << -1;
	else if (v == 0) cout << 0;
	else if (u == v) cout << 1 << endl << u;
	else if ((v - u) % 2 == 1) cout << -1;
	else {
		ll x = (v - u) / 2;
		if (((u + x) ^ x) == u) cout << 2 << endl << u + x << " " << x;
		else cout << 3 << endl << u << " " << x << " " << x;
	}
} 

