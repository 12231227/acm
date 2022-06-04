#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
using namespace std;

const ll mol = 998244353;
const int maxn = 1000;
int l[maxn + 11],r[maxn + 11],R[maxn + 11],L[maxn + 11];
vector <int> v;
ll inv[maxn + 11];
ll f[maxn + 11][maxn + 11];

ll add(ll a,ll b) { a += b; if (a >= mol) a -= mol; return a; }
ll qpow(ll a,ll b) { 
	ll ans = 1;
	while (b) { 
		if (b & 1) ans = ans * a % mol;
		a = a * a % mol;
		b >>= 1;
	} 
	return ans;
} 
void pre() {
	inv[0] = 1;
	for (int i = 1; i <= 500; i++) inv[i] = inv[i - 1] * qpow(i , mol - 2) % mol;
} 
ll C(int n,int m) {
	ll ans = 1;
	for (int i = n - m + 1; i <= n; i++) ans = ans * i % mol;
	return ans * inv[m] % mol;
}

int main() {
	int n;
	pre();
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d",&l[i],&r[i]);
		v.push_back(l[i]);
		v.push_back(r[i] + 1);
	}
	reverse(l + 1 , l + 1 + n); reverse(r + 1 , r + 1 + n);
	sort(all(v));
	v.erase(unique(all(v)) , v.end());
	for (int i = 1; i <= n; i++) {
		L[i] = lower_bound(all(v) , l[i]) - v.begin() + 1;
		R[i] = lower_bound(all(v) , r[i] + 1) - v.begin();
	}
	int m = v.size() - 1;
	for (int i = 0; i <= m; i++) f[0][i] = 1;
	for (int i = 1; i <= n; i++){ 
		for (int j = L[i]; j <= R[i]; j++){ 
			for (int k = i; k ; k--) {
				if (R[k] < j || L[k] > j) break;
				f[i][j] = add(f[i][j] , f[k - 1][j - 1] * C(i - k + v[j] - v[j - 1] , i - k + 1) % mol);
			} 
		} 
		for (int k = 1; k <= m; k++)
				f[i][k] = add(f[i][k] , f[i][k - 1]);
	} 
	ll ans = f[n][m];
	for (int i = 1; i <= n; i++) ans = ans * qpow(r[i] - l[i] + 1 , mol - 2) % mol;
	printf("%lld\n" , ans);
} 

