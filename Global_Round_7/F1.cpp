#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 16384;
ll ans[16400];
vector<ll> f[16384][15];
int a[15][15],cnt[16400];
char ch[15];

int main(){
	int n;
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s" , ch + 1);
		for (int j = 1; j <= n; j++)
			a[i][j] = ch[j] - '0';
	}
	f[0][0].resize(1); f[0][0][0] = 1;
	for (int i = 0; i < (1 << n); i++) cnt[i] = __builtin_popcount(i);
	for (int i = 1; i < (1 << n); i++)
		for (int j = 1; j <= n; j++) { 
			if (!(i & (1 << (j - 1)))) continue;
			f[i][j].resize(1 << (cnt[i] - 1));
			if (cnt[i] == 1) { f[i][j][0] = 1; break; }
			for (int k = 1; k <= n; k++)
				if (j != k && (i & (1 << (k - 1)))) {
					int s = a[j][k] ? 1 : 0;
					for (int mask = s; mask < (1 << (cnt[i] - 1)); mask += 2)
						f[i][j][mask] += f[i ^ (1 << (j - 1))][k][mask >> 1];
				} 
		} 
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < (1 << (n - 1)); j++)
			ans[j] += f[(1 << n) - 1][i][j];
	for (int j = 0; j < (1 << (n - 1)); j++)
		printf("%lld " , ans[j]);
} 

