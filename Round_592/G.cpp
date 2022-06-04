#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e6;
int b[maxn + 11];

int main(){
	int n;
	ll k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) b[i] = n - i + 1;
	ll ans = (2 * n - n / 2 + 1) * (n / 2);
	int r = n / 2 + (n % 2 == 0 ? 1 : 2);
	int add = n % 2 == 0 ? 1 : 0;
	for (int i = 1; i <= n / 2; i++) {
		if (ans <= k) break;
		ll pos = (ans - k + add) / 2;
		ans -= (2 * pos - add);
		swap(b[i] , b[r + pos - 1]);
	} 
	if (ans > k) printf("-1\n");
	else {
		printf("%lld\n" , ans);
		for (int i = 1; i <= n; i++) printf("%d%s",i , i == n ? "\n" : " ");
		for (int i = 1; i <= n; i++) printf("%d%s",b[i] , i == n ? "\n" : " ");
	}
} 

