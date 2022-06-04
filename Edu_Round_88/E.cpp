#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mol = 998244353;
const int maxn = 5e5;

ll fac[maxn + 11],inv[maxn + 11];

ll qpow(ll a,ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mol;
		a = a * a % mol;
		b >>= 1;
	}
	return ans;
}

ll C(int n,int m) { return fac[n] * inv[m] % mol * inv[n - m] % mol; }

int main(){
	int n,k;
	cin >> n >> k;
	inv[0] = fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mol;
	inv[n] = qpow(fac[n] , mol - 2);
	for (int i = n - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mol;
	ll ans = 0;
	for (int i = 1; i <= maxn; i++) {
		int cnt = n / i;
		if (cnt < k) break;
		ans += C(cnt - 1 , k - 1);
		if (ans >= mol) ans -= mol;
	}
	cout << ans << endl;
}