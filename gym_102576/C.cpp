#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 200000;
ll c[maxn + 11];

int main(){
	int t;
	for (scanf("%d",&t);t;t--) {
		int n;
		ll d;
		scanf("%d %lld",&n,&d);
		for (int i = 1; i <= n; i++) scanf("%lld",&c[i]);
		sort(c + 1 , c + 1 + n);
		for (int i = 1; i <= n; i++) c[i] -= 1ll * (i - 1) * d;
		priority_queue <ll , vector <ll> , less <ll> > q;
		ll ans = 0; q.push(c[1]);
		for (int i = 2; i <= n; i++)
			if (c[i] < 0) ans -= c[i] , c[i] = 0;
		for (int i = 2; i <= n; i++) {
			q.push(c[i]);
			if (q.top() > c[i]) {
				ans += q.top() - c[i];
				q.pop();
				q.push(c[i]);
			}
		}
		printf("%lld\n" , ans);
	}
} 
