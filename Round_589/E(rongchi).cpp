#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mol = 1e9 + 7;

ll c[255][255];

ll qpow(ll a,ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mol;
		a = a * a % mol;
		b >>= 1;
	}
	return ans;
}

void pre() {
	//c(i,j) = c(i - 1,j) + c(i - 1, j - 1)
	c[0][0] = 1;
	for (int i = 1; i <= 250; i++){
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mol;
	}
}

int main(){
	int n,k;
	ll ans = 0;
	scanf("%d %d",&n,&k);
	pre();
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) {
			ll op = (i + j) % 2 == 0 ? 1 : -1;
			ll num = n * (i + j) - i * j;
			ll res = c[n][i] * c[n][j] % mol * qpow(k - 1 , num) % mol * qpow(k , n * n - num) % mol;
			ans = (ans + (res * op % mol + mol) % mol) % mol;
		}
	cout << ans << endl;
}
