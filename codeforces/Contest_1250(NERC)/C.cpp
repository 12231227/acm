#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
#define pb emplace_back
#define ll long long
using namespace std;

const ll inf = -4e18;
const int maxn = 2e5;
ll k;

vector <pair<int,ll> > out[maxn + 11];
int l[maxn + 11],r[maxn + 11];
ll p[maxn + 11],lazy[4 * maxn + 11];
pair<ll,int> tree[4 * maxn + 11];
vector <int> res;

void push_up(int rt) { tree[rt] = max(tree[lson] , tree[rson]); }

void build(int rt,int l,int r) {
	if (l == r) {
		tree[rt] = make_pair(-k * l , l);
		return;
	}
	int mid = (l + r) >> 1;
	build(lson , l , mid);
	build(rson , mid + 1 , r);
	push_up(rt);
} 

void push_down(int rt) {
	ll val = lazy[rt]; lazy[rt] = 0;
	tree[lson].first += val; tree[rson].first += val;
	lazy[lson] += val; lazy[rson] += val;
}

void update(int rt,int l,int r,int al,int ar,ll val) {
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) {
		tree[rt].first += val;
		lazy[rt] += val;
		return;
	}
	push_down(rt);
	int mid = (l + r) >> 1;
	update(lson , l , mid , al , ar , val);
	update(rson , mid + 1 , r , al , ar , val);
	push_up(rt);
}

pair<ll,int> query(int rt,int l,int r,int al,int ar) {
	if (l > ar || r < al) return make_pair(inf , 0);
	if (l >= al && r <= ar) return tree[rt];
	push_down(rt);
	int mid = (l + r) >> 1;
	return max(query(lson , l , mid , al , ar) , query(rson , mid + 1 , r , al , ar));
} 

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n >> k;
	int m = 0;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i] >> p[i];
		m = max(m , r[i]);
	}
	build(1 , 1 , m);
	for (int i = 1; i <= n; i++) {
		update(1 , 1 , m , r[i] , m , p[i]);
		out[l[i]].pb(r[i] , p[i]);
	}
	ll ans = 0; int L,R;
	for (int i = 1;i <= m; i++) {
		pair<ll,int> pi = query(1 , 1 , m , i , m);
		if (pi.first > ans) { ans = pi.first; L = i; R = pi.second; }
		update(1 , 1 , m , i , m , k);
		for (auto u : out[i]) {
			update(1 , 1 , m , u.first , m , -u.second);
		}
	}
	if (!ans) cout << ans << endl;
	else {
		res.clear();
		for (int i = 1; i <= n; i++)
			if (L <= l[i] && R >= r[i]) res.pb(i);
		cout << ans << " " << L << " " << R << " " << res.size() << endl;
		for (int i = 0; i < res.size(); i++){
			if (i) cout << " ";
			cout << res[i];
		}
		cout << endl;
	}
} 

