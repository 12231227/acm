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
vector <int> in[maxn + 11],out[maxn + 11];
int bit[maxn + 11];

struct node{
	int x,l,r;
}q[maxn + 11];

int lowbit(int x) { return x & (-x); }
void upd(int x,int val) {
	for (; x <= maxn; x += lowbit(x)) bit[x] += val; 
}
int query(int x) {
	if (x < 0) return 0;
	int ans = 0;
	for (; x ; x -= lowbit(x)) ans += bit[x];
	return ans;
}

int query(int l,int r) { return query(r) - query(l - 1); }

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m; cin >> n >> m;
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		int y,l,r; cin >> y >> l >> r;
		if (l == 0 && r == maxn) ans++;
		in[l].pb(y); out[r].pb(y);
	}
	for (auto u : in[0]) upd(u , 1);
	for (int i = 1; i <= m; i++) {
		cin >> q[i].x >> q[i].l >> q[i].r;
		if (q[i].l == 0 && q[i].r == maxn) ans++;
	}
	sort(q + 1 , q + 1 + m , [&](node a,node b) {
		return a. x < b.x;
	});
	int l = 0;
	for (int i = 1; i <= m; i++) {
		while (l < q[i].x && l < maxn) {
			for (auto u : out[l]) upd(u , -1);
			l++;
			for (auto u : in[l]) upd(u , 1);
		}
		ans += query(q[i].l , q[i].r);
	}
	cout << ans << endl;
} 
