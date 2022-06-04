#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1e6;
const int mol = 1e9 + 7;

int l[maxn + 11],r[maxn + 11],fac[maxn + 11],inv[maxn + 11];
map <pair<int,int> , int> mp;
int ans;

int C(int n,int m) { return 1ll * fac[n] * inv[m] % mol * inv[n - m] % mol; }

void dfs(int l,int r) {
	if (!ans) return;
	if (l > r) return;
	int pos;
	if (mp.count(make_pair(l , r))) pos = mp[make_pair(l , r)]; else ans = 0;
	if (l == r) return;
	ans = 1ll * ans * C(r - l , pos - l) % mol;
	dfs(l , pos - 1); dfs(pos + 1 , r);
}

int qpow(int a ,int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1ll * ans * a % mol;
		a = 1ll * a * a % mol;
		b >>= 1;
	}
	return ans;
}

int main(){ 
	int n;
	n = 1e6;
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mol;
	inv[n] = qpow(fac[n] , mol - 2);
	for (int i = n - 1; i >= 1; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mol;
	int c = 0;
	while (~scanf("%d",&n)) {
		c++;
		mp.clear();
		for (int i = 1; i <= n; i++) scanf("%d",&l[i]);
		for (int i = 1; i <= n; i++) scanf("%d",&r[i]);
		for (int i = 1; i <= n; i++) mp[make_pair(l[i] , r[i])] = i;
		ans = 1;
		dfs(1 , n);
		printf("Case #%d: " , c);
		printf("%d\n" , ans);
	} 
} 
