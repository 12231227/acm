#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <ll> d;

int main(){
	int t;
	scanf("%d",&t);
	while (t--) {
		int n;
		scanf("%d",&n);
		ll m = 1ll * n * n;
		d.clear(); d.push_back(1); d.push_back(n); d.push_back(m);
		for (int i = 2; i < n; i++)
			if (m % i == 0) {
				d.push_back(i);
				d.push_back(m / i);
			}
		ll a = 0;
		for (auto t : d) {
			ll x = n + t;
			ll y = m / t + n;
			a = max(a , x ^ y);
		}
		printf("%lld\n" , a);
	}
} 

