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
		int n; cin >> n;
		int ans = 0;
		int x; cin >> x; ans = 3 * x;
		for (int i = 2; i <= n; i++) {
			cin >> x;
			ans = max(ans , x + 1);
		}
		if (ans & 1) ++ans;
		cout << ans << endl;
	} 
} 
