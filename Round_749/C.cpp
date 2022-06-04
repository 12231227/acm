#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> a;

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m;
	cin >> n >> m;
	a.resize(n + 1);
	for (int i = 0; i <= n; i++) a[i].resize(m + 1);
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			a[i][j + 1] = (s[j] == 'X');
	}
	vector <int> block;
	for (int i = 1; i < n; i++)
		for (int j = 2; j <= m; j++)
			if (a[i][j] && a[i + 1][j - 1]) block.pb(j - 1);
	sort(all(block));
	block.erase(unique(all(block)) , block.end());
	int q; cin >> q;
	while (q--) {
		int l,r; cin >> l >> r;
		if (l == r) { puts("YES"); continue; }
		auto it = lower_bound(all(block) , l);
		if (it == block.end()) { puts("YES"); continue; }
		if (*it < r) puts("NO");
		else puts("YES");
	}
} 
