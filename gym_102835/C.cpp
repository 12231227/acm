#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1e4;

int f[2][maxn + 11];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) { 
		int n,k; cin >> n >> k;
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		k--;
		f[0][0] = k;
		int op = 1;
		int x = 0 , y = 0;
		if (k & 1) y++; else x++;
		for (int i = 1; i < n - 1; i++ , op ^= 1) { 
			int s = 0;
			f[op][0] = (f[op ^ 1][0] + 1) / 2;
			f[op][i] = f[op ^ 1][i - 1] / 2;
			s = f[op][0] + f[op][i];
			for (int j = 1; j < i; j++) f[op][j] = (f[op ^ 1][j] + 1) / 2 + f[op ^ 1][j - 1] / 2 , s += f[op][j];
			if (f[op][y] & 1) y++; else x++;
			assert (s == k);
		} 
		cout << y << endl;
	} 
} 

