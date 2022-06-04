#include <bits/stdc++.h>
using namespace std;

int ans[555];
int to[555][555],f[555][555];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		f[i][i] = 1; to[i][i] = x;
	}
	for (int l = 2; l <= n; l++)
		for (int i = 1,j = i + l - 1;j <= n;i++,j++)
			for (int k = i; k < j; k++) {
				if (f[i][k] && f[k + 1][j] && to[i][k] == to[k + 1][j]) {
					f[i][j] = 1; to[i][j] = to[i][k] + 1;
				}
			} 
	memset(ans , 0x3f3f3f,sizeof(ans));
	ans[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			if (f[j + 1][i]) ans[i] = min(ans[i] , ans[j] + 1);
	printf("%d\n" , ans[n]);
} 

