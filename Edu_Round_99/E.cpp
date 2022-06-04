#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;

const ll inf = 1e18;
pii p[5];
vector <pii> out,last;

bool check(pii a,pii b,pii c,pii d) { 
	if (a == b && a == c && a == d) return true;
	if (a == b) return false;
	if (a == c) return false;
	if (a == d) return false;
	if (b == c) return false;
	if (b == d) return false;
	if (c == d) return false;
	if (a.fi == b.fi && a.fi == c.fi) return false;
	if (a.fi == b.fi && a.fi == d.fi) return false;
	if (a.fi == c.fi && a.fi == d.fi) return false;
	if (b.fi == c.fi && b.fi == d.fi) return false;
	if (a.se == b.se && a.se == c.se) return false;
	if (a.se == b.se && a.se == d.se) return false;
	if (a.se == c.se && a.se == d.se) return false;
	if (b.se == c.se && b.se == d.se) return false;
	return true;
}

ll go(pii s,vector <pii> v) {
	pii x,y,z;
	ll ans = inf;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			ll step = 0;
			if (i == j) continue;
			x = make_pair(s.fi , v[i].se);
			y = make_pair(v[j].fi , s.se);
			z = make_pair(y.fi , x.se);
			ll l1 = abs(s.fi - v[i].fi);
			ll l2 = abs(s.se - v[j].se);
			ll l3 = 
			ll l4 = 
			if (!check(s , x , y , z)) continue;
			step = abs(s.fi - v[i].fi) + abs(s.se - v[j].se) + abs(y.fi - v[3 - i - j].fi) + abs(x.se - v[3 - i - j].se);
			if (step < ans) {
				ans = min(ans , step);
				out.clear(); out.pb(s); out.pb(x); out.pb(y); out.pb(z);
			}
		}
	return ans;
}

ll solve(pii s , int ind) {
	vector <pii> v;
	for (int i = 0; i < 4; i++)
		if (i != ind) v.pb(p[i]);
	return go(s , v);
}

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		ll ans = inf;
		for (int i = 0; i < 4; i++) cin >> p[i].fi >> p[i].se;
		for (int i = 0; i < 4; i++) {
			for (int x = p[i].fi - 50; x <= p[i].fi + 50; x++)
				for (int y = p[i].se - 50; y <= p[i].se + 50; y++){
					ll tmp = solve(make_pair(x , y) , i) + abs(p[i].fi - x) + abs(p[i].se - y);
					if (tmp < ans) { ans = tmp; last = out; } else out.clear();
				}
		} 
		printf("%lld\n" , ans);
		for (auto pi : last) printf("%d %d\n" , pi.fi , pi.se);
	} 
} 
