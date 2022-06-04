#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 30000;
ll t[maxn + 11],a[maxn + 11];
int n;
ll k;

bool check(ll x) {
	ll sum = 0;
	for (int i = 1; i <= n; i++) t[i] = a[i]; t[n + 1] = 0;
	for (int i = 1; i <= n; i++){
		if (t[i] >= x) {
			sum += t[i] / x * x;
			t[i] %= x;
		}
		if (t[i + 1] + t[i] >= x) {
			sum += x;
			t[i + 1] -= x - t[i];
		}
	}
	return sum >= x * k;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n >> k;
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i]; sum += a[i];
		}
		ll l = 1; ll r = sum / k; ll ans = 0;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (check(mid)) { l = mid + 1; ans = mid; } else r = mid - 1;
		}
		cout << ans * k << endl;
	}
} 

