#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mol = 998244353;
const int maxn = 2e5;
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

ll add(ll a,ll b) { a += b; if (a >= mol) a -= mol; return a; }
ll sub(ll a,ll b) { a -= b; if (a < 0) a += mol; return a; }

ll C(int n,int m) { return fac[n] * inv[m] % mol * inv[n - m] % mol; }

ll S(int n,int m) {
	ll ans = 0;
	for (int k = 0; k < m; k++) { 
		ll val = C(m , k) * qpow(m - k , n) % mol;
		if (k % 2 == 1) ans = sub(ans , val); else ans = add(ans , val);
	} 
	return ans;
} 

int main(){
	int n,k;
	cin >> n >> k;
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mol;
	inv[n] = qpow(fac[n] , mol - 2);
	for (int i = n - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mol;
	if (k >= n) puts("0");
	else {
		ll val = C(n , k) * S(n , n - k) % mol;
		if (k) val = val * 2 % mol;
		printf("%lld\n" , val);
	}
} 

