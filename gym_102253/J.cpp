#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int mol = 1e9 + 7;
const int maxn = 1e5;
int f[maxn + 11],cnt[maxn + 11],s[maxn + 11],a[maxn + 11];

int add(int a,int b) { a += b; if (a >= mol) a -= mol; return a; }
int sub(int a,int b) { a -= b; if (a < 0) a += mol; return a; }

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n = 1e5;
	cnt[0] = 1;
	for (int i = 1; i <= n; i++) {
		cnt[i] = 0;
		for (int j = 1; 1ll * j * (3 * j - 1) / 2 <= i; j++) {
			if (j & 1) cnt[i] = sub(cnt[i] , cnt[i - j * (3 * j - 1) / 2]);
			else cnt[i] = add(cnt[i] , cnt[i - j * (3 * j - 1) / 2]);
			if (1ll * j * (3 * j + 1) / 2 <= i) {
				if (j & 1) cnt[i] = sub(cnt[i] , cnt[i - j * (3 * j + 1) / 2]);
				else cnt[i] = add(cnt[i] , cnt[i - j * (3 * j + 1) / 2]);
			}
		}
		cnt[i] = sub(0 , cnt[i]);
	}
	int m , k = 0;
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 0; i <= 2 * n; i++) f[i] = cnt[i];
		for (int i = 1; i <= n; i++) {
			if (1ll * i * (a[i] + 1) > 2ll * n) break;
			for (int j = 2 * n - i * (a[i] + 1); j >= 0; j--)
				f[j + i * (a[i] + 1)] = sub(f[j + i * (a[i] + 1)] , f[j]);
		}
		s[0] = sub(0 , f[0]);
		for (int i = 1; i < n; i++) s[i] = sub(s[i - 1] , f[i]);
		for (int i = n + 1; i <= 2 * n; i++) f[i] = add(f[i] , s[i - n - 1]);
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			int x; cin >> x;
			ans = add(ans , f[2 * n - x]);
		}
		cout << "Case #" << ++k << ": ";
		cout << ans << endl;
	} 
} 
