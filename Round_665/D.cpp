#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1e5;
const ll mol = 1e9 + 7;
int siz[maxn + 11],a[maxn + 11],num[maxn + 11];
int tot;
ll p[maxn + 11];
vector <int> edge[maxn + 11];

void dfs(int x,int fa) {
	siz[x] = 1;
	for (auto v : edge[x]) {
		if (v == fa) continue;
		dfs(v , x);
		siz[x] += siz[v];
	}
}

void dfs2(int x,int fa) {
	for (auto v : edge[x]) {
		if (v == fa) continue;
		num[++tot] = siz[v];
		dfs2(v , x);
	}
}

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) edge[i].clear();
		tot = 0;
		for (int i = 1; i < n; i++) {
			int u,v; cin >> u >> v;
			edge[u].pb(v); edge[v].pb(u);
		}
		for (int i = 1; i < n; i++) a[i] = i;
		dfs(1 , 0);
		dfs2(1 , 0);
		sort(a + 1 , a + n , [&](int x,int y) {
			return 1ll * num[x] * (n - num[x]) > 1ll * num[y] * (n - num[y]);
		});
		n--;
		int m; cin >> m;
		for (int i = 1; i <= m; i++) cin >> p[i];
		if (n >= m) {
			for (int i = m + 1; i <= n; i++) p[i] = 1;
			m = n;
			sort(p + 1 , p + 1 + m , [&](ll a,ll b) { return a > b; });
		}
		else {
			sort(p + 1 , p + 1 + m , [&](ll a,ll b) { return a > b; });
			ll val = 1;
			for (int i = 1; i <= m - n + 1; i++) val = val * p[i] % mol;
			p[1] = val;
			for (int i = 2 , j = m - n + 2; j <= m; i++ , j++) p[i] = p[j];
			m = n;
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += 1ll * num[a[i]] * (n + 1 - num[a[i]]) % mol * p[i] % mol;
			if (ans >= mol) ans -= mol;
		}
		cout << ans << endl;
	}
} 
