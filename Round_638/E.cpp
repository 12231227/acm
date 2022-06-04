#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 500;

ll f[maxn + 11][maxn + 11];
ll suma[maxn + 11],sumb[maxn + 11];
int a[maxn + 11],b[maxn + 11];

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d",&a[i],&b[i]);
		suma[i] = suma[i - 1] + a[i];
		sumb[i] = sumb[i - 1] + b[i];
	}
	memset(f , -1 , sizeof(f));
	f[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) {
			if (f[i][j] < 0) continue;
			int p = suma[i] + sumb[i] - (f[i][j] * k + j);
			if (a[i + 1] && b[i + 1]){
				for (int t = max(1 , k - b[i + 1]); t <= min(k - 1 , a[i + 1]); t++){
					f[i + 1][(j + a[i + 1] - t) % k] = max(f[i + 1][(j + a[i + 1] - t) % k] , f[i][j] + (j + a[i + 1] - t) / k + (p + b[i + 1] - (k - t)) / k + 1);
				}
			}
			f[i + 1][(j + a[i + 1]) % k] = max(f[i + 1][(j + a[i + 1]) % k] , f[i][j] + (j + a[i + 1]) / k + (p + b[i + 1]) / k);
		}
	ll ans = 0;
	for (int i = 0; i < k; i++) ans = max(ans , f[n][i]);
	printf("%lld\n" , ans);
} 
