#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

const int inf = 1e9;
const int maxn = 1e5;
int ans = -inf;
int lg[maxn + 11],ind[66],sum[maxn + 11];
int st[maxn + 11][25];
vector <int> pos[66];

int query(int l,int r) { int j = lg[r - l + 1]; return max(st[l][j] , st[r - (1 << j) + 1][j]); }

int main(){
	for (int i = 1; i <= 1e5; i++) {
		lg[i] = 0;
		while (1 << (lg[i] + 1) <= i) lg[i]++;
	}
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d",&x);
		st[i][0] = sum[i] = sum[i - 1] + x;
		pos[x + 30].pb(i);
	}
	for (int j = 1; j <= lg[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			st[i][j] = max(st[i][j - 1] , st[i + (1 << (j - 1))][j - 1]);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 60; j++) {
			if (pos[j].empty()) continue;
			while (pos[j][ind[j]] < i) { ind[j]++; if (ind[j] == pos[j].size()) break; }
		}
		int lim = n + 1;
		for (int j = 60; j >= 0; j--) {
			if (pos[j].empty() || ind[j] == pos[j].size()) continue;
			if (pos[j][ind[j]] > lim) continue;
			int l = pos[j][ind[j]]; int r = lim - 1;
			ans = max(ans , query(l , r) - sum[i - 1] - j + 30);
			lim = pos[j][ind[j]];
		}
	} 
	printf("%d\n" , ans);
}