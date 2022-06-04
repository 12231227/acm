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
int fa[maxn + 11][25];
int bit[maxn + 11],ans[maxn + 11],lg[maxn + 11],age[maxn + 11];
vector <int> tag[maxn + 11],edge[maxn + 11];
int n,m;

int lowbit(int x) { return x & (-x); }
void update(int x,int val) { for (; x <= maxn; x += lowbit(x)) bit[x] += val; }
int query(int x) { int ans = 0; for (; x ; x -= lowbit(x)) ans += bit[x]; return ans; }

void dfs(int x,int f) {
	for (int i = 1; i <= lg[n]; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for (auto v : edge[x]) {
		if (v == f) continue;
		dfs(v , x);
	}
} 

int find(int x,int r) {
	for (int i = lg[n]; i >= 0; i--) { 
		if (fa[x][i] == 0) continue;
		if (age[fa[x][i]] > r) continue;
		x = fa[x][i];
	}
	return x;
} 

void dfs2(int x,int f) {
	for (auto u : tag[x]) update(u , 1);
	ans[x] = query(age[x]);
	for (auto v : edge[x]) {
		if (v == f) continue;
		dfs2(v , x);
	}
	for (auto u : tag[x]) update(u , -1);
}

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	lg[1] = 0;
	for (int i = 2; i <= n; i *= 2) { 
		lg[i] = lg[i / 2] + 1;
		for (int j = i + 1; j <= min(i * 2 , n); j++) lg[j] = lg[i];
	} 
	for (int i = 1; i <= n; i++) cin >> age[i] >> fa[i][0];
	fa[1][0] = 0;
	for (int i = 2; i <= n; i++) { 
		edge[fa[i][0]].pb(i);
		edge[i].pb(fa[i][0]);
	} 
	dfs(1 , 0);
	for (int i = 1; i <= m; i++) { 
		int o,l,r; cin >> o >> l >> r;
		int f = find(o , r);
		tag[f].pb(l);
	} 
	dfs2(1 , 0);
	for (int i = 1; i <= n; i++) printf("%d%s" , ans[i] , i == n ? "\n" : " ");
} 