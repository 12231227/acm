#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5;
multiset <int> a;

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	multiset <ll> s;
	int t; cin >> t;
	while (t--) {
		s.clear(); a.clear();
		int n ;
		cin >> n;
		ll all = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			a.insert(x);
			all += x;
		}
		s.insert(all);
		while (!s.empty()) {
			ll cur = *s.begin();
			s.erase(s.begin());
			if (cur > 1e9) {
				s.insert(cur / 2); s.insert((cur + 1) / 2);
				continue;
			}
			if (cur < (*a.begin())) break;
			auto it = a.find(cur);
			if (it == a.end()) {
				s.insert(cur / 2); s.insert((cur + 1) / 2);
			}
			else {
				a.erase(it);
			}
		}
		if (a.empty()) cout << "YES" << endl; else cout << "NO" << endl;
	} 
} 
