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
pair <int,int> up[maxn + 11],down[maxn + 11];
bool out[maxn + 11];

ll area(int x , int y) { return 1ll * (up[x].second - down[y].second) * (up[x].first - down[y].first); }

ll solve(int l,int r,int ql,int qr) {
	if (l > r || ql > qr) return 0;
	int mid = (l + r) >> 1;
	ll ans = 0; int ind = 0;
	for (int i = ql; i <= qr && down[i].first < up[mid].first; i++) {
		ll ret = area(mid , i);
		if (ret > ans) ans = ret , ind = i;
	} 
	return max(ans , max(solve(l , mid - 1 , ql , ind) , solve(mid + 1 , r , ind , qr)));
} 


int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int h; cin >> h;
		up[i] = make_pair(i , h);
		down[i] = make_pair(i , -h);
	} 
	memset(out , false , sizeof(out));
	int hi = 0;
	for (int i = n; i >= 1; i--) {
		if (hi >= up[i].second) out[i] = true;
		hi = max(hi , up[i].second);
	} 
	int cn = 0;
	for (int i = 1; i <= n; i++) if (!out[i]) up[++cn] = up[i];

	memset(out , false , sizeof(out));
	int lo = 0;
	for (int i = 1; i <= n; i++) {
		if (lo <= down[i].second) out[i] = true;
		lo = min(lo , down[i].second);
	}
	int cm = 0;
	for (int i = 1; i <= n; i++) if (!out[i]) down[++cm] = down[i];
	cout << solve(1 , cn , 1 , cm) << endl;
} 
