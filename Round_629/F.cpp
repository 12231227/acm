#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf = 5e18;

const int maxn = 2e5;
int a[maxn + 11];
pair<int,int> p[maxn + 11];
ll sum[maxn + 11];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1 , a + 1 + n);
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i - 1]) p[++tot] = make_pair(a[i] , 1);
		else p[tot].second++;
	}
	for (int i = 1; i <= tot; i++){
		sum[i] = sum[i - 1] + 1ll * p[i].first * p[i].second;
	}
	int l = 0;
	ll ans = inf;
	for (int i = 1; i <= tot; i++) {
		int r = n - l - p[i].second;
		if (p[i].second >= k) { ans = 0; break; }
		ll v = p[i].first;
		if (l + p[i].second >= k) {
			ans = min(ans , v * (k - p[i].second) + (v - 1) * (l - k + p[i].second) - sum[i - 1]);
		}
		if (r + p[i].second >= k) {
			ans = min(ans , sum[tot] - sum[i] - v * (k - p[i].second) - (v + 1) * (r - k + p[i].second));
		}
		ans = min(ans , v * l - l + sum[tot] - sum[i] - sum[i - 1] - v * r - r + k - p[i].second);
		l += p[i].second;
	}
	cout << ans << endl;
}

