#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5;
const long long inf = 1e18;
int a[maxn + 11];
int pos[maxn + 11];

signed main(){
	int n;
	scanf("%lld",&n);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld",&a[i]);
		if (a[i] == 1) {
			pos[++cnt] = i;
		} 
	} 
	if (cnt <= 1) { printf("-1\n"); return 0; }
	int per;
	long long minn = inf;
	for (per = 2; per <= cnt; per++){
		if (cnt % per != 0) continue;
		long long ans = 0;
		for (int i = 1; i <= cnt / per; i++){
			int mid = ((i - 1) * per + 1 + i * per) / 2;
			for (int j = (i - 1) * per + 1; j <= i * per; j++)
				ans += 1ll * abs(pos[j] - pos[mid]);
		}
		minn = min(ans , minn);
		//printf("%lld\n" , ans);
	}
	printf("%lld\n" , minn);
} 

