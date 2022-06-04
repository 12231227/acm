#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int f[maxn + 11];
vector <int> edge[maxn + 11];

void dfs(int x,int fa) {
	for (auto v : edge[x]) {
		if (v == fa) continue;
		dfs(v , x);
		f[x] += f[v];
	}
	if (f[x]) f[x] -= 1;
	else f[x] = 1;
}

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i < n; i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1 , 0);
	if (!f[1]) printf("Bob\n"); else printf("Alice\n");
} 
