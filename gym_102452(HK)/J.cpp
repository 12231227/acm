#include <bits/stdc++.h>
using namespace std;

const int mol = 1e9 + 7;
const int maxn = 5000;
int m;
int ten[maxn + 11];
int f[maxn + 11][62][62][2] = {0};
char l[maxn + 11];
char r[maxn + 11];

int add(int a,int b,int mm) { a += b; if (a >= mm) a -= mm; return a; } 

int solve(char ch[],int op) {
	int n = strlen(ch + 1);
	f[0][0][0][1] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < m; k++)
				for (int o = 0; o < 2; o++) {
					if (!f[i][j][k][o]) continue;
					for (int p = 0; p < 10; p++) {
						if (o && p > ch[i + 1] - '0') break;
						int nxt = (o == 1) && (p == ch[i + 1] - '0');
						f[i + 1][(j + p) % m][(k + p * (j - ten[n - i - 1]) % m + m) % m][nxt] =
						add(f[i + 1][(j + p) % m][(k + p * (j - ten[n - i - 1]) % m + m) % m][nxt] , f[i][j][k][o] , mol);
					}
				}
	int ans = 0;
	for (int i = 0; i < m; i++){
		ans = add(ans , f[n][i][0][0] , mol);
		if (op == 0) ans = add(ans , f[n][i][0][1] , mol);
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < m; k++) f[i][j][k][0] = f[i][j][k][1] = 0;
	return ans;
}

int main() {
	int t;
	scanf("%d" , &t);
	while (t--) {
		scanf("%s" , l + 1);
		scanf("%s" , r + 1);
		scanf("%d",&m);
		ten[0] = 1;
		for (int i = 1; i <= 5000; i++) ten[i] = ten[i - 1] * 10 % m;	
		int ans = solve(r , 0) - solve(l , 1);
		if (ans < 0) ans += mol;
		printf("%d\n" , ans);
	} 
} 

