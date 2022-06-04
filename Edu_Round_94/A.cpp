#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int main(){ 
	int t; cin >> t;
	while (t--) {
		int n ; cin >> n;
		vector <ll> v;
		char ch[500];
		scanf("%s" , ch + 1);
		for (int i = 1; i <= n; i++) {
			ll x = 0;
			ll two = 1;
			for (int j = i; j <= i + n - 1; j++) {
				if (ch[j] == '0') x += two;
				two *= 2;
			}
			v.pb(x);
		}
		sort(all(v));
		ll ans = 0;
		for (auto u : v) if (u == ans) ans++;
		for (int i = 0; i < n; i++) 
			if (ans & (1ll << i)) printf("1"); else printf("0");
		printf("\n");
	}
} 