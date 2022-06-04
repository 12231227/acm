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

vector <int> v,num[maxn + 11];
int a[maxn + 11];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	for (int c = 1; c <= t; c++) {
		int n; cin >> n;
		v.clear();
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			v.pb(a[i]);
		} 
		a[0] = a[n + 1] = 1e9 + 7;
		sort(all(v)); v.erase(unique(all(v)) , v.end());
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int pos = lower_bound(all(v) , a[i]) - v.begin();
			num[pos].pb(i);
		} 
		for (int i = 0; i < v.size(); i++) { 
			for (auto pos : num[i]) { 
				if (a[pos - 1] >= a[pos] && a[pos + 1] >= a[pos]) {
					ans = (ans + a[pos]) % 2;
					a[pos] = 0;
					continue;
				}
				int mn = 0;
				if (a[pos - 1] < a[pos]) mn = max(mn , a[pos - 1] + 1);
				if (a[pos + 1] < a[pos]) mn = max(mn , a[pos + 1] + 1);
				ans = (ans + a[pos] - mn) % 2;
				a[pos] = mn;
			}
		}
		for (int i = 0; i < v.size(); i++) num[i].clear();
		cout << "Case " << c << ": ";
		if (ans & 1) cout << "Alice" << endl;
		else cout << "Bob" << endl;
	}
} 
