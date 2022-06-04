#include <bits/stdc++.h>
#define ll long long
using namespace std;

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

int main(){
	ll n,m,l,r;
	cin >> n >> m >> l >> r;
	if ((n * m) % 2 == 1) cout << qpow(r - l + 1 , n * m) << endl;
	else {
		ll R = r / 2; ll L = l / 2; if (l % 2 == 1) L++;
		ll a = 0;
		if (R >= L) a = R - L + 1;
		ll b = r - l + 1 - a;
		if (a < b) swap(a , b);
		cout << (qpow(a + b , n * m) + qpow(a - b , n * m)) % mol * qpow(2 , mol - 2) % mol << endl;
	}
} 

