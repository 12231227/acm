#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 3e5;
const ll mol = 998244353;
ll f[maxn + 11][5];

vector <int> edge[maxn + 11];
ll add(ll a,ll b) { a += b; if (a >= mol) a -= mol; return a; }
ll sub(ll a,ll b) { a -= b; if (a < 0) a += mol; return a; }

void dfs(int x,int fa) {
	ll tmp[10];
	tmp[0] = tmp[1] = tmp[2] = 1;
	for (auto v : edge[x]) {
		if (v == fa) continue;
		dfs(v , x);
		tmp[0] = tmp[0] * add(add(f[v][0] , f[v][1]) , f[v][2]) % mol;
		tmp[1] = tmp[1] * add(add(3 * f[v][0] % mol , 2 * f[v][1] % mol) , 2 * f[v][2] % mol) % mol;
		tmp[2] = tmp[2] * add(add(2 * f[v][0] % mol , 2 * f[v][1] % mol) , f[v][2] % mol) % mol;
	}
	f[x][0] = tmp[0];
	f[x][1] = sub(tmp[1] , tmp[0]);
	f[x][2] = sub(tmp[2] , tmp[0]);
} 

int main(){ 
	int n; scanf("%d",&n);
	for (int i = 1; i < n; i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	} 
	dfs(1 , 0);
	printf("%lld\n" , sub(add(add(f[1][0] , f[1][1]) , f[1][2]) , 1));
} 

