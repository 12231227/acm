#include <bits/stdc++.h>
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

const int maxn = 1e5;
ll a[maxn + 11];
pair<ll,ll> tree[4 * maxn + 11];
int n;
ll L,R;

pair<ll,ll> merge(pair<ll,ll> a, pair<ll,ll> b) {
	if (a.second <= b.first) return make_pair(b.first , b.first);
	else if (a.first >= b.second) return make_pair(b.second , b.second);
	else return make_pair(max(a.first , b.first) , min(a.second , b.second));
} 

void push_up(int rt) { tree[rt] = merge(tree[lson] , tree[rson]); }

void build(int rt,int l,int r) {
	if (l == r) {
		tree[rt] = make_pair(L - a[l] , R - a[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(lson , l , mid);
	build(rson , mid + 1 , r);
	push_up(rt);
} 

pair <ll,ll> query(int rt,int l,int r,int al,int ar) {
	if (l >= al && r <= ar) return tree[rt];
	int mid = (l + r) >> 1;
	if (ar <= mid) return query(lson , l , mid , al , ar);
	if (mid + 1 <= al) return query(rson , mid + 1 , r , al , ar);
	return merge(query(lson , l , mid , al , ar) , query(rson , mid + 1 , r , al , ar));
}

int main(){
	scanf("%d %lld %lld",&n,&L,&R);
	for (int i = 1; i <= n; i++) {
		scanf("%lld" , &a[i]);
		a[i] += a[i - 1];
	}
	build(1 , 1 , n);
	int q;
	scanf("%d" , &q);
	while (q--) {
		int l,r;
		ll x;
		scanf("%d %d %lld" , &l, &r, &x);
		x -= a[l - 1];
		pair <ll ,ll> pi = query(1 , 1 , n , l , r);
		if (x < pi.first) x = pi.first;
		if (x > pi.second) x = pi.second;
		x += a[r];
		printf("%lld\n" , x);
	} 
} 
