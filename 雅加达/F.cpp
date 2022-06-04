#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int maxn = 4000;

int minn;
int n;
int cnt = 0;
bool vis[40000] = {false};
int prime[4111];
vector <int> edge[maxn + 11];
int siz[maxn + 11],f[maxn + 11];
ll has[maxn + 11];

void dfs(int x,int fa) {
	siz[x] = 1;
	for (int i = 0; i < edge[x].size(); i++) { 
		int v = edge[x][i];
		if (v == fa) continue;
		dfs(v , x);
		siz[x] += siz[v];
		f[x] = max(f[x] , siz[v]);
	} 
	f[x] = max(f[x] , n - siz[x]);
	if (f[x] < minn) minn = f[x];
} 

void pre() {
	for (int i = 2; ; i++) {
		if (!vis[i]) { prime[++cnt] = i; if (cnt >= n) break; }
		for (int j = 1; j <= cnt; j++){
			vis[i * prime[j]] = true;
			if ( i % prime[j] == 0) break;
		}
	}
}

void dfs2(int x,int fa) {
	siz[x] = 1;
	has[x] = 1;
	for (int i = 0; i < edge[x].size(); i++) {
		int v = edge[x][i];
		if (v == fa) continue;
		dfs(v , x);
		siz[x] += siz[v];
		has[x] += has[v] * prime[siz[v]];
	}
}

int main(){
	pre();
	scanf("%d",&n);
	for (int i = 1; i < n; i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		edge[u].pb(v);
		edge[v].pb(u);
	}
	minn = n;
	vector <int> v;
	dfs(1 , 0);
	for (int i = 1; i <= n; i++) if (f[i] == minn) v.pb(i);
	int m = n;
	for (int i = 0;i < v.size(); i++) { 
		bool can = true;
		int u = v[i];
		dfs2(edge[u][0] , u);
		pair <int,ll> pi = make_pair(siz[edge[u][0]] , has[edge[u][0]]);
		for (int j = 1; j < edge[u].size(); j++) {
			int v = edge[u][j];
			dfs2(v , u);
			if (siz[v] != pi.first || has[v] != pi.second) { can = false; break; }
		}
		if (can) { m = min(m , (int)edge[u].size()); }
	} 
	if (m == n) printf("-1\n"); else printf("%d\n" , m);
} 

