#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5;
const ll mol = 998244353;

ll inv[maxn + 11],fac[maxn + 11];

ll qpow(ll a,ll b) {
	if (b < 0) return 1;
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
	int n,m;
	cin >> n >> m;
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= m; i++) fac[i] = fac[i - 1] * i % mol;
	inv[m] = qpow(fac[m] , mol - 2);
	for (int i = m - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mol;
	cout << C(m , n - 1) * qpow(2 , n - 3) % mol * (n - 2) % mol << endl;
} 

