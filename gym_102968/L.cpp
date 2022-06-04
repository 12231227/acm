#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e6;
set <int , greater<int> > s;
vector <int> d[maxn + 11];
int a[maxn + 11];
bool vis[maxn + 11];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j * j <= a[i]; j++)
			if (a[i] % j == 0) {
				d[j].pb(i);
				if (j * j < a[i]) d[a[i] / j].pb(i);
			}
	}
	for (int i = 1; i * i <= a[1]; i++) {
		if (a[1] % i == 0) {
			s.insert(i);
			if (i * i < a[1]) s.insert(a[1] / i);
		}
	}
	ll ans = 0;
	for (int i = 2; i <= n; i++) {
		for (auto it = s.begin(); it != s.end(); ) {
			int x = *it;
			while (!d[x].empty() && vis[d[x].back()]) d[x].pop_back();
			if (!d[x].empty()) {
				ans += x;
				int j = d[x].back();
				vis[j] = true; d[x].pop_back();
				for (int k = 1; k * k <= a[j]; k++) {
					if (a[j] % k == 0) {
						s.insert(k);
						if (k * k < a[j]) s.insert(a[j] / k);
					}
				}
				break;
			}
			else {
				it++;
				s.erase(s.begin());
			}
		}
	}
	cout << ans << endl;
} 
