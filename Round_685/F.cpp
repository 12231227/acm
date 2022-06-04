#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int a[500];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) { 
		int n,m; cin >> n >> m;
		for (int i = 2; i <= n + m; i++) a[i] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				int x; cin >> x;
				a[i + j] ^= x;
			}
		bool flag = true;
		for (int i = 2; i <= n + m; i++)
			if (a[i]) flag = false;
		if (flag) cout << "Jeel" << endl;
		else cout << "Ashish" << endl;
	} 
} 
