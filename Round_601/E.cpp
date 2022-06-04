#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6;
ll sum = 0;
int n;
int a[maxn + 11];
vector <ll> v;

ll check(ll per) {
	ll ans = 0;
	ll s = 0;
	for (int i = 1; i <= n; i++) {
		s += a[i];
		s %= per;
		ans += min(s , per - s);
	}
	return ans;
}

int main(){
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d" , &a[i]);
		sum += a[i];
	} 
	if (sum == 1) { printf("-1\n");
	return 0;
	} 
	for (ll p = 2; p * p <= sum; p++) {
		if (sum % p == 0) {
			v.push_back(p);
			while (sum % p == 0) sum /= p;
		}
	} 
	if (sum > 1) v.push_back(sum);
	ll ans = 8e18;
	for (int i = 0; i < v.size(); i++) { 
		ans = min(ans , check(v[i]));
	} 
	printf("%lld\n" , ans);
} 
