#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

char BUF[1 << 22], *ST, *EN;
#define gc (ST == EN && (ST = BUF, EN = BUF + fread(BUF, 1, 1 << 21, stdin), ST == EN) ? EOF : *ST++)
 
template<class T> void read(T &x){
	int f=0; x=0; char ch=gc;
	for(;!isdigit(ch);ch=gc) f|=(ch=='-');
	for(;isdigit(ch);ch=gc) x=x*10+ch-'0';
	if(f) x=-x;
}

const int maxn = 1000000;
int to[maxn + 11],siz[maxn + 11],val[maxn + 11],front[maxn + 11],nxt[maxn + 11],dep[maxn + 11],s[maxn + 11];
int dfn[maxn + 11],w[maxn + 11];
int f[maxn + 11][22];
pair <int,int> up[maxn + 11];
vector <int> key,edge[maxn + 11];
int tot = 0 , cnt = 0 , top;

struct node {
	int op,u,v,k;
}que[maxn + 11];

void dfs(int x,int fa) {
	dep[x] = dep[fa] + 1;
	f[x][0] = fa;
	for (int i = 1; i < 20; i++) f[x][i] = f[f[x][i - 1]][i - 1];
	dfn[x] = ++tot;
	for (auto v : edge[x]) {
		if (v == fa) continue;
		dfs(v , x);
	} 
} 

int len(int u,int v) {
	if (dfn[u] < dfn[v]) swap(u , v);
	int ans = 0;
	for (int i = 19; i >= 0; i--) if (dfn[f[u][i]] >= dfn[v]) { ans += (1 << i); u = f[u][i]; }
	return ans;
}

void add(int u,int v) {
	int l = len(u , v) - 1;
	siz[++cnt] = l; val[cnt] = 0; to[cnt] = v; nxt[cnt] = front[u]; front[u] = cnt;
	siz[++cnt] = l; val[cnt] = 0; to[cnt] = u; nxt[cnt] = front[v]; front[v] = cnt;
}

int lca(int x,int y) {
	if (dep[x] < dep[y]) swap(x , y);
	for (int i = 19; i >= 0; i--) if (dep[f[x][i]] >= dep[y]) x = f[x][i];
	for (int i = 19; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i]; y = f[y][i];
		}
	}
	if (x == y) return x;
	return f[x][0];
}

void insert(int x) { 
	if (top == 1) { s[++top] = x; return; }
	int Lca = lca(x , s[top]);
	if (Lca == s[top]) { s[++top] = x; return; }
	while (top > 1 && dfn[s[top - 1]] >= dfn[Lca]) { add(s[top] , s[top - 1]); top--; }
	if (s[top] != Lca) { add(Lca , s[top]); s[top] = Lca; }
	s[++top] = x;
} 

void dfs2(int x,int fa) {
	for (int i = front[x]; i ; i = nxt[i]) {
		int v = to[i];
		if (v == fa) continue;
		up[v] = make_pair(x , i);
		dfs2(v , x);
	}
}

int main(){ 
	int t; read(t);
	while (t--) {
		int n,m; read(n); read(m);
		for (int i = 1; i <= n; i++) edge[i].clear() , front[i] = w[i] = 0;
 		for (int i = 1; i < n; i++) { 
			int u,v; read(u); read(v);
			edge[u].pb(v); edge[v].pb(u);
		}
		tot = 0; dfs(1 , 0);
		key.clear();
		for (int i = 1; i <= m; i++) {
			read(que[i].op); read(que[i].u); read(que[i].v);
			if (que[i].op <= 3 || que[i].op == 7) read(que[i].k);
			key.pb(que[i].u); key.pb(que[i].v); key.pb(lca(que[i].u , que[i].v));
		} 
		sort(all(key) , [&](int x,int y) { return dfn[x] < dfn[y]; } );
		key.erase(unique(all(key)) , key.end());
		s[top = 1] = 1;
		for (auto u : key) insert(u);
		while (top > 1) { add(s[top] , s[top - 1]); top--; } 
		cnt = 0; dfs2(1 , 0);
		for (int i = 1; i <= m; i++) {
			int op = que[i].op , u = que[i].u , v = que[i].v , k = que[i].k;
			if (op == 1) {
				int Lca = lca(u , v) , x = u;
				while (x != Lca) { w[x] += k; val[up[x].second] += k; x = up[x].first; }
				x = v;
				while (x != Lca) { w[x] += k; val[up[x].second] += k; x = up[x].first; }
				w[Lca] += k;
			} 
			if (op == 2) {
				int Lca = lca(u , v) , x = u;
				while (x != Lca) { w[x] ^= k; val[up[x].second] ^= k; x = up[x].first; }
				x = v;
				while (x != Lca) { w[x] ^= k; val[up[x].second] ^= k; x = up[x].first; }
				w[Lca] ^= k;
			} 
			if (op == 3) {
				int Lca = lca(u , v) , x = u;
				while (x != Lca) { if (w[x] >= k) w[x] -= k; if (val[up[x].second] >= k) val[up[x].second] -= k; x = up[x].first; }
				x = v;
				while (x != Lca) { if (w[x] >= k) w[x] -= k; if (val[up[x].second] >= k) val[up[x].second] -= k; x = up[x].first; }
				if (w[Lca] >= k) w[Lca] -= k;
			}
			if (op == 4) {
				ll sum = 0;
				int Lca = lca(u , v) , x = u;
				while (x != Lca) { sum += w[x]; sum += 1ll * val[up[x].second] * siz[up[x].second]; x = up[x].first; }
				x = v;
				while (x != Lca) { sum += w[x]; sum += 1ll * val[up[x].second] * siz[up[x].second]; x = up[x].first; }
				sum += w[Lca];
				printf("%lld\n" , sum);
			}
			if (op == 5) {
				int Xor = 0;
				int Lca = lca(u , v) , x = u;
				while (x != Lca) { Xor ^= w[x]; if (siz[up[x].second] & 1) Xor ^= val[up[x].second]; x = up[x].first; }
				x = v;
				while (x != Lca) { Xor ^= w[x]; if (siz[up[x].second] & 1) Xor ^= val[up[x].second]; x = up[x].first; }
				Xor ^= w[Lca];
				printf("%d\n" , Xor);
			}
			if (op == 6) {
				int mx = 0 , mn = 1e9;
				int Lca = lca(u , v) , x = u;
				while (x != Lca) { mx = max(w[x] , mx); mn = min(w[x] , mn); if (siz[up[x].second]) mx = max(val[up[x].second] , mx) , mn = min(val[up[x].second] , mn); x = up[x].first; }
				x = v;
				while (x != Lca) { mx = max(w[x] , mx); mn = min(w[x] , mn); if (siz[up[x].second]) mx = max(val[up[x].second] , mx) , mn = min(val[up[x].second] , mn); x = up[x].first; }
				mx = max(mx , w[Lca]); mn = min(mn , w[Lca]);
				printf("%d\n" , mx - mn);
			}
			if (op == 7) {
				int ans = 1e9;
				int Lca = lca(u , v) , x = u;
				while (x != Lca) { ans = min(ans , abs(w[x] - k)); if (siz[up[x].second]) ans = min(ans , abs(val[up[x].second] - k)); x = up[x].first; }
				x = v;
				while (x != Lca) { ans = min(ans , abs(w[x] - k)); if (siz[up[x].second]) ans = min(ans , abs(val[up[x].second] - k)); x = up[x].first; }
				ans = min(ans , abs(w[Lca] - k));
				printf("%d\n" , ans);
			} 
		} 
	} 
} 
