#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

ll gcd(ll a,ll b) { return b ? gcd(b , a % b) : a; }
const int maxn = 2e5;
ll a[maxn + 11],b[maxn + 11];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	sort(a + 1 , a + 1 + n);
	ll ans = 0;
	for (int i = 2; i <= n; i++) { 
		if (a[i] == a[i - 1]) continue;
		ll x = a[i] - a[i - 1];
		ans = gcd(x , ans);
	} 
	if (ans == 0) {
		for (int i = 1; i <= m; i++) printf("%lld%s" , b[i] + a[1] , i == m ? "\n" : " ");
	} 
	else {
		for (int i = 1; i <= m; i++) {
			printf("%lld" , __gcd(ans , a[1] + b[i]));
			printf("%s" , i == m ? "\n" : " ");
		}
	}
} 
