#include <bits/stdc++.h>
using namespace std;

int n,h,l,r;
int f[2020][2020];
int sum[2020],a[2020];

int check(int x) { return x >= l && x <= r; }

int main(){
	cin >> n >> h >> l >> r;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1;i <= n; i++){
		f[i][0] = f[i - 1][0] + check(sum[i] % h);
		for (int j = 1; j < i; j++)
			f[i][j] = max(f[i - 1][j] , f[i - 1][j - 1]) + check((sum[i] - j + h) % h);
		f[i][i] = f[i - 1][i - 1] + check((sum[i] - i + h) % h);
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) ans = max(ans , f[n][i]);
	cout << ans << endl;
} 

