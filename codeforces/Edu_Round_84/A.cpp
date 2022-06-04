#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n,k;
		cin >> n >> k;
		if (1ll * n < 1ll * k * k) {
			cout << "NO" << endl;
			continue;
		}
		n %= 2; k %= 2;
		if (n == k) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
} 

