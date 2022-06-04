#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 2e5;
const int mol = 1e9 + 7;
int f[maxn + 11][5],cnt[maxn + 11],a[maxn + 11],mx[maxn + 11];

int add(int a,int b) { a += b; if (a >= mol) a -= mol; return a; } 
int sub(int a,int b) { a -= b; if (a < 0) a += mol; return a; }
int qpow(int a,int b) {
	int ans = 1;
	while (b) { 
		if (b & 1) ans = 1ll * ans * a % mol;
		a = 1ll * a * a % mol;
		b >>= 1;
	} 
	return ans;
} 

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t; int kase = 0; 
	while (t--) { 
		kase++;
		int n,m,k; cin >> n >> m >> k;
		for (int i = 1; i <= n + m; i++) cin >> a[i];
		for (int i = 1; i <= n + m; i++) mx[i] = 0;
		// x + y = i , cnt[i]
		for (int i = 2; i <= n + m; i++) {
			int l = max(1 , i - m);
			int r = min(n , i - 1);
			cnt[i] = max(r - l + 1 , 0);
		}
		cnt[n + m + 1] = 0;
		for (int i = 1; i <= k; i++) { 
			int x,y,h; cin >> x >> y >> h;
			mx[x + y] = max(mx[x + y] , h);
//			mx[x + y - 1] = max(mx[x + y - 1] , h);
			cnt[x + y]--;
		} 
		cout << "Case #" << kase << ": ";
		if (mx[2] && mx[2] != a[1]) { 
			cout << 0 << endl;
			continue;
		} 

		if (mx[n + m] && mx[n + m] != a[n + m]) {
			cout << 0 << endl;
			continue;
		}

		for (int i = 1; i <= n + m; i++) f[i][0] = f[i][1] = 0;
		if (a[1] < a[2]) f[1][0] = 1; else if (a[1] == a[2]) f[1][1] = 1;

		for (int i = 2; i < n + m; i++) { 
			if (cnt[i + 1] < 0) continue;
			if (mx[i] > a[i] || mx[i + 1] > a[i]) continue;

			if (a[i] < a[i + 1] && mx[i + 1] < a[i + 1]) { 
				if (mx[i + 1] < a[i]) f[i][0] = add(f[i][0] , 1ll * f[i - 1][0] * sub(qpow(a[i] , cnt[i + 1]) , qpow(a[i] - 1 , cnt[i + 1])) % mol);
				else if (mx[i + 1] == a[i]) f[i][0] = add(f[i][0] , 1ll * f[i - 1][0] * qpow(a[i] , cnt[i + 1]) % mol);
			} 

			if (mx[i + 1] < a[i + 1]) { 
				int lim = min(a[i] , a[i + 1] - 1);
				f[i][0] = add(f[i][0] , 1ll * f[i - 1][1] * qpow(lim , cnt[i + 1]) % mol);
			}

			if (a[i] == a[i + 1]) {
				if (mx[i + 1] < a[i]) f[i][1] = add(f[i][1] , 1ll * f[i - 1][0] * sub(qpow(a[i] , cnt[i + 1]) , qpow(a[i] - 1 , cnt[i + 1])) % mol);
				else if (mx[i + 1] == a[i]) f[i][1] = add(f[i][1] , 1ll * f[i - 1][0] * qpow(a[i] , cnt[i + 1]) % mol);
			}

			if (a[i + 1] <= a[i]) {
				if (mx[i + 1] < a[i + 1]) f[i][1] = add(f[i][1] , 1ll * f[i - 1][1] * sub(qpow(a[i + 1] , cnt[i + 1]) , qpow(a[i + 1] - 1 , cnt[i + 1])) % mol);
				else if (mx[i + 1] == a[i + 1]) f[i][1] = add(f[i][1] , 1ll * f[i - 1][1] * qpow(a[i + 1] , cnt[i + 1]) % mol);
			}
		} 

		cout << f[n + m - 1][1] << endl;
	} 
} 
