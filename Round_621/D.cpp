#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
int d1[maxn + 11],d2[maxn + 11];
pair <int,int> pi[maxn + 11],mx[maxn + 11];
bool vis[maxn + 11];
int a[maxn + 11];
vector <pair<int,int> > A,B;
int n,m,k;
vector <int> edge[maxn + 11];

void dij(int s,int dis[]) {
	memset(vis , false, sizeof(vis));
	for (int i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f;
	priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > q;
	vis[s] = true; dis[s] = 0; q.push({0 , s});
	while (!q.empty()) {
		auto pi = q.top(); q.pop();
		int u = pi.second;
		for (auto v : edge[u]) {
			if (vis[v]) continue;
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.push({dis[v] , v});
				vis[v] = true;
			}
		}
	}
}

int main(){
	scanf("%d %d %d",&n,&m,&k);
	for (int i = 1; i <= k; i++) scanf("%d" , &a[i]);
	for (int i = 1; i <= m; i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dij(1 , d1);
	dij(n , d2);
	for (int i = 1; i <= k; i++) pi[i] = {d1[a[i]] - d2[a[i]] , a[i]};
	sort(pi + 1 , pi + 1 + k);
	mx[k + 1] = {0 , 0};
	for (int i = k; i >= 1; i--) mx[i] = max(mx[i + 1] , {d2[pi[i].second] , pi[i].second});
	int x,y;
	int ans = 0;
	for (int i = 1; i < k; i++) {
		if (d1[pi[i].second] + mx[i + 1].first > ans) {
			ans = d1[pi[i].second] + mx[i + 1].first;
			x = pi[i].second; y = mx[i + 1].second;
		}
	}
	edge[x].push_back(y);
	edge[y].push_back(x);
	dij(1 , d1);
	printf("%d\n" , d1[n]);
} 

