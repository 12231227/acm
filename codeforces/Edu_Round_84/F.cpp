#include <bits/stdc++.h>
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

const ll mol = 998244353;
const int maxn = 5e5;

int to[maxn + 11],l[maxn + 11],r[maxn + 11],x[maxn + 11],a[maxn + 11];
ll f[maxn + 11];

ll sub(ll a,ll b) { a -= b; if (a < 0) a += mol; return a; }

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,k,m; cin >> n >> k >> m;
	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i] >> x[i];
	}
	ll ans = 1;
	for (int j = 0; j < k; j++) {
		for (int i = 1; i <= n; i++) a[i] = 0,to[i] = 0;
		for (int i = 1; i <= m; i++) {
			if (x[i] & (1 << j)) {
				a[l[i]]++; a[r[i] + 1]--;
			}
			else to[r[i]] = max(to[r[i]] , l[i]);
		}
		ll sum = 1;
		f[0] = 1;
		int ind = 0;
		for (int i = 1; i <= n; i++) {
			a[i] += a[i - 1];
			if (a[i]) f[i] = 0;
			else{
				f[i] = sum;
				sum = sum * 2 % mol;
			}
			if (!to[i]) continue;
			while (ind < to[i]) { sum = sub(sum , f[ind]); ind++; }
		}
		ans = ans * sum % mol;
	}
	cout << ans << endl;
	
} 
