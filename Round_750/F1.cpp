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

const int maxn = 1e5;
vector <int> ans;
int a[maxn + 11];
int f[maxn + 11][515];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int m = 0;
	for (int i = 1; i <= n; i++) cin >> a[i] , m = max(m , a[i]);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 512; j++) f[i][j] = 512;
	}
	f[1][a[1]] = a[1];
	for (int i = 2; i <= n; i++){
		f[i][a[i]] = a[i];
		for (int j = 0; j <= 512; j++) {
			f[i][j] = min(f[i][j] , f[i - 1][j]);
			if (f[i - 1][j ^ a[i]] < a[i]) f[i][j] = min(f[i][j] , a[i]);
		}
	}
	ans.pb(0);
	for (int j = 1; j < 512; j++)
		if (f[n][j] <= m) ans.pb(j);
	cout << ans.size() << endl;
	for (auto u : ans) cout << u << " ";
	cout << endl;
	for (int i = 1; i <= n; i++)
} 


