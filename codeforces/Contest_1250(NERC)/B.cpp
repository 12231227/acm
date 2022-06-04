#include <bits/stdc++.h>
#define ll long long
using namespace std;

int cnt[10000];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,k; cin >> n >> k;
	for (int i = 1; i <= n; i++) { 
		int x; cin >> x;
		cnt[x]++;
	} 
	sort(cnt + 1 , cnt + k + 1);
	ll ans = 1ll * cnt[k] * k;
	int e;
	if (k % 2 == 0) e = k; else e = k - 1;
	for (int i = e; i >= 2; i -= 2) {
		int mx = cnt[k];
		for (int j = 1,p = i;j < p;j++,p--) 
			mx = max(mx , cnt[j] + cnt[p]);
		ans = min(ans , 1ll * mx * (i / 2 + k - i));
	} 
	cout << ans << endl;
} 

