#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 500000;
int lpos[maxn + 11],rpos[maxn + 11],a[maxn + 11],out[maxn + 11];
ll f[maxn + 11],g[maxn + 11];

int main(){
	int n;
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++) scanf("%d" , &a[i]);
	stack <pair<int,int> > s; s.push({0 , 0});
	for (int i = 1; i <= n; i++) {
		while (!s.empty() && a[i] <= s.top().first) s.pop();
		lpos[i] = s.top().second;
		s.push({a[i] , i});
	}
	while (!s.empty()) s.pop(); s.push({0 , n + 1});
	for (int i = n; i >= 1; i--) {
		while (!s.empty() && a[i] <= s.top().first) s.pop();
		rpos[i] = s.top().second;
		s.push({a[i] , i});
	}
	for (int i = 1; i <= n; i++) f[i] = f[lpos[i]] + 1ll * a[i] * (i - lpos[i]);
	for (int i = n; i >= 1; i--) g[i] = g[rpos[i]] + 1ll * a[i] * (rpos[i] - i);
	int pos = 0; ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (f[i] + g[i] - a[i] > ans) { ans = f[i] + g[i] - a[i]; pos = i; }
	} 
	int i = pos;
	while (i) {
		for (int j = lpos[i] + 1; j <= i; j++) out[j] = a[i];
		i = lpos[i];
	}
	i = pos;
	while (i <= n) {
		for (int j = i; j < rpos[i]; j++) out[j] = a[i];
		i = rpos[i];
	}
	for (int i = 1; i <= n; i++) printf("%d " , out[i]);
} 
