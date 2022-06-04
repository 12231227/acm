#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int maxn = 3e5;

vector <int> edge[maxn + 11];
int f[maxn + 11][3];

void dfs1(int x,int fa) {
	for (int i = 0; i < edge[x].size(); i++) {
		int v = edge[x][i];
		if (v == fa) continue;
		dfs1(v , x);
		int num = f[v][0] + 1 + (edge[v].size() >= 3 ? edge[v].size() - 2 : 0);
		if (f[x][0] < num) { f[x][1] = f[x][0]; f[x][0] = num; } 
		else if (f[x][0] == num) f[x][1] = num;
		else if (f[x][1] < num) f[x][1] = num;
	}
}

void dfs2(int x,int fa) { 
	if (fa != 0) { 
		int num = f[x][0] + 1 + (edge[x].size() >= 3 ? edge[x].size() - 2 : 0);
		if (num == f[fa][0])
			f[x][2] = f[fa][1] + 1 + (edge[fa].size() >= 3 ? edge[fa].size() - 2 : 0);
		else f[x][2] = f[fa][0] + 1 + (edge[fa].size() >= 3 ? edge[fa].size() - 2 : 0);
	} 
	for (int i = 0; i < edge[x].size(); i++) { 
		int v = edge[x][i];
		if (v == fa) continue;
		dfs2(v , x);
	} 
} 

int main(){
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		for (int i = 1; i < n; i++) {
			int u,v;
			cin >> u >> v;
			edge[v].pb(u);
			edge[u].pb(v);
		}
		dfs1(1 , 0);
		dfs2(1 , 0);
		int ans = 0;
		for (int i = 1; i <= n; i++) 
		 ans = max(ans , f[i][0] + max(f[i][2] , f[i][1]) + 1 + (edge[i].size() >= 3 ? (int)edge[i].size() - 2 : 0));
		cout << ans << endl;
		for (int i = 1; i <= n; i++) {
			edge[i].clear();
			f[i][0] = f[i][1] = f[i][2] = 0;
		}
	}
}
