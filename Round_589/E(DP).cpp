#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mol = 1e9 + 7;

ll f[255][255];
ll jc[255],inv[255];

ll qpow(ll a,ll b) { 
	ll ans = 1;
	while (b) { 
		if (b & 1) ans = ans * a % mol;
		a = a * a % mol;
		b >>= 1;
	} 
	return ans;
} 

ll C(ll n,ll m) { return jc[n] * inv[m] % mol * inv[n - m] % mol; }

int main(){
	int n,k;
	jc[0] = inv[0] = 1;
	for (int i = 1; i <= 250; i++) jc[i] = jc[i - 1] * i % mol;
	for (int i = 1; i <= 250; i++) inv[i] = qpow(jc[i] , mol - 2);
	cin >> n >> k;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			f[i][j] = f[i - 1][j] * qpow(k - 1 , n - j) % mol * ((qpow(k , j) - qpow(k - 1 , j ) + mol) % mol) % mol;
			ll res = qpow(k - 1 , n - j);
			for (int p = 0; p < j; p++)
				f[i][j] = (f[i][j] + f[i - 1][p] * C(n - p , j - p) % mol * qpow(k , p) % mol * res % mol) % mol;
		}
	printf("%lld\n" , f[n][n]);
}
