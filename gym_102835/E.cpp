#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

char ch[511];
int a[511],L[511],R[511];
int f[511][511][10];

int get(char c) {
	if (c == 'R') return 0; if (c == 'G') return 1; if (c == 'B') return 2;
	if (c == 'C') return 3; if (c == 'M') return 4; if (c == 'Y') return 5;
	return 6;
} 

int main(){ 
	int n,m;
	scanf("%s %d" , ch + 1 , &m);
	n = strlen(ch + 1);
	for (int i = n; i >= 1; i--) { 
		if (i < n && ch[i] == ch[i + 1]) R[i] = R[i + 1];
		else R[i] = i;
	} 
	for (int i = 1; i <= n; i++) {
		if (i > 1 && ch[i] == ch[i - 1]) L[i] = L[i - 1];
		else L[i] = i;
	} 
	for (int i = 1; i <= n; i++) a[i] = get(ch[i]);
	memset(f , -1 , sizeof(f));
	for (int len = 1; len <= n; len++)
		for (int i = 1 , j = len; j <= n; i++ , j++) {
			for (int k = i; k < j; k++) 
				for (int c = 0; c < 7; c++) 
					if (f[i][k][c] != -1 && f[k + 1][j][c] != -1) f[i][j][c] = max(f[i][j][c] , f[i][k][c] + f[k + 1][j][c]);
			if (R[i] >= j) f[i][j][a[i]] = len;
			else if (a[i] == a[j]) { 
				if (f[R[i] + 1][L[j] - 1][a[i]] != -1)
					f[i][j][a[i]] = max(f[i][j][a[i]] , R[i] - i + 1 + j - L[j] + 1 + f[R[i] + 1][L[j] - 1][a[i]]);
			} 
			bool flag = false;
			for (int c = 0; c < 7; c++) if (f[i][j][c] >= m) flag = true;
			for (int c = 0; c < 7; c++) if (flag && f[i][j][c] == -1) f[i][j][c] = 0;
		}
	bool flag = false;
	for (int i = 0; i < 7; i++) if (f[1][n][i] >= m || f[1][n][i] == 0) flag = true;
	if (flag) printf("Yes\n"); else printf("No\n");
} 
