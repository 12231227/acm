#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
int dis[maxn + 11],p[maxn + 11];
bool vis[maxn + 11] = {false};
vector <int> edge[maxn + 11],g[maxn + 11];

void dij(int s) {
	queue <int> q;
	memset(dis , 0x3f3f3f , sizeof(dis));
	dis[s] = 0; q.push(s); vis[s] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : g[u]) {
			if (vis[v]) continue;
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.push(v);
				vis[v] = true;
			}
		}
	}
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= m; i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		edge[u].push_back(v);
		g[v].push_back(u);
	}
	int k;
	scanf("%d" , &k);
	for (int i = 1; i <= k; i++) scanf("%d" , &p[i]);
	dij(p[k]);
	int mx , mn;
	mn = mx = 0;
	for (int i = 1; i < k; i++) {
		int cr = dis[p[i + 1]];
		int best = dis[p[i + 1]] + 1;
		for (auto v : edge[p[i]]) {
			if (v == p[i + 1]) continue;
			best = min(best , dis[v]);
		}
		if (best < cr) { mn++; mx++; }
		else if (best == cr) mx++;
	}
	printf("%d %d\n" , mn , mx);
} 

