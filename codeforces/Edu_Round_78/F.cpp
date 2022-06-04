#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f[5050][5050];
const ll mol = 998244353;
ll add(ll a,ll b) { a += b; if (a >= mol) a -= mol; return a; }
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
	int n,m,k;
	cin >> n >> m >> k;
	f[0][0] = 1;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= i; j++)
			f[i][j] = add(f[i][j] , add(f[i - 1][j] * j % mol , f[i - 1][j - 1] * (n - j + 1) % mol));
	ll ans = 0;
	ll inv = qpow(m , mol - 2);
	for (int i = 1; i <= k; i++)
		ans = add(ans , f[k][i] * qpow(inv , i) % mol);
	cout << ans << endl;
} 

