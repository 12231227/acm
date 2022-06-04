#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mol = 1e9 + 7;

ll inv2,inv4,inv6;

ll qpow(ll a,ll b) { 
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mol;
		a = a * a % mol;
		b >>= 1;
	}
	return ans;
}

ll calc(ll n) {
	ll res = n * (n + 1) % mol * n % mol * (2 * n + 1) % mol * inv6 % mol;
	ll tmp = n * n % mol * (n + 1) % mol * (n + 1) % mol * inv4 % mol;
	res = (res - tmp + mol) % mol;
	tmp = n * (n + 1) % mol * (n + 1) % mol * inv2 % mol;
	res = (res + tmp) % mol;
	return res;
} 

int main(){
	//freopen("in.txt","r",stdin);
	int t;
	scanf("%d",&t);
	int c = 0;
	inv2 = qpow(2 , mol - 2);
	inv4 = qpow(4 , mol - 2);
	inv6 = qpow(6 , mol - 2);
	while (t--) {
		ll n,m;
		c++;
		scanf("%lld %lld",&n,&m);
		n -= 2; m -= 2;
		if (n <= 0 || m <= 0) { printf("Case %d: 0\n" , c); continue; }
		printf("Case %d: %lld\n" , c , calc(n) * calc(m) % mol * inv4 % mol);
	}
}