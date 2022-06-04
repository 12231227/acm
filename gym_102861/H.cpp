#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

ll c[65][65];
ll w[65],bit[65];
int s[65];

ll dfs(int pos,ll sum,int k){
	if (k == 0) return 1;
	if (pos == -1) return k == 0;
	ll mx = 2ll * (1ll << (pos + 1)) - 2;
	if (sum >= mx) return c[s[pos]][k];
	ll ans = 0;
	if (bit[pos]) {
		if (sum >= bit[pos]) ans += dfs(pos - 1 , sum - bit[pos] , k - 1);
		ans += dfs(pos - 1 , sum , k);
	}
	else {
		ans = dfs(pos - 1 , sum , k);
	}
	return ans;
} 

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,k; cin >> n >> k;
	c[0][0] = 1;
	for (int i = 1; i <= 50; i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	for (int i = 1; i <= n; i++) cin >> w[i];
	sort(w + 1 , w + 1 + n , [&](ll a,ll b) { return a > b; });
	for (int i = 1; i <= n; i++) { 
		for (int j = 60; j >= 0; j--)
			if (w[i] & (1ll << j)) { bit[j] = w[i]; break; }
	} 
	s[0] = (bit[0] != 0);
	for (int i = 1; i <= 60; i++) s[i] = s[i - 1] + (bit[i] != 0);
	ll a,b; cin >> a >> b;
	printf("%lld\n" , dfs(60 , b , k) - dfs(60 , a - 1 , k));
} 
