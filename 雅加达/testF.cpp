#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ll long long
using namespace std;

const int maxn = 4000;
 
int cnt = 0;
bool vis[40000] = {false};
int prime[4111];
ll has[maxn + 11];
ll siz[maxn + 11];
vector <int> edge[maxn + 11];
int n;
 
void dfs(int x,int fa) {
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
 
void pre() {
	for (int i = 2; ; i++) {
		if (!vis[i]) { prime[++cnt] = i; if (cnt >= n) break; }
		for (int j = 1; j <= cnt; j++){
			vis[i * prime[j]] = true;
			if ( i % prime[j] == 0) break;
		}
	}
}

int main(){ 
	scanf("%d",&n);
	pre();
	for (int i = 1; i < n; i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		edge[u].pb(v);
		edge[v].pb(u);
	} 
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		if (edge[i].size() == 1) continue;
		dfs(i , 0);
		ll tmp = has[edge[i][0]];
		bool can = true;
		for (int j = 1; j < edge[i].size(); j++) 
			if (has[edge[i][j]] != tmp) { can = false; break; } 
		if (can) ans = max(ans , (int)edge[i].size());
	} 
	printf("%d\n" , ans);
} 
