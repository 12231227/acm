#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll c[25][25];
int cnt[25];

int main(){
	int t;
	c[0][0] = 1;
	for (int i = 1; i <= 20; i++){
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	for (scanf("%d",&t);t;t--) {
		ll n;
		scanf("%lld",&n);
		for (int i = 0; i <= 20; i++) cnt[i] = 0;
		int bit = 0;
		for (int i = 2; ; i++) {
			if (!n) break;
			bit++;
			cnt[n % i]++;
			n /= i;
		}
		int sum = 0;
		ll ans = 1;
		for (int i = bit; i >= 1; i--) {
			ans *= c[bit - i + 1 - sum][cnt[i]];
			sum += cnt[i];
		}
		if (cnt[0] && !cnt[bit]) {
			cnt[0]--;
			int sum = 1;
			ll sub = 1;
			for (int i = bit - 1; i >= 1; i--) {
				sub *= c[bit - i + 1 - sum][cnt[i]];
				sum += cnt[i];
			}
			ans -= sub;
		}
		printf("%lld\n" , ans - 1);
	}
} 

