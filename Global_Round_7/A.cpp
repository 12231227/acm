#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) { cout << -1 << endl; continue; }
		for (int i = 1; i < n; i++) cout << 3;
		cout << 4 << endl;
	}
}