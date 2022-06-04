#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
int f[maxn + 11],a[maxn + 11];
vector <int> edge[maxn + 11];

void dfs(int x,int fa) {
	f[x] = a[x] ? 1 : -1;
	for (auto v : edge[x]) {
		if (v == fa) continue;
		dfs(v , x);
		if (f[v] > 0) f[x] += f[v];
	}
}

void dfs2(int x,int fa) {
	if (f[x] <= 0) {
		if (f[fa] > 0) f[x] += f[fa];
	}
	else {
		if (f[fa] - f[x] > 0) f[x] += f[fa] - f[x];
	}
	for (auto v : edge[x]) {
		if (v == fa) continue;
		dfs2(v , x);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	for (int i = 1; i < n; i++) {
		int u,v;
		scanf("%d %d" , &u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1 , 0);
	dfs2(1 , 1);
	for (int i = 1; i <= n; i++) printf("%d " , f[i]);
} 

