#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	for (int i = 1; i <= t; i++) { 
		int x; cin >> x;
		printf("Case #%d: " , i);
		if (x == 6) printf("-1\n");
		else if (x % 2 == 1) printf("1\n");
		else if (x % 4 == 0) printf("2\n"); 
		else {
			int ans = 4;
			if (x % 3 == 1) {
				int u = (x - 4) / 3;
				if (__gcd(u , u + 3) == 1 && __gcd(u + 1 , u + 3) == 1) ans = 3;
			}
			else if (x % 3 == 2) {
				int u = (x - 5) / 3;
				if (__gcd(u , u + 2) == 1 && __gcd(u , u + 3) == 1) ans = 3;
			} 
			if ((2 * x) % 3 == 0) {
				int u = 2 * x / 3 - 1;
				if (__gcd(u , u + 2) == 1) ans = 2;
			}
			printf("%d\n" , ans);
		}
	} 
} 
