#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 4e5;
ll day[maxn + 11],sum[maxn + 11];

int main(){
	int n; ll x;
	scanf("%d %lld",&n,&x);
	for (int i = 1; i <= n; i++) {
		scanf("%lld",&day[i]);
		day[i + n] = day[i];
		sum[i + n] = sum[i] = day[i] * (day[i] + 1) / 2;
	}
	for (int i = 1; i <= 2 * n; i++) day[i] += day[i - 1] , sum[i] += sum[i - 1];
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (day[i] - day[i - 1] >= x) {
			ll res = day[i] - day[i - 1] - x;
			ans = max(ans , sum[i] - sum[i - 1] - res * (res + 1) / 2);
			continue;
		}
		int j = upper_bound(day + 1 , day + 2 * n + 1 , x + day[i - 1]) - day - 1;
		if (day[j] - day[i - 1] == x) ans = max(ans , sum[j] - sum[i - 1]);
		else {
			ll res = x - (day[j] - day[i - 1]);
			res = min(day[i] - 1 , day[j + 1] - day[j] - res);
			ll r = x - (day[j] - day[i - 1]) + res;
			ans = max(ans , sum[j] - sum[i - 1] - res * (res + 1) / 2 + r * (r + 1) / 2);
		}
	}
	printf("%lld\n" , ans);
} 

