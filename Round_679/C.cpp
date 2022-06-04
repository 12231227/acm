#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int inf = 2e9;
const int maxn = 1e5;
int c[maxn + 11][10],a[10],b[maxn + 11];
int tree[4 * maxn + 11],id[4 * maxn + 11],maxx[4 * maxn + 11];
vector <int> v;   

void push_up(int rt) { tree[rt] = min(tree[lson] , tree[rson]); maxx[rt] = max(maxx[lson] , maxx[rson]); }

void build(int rt,int l,int r) {
	if (l == r) {
		id[rt] = 6;
		tree[rt] = c[l][6];
		maxx[rt] = c[l][6];
		return;
	}
	int mid = (l + r) >> 1;
	build(lson , l , mid); build(rson , mid + 1 , r);
	push_up(rt);
} 

void update(int rt,int l,int r,int val) {
	if (maxx[rt] < val || tree[rt] > val) return;
	if (l == r) {
		while (id[rt] > 0 && c[l][id[rt]] == val) id[rt]--;
		if (id[rt] == 0) tree[rt] = maxx[rt] = -1; else tree[rt] = maxx[rt] = c[l][id[rt]];
		return;
	}
	int mid = (l + r) >> 1;
	update(lson , l , mid , val); update(rson , mid + 1 , r , val);
	push_up(rt);
}

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 1; i <= 6; i++) cin >> a[i];
	int n ; cin >> n;
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= 6; j++) {
			v.pb(b[i] - a[j]);
			c[i][j] = b[i] - a[j];
		}
		sort(c[i] + 1 , c[i] + 7);
	}
	build(1 , 1 , n);
	sort(all(v)); v.erase(unique(all(v)) , v.end()); reverse(all(v));
	int ans = inf;
	for (auto u : v) {
		if (tree[1] == -1) break;
		ans = min(ans , u - tree[1]);
		update(1 , 1 , n , u);
	} 
	printf("%d\n" , ans);
} 
