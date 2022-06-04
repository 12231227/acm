#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int mol = 1e9 + 7;

int solve(ll m) {
	ll M = m / 4; M %= mol;
	ll N = m / 2; N %= mol;
	return ((M + 1 + N * (M + 1) % mol) % mol - 1ll * M * (M + 1) % mol + mol) % mol;
}

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) { 
		ll n; cin >> n;
		printf("%d\n" , solve(n));
	} 
} 
