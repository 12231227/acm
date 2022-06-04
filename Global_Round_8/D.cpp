#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
int a[maxn + 11];
int cnt[25];

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d",&x);
		for (int j = 0; j < 20; j++)
			if (x & (1 << j)) cnt[j]++;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		int num = 0;
		for (int j = 19; j >= 0; j--)
			if (cnt[j]) {
				cnt[j]--;
				num += (1 << j);
			}
		ans += 1ll * num * num;
	}
	printf("%lld\n" , ans);
}