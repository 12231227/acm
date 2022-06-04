#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
pair<int,int> seg[maxn + 11];
int f[maxn + 11][300];
int cnt[300];
int pos[maxn + 11];
 
int lowbit(int x) { return x & (-x); }
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		int l,r;
		scanf("%d %d",&l,&r);
		seg[++tot] = {l , i};
		seg[++tot] = {r + 1 , -i};
	}
	sort(seg + 1 , seg + 1 + tot);
	int sta = (1 << k) - 1;
	int s = sta;
	for (int i = 0; i < (1 << k); i++) cnt[i] = (k - __builtin_popcount(i)) % 2;
	for (int i = 1;i <= tot; i++) {
		int len = seg[i].first - seg[i - 1].first;
		if (seg[i].second > 0) {
			pos[seg[i].second] = lowbit(sta);
			for (int j = 0; j < (1 << k); j++) {
				if ((s ^ j) & sta) continue;
				int add = cnt[j] * len;
				f[i][j] = max(f[i][j] , f[i - 1][j] + add);
				f[i][j ^ pos[seg[i].second]] = max(f[i][j ^ pos[seg[i].second]] , f[i - 1][j] + add);
			}
			sta ^= lowbit(sta);
		}
		else {
			for (int j = 0; j < (1 << k); j++) {
				if ((s ^ j) & sta) continue;
				int add = cnt[j] * len;
				if ((j & pos[-seg[i].second])) f[i][j] = max(f[i][j] , f[i - 1][j] + add);
				else f[i][j ^ pos[-seg[i].second]] = max(f[i][j ^ pos[-seg[i].second]] , f[i - 1][j] + add);
			}
			sta ^= pos[-seg[i].second];
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << k); i++) ans = max(ans , f[tot][i]);
	printf("%d\n" , ans);
} 

