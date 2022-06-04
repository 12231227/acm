#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

const int maxn = 2e5;
int dep[maxn + 11],siz[maxn + 11],f[maxn + 11],dfn[maxn + 11];
vector <int> edge[maxn + 11];
vector <int> v;

int tot = 0;

void dfs(int x,int fa) {
	f[x] = fa;
	dep[x] = dep[fa] + 1; dfn[x] = ++tot;
	siz[x] = 1;
	for (auto v : edge[x]) {
		if (v == fa) continue;
		dfs(v , x);
		siz[x] += siz[v];
	}
}

bool isfather(int x,int y) { return dfn[x] >= dfn[y] && dfn[x] <= dfn[y] + siz[y] - 1; }

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u , v;
		cin >> u >> v;
		edge[u].pb(v); edge[v].pb(u);
	}
	dfs(1 , 1);
	for (;m;m--){
		int k; cin >> k; v.clear(); v.pb(1);
		for (int i = 1; i <= k; i++) {
			int x; cin >> x;
			v.pb(f[x]);
		}
		sort(v.begin() , v.end() , [&](int a,int b) { return dep[a] < dep[b]; });
		bool flag = true;
		for (int i = 0; i < k; i++) {
			if (!isfather(v[i + 1] , v[i])) { flag = false; break; }
		}
		if (flag) printf("YES\n"); else printf("NO\n");
	}
} 
