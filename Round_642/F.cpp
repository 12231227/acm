#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 9e18;
const int maxn = 100;
int n,m;

ll f[maxn + 11][maxn + 11],a[maxn + 11][maxn + 11];
ll ans;

void solve(ll lim) {
	if (a[1][1] < lim) return;
	f[1][1] = a[1][1] - lim;
	for (int i = 2; i <= m; i++)
		if (f[1][i - 1] == inf || a[1][i] < lim) f[1][i] = inf;
		else f[1][i] = f[1][i - 1] + a[1][i] - lim;
	for (int i = 2; i <= n; i++)
		if (f[i - 1][1] == inf || a[i][1] < lim) f[i][1] = inf;
		else f[i][1] = f[i - 1][1] + a[i][1] - lim;
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= m; j++) {
			if (f[i - 1][j] == inf && f[i][j - 1] == inf) { f[i][j] = inf; continue; }
			if (a[i][j] < lim) { f[i][j] = inf; continue; }
			ll A = inf , B = inf;
			if (f[i - 1][j] != inf) A = f[i - 1][j] + a[i][j] - lim;
			if (f[i][j - 1] != inf) B = f[i][j - 1] + a[i][j] - lim;
			f[i][j] = min(A , B);
		}
	ans = min(ans , f[n][m]);
}

int main(){
	int t;
	for (scanf("%d",&t);t;t--) {
		scanf("%d %d",&n,&m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				scanf("%lld",&a[i][j]);
				a[i][j] = a[i][j] - i - j + 2;
			}
		ans = inf;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) solve(a[i][j]);
		printf("%lld\n" , ans);
	} 
} 
