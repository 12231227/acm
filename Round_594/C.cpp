#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mol = 1e9 + 7;
const int maxn = 100000;

ll f[maxn + 11];

int main(){
	ll n,m;
	cin >> n >> m;
	f[1] = 2;
	f[2] = 4;
	for (int i = 3; i <= maxn; i++) f[i] = (f[i - 1] + f[i - 2]) % mol;
	ll ans = (f[n] + f[m]) % mol - 2;
	if (ans < 0) ans += mol;
	cout << ans << endl;
}

