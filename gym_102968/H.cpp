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
const int mol = 1e9 + 7;
int a[maxn + 11];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		a[x]++;
	}
	n = 1e5;
	int sum = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		sum = 1ll * sum * a[i] % mol;;
		sum = (sum + a[i]) % mol;
		ans = (ans + sum) % mol;
	}
	cout << ans << endl;
} 