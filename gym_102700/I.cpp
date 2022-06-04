#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const ll inf = 1e18;
const int maxn = 1e5;
ll f[maxn + 11];
vector <int> pos[maxn + 11],v;
int h[maxn + 11];

struct SGT{
	ll tree[4 * maxn + 11];
	void build(int rt,int l,int r) { 
		tree[rt] = -inf;
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(lson , l , mid); build(rson , mid + 1 , r);
	} 
	void update(int rt,int l,int r,int pos,ll val) { 
		if (l > pos || r < pos) return;
		if (l == r) { tree[rt] = val; return; }
		int mid = (l + r) >> 1;
		update(lson , l , mid , pos , val);
		update(rson , mid + 1 ,  r , pos , val);
		tree[rt] = max(tree[lson] , tree[rson]);
	} 
	ll query(int rt,int l,int r,int al,int ar) { 
		if (l > ar || r < al) return -inf;
		if (l >= al && r <= ar) return tree[rt];
		int mid = (l + r) >> 1;
		return max(query(lson , l , mid , al , ar) , query(rson , mid + 1 , r , al , ar));
	} 
}add,sub;

int main(){ 
	int n; scanf("%d",&n);
	for (int i = 1; i <= n; i++) { 
		scanf("%d",&h[i]);
		v.pb(h[i]);
	} 
	sort(all(v)); v.erase(unique(all(v)) , v.end());
	for (int i = 1; i <= n; i++) { 
		h[i] = lower_bound(all(v) , h[i]) - v.begin();
		pos[h[i]].pb(i);
	} 
	add.build(1 , 1 , n); sub.build(1 , 1 , n);
	for (int i = v.size() - 1; i >= 0; i--) { 
		for (auto j : pos[i]) { 
			f[j] = 0;
			if (j > 1) f[j] = max(f[j] , sub.query(1 , 1 , n , 1 , j - 1) + j);
			if (j + 1 <= n) f[j] = max(f[j] , add.query(1 , 1 , n , j + 1 , n) - j);
		} 
		for (auto j : pos[i]) {
			add.update(1 , 1 , n , j , f[j] + j);
			sub.update(1 , 1 , n , j , f[j] - j);
		} 
	} 
	for (int i = 1; i <= n; i++) printf("%lld%s" , f[i] , i == n ? "\n" : " ");
} 
