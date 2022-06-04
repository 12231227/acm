#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back

using namespace std;

const int maxn = 1e5;
int color[maxn + 11];
pair<int ,int > ins[3 * maxn + 11];
vector <int> edge[maxn + 11];

int main(){
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		ins[i] = make_pair(u , v);
		edge[u].pb(v);
		edge[v].pb(u);
	}
	color[1] = 1;
	for (auto u : edge[1]) color[u] = 2;
	for (int i = 1; i <= n; i++) if (color[i] == 0) color[i] = 1;
	if (edge[1].size() == 0) { printf("-1\n"); return 0; }
	int u = edge[1][0];
	for (auto v : edge[u]) if (color[v] != 1) color[v] = 3;
	for (int i = 1; i <= m; i++)
		if (color[ins[i].first] == color[ins[i].second]) { printf("-1\n"); return 0; } 
	int has[4] = {0};
	for (int i = 1; i <= n; i++) has[color[i]]++;
	for (int i = 1; i <= 3; i++) if (has[i] == 0) { printf("-1\n"); return 0; } 
	ll res = 1ll * has[1] * has[2] + 1ll * has[3] * has[2] + 1ll * has[1] * has[3];
	if (res != m) { printf("-1\n"); return 0; } 
	for (int i = 1; i <= n; i++) printf("%d ",color[i]);
}
