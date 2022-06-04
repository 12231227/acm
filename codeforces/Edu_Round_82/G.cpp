#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
#define ll long long
using namespace std;

const ll inf = 1e9;
const int maxn = 150000;
ll ans = 0;

vector <int> edge[maxn + 11];
ll a[maxn + 11];
int dep[maxn + 11],f[maxn + 11],siz[maxn + 11];
bool vis[maxn + 11] = {false};
int root,all,minn;
int n;

struct Line{
	ll k,b;
	Line() { k = b = -inf; }
	Line(ll k,ll b) { this -> k = k; this -> b = b; }
	ll at(int x) { return k * x + b; }
};

struct LiChao{
	Line tree[4 * maxn + 11];
	int n;
	void build(int rt,int l,int r) {
		tree[rt] = Line();
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(lson , l , mid);
		build(rson , mid + 1 , r);
	}
	void clear(int _) { n = _; build(1 , 1 , _); }

	void update(int rt,int l,int r,Line line) {
		int mid = (l + r) >> 1;
		if (tree[rt].at(mid) < line.at(mid)) swap(tree[rt] , line);
		if (l == r) return;
		if (tree[rt].at(l) < line.at(l)) update(lson , l , mid , line);
		else update(rson , mid + 1 , r , line);
	}
	void modify(int rt,int l,int r,int al,int ar,Line line) {
		if (l > ar || r < al) return;
		if (l >= al && r <= ar) {
			update(rt , l , r , line);
			return;
		}
		int mid = (l + r) >> 1;
		modify(lson , l , mid , al , ar , line);
		modify(rson , mid + 1 , r , al , ar , line);
	}
	void add(int l,int r,ll k,ll b) { // 在[l,r]插入一条y=kx+b线段 
		modify(1 , 1 , n , l , r , Line{k , b});
	}

	ll query(int rt,int l,int r,int x) {
		if (l == r) return tree[rt].at(x);
		int mid = (l + r) >> 1;
		if (mid >= x) return max(tree[rt].at(x) , query(lson , l , mid , x));
		return max(tree[rt].at(x) , query(rson , mid + 1 , r , x));
	}
	ll query(int x) {//查找x处的最大y
		return query(1 , 1 , n , x);
	}
}Lc;

void getroot(int x,int fa) {
	siz[x] = 1; f[x] = 0;
	for (auto v : edge[x]) {
		if (v == fa || vis[v]) continue;
		getroot(v , x);
		siz[x] += siz[v];
		if (siz[v] > f[x]) f[x] = siz[v];
	}
	f[x] = max(f[x] , all - siz[x]);
	if (f[x] < minn) { minn = f[x]; root = x; }
}

void setdep(int x,int fa) {
	for (auto v : edge[x]) {
		if (vis[v] || v == fa) continue;
		dep[v] = dep[x] + 1;
		setdep(v , x);
	}
}

ll query(int x,int fa,ll sum,ll val) {
	ll ans = Lc.query(dep[x]) + val;
	for (auto v : edge[x]) {
		if (v == fa || vis[v]) continue;
		ans = max(ans , query(v , x , sum + a[v] , val + sum + a[v]));
	}
	return ans;
}

void add(int x,int fa,ll sum,ll val) {
	ans = max(ans , val); Lc.add(1 , n , sum , val);
	for (auto v : edge[x]) {
		if (vis[v] || v == fa) continue;
		add(v , x , sum + a[v] , val + a[v] * (dep[v] + 1));
	}
}

void divide(int x) {
	vis[x] = true;
	if (minn == 0) { ans = max(ans , a[x]); return; }
	Lc.clear(minn);
	Lc.add(1 , minn , a[x] , a[x]);
	for (auto v : edge[x]) {
		if (vis[v]) continue;
		ans = max(ans , query(v , x , a[v] , a[v]));
		add(v , x , a[x] + a[v] , a[x] + a[v] * 2);
	}
	
	reverse(edge[x].begin() , edge[x].end());
	Lc.clear(minn);
	Lc.add(1 , minn , a[x] , a[x]);
	
	for (auto v : edge[x]) {
		if (vis[v]) continue;
		ans = max(ans , query(v , x , a[v] , a[v]));
		add(v , x , a[x] + a[v] , a[x] + a[v] * 2);
	}

	for (auto v : edge[x]) {
		if (vis[v]) continue;
		all = minn = siz[v]; root = 0;
		getroot(v , x); dep[root] = 0; setdep(root , x);
		divide(root);
	}
}

int main(){
	scanf("%d" , &n);
	for (int i = 1; i < n; i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) scanf("%lld" , &a[i]);
	all = minn = n; root = 0;
	getroot(1 , 0); dep[root] = 0; setdep(root , 0);
	divide(root);
	printf("%lld\n" , ans);
} 

