#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1e6;
ll tree[4 * maxn + 11],ls[4 * maxn + 11],rs[4 * maxn + 11],done[4 * maxn + 11];
int a[maxn + 11];
int N,sta;

void push_up(int rt) { tree[rt] = tree[ls[rt]] + tree[rs[rt]]; }

void build(int rt,int l,int r) {
	if (l == r) { tree[rt] = a[l]; return; }
	ls[rt] = lson; rs[rt] = rson;
	int mid = (l + r) >> 1;
	build(lson , l , mid); build(rson , mid + 1 , r);
	push_up(rt);
}

void update(int rt,int l,int r,int pos,int val,int d) {
	if (l == r) { tree[rt] = val; return; }
	int mid = (l + r) >> 1;
	if ((sta & (1 << (d - 1))) && !done[rt]) { swap(ls[rt] , rs[rt]); done[rt] = 1; }
	if (!(sta & (1 << (d - 1))) && done[rt]) { swap(ls[rt] , rs[rt]); done[rt] = 0; }
	if (mid >= pos) update(ls[rt] , l , mid , pos , val , d - 1);
	else update(rs[rt] , mid + 1 , r , pos , val , d - 1);
	push_up(rt);
}

ll query(int rt,int l,int r,int al,int ar,int d) {
	if (l > ar || r < al) return 0;
	if (l >= al && r <= ar) return tree[rt];
	if ((sta & (1 << (d - 1))) && !done[rt]) { swap(ls[rt] , rs[rt]); done[rt] = 1; }
	if (!(sta & (1 << (d - 1))) && done[rt]) { swap(ls[rt] , rs[rt]); done[rt] = 0; }
	int mid = (l + r) >> 1;
	return query(ls[rt] , l , mid , al , ar , d - 1) + query(rs[rt] , mid + 1 , r , al , ar , d - 1);
}

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,q; cin >> n >> q;
	N = (1 << n);
	for (int i = 1; i <= N; i++) cin >> a[i];
	build(1 , 1 , N);
	sta = 0;
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int x,k; cin >> x >> k;
			update(1 , 1 , N , x , k , n);
		}
		else if (op == 2) {
			int k; cin >> k;
			sta ^= (1 << k) - 1;
		}
		else if (op == 3) {
			int k; cin >> k;
			sta ^= (1 << k);
		}
		else if (op == 4) {
			int l,r; cin >> l >> r;
			printf("%lld\n" , query(1 , 1 , N , l , r , n));
		}
	}
} 
