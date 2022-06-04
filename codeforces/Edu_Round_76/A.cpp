#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--) {
		int n,x,a,b;
		cin >> n >> x >> a >> b;
		if (a > b) swap(a , b);
		int tmp = x;
		x -= min(a - 1 , tmp);
		a -= min(a - 1 , tmp);
		b += min(n - b , x);
		cout << b - a << endl;
	}
}
