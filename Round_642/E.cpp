#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

char ch[maxn + 11];
int f[maxn + 11][2];
int cnt[maxn + 11];

int main(){
	int t;
	for (scanf("%d",&t);t;t--) {
		int n,k;
		scanf("%d %d",&n,&k);
		scanf("%s" , ch + 1);
		for (int i = 1; i <= n; i++) {
			cnt[i] = cnt[i - 1];
			if (ch[i] == '1') cnt[i]++;
			f[i][0] = f[i][1] = maxn;
		}
		f[0][0] = 0; f[0][1] = maxn;
		for (int i = 1; i <= n; i++) {
			if (i - k <= 0) {
				f[i][1] = cnt[i - 1] + (ch[i] == '0');
			}
			else {
				f[i][1] = min(f[i - k][1] + cnt[i - 1] - cnt[i - k] , cnt[i - 1]) + (ch[i] == '0');
			}
			f[i][0] = min(f[i - 1][0] , f[i - 1][1]) + (ch[i] == '1');
		}
		printf("%d\n" , min(f[n][0] , f[n][1]));
	}
} 

