#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e5;

ll cnt[70];
int a[maxn + 11];

int main(){
	int t;
	scanf("%d" , &t);
	while (t--) {
		ll n; int m;
		scanf("%lld %d",&n,&m);
		for (int i = 0; i < 64; i++) cnt[i] = 0;
		for (int i = 1; i <= m; i++) {
			scanf("%d" , &a[i]);
			for (int j = 0; j <= 30; j++)
				if (a[i] == (1 << j)) cnt[j]++;
		}
		ll ans = 0;
		bool flag = true;
		for (int i = 0; i < 64; i++) {
			if (n & (1ll << i)) {
				if (cnt[i]) cnt[i]--;
				else {
					int f = 0;
					for (int j = i + 1; j < 64; j++)
						if (cnt[j]) { f = j; break; }
					if (!f) flag = false;
					else {
						cnt[f]--;
						for (int j = f - 1; j >= i; j--) { cnt[j]++; ans++; }
					}
				}
			}
			if (!flag) break;
			if (cnt[i] >= 2) cnt[i + 1] += cnt[i] / 2;
		}
		if (flag) printf("%lld\n" , ans);
		else printf("-1\n");
	}
} 

