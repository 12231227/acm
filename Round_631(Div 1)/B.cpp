#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f[50],dp[50][50],sum[50];
ll m;
ll add(ll a,ll b) { a += b; if (a >= m) a -= m; return a; }
ll sub(ll a,ll b) { a -= b; if (a < 0) a += m; return a; }

int main(){
	int _;
	for (scanf("%d",&_);_;_--) {
		int d; scanf("%d %lld",&d,&m);
		int l = 0; f[0] = 1;
		while (true) { 
			if (f[l] * 2 > d) break;
			f[l + 1] = f[l] * 2;
			l++;
		} 
		f[l] = d - f[l] + 1;
		ll ans = 1;
		for (int i = 0; i <= l; i++) {
			f[i] %= m;
			ans = ans * add(f[i] , 1) % m;
		}
		ans = sub(ans , 1);
		printf("%lld\n" , ans);
	} 
} 
