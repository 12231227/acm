#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mol = 998244353;
const int maxn = 1e6;

ll p[maxn + 11];
vector <int> a[maxn + 11];

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

int main(){
	int n;
	scanf("%d" , &n);
	ll inv = qpow(n , mol - 2);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d" , &k);
		ll con = inv * qpow(k , mol - 2) % mol;
		for (int j = 0; j < k; j++) {
			int x;
			scanf("%d" , &x);
			a[i].push_back(x);
			p[x] = add(p[x] , con);
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (auto x : a[i]) {
			ans = add(ans , inv * p[x] % mol);
		}
	}
	printf("%lld\n" , ans);
} 

