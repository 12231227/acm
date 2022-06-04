#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int a[511];

bool check(int n) {
	bool flag = true;
	for (int i = 1; i < n; i++) if (a[i + 1] < a[i]) flag = false;
	return flag;
}

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n,x; cin >> n >> x;
		int mx = 0;
		for (int i = 1; i <= n; i++) cin >> a[i] , mx = max(mx , a[i]);
		if (check(n)) {
			printf("0\n");
			continue;
		}
		int ans = 0;
		int j = 1;
		while (1) { 
			if (x >= mx) break;
			while (j <= n && a[j] <= x) j++;
			if (j > n) break;
			swap(a[j] , x);
			ans++;
			if (check(n)) break;
		} 
		if (check(n)) printf("%d\n" , ans);
		else printf("-1\n");
	} 
} 

