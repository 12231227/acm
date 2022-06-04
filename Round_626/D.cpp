#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e7;

int sum[2][maxn + 11],cnt[2][maxn + 11],a[400000 + 11];

int calc(int x) { return 1ll * x * (x - 1) / 2 % 2; }

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < (1 << i); j++) cnt[0][j] = cnt[1][j] = 0;
		for (int j = 1; j <= n; j++)
			if (a[j] & (1 << i)) cnt[1][a[j] % (1 << i)]++; else cnt[0][a[j] % (1 << i)]++;
		sum[0][0] = cnt[0][0]; sum[1][0] = cnt[1][0];
		for (int j = 1; j < (1 << i); j++) {
			sum[0][j] = sum[0][j - 1] + cnt[0][j];
			sum[1][j] = sum[1][j - 1] + cnt[1][j];
		}
		int _ = 0;
		for (int j = 0; j < (1 << i); j++) {
			if (j + j < (1 << i)) 
				_ = (_ + (1ll * cnt[1][j] * sum[0][j] + 1ll * cnt[0][j] * sum[1][j] - 1ll * cnt[1][j] * cnt[0][j]) % 2) % 2;
			else {
				int l = (1 << i) - j;
				_ = (_ + 1ll * cnt[1][j] * sum[0][l - 1] % 2 + 1ll * cnt[0][j] * sum[1][l - 1] % 2) % 2;
				if (l < j)
					_ = (_ + 1ll * cnt[1][j] * (sum[1][j - 1] - sum[1][l - 1])% 2 + 1ll * cnt[0][j] * (sum[0][j - 1] - sum[0][l - 1]) % 2) % 2;
				_ = (_ + calc(cnt[1][j]) + calc(cnt[0][j])) % 2;
			}
		}
		if (_) ans |= (1 << i);
	}
	cout << ans << endl;
} 

