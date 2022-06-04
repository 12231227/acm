#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int maxn = 1e6;
ll sqr;

int cnt = 0;
int m;
int prime[maxn + 11];
bool vis[maxn + 11] = {false};
ll g[maxn + 11];
int id1[maxn + 11],id2[maxn + 11];
ll w[maxn + 11];

struct FastMod {
    int k, m; ull x;
    FastMod(int m) {
        this->m = m, k = m == 1 ? 0 : 31 - __builtin_clz(m - 1), k += 32, x = ((1ull << k) + m - 1) / m;
    }
    ull reduce(ull a) { return a < INT_MAX ? (ull)((a * x) >> k) : a / m; }
};

void pre(){
	for (int i = 2; i <= maxn; i++){
		if (!vis[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt; j++) {
			if (i * prime[j] > maxn) break;
			vis[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

void getg(ll n){
	ll last = 1;
	m = 0;
	for (ll i = 1; i <= n; i = last + 1) {
		last = n / (n / i); w[++m] = n / i;
		if (w[m] <= sqr) id1[w[m]] = m;
		else id2[n / w[m]] = m;
		g[m] = w[m] - 1;
	} 
	for (int j = 1; j <= cnt; j++) {
	 if (1ll * prime[j] * prime[j] > n) break;
	 FastMod F(prime[j]);
	 for (int i = 1; i <= m && 1ll * prime[j] * prime[j] <= w[i]; i++) {
	 	ll id = F.reduce(w[i]);
	 	if (id <= sqr) id = id1[id]; else id = id2[n / id];
	 	g[i] = g[i] - (g[id] - j + 1);
	 }
	}
} 

void sum(ll n) {
	sqr = sqrt(n);
	getg(n);
}

int main() { 
	pre();
	int t;
	for (scanf("%d",&t);t;t--) {
		ll n;
		scanf("%lld",&n);
		sum(n);
		auto getid = [&](ll x) { return x <= sqr ? id1[x] : id2[n / x]; };
		ll ans = g[getid(n)] - g[getid(n / 2)] + 1;
		n -= ans;
		ans += n / 2 + n % 2;
		printf("%lld\n" , ans);
	}
} 
