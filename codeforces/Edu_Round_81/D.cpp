#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b) { return  b ? gcd(b , a % b) : a; }

ll phi(ll m) {
	ll ans = m;
	for (ll i = 2; i * i <= m; i++) {
		if (m % i == 0) {
			ans = ans / i * (i - 1);
			while (m % i == 0) m /= i;
		}
	}
	if (m != 1) ans = ans / m * (m - 1);
	return ans;
} 

int main() { 
	int t;
	scanf("%d" , &t);
	while (t--){
		ll a,m;
		cin >> a >> m;
		ll g = gcd(a , m);
		a /= g; m /= g;
		printf("%lld\n" , phi(m));
	} 
} 

