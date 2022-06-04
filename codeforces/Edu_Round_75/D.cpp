#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5;

int n;
ll s;
ll rr[maxn + 11];
struct salary{
	ll l,r;
	bool operator < (const salary &rh) {
		if (l != rh.l) return l < rh.l;
		return r < rh.r;
	}
}sal[maxn + 11];

bool check(ll mid) {
	ll tot = 0;
	int st = n;
	int cnt = 0;
	cnt = 0;
	for (int i = n; i >= 1; i--) {
		if (sal[i].l > mid) { tot += sal[i].l; cnt++; } else { st = i; break; }
	}
	if (tot >= s) return false;
	for (int i = st; i >= 1; i--) { 
		if (sal[i].r >= mid && cnt < n / 2 + 1) { 
			tot += mid;
			cnt++;
		}
		else tot += sal[i].l;
	}
	return tot <= s;
} 

int main(){
	int t;
	scanf("%d",&t);
	while (t--) {
		scanf("%d %lld",&n,&s);
		for (int i = 1; i <= n; i++) {
			scanf("%lld %lld",&sal[i].l,&sal[i].r);
			rr[i] = sal[i].r;
		}
		sort(rr + 1 , rr + 1 + n);
		sort(sal + 1 , sal + 1 + n);
		ll l = sal[n / 2 + 1].l; ll r = rr[n / 2 + 1];
		ll ans = l;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (check(mid)) { ans = mid; l = mid + 1; } else r = mid - 1;
		} 
		printf("%lld\n",ans);
	} 
} 

