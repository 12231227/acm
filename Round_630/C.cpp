#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
char ch[maxn + 11];
int cnt[maxn + 11][30];

int main(){
	int _;
	for (scanf("%d",&_);_;_--) {
		int n,k; scanf("%d %d",&n,&k);
		scanf("%s" , ch + 1);
		for (int i = 1; i <= k; i++)
			for (int j = 0; j < 26; j++) cnt[i][j] = 0;
		for (int i = 1; i <= n / k; i++)
			for (int j = 1; j <= k; j++) 
				cnt[j][ch[(i - 1) * k + j] - 'a']++;
		int ans = 0;
		for (int l = 1, r = k;;l++,r--) {
			if (l > r) break;
			int mn = 4 * n;
			for (int j = 0; j < 26; j++) {
				mn = min(mn , n / k - cnt[l][j] + n / k - cnt[r][j]);
			}
			if (l == r) mn /= 2;
			ans += mn;
		}
		printf("%d\n" , ans);
	} 
} 
