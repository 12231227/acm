#include <bits/stdc++.h>
using namespace std;

const int maxn = 500;
int a[maxn + 11][maxn + 11];
int f[maxn + 11][maxn + 11];

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++){
		char ch[maxn + 11];
		scanf("%s",ch + 1);
		for (int j = 1; j <= n; j++)
			a[i][j] = ch[j] - '0';
	}
	for (int s = 1; s < n; s++){
		f[s][s + 1] = a[s][s + 1];
		for (int e = s + 2; e <= n; e++){
			int res = 0;
			for (int i = s + 1; i < e; i++) res = (res + f[s][i] * a[i][e] % 10) % 10;
			if (res == a[s][e]) f[s][e] = 0; else f[s][e] = 1;
		} 
	} 
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= n; j++) 
			printf("%d",f[i][j]);
		printf("\n");
	} 
} 

