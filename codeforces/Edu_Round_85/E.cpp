#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
using namespace std;

const int maxn = 1e5;
const ll mol = 998244353;

ll fac[maxn + 11],inv[maxn + 11];
int cnt[maxn + 11];
vector <ll> v;

ll gcd(ll a,ll b) { return b ? gcd(b , a % b) : a; }

ll calc(ll a,ll b) {
	int n = 0;
	for (int i = 0; i < v.size(); i++) {
		cnt[i] = 0;
		while (a % v[i] == 0) { a /= v[i]; cnt[i]++; }
		while (b % v[i] == 0) { b /= v[i]; cnt[i]--; }
		n += cnt[i];
	}
	ll ans = fac[n];
	for (int i = 0; i < v.size(); i++) ans = ans * inv[cnt[i]] % mol;
	return ans;
}

ll qpow(ll a,ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mol;
		a = a * a % mol;
		b >>= 1;
	}
	return ans;
}

int main(){
	ll d;
	scanf("%lld",&d);
	for (ll i = 2; i * i <= d; i++) {
		if (d % i != 0) continue;
		v.pb(i);
		while (d % i == 0) d /= i;
	} 
	if (d != 1) v.pb(d);
	int q;
	inv[0] = fac[0] = 1;
	for (int i = 1; i <= maxn; i++) fac[i] = fac[i - 1] * i % mol;
	inv[maxn] = qpow(fac[maxn] , mol - 2);
	for (int i = maxn - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mol;
	scanf("%d",&q);
	while (q--) {
		ll u,v;
		scanf("%lld %lld",&u,&v);
		ll g = gcd(u , v);
		printf("%lld\n" , calc(u , g) * calc(v , g) % mol);
	}
} 
