#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const ll inf = 1e16;
const int maxn =1e5;


ll res;
vector <int> edge[maxn + 11];
int deg[maxn + 11];
int tmp[maxn + 11],color[maxn + 11];
ll c[3][maxn + 11]; 

void dfs(int x,int fa,int c1,int c2) {
	for (int i = 0; i < edge[x].size(); i++) {
		int v = edge[x][i];
		if (v == fa) continue;
		int cn = 3 ^ c1 ^ c2;
		res += c[cn][v];
		color[v] = cn;
		dfs(v , x , c2 , cn);
	}
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[0][i];
	for (int i = 1; i <= n; i++) cin >> c[1][i];
	for (int i = 1; i <= n; i++) cin >> c[2][i];
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
		deg[u]++;
		deg[v]++;
	}
	for (int i = 1; i <= n; i++) if (deg[i] > 2) { printf("-1\n"); return 0; }
	int s;
	for (int i = 1; i <= n; i++) if (deg[i] == 1) { s = i; break; }
	ll ans = inf;
	for (int c1 = 0; c1 < 3; c1++)
		for (int c2 = 0; c2 < 3; c2++) if (c1 != c2){
			res = c[c1][s] + c[c2][edge[s][0]];
			color[s] = c1; color[edge[s][0]] = c2;
			dfs(edge[s][0] , s, c1 , c2);
			if (ans > res) {
				ans = res;
				for (int i = 1; i <= n; i++) tmp[i] = color[i];
			}
		}
	cout << ans << endl;
	for (int i = 1; i <= n; i++) cout << tmp[i] + 1 << " ";
}

