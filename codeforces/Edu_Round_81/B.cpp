#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int cnt[maxn + 11];
char ch[maxn +11];

int main() {
	int t;
	scanf("%d" , &t);
	while (t--) {
		int n,x;
		scanf("%d %d",&n,&x);
		scanf("%s" , ch + 1);
		for (int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + (ch[i] == '0' ? 1 : -1);
		if (cnt[n] == 0) {
			bool flag = false;
			for (int i = 1; i <= n; i++) if (cnt[i] == x) { flag = true; break; }
			printf("%d\n" , flag ? -1 : 0);
		}
		else {
			int ans = 0;
			if (x == 0) ans = 1;
			for (int i = 1; i <= n; i++)
				if ((x - cnt[i]) % cnt[n] == 0 && (x - cnt[i]) / cnt[n] >= 0) ans++;
			printf("%d\n" , ans);
		}
	}
} 

