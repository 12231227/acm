#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int maxn = 5e5;

ll has[maxn + 11];
vector <pair<ll,int> > pos[maxn + 11];
ll a[maxn + 11];

ll qpow(ll a,ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld",&a[i]);
	} 
	sort(a + 1 , a + 1 + n);
	for (int i = 1; i <= n; i++) {
		ll res = a[i];
		for (ll j = 2; j <= sqrt(a[i]);j++){
			if (res < j) break;
			if (res % j == 0) {
				int e = 0;
				while (res % j == 0) {
					e++;
					res /= j;
				}
				e %= k;
				if (e) pos[i].pb(make_pair(j , e));
			}
		}
		if (res != 1) pos[i].pb(make_pair(res , 1));
	}
	ll num = 0;
	for (int i = 1; i <= n; i++) {
		if (pos[i].empty()) {
			num++;
		}
		else {
			ll tmp = 1;
			for (int j = 0; j < pos[i].size(); j++){
				tmp = tmp * qpow(pos[i][j].first , pos[i][j].second);
			}
			has[tmp]++;
		}
	} 
	ll ans = num * (num - 1) / 2;
	for (int i = 1; i <= n; i++) {
		if (pos[i].empty()) continue;
		ll tmp = 1;
		ll m = 1;
		for (int j = 0; j < pos[i].size(); j++){
			tmp = tmp * qpow(pos[i][j].first , pos[i][j].second);
			m = m * qpow(pos[i][j].first , k);
		}
		if (tmp * tmp == m) {
			if (has[tmp] != 0){ 
				ans += has[tmp] * (has[tmp] - 1) / 2;
				has[tmp] = 0;
			}
		}
		else {
			if (m % tmp == 0 && m / tmp > tmp && m / tmp <= 1e5) {
				ans += has[m / tmp];
			}
		}
	}
	printf("%lld\n",ans);
} 

