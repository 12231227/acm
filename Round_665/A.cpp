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
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n,k; cin >> n >> k;
		int x = max((n - k) / 2 , 0);
		int ans = 1e7;
		for (int i = max(x - 100 , 0); i <= x + 100; i++) {
			ans = min(ans , abs(2 * i + k - n));
		}
		printf("%d\n" , ans);
	}
} 
