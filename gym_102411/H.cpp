#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

int res[maxn + 11],pos[maxn + 11],a[maxn + 11],ans[maxn + 11];

int main(){ 
	int n;
	scanf("%d",&n);
	int sum = 0;
	int m = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
		res[i] = res[i - 1] + a[i];
		pos[res[i]] = i;
		m = max(m , a[i]);
	} 
	sum = res[n];
	for (int i = sum; i >= 0; i --)
		if (pos[i] == 0) pos[i] = pos[i + 1];
	for (int i = m; i <= sqrt(sum); i++) {
		int now = 0;
		int cnt = 1;
		for (int j = 1; j <= n; j++) {
			if (a[j] + now <= i) {
				now += a[j];
			}
			else {
				now = a[j];
				cnt++;
			}
		}
		ans[i] = cnt;
	}
	int q;
	scanf("%d",&q);
	while (q--) {
		int t;
		scanf("%d",&t);
		if (t < m) { printf("Impossible\n"); continue; } 
		if (t <= sqrt(sum)) { printf("%d\n" , ans[t]); continue; } 
		int cnt = 0;
		int now = 0;
		int ind = 1;
		while (true) { 
			if (now + t + 1 > sum) { cnt++; break; }
			int i = pos[now + t + 1];
			now = now + res[i - 1] - res[ind - 1];
			ind = i;
			cnt++;
		} 
		printf("%d\n" , cnt);
	} 
} 

