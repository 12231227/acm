#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1e5;

pii a[maxn + 11];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		int g = 1e9;
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			a[i] = make_pair(x , i);
			g = min(g , x);
		}
		sort(a + 1 , a + 1 + n);
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (a[i].second != i && a[i].first % g != 0) { flag = false; break; }
		}
		if (!flag) printf("NO\n"); else printf("YES\n");

	}
} 