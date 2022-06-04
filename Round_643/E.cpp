#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int h[maxn + 11];
int n,a,r,m;

long long f(int lim) {
	long long add = 0 , sub = 0;
	for (int i = 1; i <= n; i++)
		if (h[i] > lim) sub += h[i] - lim; else add += lim - h[i];
	if (a + r <= m) return 1ll * a * add + 1ll * r * sub;
	if (add >= sub) return 1ll * a * (add - sub) + 1ll * m * sub;
	return 1ll * r * (sub - add) + 1ll * m * add;
}

int main(){	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> a >> r >> m;
	for (int i = 1; i <= n; i++) cin >> h[i];
	int l = 0; int r = 1e9;
	long long ans = 4e18;
	while (l <= r) {
		int len = (r - l + 1) / 3;
		int ml = l + len;
		int mr = ml + len;
		long long al = f(ml);
		long long ar = f(mr);
		ans = min(ans , min(al , ar));
		if (al < ar) r = mr - 1; else l = ml + 1;
	}
	printf("%lld\n" , ans);
}
