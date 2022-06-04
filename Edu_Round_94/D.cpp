#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 3000;
int cnt[maxn + 11],a[maxn + 11];

int main(){ 
	int t; scanf("%d",&t);
	while (t--) {
		int n; scanf("%d",&n);
		for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
		ll ans = 0;
		for (int i = 3; i < n; i++) {
			for (int j = i + 1; j <= n; j++) cnt[a[j]]++;
			ll res = 0;
			for (int j = 1; j < i; j++) res += cnt[a[j]];
			for (int j = 1; j < i - 1; j++) {
				res -= cnt[a[j]];
				if (a[j] == a[i]) ans += res;
			}
			for (int j = i + 1; j <= n; j++) cnt[a[j]]--;
		}
		printf("%lld\n" , ans);
	}
} 
