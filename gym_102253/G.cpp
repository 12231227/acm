#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int inf = 1e9;
const int maxn = 1e5;
int L[maxn + 11],R[maxn + 11],pl[maxn + 11],pr[maxn + 11],id[maxn + 11],fa[maxn + 11],dif[maxn + 11],ang[maxn + 11],rad[maxn + 11],rev[maxn + 11],B[maxn + 11],s[maxn + 11],e[maxn + 11];
int tree[4 * maxn + 11],lazy[4 * maxn + 11];
vector <int> av[maxn + 11],edge[maxn + 11];
bool up[maxn + 11],vis[maxn + 11];
int block;

int Tot = 0;

int log2(int x) { int ans = 0; while (x > 1) { ans++; x /= 2; } return ans; }

int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }

void merge(int x,int y) { int fax = get(x) , fay = get(y); if (fax == fay) return; fa[fax] = fay; } 

void dfs(int x,int fa) { 
	B[x] = block;
	vis[x] = true;
	L[x] = ++Tot; id[Tot] = x;
	for (auto u : av[x]) { 
		pl[u] = pr[u] = 0;
		for (auto v : edge[u]) { 
			if (ang[v] == fa) continue;
			dif[ang[v]] = dif[x] + rad[u] - rad[v];
			up[v] = true;
			dfs(ang[v] , x);
			if (!pl[u]) pl[u] = L[ang[v]];
			pr[u] = max(pr[u] , R[ang[v]]);
		} 
	} 
	R[x] = Tot;
} 

void build(int rt,int l,int r,int op) {
	if (!op) {
		tree[rt] = lazy[rt] = 0;
		if (l == r) return;
	}
	if (l == r) { tree[rt] =  dif[id[l]]; return; }
	int mid = (l + r) >> 1;
	build(lson , l , mid , op); build(rson , mid + 1 , r , op);
	tree[rt] = max(tree[lson] , tree[rson]);
}

void push_down(int rt) {
	int val = lazy[rt]; lazy[rt] = 0;
	tree[lson] += val; tree[rson] += val;
	lazy[lson] += val; lazy[rson] += val;
}

void update(int rt,int l,int r,int al,int ar,int val) {
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) { tree[rt] += val; lazy[rt] += val; return; }
	int mid = (l + r) >> 1;
	if (lazy[rt] != 0) push_down(rt);
	update(lson , l , mid , al , ar , val); update(rson , mid + 1 , r , al , ar , val);
	tree[rt] = max(tree[lson] , tree[rson]);
}

int query(int rt,int l,int r,int al,int ar) {
	if (l > ar || r < al) return -inf;
	if (l >= al && r <= ar) return tree[rt];
	int mid = (l + r) >> 1;
	if (lazy[rt] != 0) push_down(rt);
	return max(query(lson , l , mid , al , ar) , query(rson , mid + 1 , r , al , ar));
}

int main(){ 
	int n,m,q;
	int k = 0;
	while (~scanf("%d %d %d",&n,&m,&q)) {
		Tot = 0;
		for (int i = 1; i <= n; i++) { int x; scanf("%d",&x); rad[i] = log2(x); }
		for (int i = 1; i <= n; i++) ang[i] = -1 , fa[i] = i , up[i] = vis[i] = false , av[i].clear() , edge[i].clear() , pl[i] = pr[i] = 0;
		int tot = 0;
		for (int i = 1; i <= m; i++) {
			int a,x,y; scanf("%d %d %d",&a,&x,&y);
			if (a == 1) { edge[x].pb(y); edge[y].pb(x); }
			else merge(x , y);
		} 
		for (int i = 1; i <= n; i++) {
			fa[i] = get(i);
			if (fa[i] == i) rev[i] = ++tot;
		}
		for (int i = 1; i <= n; i++) {
			ang[i] = rev[fa[i]];
			av[ang[i]].pb(i);
		} 
		block = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[ang[i]]) {
				++block;
				s[block] = Tot + 1;
				dfs(ang[i] , 0);
				e[block] = Tot;
			}
		build(1 , 1 , tot , 0);
		build(1 , 1 , tot , 1);
		printf("Case #%d:\n" , ++k);
		while (q--) { 
			int a,x,y; scanf("%d %d %d",&a,&x,&y);
			if (a == 1) { 
				int newr = log2(y);
				if (pl[x]) update(1 , 1 , tot , pl[x] , pr[x] , newr - rad[x]);
				if (up[x]) update(1 , 1 , tot , L[ang[x]] , R[ang[x]] , rad[x] - newr);
				rad[x] = newr;
			} 
			else { 
				int fa = get(x);
				int ans = query(1 , 1 , tot , s[B[ang[fa]]] , e[B[ang[fa]]]) - query(1 , 1 , tot , L[ang[x]] , L[ang[x]]);
				printf("%.3lf\n" , log(y) + ans * log(2));
			} 
		} 
	} 
} 

