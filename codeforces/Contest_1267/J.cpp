#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6;
int cnt[maxn + 11],res[maxn + 11];
int tot;

bool check(int s) {
	for (int i = 1; i <= tot; i++)
		if ((res[i] - 1) / s + 1 > res[i] / (s - 1)) return false;
	return true;
}

int calc(int s) {
	int ans = 0;
	for (int i = 1; i <= tot; i++) {
		int l = res[i] / (s - 1);
		int mod = l - res[i] % (s - 1);
		ans += l - mod / s;
	}
	return ans;
}

int main(){
	int t;
	for (scanf("%d",&t);t;t--) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d",&x);
			cnt[x]++;
		}
		tot = 0;
		for (int i = 1; i <= n; i++) if (cnt[i]) res[++tot] = cnt[i];
		sort(res + 1 , res + 1 + tot);
		int s = res[1] + 1;
		if (check(s)) { printf("%d\n" , calc(s)); continue; }
		s--;
		if (check(s)) { printf("%d\n" , calc(s)); continue; }
		for (s = res[1] / 2 + 1; s >= 1; s--) {
			if (check(s)) { printf("%d\n" , calc(s)); break; }
		}
	}
} 

