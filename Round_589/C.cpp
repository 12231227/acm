#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
using namespace std;

const int N = 1e5;
const ll mol = 1e9 + 7;

vector <ll> v;

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
	int x; ll n;
	scanf("%d %lld" , &x , &n);
	int val = x;
	for (int i = 2; i <= sqrt(x); i++) {
		if (val % i == 0) {
			v.pb(i);
			while (val % i == 0) val /= i;
		}
	}
	ll ans = 1;
	if (val != 1) v.pb(val);
	for (auto p : v) {
		ll num = n;
		ll cnt = 0;
		while (num) { cnt += num / p; num /= p; }
		ans = ans * qpow(p , cnt) % mol;
	}
	cout << ans << endl;
}
