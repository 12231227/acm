#include <bits/stdc++.h>
#define ll long long
using namespace std;

int lcm;
int f[200 * 200 + 11];

int gcd(int a,int b) { return b ? gcd(b , a % b) : a; }

int find(ll l,ll r) {
	if (l > r) return 0;
	l %= lcm; r %= lcm;
	if (l == 0) l = lcm;
	if (r == 0) r = lcm;
	if (l <= r) return f[r] - f[l - 1];
	return f[lcm] - f[l - 1] + f[r];
}

int main(){
	int t;
	for (scanf("%d",&t);t;t--) {
		int a,b,q;
		scanf("%d %d %d",&a,&b,&q);
		if (a > b) swap(a , b);
		lcm = a * b / gcd(a , b);
		f[0] = 0;
		for (int i = 1; i <= lcm; i++){
			f[i] = f[i - 1];
			if (i % b % a == i % a) f[i]++;
		}  
		while (q--) {
			ll l,r;
			scanf("%lld %lld",&l,&r);
			ll ans = 0;
			if (r - l + 1 <= lcm) {
				ans = find(l , r);
				printf("%lld " , r - l + 1 - ans);
			}
			else {
				ans = 1ll * f[lcm] * ((r - l + 1) / lcm);
				ll res = (r - l + 1) % lcm;
				ans += find(r - res + 1 , r);
				printf("%lld " , r - l + 1 - ans);
			}
		}
		puts("");
	}
} 

