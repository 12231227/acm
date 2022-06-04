#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5;

int m;
ll val[maxn + 11];
int cnt[maxn + 11];
pair<int,int> p[maxn + 11];
vector <int> v;

int lowbit(int x) { return x & (-x); }
void add(int x,int o) {
	for (; x <= m; x += lowbit(x)) {
		cnt[x] += 1;
		val[x] += o;
	}
}
pair <int,ll> query(int x) {
	int resc = 0;
	ll resv = 0;
	for (; x; x -= lowbit(x)) {
		resc += cnt[x];
		resv += val[x];
	}
	return make_pair(resc , resv);
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i].first;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].second;
		v.emplace_back(p[i].second);
	}
	sort(p + 1 , p + 1 + n);
	sort(v.begin() , v.end());
	v.erase(unique(v.begin() , v.end()) , v.end());
	m = v.size();
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int pos = lower_bound(v.begin() , v.end() , p[i].second) - v.begin() + 1;
		pair <int,ll> pi = query(pos);
		ans += 1ll * pi.first * p[i].first - pi.second;
		add(pos , p[i].first);
	}
	cout << ans << endl;
} 

