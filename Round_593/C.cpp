#include <bits/stdc++.h>
using namespace std;

const int maxn = 300;

int a[maxn + 11][maxn + 11];

int main(){
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) a[i][j] = ++cnt;
		}
		else for (int j = n; j >= 1; j--) a[i][j] = ++cnt;
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) printf("%d ", a[i][j]);
		printf("\n");
	}
} 

