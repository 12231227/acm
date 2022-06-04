#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 4e5;
int a[maxn + 11];
ll fac[maxn + 11],jc[maxn + 11],inv[maxn + 11];

const ll mol = 998244353;

ll qpow(ll a,ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mol;
		a = a * a % mol;
		b >>= 1;
	}
	return ans;
}

ll calc(ll n,ll m) {
	if (n == 0 || m == 0) return 1;
	return jc[n] * inv[m] % mol * inv[n - m] % mol;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
	} 
	if (k == 1) { printf("0\n"); return 0; } 
	a[n + 1] = a[1];
	int m = 0;
	for (int i = 1; i <= n; i++) if (a[i] != a[i + 1]) m++;
	ll ans = 0;
	fac[0] = 1;
	for (int i = 1; i <= 2 * n + 2; i++) fac[i] = fac[i - 1] * (k - 2) % mol;
	jc[0] = inv[0] = 1;
	for (int i = 1; i <= n + 1; i++) jc[i] = jc[i - 1] * i % mol;
	inv[n + 1] = qpow(jc[n + 1] , mol - 2);
	for (int i = n; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mol;
	for (int i = 0; i <= m / 2; i++) ans = (ans + calc(m , i) * calc(m - i , i) % mol * fac[m - 2 * i] % mol) % mol;
	ans = ans * qpow(k , n - m) % mol;
	ans = (qpow(k , n) - ans + mol) % mol * qpow(2 , mol - 2) % mol;
	printf("%lld\n" , ans);
} 

