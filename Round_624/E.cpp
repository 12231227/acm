#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000;
int par[maxn + 11],two[maxn + 11],cnt[maxn + 11],full[maxn + 11];
int dep[maxn + 11];

int main() {
	int t;
	scanf("%d" , &t);
	two[0] = 1;
	for (int i = 1; i <= 12; i++) two[i] = two[i - 1] * 2;
	while (t--) {
		int n,d;
		scanf("%d %d",&n,&d);
		int mn = 0;
		int res = n - 1;
		for (int i = 1; i <= 12; i++) {
			if (res > two[i]) { mn += i * two[i]; res -= two[i]; }
			else { mn += res * i; break; }
		}
		int mx = n * (n - 1) / 2;
		if (d < mn || d > mx) { printf("NO\n"); continue; }
		printf("YES\n");
		int cur = n * (n - 1) / 2;
		for (int i = 1; i < n; i++) cnt[i] = 1; cnt[n] = 0;
		for (int i = 2; i <= n; i++) par[i] = dep[i] = i - 1;
		for (int i = 2; i <= n; i++) full[i] = 0;
		while (cur > d) {
			int v = 0;
			for (int i = 2;i <= n; i++) 
				if (cnt[i] == 0 && !full[i] && (!v || dep[i] < dep[v])) v = i;
			int u = 0;
			for (int i = 1; i <= n; i++)
				if (dep[i] == dep[v] - 2 && cnt[i] < 2) { u = i; break; }
			if (!u) { full[v] = 1; continue; }
			cnt[par[v]]--;
			cnt[u]++;
			par[v] = u;
			dep[v] = dep[u] + 1;
			cur--;
		}
		for (int i = 2; i <= n; i++) printf("%d%s" , par[i] , i == n ? "\n" : " ");
	}
} 
