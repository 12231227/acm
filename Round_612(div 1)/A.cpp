#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
int f[maxn + 11][5][maxn + 11][maxn + 11];
int a[maxn + 11];
int vis[maxn + 11];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		vis[a[i]] = 1;
	}
	int num[2] = {0};
	for (int i = 1; i <= n; i++)
		if (vis[i] == 0) num[i % 2]++;
	memset(f , 0x3f3f3f,sizeof(f));
	if (a[1] == 0) {
		for (int i = 1; i <= n; i++)
			if (vis[i] == 0)
				f[1][i % 2][num[0] - (i % 2 == 0)][num[1] - (i % 2 == 1)] = 0;
	}
	else {
		f[1][a[1] % 2][num[0]][num[1]] = 0;
	}
	for (int i = 2; i <= n; i++) 
		for (int j = 0; j <= num[0]; j++)
			for (int k = 0; k <= num[1]; k++){
				if (a[i] != 0) {
					int s = a[i] % 2;
					f[i][s][j][k] = min(f[i - 1][s][j][k] , f[i - 1][s ^ 1][j][k] + 1);
				}
				else {
					if (j < num[0]) f[i][0][j][k] = min(f[i - 1][0][j + 1][k] , f[i - 1][1][j + 1][k] + 1);
					if (k < num[1]) f[i][1][j][k] = min(f[i - 1][0][j][k + 1] + 1 , f[i - 1][1][j][k + 1]);
				}
			}
	int ans = 1999;
	for (int j = 0; j <= num[0]; j++)
			for (int k = 0; k <= num[1]; k++)
				ans = min(ans , min(f[n][0][j][k] , f[n][1][j][k]));
	cout << ans << endl;
} 
