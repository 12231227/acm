
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5;
int n;
ll a[maxn + 11];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int check(ll d) {
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > d){
			ll x = a[i] % d;
			ans += min(x , d - x);
		}
		else ans += d - a[i];
		if (ans >= n) return n;
	}
	return ans;
}
 
int go(ll x) {
	if (x <= 1) return n;
	int ans = n;
	for (int i = 2; 1ll * i * i <= x; i++) { 
		if (x % i == 0) {
			ans = min(ans , check(i));
			while (x % i == 0) x /= i;
		} 
	} 
	if (x != 1) ans = min(ans , check(x));
	return ans;
} 
 
int main(){
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld",&a[i]);
	}
	int ans = n;
	shuffle(a + 1 , a + 1 + n , rng);
	for (int i = 1; i <= min(30 , n); i++) {
		ans = min(ans , go(a[i]));
		ans = min(ans , go(a[i] - 1));
		ans = min(ans , go(a[i] + 1));
	} 
	printf("%d\n" , ans);
} 
