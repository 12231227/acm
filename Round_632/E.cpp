#include <bits/stdc++.h>
using namespace std;

int n;
int a[511][511];

void out() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d " , a[i][j]);
		puts("");
	}
}

int main(){
	cin >> n;
	if (n == 1 || n == 2) { puts("-1"); return 0; }
	int s = n * n;
	a[n - 2][n - 2] = s - 8; a[n - 2][n - 1] = s - 7; a[n - 2][n] = s - 5;
	a[n - 1][n - 2] = s - 4; a[n - 1][n - 1] = s - 6; a[n - 1][n] = s - 1;
	a[n][n - 2] = s; a[n][n - 1] = s - 3; a[n][n] = s - 2;
	if (n == 3) { out(); return 0; }
	int x = n; int y = 1;
	a[x][y] = 1; int fx = 1; int num = 1;
	while (x != n - 3 || y != n - 3) {
		if (fx == 1) {
			for (int i = x - 1; ; i--) {
				if (a[i][y] || !i) { x = i + 1; break; }
				a[i][y] = ++num;
			}
			fx = 2;
		}
		else if (fx == 2) {
			for (int i = y + 1; ; i++) {
				if (a[x][i] || i == n + 1) { y = i - 1; break; }
				a[x][i] = ++num;
			}
			fx = 3;
			a[++x][y] = ++num;
		}
		else if (fx == 3) {
			for (int i = y - 1; ; i--) {
				if (a[x][i] || !i) { y = i + 1; break; }
				a[x][i] = ++num;
			}
			fx = 4;
		}
		else if (fx == 4) {
			for (int i = x + 1; ; i++) {
				if (a[i][y] || i == n + 1) { x = i - 1; break; }
				a[i][y] = ++num;
			}
			fx = 1;
			a[x][++y] = ++num;
		}
	}
	if (fx == 4) {
		a[n][y] = ++num; a[n - 1][y] = ++num; a[n - 2][y] = ++num;
	}
	if (fx == 2) {
		a[x][n] = ++num; a[x][n - 1] = ++num; a[x][n -2 ] = ++num;
	}
	out();
} 
