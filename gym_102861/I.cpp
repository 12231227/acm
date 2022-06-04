#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1e5;
const int mol = 1e9 + 7;

vector <int> edge[maxn + 11];
int f[maxn + 11][2],fa[maxn + 11];
int pre[maxn + 11],suf[maxn + 11];

int add(int a,int b) { a += b; if (a >= mol) a -= mol; return a; }
int qpow(int a,int b) { 
	int ans = 1;
	while (b) { 
		if (b & 1) ans = 1ll * ans * a % mol;
		a = 1ll * a * a % mol;
		b >>= 1;
	} 
	return ans;
} 

void dfs(int x) { 
	if (edge[x].empty()) { f[x][0] = f[x][1] = 1; return; }
	for (auto u : edge[x]) dfs(u);
	int n = edge[x].size();
	pre[0] = 1; suf[n + 1] = 1;
	for (int i = 0; i < n; i++) pre[i + 1] = 1ll * pre[i] * f[edge[x][i]][0] % mol;
	for (int i = n - 1; i >= 0; i--) suf[i + 1] = 1ll * suf[i + 2] * f[edge[x][i]][0] % mol;
	for (int i = 1; i <= n; i++) f[x][1] = add(f[x][1] , 1ll * pre[i - 1] * suf[i + 1] % mol * f[edge[x][i - 1]][1] % mol);
	f[x][0] = add(f[x][1] , pre[n]);
	//assert(f[x][0] > 0);
} 

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 2; i <= n; i++) { 
		int p; cin >> p;
		edge[p].pb(i);
	} 
	dfs(1);
	printf("%d\n" , f[1][0]);
} 
