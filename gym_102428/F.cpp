#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 5000;
const ll mol = 1e9 + 7;

ll f[maxn + 11][maxn + 11];
ll pre[maxn * 2 + 11],sum[maxn * 2 + 11];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	m -= n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			pre[j] = (pre[j] + sum[j]) % mol;
			 if (j == 0) f[i][j] = 1;
			 else f[i][j] = pre[j];
			sum[i + j] = (sum[i + j] + f[i][j]) % mol;
		}
	} 
	printf("%lld\n" , f[n][m]);
} 

