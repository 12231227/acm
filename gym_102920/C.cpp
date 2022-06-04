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
int tag[maxn + 11],siz[maxn + 11],fat[maxn + 11];
vector <int> edge[maxn + 11];

void dfs(int x,int fa) {
	fat[x] = fa;
	siz[x] = tag[x];
	for (auto v : edge[x]) {
		if (v == fa) continue;
		dfs(v , x);
		siz[x] += siz[v];
	} 
} 

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,k; cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u,v,w; cin >> u >> v >> w;
		edge[u].pb(v); edge[v].pb(u);
	}
	memset(tag , 0 , sizeof(tag));
	for (int i = 1; i <= k; i++) { 
		int u; cin >> u;
		tag[u] = 1;
	} 
	dfs(1 , 0);
	int ans = n;
	for (int i = 2; i <= n; i++) { 
		if (tag[i]) continue;
		bool flag = true;
		if (siz[i] == 0) flag = false;
		for (auto v : edge[i]) {
			if (v == fat[i]) continue;
			if (siz[v] == k) flag = false;
		}
		if (!flag) ans--;
	} 
	if (!tag[1]) { 
		bool flag = true;
		for (auto v : edge[1])
			if (siz[v] == k) flag = false;
		if (!flag) ans--;
	} 
	cout << ans << endl;
} 
