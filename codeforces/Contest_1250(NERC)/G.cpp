#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
using namespace std;

const int maxn = 2e5;
ll a[maxn + 11],b[maxn + 11],mn[maxn + 11];
vector <int> res;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n,k; cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i] , a[i] += a[i - 1];
		for (int i = 1; i <= n; i++) cin >> b[i] , b[i] += b[i - 1];
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			if (a[i] < k && b[i] >= k) ans = 0;
			mn[i] = min(a[i] , b[i]);
		}
		if (ans == 0) { cout << ans << endl; continue; } 
		if (a[1] >= k) { cout << -1 << endl; continue; } 
		for (int i = 1;i <= n; i++) {
			if (a[i] >= b[i] || a[i] < k) continue;
			int ind = upper_bound(mn + 1 , mn + 1 + i , mn[i] - k) - mn;
			if (mn[ind] <= max(a[i] , b[i]) - k) {
				ans = ind; break;
			}
		}
		if (ans == -1) { cout << -1 << endl; continue; }
		res.clear();
		ll sub = 0;
		for (int i = 1; i < ans; i++) {
			if (a[i] - sub >= k) {
				ans = -1; break;
			}
			if (a[i] - sub < k && a[i + 1] - sub >= k) {
				res.pb(i); sub = mn[i];
			}
		}
		if (ans == -1) { cout << -1 << endl; continue; }
		if (a[ans] - sub >= k) { cout << -1 << endl; continue; }
		res.pb(ans);
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) { 
			if (i) cout << " ";
			cout << res[i];
		} 
		cout << endl;
	} 
} 

