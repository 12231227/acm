#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pb emplace_back
using namespace std;
const ll mol = 1e9 + 7;
const ll inv = 500000004;
const int maxn = 3e5;

int m;
pair<int,int> qry[maxn + 11];
int p[maxn + 11];
vector <int> v;
struct node{
	ll l,r,ans;
	int cnt;
}tree[8 * maxn + 11];
ll two[maxn + 11];

ll qpow(ll a,ll b) { 
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mol;
		a = a * a % mol;
		b >>= 1;
	} 
	return ans;
} 

void push_up(int rt) {
	tree[rt].cnt = tree[lson].cnt + tree[rson].cnt;
	tree[rt].l = (tree[lson].l + tree[rson].l * two[tree[lson].cnt] % mol) % mol;
	tree[rt].r = (tree[rson].r + tree[lson].r * two[tree[rson].cnt] % mol) % mol;
	tree[rt].ans = ((tree[lson].ans * two[tree[rson].cnt] % mol + tree[rson].ans * two[tree[lson].cnt] % mol) % mol + tree[lson].l * tree[rson].r % mol) % mol;
}

ll sub(ll a,ll b) { a -= b; if (a < 0) a += mol; return a; }

void update(int rt,int l,int r,int pos,int val) {
	if (l > pos || r < pos) return;
	if (l == r) {
		if (val == 1){
			tree[rt].ans = (tree[rt].ans * 2 % mol + tree[rt].l * v[l - 1] % mol) % mol;
			tree[rt].l = (tree[rt].l * 2 + v[l - 1]) % mol;
			tree[rt].r = (tree[rt].r * 2 + v[l - 1]) % mol;
		}
		else {
			tree[rt].l = sub(tree[rt].l , v[l - 1]) * inv % mol;
			tree[rt].r = sub(tree[rt].r , v[l - 1]) * inv % mol;
			tree[rt].ans = sub(tree[rt].ans , tree[rt].l * v[l - 1] % mol) * inv % mol;
		}
		tree[rt].cnt += val;
		return;
	}
	int mid = (l + r) >> 1;
	update(lson , l , mid , pos , val);
	update(rson , mid + 1 , r , pos , val);
	push_up(rt);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) { cin >> p[i]; v.pb(p[i]); }
	two[0] = 1;
	for (int i = 1; i <= n; i++) two[i] = two[i - 1] * 2 % mol;
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> qry[i].first >> qry[i].second;
		v.pb(qry[i].second);
	}
	sort(all(v)); v.erase(unique(all(v)) , v.end());
	m = v.size();
	for (int i = 1; i <= n; i++) p[i] = lower_bound(all(v) , p[i]) - v.begin() + 1;
	for (int i = 1; i <= q; i++) qry[i].second = lower_bound(all(v) , qry[i].second) - v.begin() + 1;
	for (int i = 1; i <= n; i++) update(1 , 1 , m , p[i] , 1);
	ll fm = qpow(two[n] , mol - 2);
	cout << tree[1].ans * fm % mol << endl; 
	for (int i = 1; i <= q; i++) {
		int x = qry[i].first;
		update(1 , 1 , m , p[x] , -1);
		p[x] = qry[i].second;
		update(1 , 1 , m , p[x] , 1);
		cout << tree[1].ans * fm % mol << endl;
	} 
} 

