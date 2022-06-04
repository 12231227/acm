#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

const int maxn = 2e5;
int a[maxn + 11],p[maxn + 11],f[maxn + 11];
vector <int> edge[maxn + 11];
long long ans = 0;

void dfs(int x,int fa) {
	for (auto v : edge[x]) {
		if (v == fa) continue;
		f[v] = min(a[v] , f[x]);
		dfs(v , x);
	}
}

pair<int,int> dfs2(int x,int fa) {
	pair <int,int> pi = {0 , 0};
	if (p[x] > 0) pi = {1 , 0}; else if (p[x] < 0) pi = {0 , 1};
	for (auto v : edge[x]) {
		if (v == fa) continue;
		pair <int,int> t = dfs2(v , x);
		pi.first += t.first;
		pi.second +=  t.second;
	}
	int c = min(pi.first , pi.second);
	ans += 1ll * c * f[x];
	pi.first -= c; pi.second -= c;
	return pi;
}

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		int b,c;
		scanf("%d %d %d",&a[i],&b,&c);
		p[i] = b - c;
	}
	for (int i = 1; i < n; i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		edge[u].pb(v);
		edge[v].pb(u);
	}
	f[1] = a[1];
	dfs(1 , 0);
	pair <int,int> pi = dfs2(1 , 0);
	if (pi.first != pi.second) puts("-1");
	else {
		ans += 1ll * pi.first * f[1];
		printf("%lld\n" , ans * 2);
	}
	
} 
