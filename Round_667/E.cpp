#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 2e5;
int x[maxn + 11],a[maxn + 11],mx[maxn + 11];
vector <int> v;

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n,k; cin >> n >> k;
		v.clear();
		for (int i = 1; i <= n; i++) { cin >> x[i]; v.pb(x[i]); }
		int y;
		for (int i = 1; i <= n; i++) cin >> y;
		for (int i = 1; i <= v.size(); i++) a[i] = 0;
		sort(all(v)); v.erase(unique(all(v)) , v.end());
		for (int i = 1; i <= n; i++) {
			int l = lower_bound(all(v) , x[i] - k) - v.begin() + 1;
			int r = lower_bound(all(v) , x[i]) - v.begin() + 1;
			a[r + 1]--; a[l]++;
		}
		for (int i = 2; i <= v.size(); i++) a[i] += a[i - 1];
		mx[v.size() + 1] = 0;
		for (int i = v.size(); i >= 1; i--) mx[i] = max(mx[i + 1] , a[i]);
		int ans = mx[1];
		for (int i = 0; i < v.size(); i++) { 
			int u = v[i];
			if (u + k + 1 > v.back()) break;
			int ind = lower_bound(all(v) , u + k + 1) - v.begin() + 1;
			ans = max(ans , mx[ind] + a[i + 1]);
		} 
		cout << ans << endl;
	} 
} 

