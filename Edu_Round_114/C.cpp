#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector <ll> v;

ll get(ll s , ll cur , ll x , ll y) {
	ll ans = 0;
	if (s - cur < y) ans = y - (s - cur);
	if (cur < x) ans += x - cur;
	return ans;
}

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	ll s = 0;
	for (int i = 1; i <= n; ++i) {
		ll a; cin >> a;
		v.pb(a);
		s += a;
	}
	sort(all(v));
	int m; cin >> m;
	for (int i = 1; i <= m; ++i) {
		ll x,y; cin >> x >> y;
		auto it = lower_bound(all(v) , x);
		if (it == v.end()) {
			--it;
			cout << get(s , *it , x , y) << endl;
		}
		else if (it == v.begin()) {
			cout << get(s , *it , x , y) << endl;
		}
		else {
			ll ans = get(s , *it , x , y);
			--it;
			ans = min(ans , get(s , *it , x , y));
			cout << ans << endl;
		}
	}
} 
