#include <bits/stdc++.h>
using namespace std;

int f[411][411];
char s[411],t[411];

int main(){
	int T;
	scanf("%d" , &T);
	while (T--) {
		scanf("%s" , s + 1); int n = strlen(s + 1);
		scanf("%s" , t + 1); int m = strlen(t + 1);
		bool can = false;
		for (int i = 1; i <= m; i++) {
			if (can) break;
			for (int j = 0; j <= n; j++){
				for (int k = 1; k <= i; k++) f[j][k] = -1;
				f[j][0] = 0;
			}
			for (int j = 1; j <= n; j++)
				for (int k = 0; k <= min(i , j); k++){
					if (f[j - 1][k] >= 0) {
						f[j][k] = f[j - 1][k];
						if (f[j][k] < m - i && s[j] == t[f[j][k] + 1 + i]) f[j][k]++;
					}
					if (s[j] == t[k] && f[j - 1][k - 1] >= 0) f[j][k] = max(f[j][k] , f[j - 1][k - 1]);
				} 
			if (f[n][i] >= m - i) can = true;
		} 
		printf("%s\n" , can ? "YES" : "NO");
	} 
} 

