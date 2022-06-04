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
int lazy[4 * maxn + 11][35],tree[4 * maxn + 11][35];
int a[maxn + 11];
int n,p;
int cnt[50],res[50],tran[50];
vector <int> v[45];

int gcd(int a,int b) { return b ? gcd(b , a % b) : a; }

int add(int a,int b) { a += b; return a; }

void push_up(int rt) { for (int i = 0; i < p; i++) tree[rt][i] = add(tree[lson][i] , tree[rson][i]); }

void push_down(int rt) { 
	for (int i = 0; i < p; i++) cnt[i] = lazy[rt][i] , lazy[rt][i] = i;
	int tmp[50];
	for (int i = 0; i < p; i++) tmp[i] = 0;
	for (int i = 0; i < p; i++) tmp[cnt[i]] = add(tmp[cnt[i]] , tree[lson][i]);
	for (int i = 0; i < p; i++) tree[lson][i] = tmp[i];
	for (int i = 0; i < p; i++) tmp[i] = 0;
	for (int i = 0; i < p; i++) tmp[cnt[i]] = add(tmp[cnt[i]] , tree[rson][i]);
	for (int i = 0; i < p; i++) tree[rson][i] = tmp[i];
	for (int i = 0; i < p; i++) lazy[lson][i] = cnt[lazy[lson][i]];
	for (int i = 0; i < p; i++) lazy[rson][i] = cnt[lazy[rson][i]];
} 

void build(int rt,int l,int r) {
	for (int i = 0; i < p; i++) lazy[rt][i] = i;
	if (l == r) { tree[rt][a[l]] = 1; return; }
	int mid = (l + r) >> 1;
	build(lson , l , mid); build(rson , mid + 1 , r);
	push_up(rt);
} 

void add(int rt,int l,int r,int al,int ar,int val) {
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) { 
		for (int i = 0; i < p; i++) cnt[i] = 0;
		for (int i = 0; i < p; i++) cnt[(i + val) % p] = add(cnt[(i + val) % p] , tree[rt][i]);
		for (int i = 0; i < p; i++) tree[rt][i] = cnt[i];
		for (int i = 0; i < p; i++) lazy[rt][i] = (lazy[rt][i] + val) % p;
		return;
	} 
	push_down(rt);
	int mid = (l + r) >> 1;
	add(lson , l , mid , al , ar , val); add(rson , mid + 1 , r , al , ar , val);
	push_up(rt);
} 

void mul(int rt,int l,int r,int al,int ar,int val) { 
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) { 
		for (int i = 0; i < p; i++) cnt[i] = 0;
		for (int i = 0; i < p; i++) cnt[(i * val) % p] = add(cnt[(i * val) % p] , tree[rt][i]);
		for (int i = 0; i < p; i++) tree[rt][i] = cnt[i];
		for (int i = 0; i < p; i++) lazy[rt][i] = lazy[rt][i] * val % p;
		return;
	} 
	push_down(rt);
	int mid = (l + r) >> 1;
	mul(lson , l , mid , al , ar , val); mul(rson , mid + 1 , r , al , ar , val);
	push_up(rt);
} 

int get(int x,int k) { return tran[x]; } 

int qpow(int a,int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1ll * ans * a % p;
		a = 1ll * a * a % p;
		b >>= 1;
	}
	return ans;
}

void kpow(int rt,int l,int r,int al,int ar,int k) { 
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) { 
		for (int i = 0; i < p; i++) cnt[i] = 0;
		for (int i = 0; i < p; i++) cnt[get(i , k)] = add(cnt[get(i , k)] , tree[rt][i]);
		for (int i = 0; i < p; i++) tree[rt][i] = cnt[i];
		for (int i = 0; i < p; i++) lazy[rt][i] = get(lazy[rt][i] , k);
		return;
	} 
	push_down(rt);
	int mid = (l + r) >> 1;
	kpow(lson , l , mid , al , ar , k); kpow(rson , mid + 1 , r , al , ar , k);
	push_up(rt);
} 

void query(int rt,int l,int r,int al,int ar) { 
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) { 
		for (int i = 0; i < p; i++) res[i] = add(res[i] , tree[rt][i]);
		return;
	} 
	push_down(rt);
	int mid = (l + r) >> 1;
	query(lson , l , mid , al , ar); query(rson , mid + 1 , r , al , ar);
} 

void go(int k) { for (int i = 0; i < p; i++) tran[i] = qpow(i , k); } 

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> p;
	for (int i = 1; i <= n; i++) cin >> a[i] , a[i] %= p;
	build(1 , 1 , n);
	int q; cin >> q;
	while (q--) {
		int op,l,r,k; cin >> op >> l >> r >> k;
		if (op == 1) add(1 , 1 , n , l , r , k % p);
		if (op == 2) mul(1 , 1 , n , l , r , k % p);
		if (op == 3) go(k) , kpow(1 , 1 , n , l , r , k);
		for (int i = 0; i < p; i++) res[i] = 0;
		if (op == 4) { 
			query(1 , 1 , n , l , r);
			int ans = 0;
			for (int i = 0; i < p; i++) 
				ans = (ans + 1ll * res[i] * qpow(i , k) % p) % p;
			printf("%d\n" , ans);
		} 
		if (op == 5) {
			query(1 , 1 , n , l , r);
			int ans = 1;
			for (int i = 0; i < p; i++) ans = 1ll * ans * qpow(i , res[i]) % p;
			printf("%d\n" , ans);
		} 
	} 
} 
