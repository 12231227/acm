#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

const int maxn = 5000;
bool flag = true;
int num = 0;
int n1,n2,n3;
bool vis[maxn + 11];
vector <int> edge[maxn + 11],rec;
int ans[maxn + 11],col[maxn + 11];
pair<int,int> g[maxn + 11];
int f[maxn + 11][maxn + 11][2];
int cnt[5];

void dfs(int x,int fa) {
	vis[x] = true;
	for (auto v : edge[x]) {
		if (v == fa) continue;
		if (col[v] == -1) {
			col[v] = col[x] ^ 1;
			cnt[col[v]]++;
			dfs(v , x);
		}
		else {
			if (col[v] == col[x]) flag = false;
			continue;
		}
	}
}

int get() { if (num < n1) { num++; return 1; } return 3; }

void dfs2(int x,int fa,int op) {
	vis[x] = true; if (op == 0) ans[x] = 2; else ans[x] = get();
	for (auto v : edge[x]) {
		if (v == fa || vis[v]) continue;
		dfs2(v , x , op ^ 1);
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m;
	cin >> n >> m;
	cin >> n1 >> n2 >> n3;
	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	for (int i = 1; i <= n; i++) vis[i] = false , col[i] = -1;
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		cnt[0] = 1; cnt[1] = 0;
		col[i] = 0;
		dfs(i , 0);
		if (!flag) break;
		g[++tot] = make_pair(cnt[0] , cnt[1]);
	}
	if (!flag) { puts("NO"); return 0; }
	for (int i = 1; i <= n; i++) vis[i] = false;
	f[0][0][0] = f[0][0][1] = 1;
	int sum = 0;
	for (int i = 1; i <= tot; i++) {
		for (int j = 0; j <= n2; j++) {
			if (j >= g[i].first) f[i][j][0] = f[i - 1][j - g[i].first][0] | f[i - 1][j - g[i].first][1];
			if (j >= g[i].second) f[i][j][1] = f[i - 1][j - g[i].second][0] | f[i - 1][j - g[i].second][1];
		}
	}
	if (f[tot][n2][0] || f[tot][n2][1]) {
		puts("YES");
		int j = n2;
		for (int i = tot; i >= 1; i--) {
			if (f[i][j][0]) { rec.pb(0); j -= g[i].first; } 
			else { rec.pb(1); j -= g[i].second; }
		}
		reverse(rec.begin() , rec.end());
		int ind = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			dfs2(i , 0 , rec[ind]);
			ind++;
		}
		for (int i = 1; i <= n; i++) printf("%d" , ans[i]);
		puts("");
	}
	else {
		puts("NO");
	}
} 
