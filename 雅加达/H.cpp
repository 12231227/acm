#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e5;

multiset <ll> s;
pair<ll,ll> p[maxn + 11];

void out(ll ans) {
	if (ans % 2 == 1) printf("%lld.5\n" , ans / 2);
	else printf("%lld.0\n" , ans / 2);
}

int main(){
	int n;
	scanf("%d",&n); 
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll l,r;
		scanf("%lld %lld",&l,&r);
		if (l > r) swap(l , r);
		ans = max(ans , l * r);
		p[i] = make_pair(l , r);
		s.insert(r);
	}
	sort(p + 1, p + 1 + n);
	for (int i = 1; i <= n - 1; i++) {
		multiset <ll>::iterator it = s.end();
		it--; it--;
		ll len = *it;
		ans = max(ans , p[i].first * len * 2);
		it = s.lower_bound(p[i].second);
		s.erase(it);
	} 
	out(ans);
} 

