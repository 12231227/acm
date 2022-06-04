#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 100000;

char BUF[1 << 22], *ST, *EN;
#define gc (ST == EN && (ST = BUF, EN = BUF + fread(BUF, 1, 1 << 21, stdin), ST == EN) ? EOF : *ST++)
template<class T> void read(T &x){
	int f=0; x=0; char ch=gc;
	for(;!isdigit(ch);ch=gc) f|=(ch=='-');
	for(;isdigit(ch);ch=gc) x=x*10+ch-'0';
	if(f) x=-x;
}

struct node{
	ll val,sum;
}tree[4 * maxn + 11];
ll a[maxn + 11],b[maxn + 11];

void push_up(int rt) {
	tree[rt].sum = tree[lson].sum + tree[rson].sum;
	tree[rt].val = tree[lson].val + tree[rson].val;
}

void upd(int rt) { tree[rt].sum = tree[rt].val > 0 ? tree[rt].val : 0; }

void build(int rt,int l,int r) {
	if (l == r) { tree[rt].val = b[l]; upd(rt); return; }
	int mid = (l + r) >> 1;
	build(lson , l , mid); build(rson , mid + 1 , r);
	push_up(rt);
}

ll query_1(int rt,int l,int r,int al,int ar) {
	if (l > ar || r < al) return 0;
	if (l >= al && r <= ar) return tree[rt].val;
	int mid = (l + r) >> 1;
	return query_1(lson , l , mid , al , ar) + query_1(rson , mid + 1 , r , al , ar);
}

ll query_2(int rt,int l,int r,int al,int ar) {
	if (al > ar) return 0;
	if (l > ar || r < al) return 0;
	if (l >= al && r <= ar) return tree[rt].sum;
	int mid = (l + r) >> 1;
	return query_2(lson , l , mid , al , ar) + query_2(rson , mid + 1 , r , al , ar);
}

void update(int rt,int l,int r,int pos,int val) {
	if (l == r) { tree[rt].val += val; upd(rt); return; }
	int mid = (l + r) >> 1;
	if (mid >= pos) update(lson , l , mid , pos , val);
	else update(rson , mid + 1 , r , pos , val);
	push_up(rt);
}

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; read(t);
	while (t--) {
		int n,m; read(n); read(m);
		for (int i = 1; i <= n; i++) read(a[i]);
		for (int i = 1; i <= n; i++) b[i] = a[i] - a[i - 1];
		build(1 , 1 , n);
		for (int i = 1; i <= m; i++) {
			int op,l,r; read(op); read(l); read(r);
			if (op == 1) {
				int k; read(k);
				update(1 , 1 , n , l , k);
				if (r < n) update(1 , 1 , n , r + 1 , -k);
			}
			else printf("%lld\n" , query_1(1 , 1 , n , 1 , l) + query_2(1 , 1 , n , l + 1 , r));
		}
	} 
} 
