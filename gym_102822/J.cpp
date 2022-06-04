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
int a[maxn + 11];
int lazy[4 * maxn + 11],tree[4 * maxn + 11];

void build(int rt,int l,int r) {
	lazy[rt] = tree[rt] = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(lson , l , mid);
	build(rson , mid + 1 , r);
} 

void push_up(int rt) { tree[rt] = max(tree[lson] , tree[rson]); }
void push_down(int rt) {
	int val = lazy[rt]; lazy[rt] = 0;
	tree[lson] = max(tree[lson] , val); tree[rson] = max(tree[rson] , val);
	lazy[lson] = max(lazy[lson] , val); lazy[rson] = max(lazy[rson] , val);
}

void update(int rt,int l,int r,int al,int ar,int val) {
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) {
		tree[rt] = max(tree[rt] , val);
		lazy[rt] = max(lazy[rt] , val);
		return;
	} 
	if (lazy[rt]) push_down(rt);
	int mid = (l + r) >> 1;
	update(lson , l , mid , al , ar , val);
	update(rson , mid + 1 , r , al , ar , val);
	push_up(rt);
} 

int query(int rt,int l,int r,int pos) {
	if (l == r) return tree[rt];
	int mid = (l + r) >> 1;
	if (lazy[rt]) push_down(rt);
	if (mid >= pos) return query(lson , l , mid , pos);
	return query(rson , mid + 1 , r , pos);
} 

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	for (int o = 1; o <= t; o++) {
		int n,m; cin >> n >> m;
		for (int i = 1; i <= m; i++) a[i] = 0;
		for (int i = 1; i <= n; i++) {
			int t,x; cin >> t >> x;
			t = min(t , m);
			a[t] = max(a[t] , x);
		}
		build(1 , 1 , m);
		for (int i = 1; i <= m; i++) { 
			for (int k = 0; 2 * k * i + 1 <= m; k++) {
				int l = 2 * k * i + 1;
				int r = min(2 * k * i + i , m);
				update(1 , 1 , m , l , r , a[i]);
			}
		} 
		printf("Case #%d: " , o);
		for (int i = 1; i <= m; i++) printf("%d%s" , query(1 , 1 , m , i) , i == m ? "\n" : " ");
	} 
} 

