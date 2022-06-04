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
vector <int> v;
int h[maxn + 11],a[maxn + 11],b[maxn + 11];

struct node{
	ll k,b,tag;
}lazy[4 * maxn + 11],tree[4 * maxn + 11];

void push_up(int rt) { tree[rt].tag = max(tree[lson].tag , tree[rson].tag); }
void push_down(int rt) { 
	if (lazy[rt].tag >= 0) { 
		ll b = lazy[rt].tag;
		lazy[lson].tag = lazy[rson].tag = b;
		tree[lson].k = 0; tree[lson].b = b; tree[rson].k = 0; tree[rson].b = b; tree[lson].tag = tree[rson].tag = 0;
		lazy[lson].k = lazy[lson].b = lazy[rson].k = lazy[rson].b = 0;
		lazy[rt].tag = -1;
	}
	ll k = lazy[rt].k , b = lazy[rt].b;
	lazy[rt].k = lazy[rt].b = 0;
	tree[lson].tag += k; tree[lson].k += k; lazy[lson].k += k; lazy[lson].b += b; tree[lson].b += b;
	tree[rson].tag += k; tree[rson].k += k; lazy[rson].k += k; lazy[rson].b += b; tree[rson].b += b;
}

void update(int rt,int l,int r,int al,int ar,ll k,ll b) {
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) {
		tree[rt].tag += k; tree[rt].k += k; tree[rt].b += b;
		lazy[rt].k += k; lazy[rt].b += b;
		return;
	}
	push_down(rt);
	int mid = (l + r) >> 1;
	update(lson , l , mid , al , ar , k , b);
	update(rson , mid + 1 , r , al , ar , k , b);
	push_up(rt);
} 

void remove(int rt,int l,int r,int al,int ar,ll b) {
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) {
		tree[rt].tag = tree[rt].k = 0; tree[rt].b = b;
		lazy[rt].tag = b; lazy[rt].k = 0; lazy[rt].b = 0;
		return;
	}
	push_down(rt);
	int mid = (l + r) >> 1;
	remove(lson , l , mid , al , ar , b);
	remove(rson , mid + 1 , r , al , ar , b);
	push_up(rt);
}

int query(int rt,int l,int r) {
	if (l == r) return l;
	push_down(rt);
	int mid = (l + r) >> 1;
	if (tree[lson].tag >= 0) return query(lson , l , mid);
	return query(rson , mid + 1 , r);
}

pll find(int rt,int l,int r,int pos) {
	if (l == r) return make_pair(tree[rt].k , tree[rt].b);
	push_down(rt);
	int mid = (l + r) >> 1;
	if (pos <= mid) return find(lson , l , mid , pos);
	return find(rson , mid + 1 , r , pos);
}

void build(int rt,int l,int r) {
	tree[rt].tag = tree[rt].k = tree[rt].b = 0;
	lazy[rt].tag = -1;
	lazy[rt].k = lazy[rt].b = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(lson , l , mid); build(rson , mid + 1 , r);
}

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		v.clear();
		for (int i = 1; i <= n; i++) cin >> h[i] , v.pb(h[i]);
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		sort(all(v)); v.erase(unique(all(v)) , v.end());
		v.pb(inf);
		int m = v.size();
		build(1 , 1 , m);
		for (int i = 1; i <= n; i++) h[i] = lower_bound(all(v) , h[i]) - v.begin() + 1;
		for (int i = 1; i <= n; i++) { 
			update(1 , 1 , m , h[i] + 1 , m , a[i] , -1ll * a[i] * v[h[i] - 1]);
			update(1 , 1 , m , 1 , h[i] , -b[i] , 1ll * b[i] * v[h[i] - 1]);
			int ind = query(1 , 1 , m);
			ll x = v[ind - 2];
			pll pi = find(1 , 1 , m , ind);
			ll B = 1ll * x * pi.first + pi.second;
			remove(1 , 1 , m , ind , m , B);
		} 
		int ind = query(1 , 1 , m);
		pll pi = find(1 , 1 , m , ind);
		ll x = v[ind - 2];
		ll ans = 1ll * x * pi.first + pi.second;
		printf("%lld\n" , ans);
	} 
} 

/*
10
2 3 1 10 2 4 7 2 7 5
6 13 9 11 17 16 2 3 15 20
4 20 18 13 10 3 3 13 4 14
*/

