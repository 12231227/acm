#include <bits/stdc++.h>
using namespace std;

bool vis[111][111];
char ans[111][111];
char s[111],ch[111];

int main(){
	int num = 0;
	for (int i = 0; i <= 9; i++) {
		s[++num] = i + '0';
	}
	for (int i = 0; i < 26; i++) {
		s[++num] = i + 'a';
	}
	for (int i = 0; i < 26; i++) {
		s[++num] = i + 'A';
	}
	int t;
	scanf("%d",&t);
	while (t--) {
		int r,c,k;
		scanf("%d %d %d",&r,&c,&k);
		int cnt = 0;
		for (int i = 1; i <= r; i++) {
			scanf("%s",ch + 1);
			for (int j = 1; j <= c; j++) {
				if (ch[j] == 'R') { cnt++; vis[i][j] = 1; } else vis[i][j] = 0;
			}
		}
		int per = cnt / k;
		int cnt2 = cnt - per * k;
		int cnt1 = k - cnt1;
		int sta = cnt2 == 0 ? per : per + 1;
		int now = 0;
		int ind = 1;
		for (int i = 1; i <= r; i++) {
			if (i % 2 == 1){
			
				for (int j = 1; j <= c; j++)
			 {
				ans[i][j] = s[ind];
				now += vis[i][j];
				if (now == sta) { 
					if (cnt2) { cnt2--; if (cnt2 == 0) sta -= 1; now = 0; ind++; }
					else { now = 0; if (ind < k) ind++; }
				}
			}
			}
			else {
				for (int j = c; j >= 1; j--)
			 {
				ans[i][j] = s[ind];
				now += vis[i][j];
				if (now == sta) {
					if (cnt2) { cnt2--; if (cnt2 == 0) sta -= 1; now = 0; ind++; }
					else { now = 0; if (ind < k) ind++; }
				}
			}
			}
		}
		bool flag = false;
		if (ans[r][1] != s[k] && ans[r][c] != s[k]) {
			for (int i = 1; i <= r; i++) {
				if (flag) break;
				if (i % 2 == 1) {
					for (int j = 1; j <= c; j++)
						if (vis[i][j] == 0) {
							ans[i][j] = s[ind++];
							if (ind > k) {
								flag = true; break;
							}
						}
				}
				else {
					for (int j = c; j >= 1; j--)
						if (vis[i][j] == 0) {
							ans[i][j] = s[ind++];
							if (ind > k) { flag = true; break;
							}
						}
				}
			}
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) printf("%c",ans[i][j]);
			printf("\n");
		}
	}
}
