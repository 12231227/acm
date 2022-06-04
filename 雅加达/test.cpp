#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
 
const int inf = 2e9;
const int maxn = 1e5;
 
int f[maxn + 11][55];
char ch[maxn + 11];
 
int main() {
	int n, k, g1, g2, g3;
	cin >> n >> k >> g1 >> g2 >> g3;
	scanf("%s", ch + 1);
	int m = 0;
	for (int i = 1; i <= n; i++) if (ch[i] == '#') m++;
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= m; j++)
			if (j > 0) f[i][j] = -inf;
			else f[i][j] = 0;
	for (int i = 2; i <= n; i++) { 
		for (int j = 0; j <= m; j++) {
			f[i][j] = f[i - 1][j];
			if (ch[i] == '.' && ch[i - 1] == '.') f[i][j] = max(f[i][j], f[i - 2][j] + g2);
			if (j >= 1 && i >= 3 && ch[i] == '.' && ch[i - 2] == '.' && ch[i - 1] == '#') 
				f[i][j] = max(f[i][j], f[i - 3][j - 1] + g3);
		}
	}
	int ans = 0;
	for (int i = 0; i <= m; i++) { 
		if (f[n][i] < 0) continue;
		int has = (f[n][i] - g3 * i) / g2;
		int res = n - has * 2 - i * 2 - m;
		if (res >= k) { 
			ans = max(ans, k * g1 + f[n][i]);
		}
		else { 
			int tmp = res * g1 + f[n][i];
			res = k - res;
			if (g1 * 2 > g2) { 
				tmp += min(res / 2, has) * (g1 * 2 - g2);
				res -= min(res / 2, has) * 2;
				has -= min(res / 2, has);
				if (res == 1 && has > 0 && g1 > g2) { 
					tmp += g1 - g2;
					res--;
				}
			} 
			ans = max(ans , tmp);
		}
	}
	printf("%d\n", ans);
	return 0;
} 
