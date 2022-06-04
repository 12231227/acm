#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mol = 1e9 + 7;

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
	ll n,m;
	cin >> n >> m;
	ll ans = qpow(qpow(2 , m) - 1 , n);
	cout << ans << endl;
}

