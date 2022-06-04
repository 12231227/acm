#include <bits/stdc++.h>
using namespace std;

char ch[500][500];

int main(){
	int _;
	for (scanf("%d",&_);_;_--) {
		int n,m;
		scanf("%d %d",&n,&m);
		if (n % 2 == 1 && m % 2 == 1) {
			for (int i = 1; i < n; i++){
				char c = i % 2 == 1 ? 'B' : 'W';
				for (int j = 1; j <= m; j++) printf("%c" , c);
				puts("");
			}
			for (int i = 1; i <= m; i++){
				char c = i % 2 == 1 ? 'B' : 'W';
				printf("%c" , c);
			}
			puts("");
		}
		else {
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++) ch[i][j] = (i + j) % 2 == 1 ? 'W' : 'B';
			if (m % 2 == 0) ch[1][m] = 'B';
			else ch[n][1] = 'B';
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= m;j++)
					printf("%c" , ch[i][j]);
				puts("");
			}
		}
	}
}

