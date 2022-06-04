#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int mol = 998244353;
const int maxn = (1 << 20);
const int N = 3e5;
int add[maxn + 11][42];
vector <int> in[maxn + 11],out[maxn + 11];
int a[maxn + 11],b[maxn + 11],fac[maxn + 11],inv[maxn + 11];
vector <pii> bit[maxn + 11];
int num[maxn + 11];
bool vis[maxn + 11];

int Add(int a,int b) { a += b; if (a >= mol) a -= mol; return a; }

int qpow(int a,int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1ll * ans * a % mol;
		a = 1ll * a * a % mol;
		b >>= 1;
	}
	return ans;
}

int C(int n,int m) {
	if (n < 0 || m < 0 || n < m) return 0;
	return 1ll * fac[n] * inv[m] % mol * inv[n - m] % mol;
}

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m; cin >> n >> m;
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= maxn; i++) fac[i] = 1ll * fac[i - 1] * i % mol;
	inv[maxn] = qpow(fac[maxn] , mol - 2);
	for (int i = maxn - 1; i >= 1; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mol;
	for (int i = 1; i <= n; i++) {
		int l,r; cin >> l >> r;
		in[l].pb(i); out[r].pb(i);
	}
	for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
	for (int i = 1; i < (1 << m); i++) {
		//set <int> s;
		int cnt = 0;
		for (int j = 0; j < m; j++) if (i & (1 << j)) {
			if (!vis[a[j]]) cnt++;
			vis[a[j]] = true;
			if (!vis[b[j]]) cnt++;
			vis[b[j]] = true;
		}
		num[i] = cnt;
		for (int j = 0; j < m; j++) if (i & (1 << j)) {
			vis[a[j]] = false;
			vis[b[j]] = false;
		}
	}
	for (int i = 1; i < (1 << m); i++) {
		int n = __builtin_popcount(i);
		if (n & 1) add[i][num[i]] = 998244352; else add[i][num[i]] = 1;
	}
		for (int j = 0; j < m; j++)
			for (int i = 1; i < (1 << m); i++)
				if (i & (1 << j)) {
					for (int k = 1; k <= 2 * m; k++)
						add[i][k] = Add(add[i][k] , add[i ^ (1 << j)][k]);
				}
	int cnt = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (auto u : in[i]) { vis[u] = true; cnt++; }
		int sta = 0;
		for (int j = 0; j < m; j++)
			if (vis[a[j]] && vis[b[j]]) sta |= (1 << j);
		bit[sta].pb(make_pair(cnt , i));
		ans = Add(ans , C(cnt , i));
		for (auto u : out[i]) { vis[u] = false; cnt--; }
	}
	for (int i = 0; i < (1 << m); i++) {
		for (auto pi : bit[i]) {
			int cnt = pi.first , x = pi.second;
			for (int j = 1; j <= 2 * m; j++) {
				ans = Add(ans , 1ll * C(cnt - j , x - j) * add[i][j] % mol);
			}
		}
	}
	cout << ans << endl;
} 
