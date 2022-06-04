#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

const int maxn = 2e5;
queue <int> q;
vector <int> edge[maxn + 11];
int score[maxn + 11],deg[maxn + 11];
ll line[maxn + 11];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) scanf("%d",&score[i]);
	for (int i = 1; i <= m; i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		edge[u].push_back(v); deg[u]++;
		edge[v].push_back(u); deg[v]++;
	}
	int s;
	scanf("%d",&s);
	for (int i = 1; i <= n; i++) if (deg[i] == 1 && i != s) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop(); deg[u] = -1;
		for (int i = 0; i < edge[u].size(); i++) { 
			int v = edge[u][i];
			if (deg[v] == -1) continue;
			line[v] = max(line[v] , line[u] + score[u]);
			if (--deg[v] == 1 && v != s) q.push(v);
		} 
	} 
	ll ans = 0;
	ll maxx = 0;
	for (int i = 1; i <= n; i++)
	 if (deg[i] != -1) {
	 	ans += score[i];
	 	maxx = max(maxx  , line[i]);
	 } 
	printf("%lld\n" , ans + maxx);
} 

