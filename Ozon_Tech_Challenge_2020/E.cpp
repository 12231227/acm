#include <bits/stdc++.h>
using namespace std;

int a[5111];

int main(){
	int n,m;
	cin >> n >> m;
	int mx = 0;
	for (int i = 3; i <= n; i++) mx += (i - 1) / 2;
	if (mx < m) { printf("-1\n"); return 0; }
	if (mx == m) {
		for (int i = 1; i <= n; i++)
		printf("%d " , i);
		return 0;
		
	}
	int r = 2;
	mx = 0;
	for (int i = 3; i <= n; i++) {
		if (mx + (i - 1) / 2 > m) { r = i - 1; break; }
		mx += (i - 1) / 2;
	}
	for (int i = 1; i <= r; i++) a[i] = i;
	mx = m - mx;
	int l;
	if (mx) {
		l = r - 1 - 2 * (mx - 1);
		a[r + 1] = a[r] + a[l]; r += 2;
	} else r++;
	int tmp = 1e9;
	int val = a[r - 1] + 1;
	for (int i = n; i >= r; i--) {
		a[i] = tmp - val;
		tmp -= val;
	}
	if (r < n && a[r + 1] <= a[r]) { printf("-1\n"); return 0; } 
	for (int i = 1; i <= n; i++) printf("%d " , a[i]);
} 

