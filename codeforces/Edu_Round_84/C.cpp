#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 1; i <= 2 * k; i++) {
		int x,y;
		cin >> x >> y;
	}
	cout << 2 * n * m << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++)
			if (i % 2 == 1) cout << "R"; else cout << "L";
		cout << "D";
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++)
			if (i % 2 == 1) cout << "L"; else cout << "R";
		cout << "U";
	}
} 
 
