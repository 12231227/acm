#include <bits/stdc++.h>
#define ll long long
signed main(){ 
	long long n,p;
	scanf("%lld %lld",&n,&p);
	int can = 0;
	for (ll m = 1; ; m++) { 
		ll tmp = n - p * m;
		if (tmp <= 0) break;
		ll has = __builtin_popcount(tmp);
		if (has <= m && m <= tmp) { 
			can = 1;
			printf("%lld\n",m);
			break;
		}
	}
	if (can == 0) printf("-1\n");
} 

