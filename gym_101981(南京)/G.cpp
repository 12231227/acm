#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mol = 1e9 + 7;

ll inv;

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
	inv = qpow(24 , mol - 2);
	int t;
	scanf("%d",&t);
	while (t--) {
		ll n;
		scanf("%lld",&n);
		n += 3;
		printf("%lld\n" , n * (n - 1) % mol * (n - 2) % mol * (n - 3) % mol * inv % mol);
	}
} 

