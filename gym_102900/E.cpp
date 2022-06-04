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
const int maxn = 1e7;

int f[maxn + 11],fac[maxn + 11],inv[maxn + 11];

int C(int n,int m) { return 1ll * fac[n] * inv[m] % mol * inv[n - m] % mol; }

int add(int a,int b) { a += b; if (a >= mol) a -= mol; return a; }
int sub(int a,int b) { a -= b; if (a < 0) a += mol; return a; }

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n = 1e7;
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mol;
	inv[1] = 1;
	for (int i = 2; i <= n; i++) inv[i] = 1ll * (mol - mol / i) * inv[mol % i] % mol;
	for (int i = 2; i <= n; i++) inv[i] = 1ll * inv[i - 1] * inv[i] % mol;
	int k;
	cin >> n >> k;
	f[0] = 1;
	for (int i = 1; i <= k; i++) f[i] = fac[i];
	int sum = k;
	for (int i = k + 1; i <= n; i++) {
		f[i] = 1ll * fac[i - 1] * sum % mol;
		sum = add(sum , 1ll * f[i] * inv[i] % mol);
		sum = sub(sum , 1ll * f[i - k] * inv[i - k] % mol);
	}
	cout << f[n] << endl;
} 
