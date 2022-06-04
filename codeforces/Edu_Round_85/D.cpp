#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int t;
	for (scanf("%d",&t);t;t--) {
		int n; ll l,r;
		scanf("%d %lld %lld",&n,&l,&r);
		if (l == 1ll * n * (n - 1) + 1) {
			puts("1");
			continue;
		}
		ll now = 0;
		int si = 0,j = 0;
		for (int i = 1; i < n; i++) {
			if (now + 2 * (n - i) >= l) {
				si = i;
				j = (l - now);
				break;
			}
			now += 2 * (n - i);
		}
		now = 0;
		for (int i = si; i < n; i++) {
			while (now < r - l + 1) {
				int out = i;
				if (j % 2 == 0) out += j / 2;
				printf("%d " , out);
				now++;
				if (j == 2 * (n - i)) { j = 1; break; }
				j++;
			}
			if (now == r - l + 1) break;
		}
		if (now < r - l + 1) printf("1");
		puts("");
	}
}
