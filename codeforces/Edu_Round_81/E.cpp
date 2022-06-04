#include <bits/stdc++.h>
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

const int maxn = 2e5;
ll lazy[4 * maxn + 11],tree[4 * maxn + 11];
int a[maxn + 11],p[maxn + 11],pos[maxn + 11];
ll sum[maxn + 11];

void push_up(int rt) { tree[rt] = min(tree[lson] , tree[rson]); }
void build(int rt,int l,int r) {
	if (l == r) { tree[rt] = sum[l]; return; }
	int mid = (l + r) >> 1;
	build(lson , l , mid);
	build(rson , mid + 1 , r);
	push_up(rt);
} 

void push_down(int rt) {
	ll val = lazy[rt];
	lazy[rt] = 0;
	tree[lson] += val; tree[rson] += val;
	lazy[lson] += val; lazy[rson] += val;
} 

void upd(int rt,int l,int r,int al,int ar,int val) {
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) {
		tree[rt] += val;
		lazy[rt] += val;
		return;
	}
	if (lazy[rt]) push_down(rt);
	int mid = (l + r) >> 1;
	upd(lson , l , mid , al , ar , val);
	upd(rson , mid + 1 , r , al , ar , val);
	push_up(rt);
} 

ll query(int rt,int l,int r,int al,int ar) {
	if (l > ar || r < al) return 1e18;
	if (l >= al && r <= ar) return tree[rt];
	if (lazy[rt]) push_down(rt);
	int mid = (l + r) >> 1;
	return min(query(lson , l , mid , al , ar) , query(rson , mid + 1 , r , al , ar));
}

int main() {
	int n;
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++) scanf("%d" , &p[i]) , pos[p[i]] = i;
	for (int i = 1; i <= n; i++) scanf("%d" , &a[i]) , sum[i] = sum[i - 1] + a[i];
	build(1 , 1 , n);
	ll ans = query(1 , 1 , n , 1 , n - 1);
	for (int i = 1; i <= n; i++) {
		upd(1 , 1 , n , pos[i] , n , -a[pos[i]]);
		if (pos[i] - 1 > 0) upd(1 , 1 , n , 1 , pos[i] - 1 , a[pos[i]]);
		ans = min(ans , query(1 , 1 , n , 1 , n - 1));
	} 
	printf("%lld\n" , ans);
} 

