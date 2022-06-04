#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mol = 998244353;
const int maxn = 2000;

ll f[maxn + 11][2 * maxn + 11];
int h[maxn + 11];

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i = 1; i <= n; i++) scanf("%d" , &h[i]); h[n + 1] = h[1];
	f[0][n] = 1;
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= 2 * n; j++){
			if (h[i] != h[i + 1]) {
				f[i][j] = f[i - 1][j] * (k - 2) % mol;
				if (j > 0) f[i][j] = (f[i][j] + f[i - 1][j - 1]) % mol;
				if (j < 2 * n) f[i][j] = (f[i][j] + f[i - 1][j + 1]) % mol;
			}
			else {
				f[i][j] = f[i - 1][j] * k % mol;
			} 
		} 
	ll ans = 0;
	for (int i = n + 1; i <= 2 * n; i++) ans = (ans + f[n][i]) % mol;
	printf("%lld\n" , ans);
} 

