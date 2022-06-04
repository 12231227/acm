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

const ll inf = 1e18;
const int maxn = 1e5;
ll s[maxn + 11];
int a[maxn + 11];
ll f[maxn + 11][450];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = n; i >= 1; i--) cin >> a[i];
		s[0] = 0;
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
		int k = 1;
		while (k * (k + 1) / 2 <= n) k++;
		--k;
		for (int i = 0; i <= n; i++) {
			f[i][0] = inf;
			for (int j = 1; j <= k; j++) f[i][j] = 0;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= k; j++) {
				f[i][j] = f[i - 1][j];
				if (i - j >= 0 && f[i - j][j - 1] > s[i] - s[i - j])
					f[i][j] = max(f[i][j] , s[i] - s[i - j]);
			}
		int ans = 0;
		for (int i = 1; i <= k; i++)
			if (f[n][i]) ans = i;
		cout << ans << endl;
	}
} 