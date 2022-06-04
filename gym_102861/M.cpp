#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
using namespace std;

const int P = 5782344;
const int mol = 1e9 + 7;
const int maxn = 1e5;

int fac[maxn + 11],x[maxn + 11],y[maxn + 11];
vector <int> Y,v1,v2;

struct node {
	int fi; ll se; int id;
};

struct Segment_Tree{
	vector <pli> tree[4 * maxn + 11];
 	vector <node> v;

	void update(int rt,int l,int r,int pos,pli pi) {
		tree[rt].pb(pi);
		if (l == r) return;
		int mid = (l + r) >> 1;
		if (mid >= pos) update(lson , l , mid , pos , pi);
		else update(rson , mid + 1 , r , pos , pi);
	}
 
	void query(int rt,int l,int r,int al,int ar,ll val,vector <int> &v) {
		if (l > ar || r < al) return;
		if (l >= al && r <= ar) { 
			for (auto u : tree[rt]) {
				if (u.first <= val) v.pb(u.second); else break;
			}
			return;
		}
		int mid = (l + r) >> 1;
		query(lson , l , mid , al , ar , val , v); query(rson , mid + 1 , r , al , ar , val , v);
	}
}add,sub;

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,q; cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		Y.pb(y[i]);
		sub.v.pb(node{y[i] , 2ll * y[i] - x[i] , i});
		add.v.pb(node{y[i] , -2ll * y[i] - x[i] , i});
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * P % mol;
	sort(all(Y)); Y.erase(unique(all(Y)) , Y.end());
	int m = Y.size();
	for (int i = 0; i < n; i++) {
		node pi = add.v[i];
		int ind = lower_bound(all(Y) , pi.fi) - Y.begin() + 1;
		add.v[i].fi = ind;
		pi = sub.v[i];
		ind = lower_bound(all(Y) , pi.fi) - Y.begin() + 1;
		sub.v[i].fi = ind;
	}
	sort(all(add.v) , [&](node a,node b) {
		if (a.se != b.se) return a.se < b.se;
		return a.id < b.id;
	});
	sort(all(sub.v) , [&](node a,node b) {
		if (a.se != b.se) return a.se < b.se;
		return a.id < b.id;
	});
	for (auto pi : sub.v) sub.update(1 , 1 , m , pi.fi , make_pair(pi.se , pi.id));
	for (auto pi : add.v) add.update(1 , 1 , m , pi.fi , make_pair(pi.se , pi.id));
	ll p = 0;
	while (q--) {
		ll a,b; cin >> a >> b;
		a = -1 - (p + a) % mol; b = (p + b) % mol;
		v1.clear(); v2.clear();
		int ind = lower_bound(all(Y) , b) - Y.begin() + 1;
		if (ind <= m) sub.query(1 , 1 , m , ind , m , 2 * b - a , v1);
		ind--;
		if (ind > 0) add.query(1 , 1 , m , 1 , ind , -2 * b - a , v2);
		for (auto u : v2) v1.pb(u);
		sort(all(v1));
		p = 0;
		for (int i = 0; i < v1.size(); i++) p = (p + 1ll * v1[i] * fac[i] % mol) % mol;
		cout << p << endl;
	}
} 
